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
 * File: test_main.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Jun  4 11:30:47 2026
 */

/* Set Fuses Options */
/* USER_WORD_0 */

#pragma config NVMCTRL_BOOTPROT = SIZE_0BYTES
#pragma config NVMCTRL_EEPROM_SIZE = SIZE_16384BYTES
#pragma config BODVDDUSERLEVEL = 0x3F
#pragma config BODVDD_DIS = ENABLED
#pragma config BODVDD_ACTION = INT
#pragma config WDT_ENABLE = DISABLED
#pragma config WDT_ALWAYSON = DISABLED
#pragma config WDT_PER = CYC16384

/* USER_WORD_1 */

#pragma config WDT_WINDOW = CYC16384
#pragma config WDT_EWOFFSET = CYC16384
#pragma config WDT_WEN = DISABLED
#pragma config BODVDD_HYST = ENABLED
#pragma config NVMCTRL_REGION_LOCKS = 0xFFFF

#define MCHP_isMainFile
#include "test.h"
#include "test_private.h"

/* Microchip Global Variables */
/* Scheduler */
void __attribute__((section("MCHP_MemSectionScheduler"))) SysTick_Handler(void)
{
  {
    extern volatile uint_T ContinueTimeStep ;
    ContinueTimeStep = ContinueTimeStep | 1;/* Atomic bit-set of bit 0 */
  }
}

/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* WAIT STATES (start with 0 WS) */
  NVMCTRL_REGS->NVMCTRL_CTRLB |= NVMCTRL_CTRLB_RWS(2);
                                      /* 2 Wait State above 38MHz (VDD > 4.5V)*/

  /* ------------- Configure Oscillator -------------------------- */
  /* Targetted frequency is 4.8E+7 */
  MCLK_REGS->MCLK_CPUDIV = MCLK_CPUDIV_CPUDIV_DIV1;/* CPU Clock is 4.8E+7 : 4.8E+7 / 1 */

  {
    uint_T tmp_REG;                    /* Temp Configuration register */

    /* DFLL48Mhz running on startup */
    /* Copy Factory Calibration parameters */
    const uint32_T * OTP5_Ptr = (uint32_T *) OTP5_ADDR;
                        /* NVM Software Calibration Area Mapping (@ 0x806020) */
    OSCCTRL_REGS->OSCCTRL_CAL48M = ( (OTP5_Ptr[0] >> 19U) + (OTP5_Ptr[1] << 13U)
      ) & 0x1FFFFF ;            /*  OSC48M factory Calibration for VDD > 3.6V */
    OSCCTRL_REGS->OSCCTRL_OSC48MDIV = OSCCTRL_OSC48MDIV_DIV_DIV1;/* devide internal 48Mhz clock by 1 */
    OSCCTRL_REGS->OSCCTRL_OSC48MSTUP = OSCCTRL_OSC48MSTUP_STARTUP_CYCLE256;
                               /* Startup time, multiple of 48Mhz period (0s) */
    tmp_REG = OSCCTRL_OSC48MCTRL_ENABLE_Msk;
    tmp_REG |= OSCCTRL_OSC48MCTRL_RUNSTDBY_Msk;/* Run in Standby Position */
    OSCCTRL_REGS->OSCCTRL_OSC48MCTRL = tmp_REG;
    while (!((OSCCTRL_REGS->OSCCTRL_OSC48MSYNCBUSY) == 0)) ;/* Wait for Synchronisation */

    /* ---- Configure GCLK used to clock CPU (GCLK0) and peripherals ---- */
    tmp_REG = GCLK_GENCTRL_SRC_OSC48M; /* OSC48M oscillator output  */
    tmp_REG |= GCLK_GENCTRL_RUNSTDBY_Msk;/* Run in stdby mode */
    tmp_REG |= GCLK_GENCTRL_IDC_Msk;   /* Improve Duty Cycle */
    tmp_REG |= GCLK_GENCTRL_GENEN_Msk; /* Generic Clock Generator Enabled */
    tmp_REG |= GCLK_GENCTRL_DIV(1);    /* Divider factor */
    GCLK_REGS->GCLK_GENCTRL[0] = tmp_REG;/* GCLK0 config */
    tmp_REG = 0;
    tmp_REG |= GCLK_SYNCBUSY_GENCTRL0_Msk;/* GENCTRL0 sync bit */
    while ((GCLK_REGS->GCLK_SYNCBUSY & tmp_REG) != 0) ;/* Wait Sync for GCLKs */
  }

  /* ------- END of Clock Configuration ----  */
  /* ------- Configure pin groups ------- */
  /* Ports A27 use default settings */
  /* ------- Set pin Output Direction ------- */
  PORT_REGS->GROUP[0].PORT_DIRSET = 0x08000000;/* Port A Output Pins */

  /* Initialize model */
  test_initialize();

  /* Configure Timer Counter (TC0) module */
  GCLK_REGS->GCLK_PCHCTRL[30] = 0x40;  /* Start GCLK 30 used by TC0 */
  MCLK_REGS->MCLK_APBCMASK |= MCLK_APBCMASK_TC0_Msk;/* Enable peripheral clock */
  TC0_REGS->COUNT16.TC_CTRLA = TC_CTRLA_ENABLE_Msk | TC_CTRLA_RUNSTDBY_Msk |
    TC_CTRLA_MODE_COUNT16 | TC_CTRLA_PRESCALER_DIV1;

  /* ------- NVIC Setup ------ */
  NVIC_SetPriority(SysTick_IRQn, 3U);  /* Scheduler Priority set to 3 */
  __enable_irq();                      /* Enable Interrupt (Clear PRIMASK) */

  /* Enable Time-step */
  /* ------ SysTick  Init -----------  */
  SysTick->VAL = 1UL*8;
            /*  Start value for the sys Tick counter. Execute first STEP ASAP */
  SysTick->LOAD = 47999UL;
  /*  Reload value (corresponds to 1s). This value will be decremented at each CPU tick */
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
    SysTick_CTRL_ENABLE_Msk;
  /*  Enable SysTick Interrupt; start the counter; select the source for tick (MCLK)   */

  /* Main Loop */

  /* Single rate scheduler function */
  MCHP_Scheduler();                    /* no return */
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
