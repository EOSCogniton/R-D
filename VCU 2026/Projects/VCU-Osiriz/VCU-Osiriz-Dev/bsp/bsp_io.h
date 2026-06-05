/*
 * bsp_io.h
 *
 * Created: 03/06/2026 21:22:59
 *  Author: maxbo
 */ 


#ifndef BSP_IO_H_
#define BSP_IO_H_


bool bsp_start_button;

void bsp_io_read(void);
void bsp_io_write(void);
void bsp_io_init(void);
void bsp_set_buzzer(bool state);



#endif /* BSP_IO_H_ */