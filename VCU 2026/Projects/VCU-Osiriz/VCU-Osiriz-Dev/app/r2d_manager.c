/*
 * r2d_manager.c
 *
 * Created: 02/06/2026 16:52:37
 *  Author: maxbo
 */ 
#include <atmel_start.h>
#include <stdio.h>
#include "r2d_manager.h"
#include "../bsp/bsp_io.h"
#include "../bsp/bsp_can.h"
#include "../bsp/bsp_analog.h"
#include "../bsp/bsp_counter.h"


extern bool ts_active;
extern bool bsp_brake_pressed;
extern bool bsp_start_button;

static r2d_state_t current_state = STATE_LV_ON;
static uint32_t buzzer_start_time = 0;

void r2d_init(void) {
	current_state = STATE_LV_ON;
	buzzer_start_time = 0;
}

void r2d_update(void)
{
	switch (current_state) {
		
		case STATE_LV_ON:
		bsp_disable_inverter();
		bsp_set_buzzer(false);


		if (ts_active) {
			current_state = STATE_APPS_BRAKE_CHECK;
			printf("[R2D] Haute Tension detectee.\r\n");
		}
		break;

		case STATE_APPS_BRAKE_CHECK:

		if (bsp_brake_pressed && bsp_start_button) {

			buzzer_start_time = get_system_ms();
			bsp_set_buzzer(true); 
			
			current_state = STATE_BUZZER_RINGING;
			printf("[R2D] Demarrage valide.\r\n");
		}
		

		if (!ts_active) current_state = STATE_LV_ON;
		break;

		case STATE_BUZZER_RINGING:
		



		if (buzzer_start_time > 0 && get_system_ms() - buzzer_start_time >= 2000) {
			buzzer_start_time = 0;
			bsp_set_buzzer(false); 

			bsp_enable_inverter();
			
			current_state = STATE_READY_TO_DRIVE;
			printf("[R2D] Ready to Drive active.\r\n");
		}
		
		if (!ts_active) {
			bsp_set_buzzer(false);
			current_state = STATE_LV_ON;
		}
		break;

		case STATE_READY_TO_DRIVE:

		if (!ts_active) {
			current_state = STATE_LV_ON;
			printf("[R2D] Securite : Coupure Haute Tension, retour a l'etat initial.\r\n");
		}
		break;

		case STATE_FAULT:

		break;
	}
}