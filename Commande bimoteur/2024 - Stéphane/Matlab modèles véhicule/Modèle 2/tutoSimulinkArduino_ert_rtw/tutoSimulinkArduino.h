/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tutoSimulinkArduino.h
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

#ifndef RTW_HEADER_tutoSimulinkArduino_h_
#define RTW_HEADER_tutoSimulinkArduino_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef tutoSimulinkArduino_COMMON_INCLUDES_
#define tutoSimulinkArduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_arduino_digitalio.h"
#endif                                /* tutoSimulinkArduino_COMMON_INCLUDES_ */

#include "tutoSimulinkArduino_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
} B_tutoSimulinkArduino_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_blocks_DigitalWrite_tutoSimulinkArduino_T obj;/* '<Root>/Digital Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_tutoSimulinkArduino_T;

/* Parameters (default storage) */
struct P_tutoSimulinkArduino_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_tutoSimulinkArduino_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_tutoSimulinkArduino_T tutoSimulinkArduino_P;

/* Block signals (default storage) */
extern B_tutoSimulinkArduino_T tutoSimulinkArduino_B;

/* Block states (default storage) */
extern DW_tutoSimulinkArduino_T tutoSimulinkArduino_DW;

/* Model entry point functions */
extern void tutoSimulinkArduino_initialize(void);
extern void tutoSimulinkArduino_step(void);
extern void tutoSimulinkArduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tutoSimulinkArduino_T *const tutoSimulinkArduino_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tutoSimulinkArduino'
 */
#endif                                 /* RTW_HEADER_tutoSimulinkArduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
