/*
 * bsp_can.h
 *
 * Created: 02/06/2026 17:04:21
 *  Author: maxbo
 */ 


#ifndef BSP_CAN_H_
#define BSP_CAN_H_


bool ts_active;
extern float inverter_dc_voltage;
extern bool ts_command;

void bsp_disable_inverter(void);
void bsp_enable_inverter(void);
void bsp_can_init(void);
void bsp_can_read(void);
void bsp_can_send(uint32_t id, uint8_t *data, uint8_t length);

#endif /* BSP_CAN_H_ */