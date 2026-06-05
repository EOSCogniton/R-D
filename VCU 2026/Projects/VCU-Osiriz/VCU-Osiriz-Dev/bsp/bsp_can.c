/*
 * bsp_can.c
 * Created: 02/06/2026
 * Author: maxbo
 */ 

#include <atmel_start.h> 
#include <stdio.h>
#include "bsp_can.h" 
#include "bsp_analog.h"  


static struct can_message received_msg;
static uint8_t rx_data[8];
float inverter_dc_voltage = 0.0f;
bool ts_command = false;


void bsp_can_init(void) {
    can_async_enable(&CAN_0);
       
    // Liaison de la structure de réception (RX) à son buffer physique
    received_msg.data = rx_data;
}


void bsp_can_read(void) {
    if (can_async_read(&CAN_0, &received_msg) == ERR_NONE) {
        
        printf("[CAN RX] Message recu ! ID: 0x%03X | DLC: %d | Data: ",
               received_msg.id, received_msg.len);
        
        for (uint8_t i = 0; i < received_msg.len; i++) {
            printf("%02X ", rx_data[i]);
        }
        printf("\r\n");
		
		
        
        if (received_msg.id == 0x500) {
            printf("-> Message can de tests R2D recu !\r\n");
			uint8_t flags = rx_data[0];
			
			bool ts_switch      = (flags & (1 << 0)) != 0; // Vrai si le bit 0 est à 1
			if(ts_switch){
				ts_command = !ts_command;
				if(sdc_state){
					printf("[R2D] Etat du SDC : Ferme \r\n");
				}else{
					printf("[R2D] Etat du SDC : Ouvert \r\n");
				}
				if(ts_command){
					printf("[R2D] Commande tractive system : TS on \r\n");
				}else{
					printf("[R2D] Commande tractive system : TS off \r\n");
				}
				
			}
			bsp_brake_pressed = (flags & (1 << 1)) != 0; // Vrai si le bit 1 est à 1
			bsp_start_button   = (flags & (1 << 2)) != 0; // Vrai si le bit 2 est à 1
			sdc_state = (flags & (1 << 3)) != 0; // Vrai si le bit 3 est à 1
        }
		
		if (received_msg.id == 0x20) {
			int16_t raw_voltage = (int16_t)((rx_data[6] << 8) | rx_data[7]);
			inverter_dc_voltage = (float)raw_voltage / 10.0f;
			
			printf("Tension DC Onduleur : %d.%d V\r\n", (raw_voltage / 10), (raw_voltage % 10));
			
			if(inverter_dc_voltage > 558.0f){
				ts_active = true;
			}else{
				ts_active = false;
			}
		}
    }
}

void bsp_can_send(uint32_t id, uint8_t *data, uint8_t length) {
	struct can_message tx_msg;
	tx_msg.id   = id;
	tx_msg.type = CAN_TYPE_DATA;
	tx_msg.data = data;
	tx_msg.len  = length;
	can_async_write(&CAN_0, &tx_msg);
}


void bsp_disable_inverter(void){
	
}

void bsp_enable_inverter(void){
	
}
