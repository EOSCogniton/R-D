/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tutoSimulinkArduino_types.h
 *
 * Code generated for Simulink model 'tutoSimulinkArduino'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu May 30 17:06:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tutoSimulinkArduino_types_h_
#define RTW_HEADER_tutoSimulinkArduino_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigitalIO_tutoSimulinkArduino_T
#define typedef_b_arduinodriver_ArduinoDigitalIO_tutoSimulinkArduino_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C
  b_arduinodriver_ArduinoDigitalIO_tutoSimulinkArduino_T;

#endif      /* typedef_b_arduinodriver_ArduinoDigitalIO_tutoSimulinkArduino_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalIO_tutoSimulinkArduino_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_blocks_DigitalWrite_tutoSimulinkArduino_T
#define typedef_codertarget_arduinobase_blocks_DigitalWrite_tutoSimulinkArduino_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG
  codertarget_arduinobase_blocks_DigitalWrite_tutoSimulinkArduino_T;

#endif
/* typedef_codertarget_arduinobase_blocks_DigitalWrite_tutoSimulinkArduino_T */

/* Parameters (default storage) */
typedef struct P_tutoSimulinkArduino_T_ P_tutoSimulinkArduino_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_tutoSimulinkArduino_T RT_MODEL_tutoSimulinkArduino_T;

#endif                             /* RTW_HEADER_tutoSimulinkArduino_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
