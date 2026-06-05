/*
 * vehicle_logic.c
 *
 * Created: 02/06/2026 16:52:56
 *  Author: maxbo
 */ 

#include <atmel_start.h>
#include "vehicle_logic.h"
#include "../bsp/bsp_can.h"
#include "../bsp/bsp_analog.h"

bool closeAIRpos = false;
bool closeAIRneg = false;
bool closePre = false;


void vehicle_logic_init(void){
	
}

void vehicle_logic_safety_check(void){
	
	if(ts_command && sdc_state){
		if(inverter_dc_voltage > 0.95*588){
			closeAIRpos = true;
			closeAIRneg = true;
			closePre = false;
		}else{
			closeAIRpos = true;
			closeAIRneg = false;
			closePre = true;
		}
		
	}else{
		closeAIRpos = false;
		closeAIRneg = false;
		closePre = false;
	}
	
}