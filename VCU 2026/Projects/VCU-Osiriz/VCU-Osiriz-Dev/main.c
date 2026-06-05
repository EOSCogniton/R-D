#include <atmel_start.h>
#include "bsp/bsp_can.h"
#include "bsp/bsp_analog.h"
#include "bsp/bsp_io.h"
#include "app/r2d_manager.h"
#include "bsp/bsp_counter.h"
#include "bsp/bsp_counter.h"
#include "app/vehicle_logic.h"

int main(void)
{
	atmel_start_init();
	bsp_can_init();
	bsp_analog_init();
	bsp_timer_init();
	bsp_io_init();
	vehicle_logic_init(); 
	r2d_init();

	printf("VCU EPSA 2026 - Initialisation OK\r\n");
	
	uint32_t last_can_timer = get_system_ms();
	uint32_t canDeltaT = 20;
	

	while (1) {
		
		bsp_can_read();       // Check si des messages (BMS, Onduleur) sont dans la FIFO 0
		bsp_analog_readAll(); // Lit l'ADC et met à jour les moyennes des pédales

		// 2. Tâche Logique / Décisionnelle
		vehicle_logic_safety_check(); // Vérifie la plausibilité APPS
		r2d_update();        // Fait tourner la machine à états (LV -> R2D)
		

		// 3. Tâche Sorties (Écriture) - Cadencée (Exemple toutes les 20ms pour le CAN)
		// On peut utiliser un timer logiciel ou le SysTick pour cadencer proprement
		if (get_system_ms() - last_can_timer > canDeltaT) {
			last_can_timer = get_system_ms();
			//bsp_can_send_inverter_torque();
			//bsp_can_send_telemetry(); // Envoie l'odomètre et les statuts sur le bus
		}
		/*
		// 4. Gestion de la sauvegarde non volatile
		if (time_to_save()) {
			vehicle_logic_save_odometer(); // Sauvegarde finale en Flash juste avant l'extinction
		}*/
	}
}