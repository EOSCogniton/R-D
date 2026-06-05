#include <atmel_start.h>
#include <stdio.h>


#define FLASH_ODOMETRE_ADDR  (0x0003F000)
uint32_t distance_parcourue = 0;


struct can_message my_tx_msg;
uint8_t tx_data[4] = {0xAA, 0xBB, 0xCC, 0x00}; 
	
struct can_message my_rx_msg;
uint8_t rx_data[8];

void charger_distance_au_demarrage(void)
{
	// Lit 4 octets à l'adresse spécifiée et les copie dans notre variable
	flash_read(&FLASH_0, FLASH_ODOMETRE_ADDR, (uint8_t *)&distance_parcourue, sizeof(distance_parcourue));
	
	// Si la Flash est neuve/vide, elle renvoie 0xFFFFFFFF. On remet à 0 dans ce cas.
	if (distance_parcourue == 0xFFFFFFFF) {
		distance_parcourue = 0;
	}
}

void sauvegarder_distance_en_flash(uint32_t nouvelle_distance)
{
	// Étape 1 : Le contrôleur Flash du SAMC21 impose d'effacer la zone (la page) avant d'écrire
	flash_erase(&FLASH_0, FLASH_ODOMETRE_ADDR, 1);
	
	// Étape 2 : On écrit la nouvelle valeur
	distance_parcourue = nouvelle_distance;
	flash_write(&FLASH_0, FLASH_ODOMETRE_ADDR, (uint8_t *)&distance_parcourue, sizeof(distance_parcourue));
}



void can_system_init(void){
	can_async_enable(&CAN_0);
	my_tx_msg.id   = 0x123;       // ID du message (11 bits)
	my_tx_msg.type = CAN_TYPE_DATA;
	my_tx_msg.len  = 4;           // On envoie 4 octets
	my_tx_msg.data = tx_data;     // Pointeur vers notre tableau de données
	
	my_rx_msg.data = rx_data;
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	can_system_init();
	
	flash_unlock(&FLASH_0, FLASH_ODOMETRE_ADDR, 1);
	gpio_set_pin_level(GPIO(GPIO_PORTA, 23), false); // Mode normal (pas de standby)
	charger_distance_au_demarrage();
	printf("Odomètre chargé : %lu mètres accumulés.\r\n", distance_parcourue);

	
	bool inputValue = false;

	/* Replace with your application code */
	while (1) {
		
		inputValue = gpio_get_pin_level(DigitalInputTest);
		if(inputValue == true){
			printf("True\n\r");
			distance_parcourue+=1;
			printf("Distance parcourue : %u \n\r",distance_parcourue);
		}else{
			printf("False\n\r");
		}
		
		if(distance_parcourue%5==0 && distance_parcourue>0){
			printf("Sauvegarde distance\n\r");
			sauvegarder_distance_en_flash(distance_parcourue);
		}
		gpio_set_pin_level(DigitalOutputTest, inputValue);
		
		if (can_async_read(&CAN_0, &my_rx_msg) == ERR_NONE) {
			
			// On a reçu un message ! On affiche ses infos dans PuTTY
			printf("[CAN RX] Message reçu ! ID: 0x%03X | DLC: %d | Data: ",
			my_rx_msg.id, my_rx_msg.len);
			
			for (uint8_t i = 0; i < my_rx_msg.len; i++) {
				printf("%02X ", rx_data[i]);
			}
			printf("\r\n");
			
			// Exemple d'action : si on reçoit l'ID 0x500, on fait quelque chose
			if (my_rx_msg.id == 0x500) {
				printf("-> Ordre spécifique reçu sur l'ID 0x500 !\r\n");
			}
		}

		delay_ms(200);
		
	}
}
