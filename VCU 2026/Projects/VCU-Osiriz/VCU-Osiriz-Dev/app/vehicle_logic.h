/*
 * vehicle_logic.h
 *
 * Created: 03/06/2026 21:27:34
 *  Author: maxbo
 */ 


#ifndef VEHICLE_LOGIC_H_
#define VEHICLE_LOGIC_H_

extern bool closeAIRpos;
extern bool closeAIRneg;
extern bool closePre;
void vehicle_logic_init(void);
void vehicle_logic_safety_check(void);


#endif /* VEHICLE_LOGIC_H_ */