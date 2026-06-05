/*
 * r2d_manager.h
 *
 * Created: 02/06/2026 16:56:22
 *  Author: maxbo
 */ 


#ifndef R2D_MANAGER_H_
#define R2D_MANAGER_H_

#include <stdbool.h>
#include <stdint.h>


typedef enum {
	STATE_LV_ON,
	STATE_APPS_BRAKE_CHECK,
	STATE_BUZZER_RINGING,
	STATE_READY_TO_DRIVE,
	STATE_FAULT
} r2d_state_t;


void r2d_init(void);
void r2d_update(void);

#endif /* R2D_MANAGER_H_ */