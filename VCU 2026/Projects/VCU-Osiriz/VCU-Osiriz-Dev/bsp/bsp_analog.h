/*
 * bsp_analog.h
 *
 * Created: 03/06/2026 21:20:15
 *  Author: maxbo
 */ 


#ifndef BSP_ANALOG_H_
#define BSP_ANALOG_H_


bool bsp_brake_pressed;
bool bsp_start_button;
extern bool sdc_state;
void bsp_analog_read(void);
void bsp_analog_init(void);
void bsp_analog_readAll(void);


#endif /* BSP_ANALOG_H_ */