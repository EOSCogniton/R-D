/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.63.03 (03-Feb-2026)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: test.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Jun  4 11:30:47 2026
 */

#include "test.h"
#include "rtwtypes.h"

/* Real-time model */
static RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
volatile uint_T ContinueTimeStep = 0;
                       /* Microchip Global Variable for single rate scheduler */

/* Model step function */
void test_step(void)
{
  boolean_T rtb_DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_DataTypeConversion = true;

  /* S-Function (MCHP_Digital_Output_Write): '<Root>/Digital Output Write' */
  if (rtb_DataTypeConversion)
    PORT_REGS->GROUP[0].PORT_OUTSET = 0x08000000;/* Set pin A27*/
  else
    PORT_REGS->GROUP[0].PORT_OUTCLR = 0x08000000;/* Clear pin A27*/
}

/* Model initialize function */
void test_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  for (;;) {                           /* Infinite loop, no return */
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    __disable_irq();                   /* Disable all interrupts */
    ContinueTimeStep = ContinueTimeStep & (~ 1UL);
                                /* Atomic bit-clear of ContinueTimeStep bit 0 */

    /* Call model Scheduler */
    /* Step the model for base rate */
    test_step();

    /* Get model outputs here */

    /* Re-Enable Scheduler Interrupt */
    __enable_irq();
  }                                    /* end infinite loop for(;;) */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
