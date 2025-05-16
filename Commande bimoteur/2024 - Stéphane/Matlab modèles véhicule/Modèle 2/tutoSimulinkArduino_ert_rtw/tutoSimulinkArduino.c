/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tutoSimulinkArduino.c
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

#include "tutoSimulinkArduino.h"
#include "tutoSimulinkArduino_private.h"
#include "tutoSimulinkArduino_dt.h"

/* Block signals (default storage) */
B_tutoSimulinkArduino_T tutoSimulinkArduino_B;

/* Block states (default storage) */
DW_tutoSimulinkArduino_T tutoSimulinkArduino_DW;

/* Real-time model */
static RT_MODEL_tutoSimulinkArduino_T tutoSimulinkArduino_M_;
RT_MODEL_tutoSimulinkArduino_T *const tutoSimulinkArduino_M =
  &tutoSimulinkArduino_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void tutoSimulinkArduino_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (tutoSimulinkArduino_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    tutoSimulinkArduino_B.ManualSwitch = tutoSimulinkArduino_P.Constant_Value;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    tutoSimulinkArduino_B.ManualSwitch = tutoSimulinkArduino_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(tutoSimulinkArduino_B.ManualSwitch);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)tutoSimulinkArduino_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(tutoSimulinkArduino_M)!=-1) &&
        !((rtmGetTFinal(tutoSimulinkArduino_M)-
           tutoSimulinkArduino_M->Timing.taskTime0) >
          tutoSimulinkArduino_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(tutoSimulinkArduino_M, "Simulation finished");
    }

    if (rtmGetStopRequested(tutoSimulinkArduino_M)) {
      rtmSetErrorStatus(tutoSimulinkArduino_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  tutoSimulinkArduino_M->Timing.taskTime0 =
    ((time_T)(++tutoSimulinkArduino_M->Timing.clockTick0)) *
    tutoSimulinkArduino_M->Timing.stepSize0;
}

/* Model initialize function */
void tutoSimulinkArduino_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(tutoSimulinkArduino_M, 10.0);
  tutoSimulinkArduino_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  tutoSimulinkArduino_M->Sizes.checksums[0] = (2770255797U);
  tutoSimulinkArduino_M->Sizes.checksums[1] = (1324056840U);
  tutoSimulinkArduino_M->Sizes.checksums[2] = (1051842120U);
  tutoSimulinkArduino_M->Sizes.checksums[3] = (2963251748U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    tutoSimulinkArduino_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(tutoSimulinkArduino_M->extModeInfo,
      &tutoSimulinkArduino_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(tutoSimulinkArduino_M->extModeInfo,
                        tutoSimulinkArduino_M->Sizes.checksums);
    rteiSetTPtr(tutoSimulinkArduino_M->extModeInfo, rtmGetTPtr
                (tutoSimulinkArduino_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    tutoSimulinkArduino_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  tutoSimulinkArduino_DW.obj.matlabCodegenIsDeleted = false;
  tutoSimulinkArduino_DW.obj.isInitialized = 1;
  digitalIOSetup(13, 1);
  tutoSimulinkArduino_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void tutoSimulinkArduino_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!tutoSimulinkArduino_DW.obj.matlabCodegenIsDeleted) {
    tutoSimulinkArduino_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
