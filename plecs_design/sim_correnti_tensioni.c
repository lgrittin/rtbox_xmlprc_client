/*
 * Implementation file for: sim_correnti_tensioni
 * Generated with         : PLECS 4.7.3
 *                          PLECS RT Box 3 2.3.6
 * Generated on           : 6 Jun 2023 16:17:50
 */
#include "sim_correnti_tensioni.h"
#ifndef PLECS_HEADER_sim_correnti_tensioni_h_
#error The wrong header file "sim_correnti_tensioni.h" was included. Please
#error check your include path to see whether this file name conflicts with
#error the name of another header file.
#endif /* PLECS_HEADER_sim_correnti_tensioni_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "plexim/ProgrammableValue.h"
#include "plexim/AnalogOut.h"
#include "plexim/DataCapture.h"
#include "plexim/hw_wrapper.h"
#include "plexim/DigitalOut.h"
#include "plexim/DigitalIn.h"
#include "plexim/AnalogIn.h"
#include "plexim/SFP.h"
#include "plexim/HIL_Framework.h"
#include "plexim/ToFile.h"
#include <stdlib.h>
#define PLECSRunTimeError(msg) sim_correnti_tensioni_errorStatus = msg
struct CScriptStruct
{
   int numInputTerminals;
   int numOutputTerminals;
   int* numInputSignals;
   int* numOutputSignals;
   int numContStates;
   int numDiscStates;
   int numZCSignals;
   int numSampleTimes;
   int numParameters;
   int isMajorTimeStep;
   float time;
   const float ***inputs;
   float ***outputs;
   float *contStates;
   float *contDerivs;
   float *discStates;
   float *zCSignals;
   const int *paramNumDims;
   const int **paramDims;
   const int *paramNumElements;
   const float **paramRealData;
   const char **paramStringData;
   const char * const *sampleHits;
   const float *sampleTimePeriods;
   const float *sampleTimeOffsets;
   float *nextSampleHit;
   const char** errorStatus;
   const char** warningStatus;
   const char** rangeErrorMsg;
   int* rangeErrorLine;
   void (*writeCustomStateDouble)(void*, float);
   float (*readCustomStateDouble)(void*);
   void (*writeCustomStateInt)(void*, int);
   void (*writeCustomStateData)(void*, const void*, int);
   void (*readCustomStateData)(void*, void*, int);
};
static struct CScriptStruct sim_correnti_tensioni_cScriptStruct[1];
static char sim_correnti_tensioni_isMajorStep = '\001';
static const uint32_t sim_correnti_tensioni_subTaskPeriod[1]= {
   /* [0.0001, 0], [0, 0] */
   10
};
static uint32_t sim_correnti_tensioni_subTaskTick[1];
static char sim_correnti_tensioni_subTaskHit[1];
static const float sim_correnti_tensioni_UNCONNECTED = 0;
static float sim_correnti_tensioni_D_float[1];
static uint32_t sim_correnti_tensioni_D_uint32_t[17];
static float sim_correnti_tensioni_deriv[48] _ALIGN;
void sim_correnti_tensioni_0_cScriptStart(
                                          const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_0_cScriptOutput(
                                           const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_0_cScriptUpdate(
                                           const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_0_cScriptDerivative(
                                               const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_0_cScriptTerminate(
                                              const struct CScriptStruct *cScriptStruct);
static uint32_t sim_correnti_tensioni_tickLo[2];
static int32_t sim_correnti_tensioni_tickHi[2];
sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
static float sim_correnti_tensioni_ExtModeBuffer[3];
const float * const sim_correnti_tensioni_ExtModeSignals[] = {
   &sim_correnti_tensioni_ExtModeBuffer[0],
   &sim_correnti_tensioni_ExtModeBuffer[1],
   &sim_correnti_tensioni_ExtModeBuffer[2],
   &sim_correnti_tensioni_B.Sum1,
   &sim_correnti_tensioni_B.Sum1_1,
   &sim_correnti_tensioni_B.Sum1_2
};
#endif /* defined(EXTERNAL_MODE) */
sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X _ALIGN;
const char * sim_correnti_tensioni_errorStatus;
const float sim_correnti_tensioni_sampleTime[2][2] = {
   /* Task "[0, 0]" */
   {1e-05f, 0.f},
   /* Task "[0.0001, 0]" */
   {0.0001f, 0.f}
};
const char * const sim_correnti_tensioni_checksum =
   "895b68800ba303bf3278b96c89da0a82cbdcb1a4";
/* Target declarations */
struct PlxDataCaptureRegistry plxDataCaptureRegistry[3];
const int plxUseEthercat = 0;
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[21];
struct PlxToFileRegistry plxToFileRegistry[1];

void sim_correnti_tensioni_initialize(float time)
{
   float remainder;
   sim_correnti_tensioni_errorStatus = NULL;
   sim_correnti_tensioni_tickHi[0] =
      floor(time/(4294967296.0*sim_correnti_tensioni_sampleTime[0][0]));
   remainder = time - sim_correnti_tensioni_tickHi[0]*4294967296.0*
               sim_correnti_tensioni_sampleTime[0][0];
   sim_correnti_tensioni_tickLo[0] = floor(
                                           remainder/
                                           sim_correnti_tensioni_sampleTime[0][
                                              0] + .5);
   remainder -= sim_correnti_tensioni_tickLo[0]*
                sim_correnti_tensioni_sampleTime[0][0];
   if (fabsf(remainder) > 1e-6*fabsf(time))
   {
      sim_correnti_tensioni_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   sim_correnti_tensioni_subTaskTick[0] = 0; /* [0, 0], [0.0001, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(sim_correnti_tensioni_tickHi[0]);
      for (i = 0; i < 1; ++i)
      {
         delta = -sim_correnti_tensioni_subTaskPeriod[i];
         delta %= sim_correnti_tensioni_subTaskPeriod[i];
         if (sim_correnti_tensioni_tickHi[0] < 0)
         {
            delta = sim_correnti_tensioni_subTaskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            sim_correnti_tensioni_subTaskTick[i] =
               (sim_correnti_tensioni_subTaskTick[i] +
                delta) % sim_correnti_tensioni_subTaskPeriod[i];
         }
         sim_correnti_tensioni_subTaskTick[i] =
            (sim_correnti_tensioni_subTaskTick[i] +
             sim_correnti_tensioni_tickLo[0] %
             sim_correnti_tensioni_subTaskPeriod[i]) %
            sim_correnti_tensioni_subTaskPeriod[i];
      }
   }

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(3);
   setDigitalOutVoltage(0);
   plxInitDigitalOut();
   initPWMCapture();
   plxSetupAnalogSampling(1, 0, 1.00000000000000008e-05);
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0, 0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);


   /* Initialization for Subsystem : 'sim_correnti_tensioni' */
   sim_correnti_tensioni_D_float[0] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input10' */
   {
      static double programmableValueData[] = {
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00,
         -1.00000000000000000e+00, -1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(0, "Input10", 16, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input00' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(1, "Input00", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_x = 0;
   sim_correnti_tensioni_X.Integrator7_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder62/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1 = 0.;
   sim_correnti_tensioni_D_uint32_t[0] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input01' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(2, "Input01", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_1_x = 0;
   sim_correnti_tensioni_X.Integrator7_1_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_1_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_1_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder61/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_1 = 0.;
   sim_correnti_tensioni_D_uint32_t[1] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input02' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(3, "Input02", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_2_x = 0;
   sim_correnti_tensioni_X.Integrator7_2_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_2_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_2_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder63/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_2 = 0.;
   sim_correnti_tensioni_D_uint32_t[2] = 0;

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out4' */
   setupAnalogOut(0, 1.000000000e+00f, 0.000000000e+00f, -1.000000000e+01,
                  1.000000000e+01);

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input11' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(4, "Input11", 1, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input03' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(5, "Input03", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_3_x = 0;
   sim_correnti_tensioni_X.Integrator7_3_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_3_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_3_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder64/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_3 = 0.;
   sim_correnti_tensioni_D_uint32_t[3] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input04' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(6, "Input04", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_4_x = 0;
   sim_correnti_tensioni_X.Integrator7_4_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_4_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_4_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder65/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_4 = 0.;
   sim_correnti_tensioni_D_uint32_t[4] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input05' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(7, "Input05", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_5_x = 0;
   sim_correnti_tensioni_X.Integrator7_5_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_5_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_5_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder66/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_5 = 0.;
   sim_correnti_tensioni_D_uint32_t[5] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input06' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(8, "Input06", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_6_x = 0;
   sim_correnti_tensioni_X.Integrator7_6_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_6_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_6_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder67/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_6 = 0.;
   sim_correnti_tensioni_D_uint32_t[6] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input07' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(9, "Input07", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_7_x = 0;
   sim_correnti_tensioni_X.Integrator7_7_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_7_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_7_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder68/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_7 = 0.;
   sim_correnti_tensioni_D_uint32_t[7] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input08' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(10, "Input08", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_8_x = 0;
   sim_correnti_tensioni_X.Integrator7_8_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_8_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_8_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder69/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_8 = 0.;
   sim_correnti_tensioni_D_uint32_t[8] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input09' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(11, "Input09", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_9_x = 0;
   sim_correnti_tensioni_X.Integrator7_9_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_9_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_9_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder70/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_9 = 0.;
   sim_correnti_tensioni_D_uint32_t[9] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0A' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(12, "Input0A", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_10_x = 0;
   sim_correnti_tensioni_X.Integrator7_10_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_10_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_10_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder71/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_10 = 0.;
   sim_correnti_tensioni_D_uint32_t[10] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0B' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(13, "Input0B", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_11_x = 0;
   sim_correnti_tensioni_X.Integrator7_11_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_11_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_11_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder72/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_11 = 0.;
   sim_correnti_tensioni_D_uint32_t[11] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0C' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(14, "Input0C", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_12_x = 0;
   sim_correnti_tensioni_X.Integrator7_12_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_12_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_12_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder73/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_12 = 0.;
   sim_correnti_tensioni_D_uint32_t[12] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0D' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(15, "Input0D", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_13_x = 0;
   sim_correnti_tensioni_X.Integrator7_13_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_13_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_13_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder74/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_13 = 0.;
   sim_correnti_tensioni_D_uint32_t[13] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0E' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(16, "Input0E", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_14_x = 0;
   sim_correnti_tensioni_X.Integrator7_14_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_14_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_14_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder75/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_14 = 0.;
   sim_correnti_tensioni_D_uint32_t[14] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0F' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e+00, 3.14158999999999992e+02,
         0.00000000000000000e+00, 1.00000000000000000e+01,
         0.00000000000000000e+00, 6.80000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e+00,
         3.14158999999999992e+02, 0.00000000000000000e+00,
         1.00000000000000000e+01, 0.00000000000000000e+00,
         6.80000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(17, "Input0F", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_15_x = 0;
   sim_correnti_tensioni_X.Integrator7_15_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_15_x = 0.f;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_15_x = 0.f;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Signal Builder76/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_15 = 0.;
   sim_correnti_tensioni_D_uint32_t[15] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input14' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(18, "Input14", 1, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input12' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(19, "Input12", 1, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input13' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(20, "Input13", 1, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1_16 = 0.;
   sim_correnti_tensioni_D_uint32_t[16] = 0;

   /* Initialization for Data Capture : 'sim_correnti_tensioni/Capture1' */
   {
      static double dataBuffer[4000];
      plxSetupDataCapture(0, "Capture1", 1, 2000, dataBuffer, 1,
                          5.00000000000000000e-01, 1.00000000000000008e-05);
   }


   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out5' */
   setupAnalogOut(1, 1.000000000e+00f, 0.000000000e+00f, -1.000000000e+01,
                  1.000000000e+01);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out6' */
   setupAnalogOut(2, 1.000000000e+00f, 0.000000000e+00f, -1.000000000e+01,
                  1.000000000e+01);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out7' */
   setupAnalogOut(3, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out8' */
   setupAnalogOut(4, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out9' */
   setupAnalogOut(5, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out10' */
   setupAnalogOut(6, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out11' */
   setupAnalogOut(7, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out13' */
   setupAnalogOut(8, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out14' */
   setupAnalogOut(9, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out15' */
   setupAnalogOut(10, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out16' */
   setupAnalogOut(11, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out17' */
   setupAnalogOut(12, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out18' */
   setupAnalogOut(13, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out19' */
   setupAnalogOut(14, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out20' */
   setupAnalogOut(15, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Data Capture : 'sim_correnti_tensioni/Capture2' */
   {
      static double dataBuffer[4000];
      plxSetupDataCapture(1, "Capture2", 1, 2000, dataBuffer, 1,
                          5.00000000000000000e-01, 1.00000000000000008e-05);
   }


   /* Initialization for Data Capture : 'sim_correnti_tensioni/Capture3' */
   {
      static double dataBuffer[4000];
      plxSetupDataCapture(2, "Capture3", 1, 2000, dataBuffer, 1,
                          5.00000000000000000e-01, 1.00000000000000008e-05);
   }


   /* Initialization for Subsystem : 'sim_correnti_tensioni' */
   sim_correnti_tensioni_B.sim_correnti_tensioni_i1 = 0;

   /* Initialization for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   {
      static int numInputSignals[] = {
         1
      };
      static const float* inputPtrs[] = {
         &sim_correnti_tensioni_B.sim_correnti_tensioni_i1
      };
      static const float** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static float* outputPtrs[] = {
         &sim_correnti_tensioni_B.C_Script
      };
      static float** outputs[] = {
         &outputPtrs[0]
      };
      static float nextSampleHit;
      static const char * sampleHits[] = {
         &sim_correnti_tensioni_isMajorStep
      };
      static float sampleTimePeriods[] = {
         0.0001
      };
      static float sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      static const float paramData[] = {
         0.f,2.f,0.f,0.0001f
      };
      static const float* paramDataPtr[] = {
         paramData+0,paramData+1,paramData+2,paramData+3
      };
      static const char paramStringData[] = "\0\0\0\0";
      static const char* paramStringDataPtr[] = {
         paramStringData+0,paramStringData+1,paramStringData+2,
         paramStringData+3
      };
      static const int paramDim[] = {
         1,1,1,1,1,1,1,1
      };
      static const int* paramDimPtr[] = {
         paramDim+0,paramDim+2,paramDim+4,paramDim+6
      };
      static const int paramNumElements[] = {
         1,1,1,1
      };
      static const int paramNumDims[] = {
         2,2,2,2
      };
      errorStatus = NULL;
      warningStatus = NULL;
      rangeErrorMsg = NULL;
      sim_correnti_tensioni_cScriptStruct[0].isMajorTimeStep = 1;
      sim_correnti_tensioni_cScriptStruct[0].numInputTerminals = 1;
      sim_correnti_tensioni_cScriptStruct[0].numInputSignals =
         numInputSignals;
      sim_correnti_tensioni_cScriptStruct[0].inputs = inputs;
      sim_correnti_tensioni_cScriptStruct[0].numOutputTerminals = 1;
      sim_correnti_tensioni_cScriptStruct[0].numOutputSignals =
         numOutputSignals;
      sim_correnti_tensioni_cScriptStruct[0].outputs = outputs;
      sim_correnti_tensioni_cScriptStruct[0].numContStates = 0;
      sim_correnti_tensioni_cScriptStruct[0].contStates = NULL;
      sim_correnti_tensioni_cScriptStruct[0].contDerivs = NULL;
      sim_correnti_tensioni_cScriptStruct[0].numDiscStates = 1;
      sim_correnti_tensioni_cScriptStruct[0].discStates =
         &sim_correnti_tensioni_X.C_Script;
      sim_correnti_tensioni_cScriptStruct[0].numZCSignals = 0;
      sim_correnti_tensioni_cScriptStruct[0].numParameters = 4;
      sim_correnti_tensioni_cScriptStruct[0].paramNumDims = paramNumDims;
      sim_correnti_tensioni_cScriptStruct[0].paramDims = paramDimPtr;
      sim_correnti_tensioni_cScriptStruct[0].paramNumElements =
         paramNumElements;
      sim_correnti_tensioni_cScriptStruct[0].paramRealData = paramDataPtr;
      sim_correnti_tensioni_cScriptStruct[0].paramStringData =
         paramStringDataPtr;
      sim_correnti_tensioni_cScriptStruct[0].numSampleTimes = 1;
      sim_correnti_tensioni_cScriptStruct[0].sampleTimePeriods =
         sampleTimePeriods;
      sim_correnti_tensioni_cScriptStruct[0].sampleTimeOffsets =
         sampleTimeOffsets;
      sim_correnti_tensioni_cScriptStruct[0].numSampleTimes = 1;
      sim_correnti_tensioni_cScriptStruct[0].sampleHits = sampleHits;
      sim_correnti_tensioni_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      sim_correnti_tensioni_cScriptStruct[0].errorStatus = &errorStatus;
      sim_correnti_tensioni_cScriptStruct[0].warningStatus = &warningStatus;
      sim_correnti_tensioni_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      sim_correnti_tensioni_0_cScriptStart(
                                           &sim_correnti_tensioni_cScriptStruct[
                                              0]);
      if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
         sim_correnti_tensioni_errorStatus =
            *sim_correnti_tensioni_cScriptStruct[0].errorStatus;
   }
}

void sim_correnti_tensioni_step(int task_id)
{
   if (sim_correnti_tensioni_errorStatus)
   {
      return;
   }
   switch(task_id)
   {
   case 0: /* Task "[0, 0]" */
   {
      {
         size_t i;
         for (i = 0; i < 1; ++i)
         {
            sim_correnti_tensioni_subTaskHit[i] =
               (sim_correnti_tensioni_subTaskTick[i] == 0);
         }
      }
      if (sim_correnti_tensioni_subTaskHit[0])
      {
         /* Subsystem : 'sim_correnti_tensioni' */
         sim_correnti_tensioni_B.sim_correnti_tensioni =
            sim_correnti_tensioni_D_float[0];
      }
      /* Programmable Value : 'sim_correnti_tensioni/Input10' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[0];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input10[0] = plxGetProgrammableValueData(0, 0);
      sim_correnti_tensioni_B.Input10[1] = plxGetProgrammableValueData(0, 1);
      sim_correnti_tensioni_B.Input10[2] = plxGetProgrammableValueData(0, 2);
      sim_correnti_tensioni_B.Input10[3] = plxGetProgrammableValueData(0, 3);
      sim_correnti_tensioni_B.Input10[4] = plxGetProgrammableValueData(0, 4);
      sim_correnti_tensioni_B.Input10[5] = plxGetProgrammableValueData(0, 5);
      sim_correnti_tensioni_B.Input10[6] = plxGetProgrammableValueData(0, 6);
      sim_correnti_tensioni_B.Input10[7] = plxGetProgrammableValueData(0, 7);
      sim_correnti_tensioni_B.Input10[8] = plxGetProgrammableValueData(0, 8);
      sim_correnti_tensioni_B.Input10[9] = plxGetProgrammableValueData(0, 9);
      sim_correnti_tensioni_B.Input10[10] =
         plxGetProgrammableValueData(0, 10);
      sim_correnti_tensioni_B.Input10[11] =
         plxGetProgrammableValueData(0, 11);
      sim_correnti_tensioni_B.Input10[12] =
         plxGetProgrammableValueData(0, 12);
      sim_correnti_tensioni_B.Input10[13] =
         plxGetProgrammableValueData(0, 13);
      sim_correnti_tensioni_B.Input10[14] =
         plxGetProgrammableValueData(0, 14);
      sim_correnti_tensioni_B.Input10[15] =
         plxGetProgrammableValueData(0, 15);
      sim_correnti_tensioni_B.Input10[16] = plxGetProgrammableValueUpdateFlag(
                                                                              0);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder62/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant =
         sim_correnti_tensioni_B.Input10[0] != 1.f;

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder61/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_1 =
         sim_correnti_tensioni_B.Input10[1] != 1.f;

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder63/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_2 =
         sim_correnti_tensioni_B.Input10[2] != 1.f;

      /* Programmable Value : 'sim_correnti_tensioni/Input00' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[1];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input00[0] = plxGetProgrammableValueData(1, 0);
      sim_correnti_tensioni_B.Input00[1] = plxGetProgrammableValueData(1, 1);
      sim_correnti_tensioni_B.Input00[2] = plxGetProgrammableValueData(1, 2);
      sim_correnti_tensioni_B.Input00[3] = plxGetProgrammableValueData(1, 3);
      sim_correnti_tensioni_B.Input00[4] = plxGetProgrammableValueData(1, 4);
      sim_correnti_tensioni_B.Input00[5] = plxGetProgrammableValueData(1, 5);
      sim_correnti_tensioni_B.Input00[6] = plxGetProgrammableValueData(1, 6);
      sim_correnti_tensioni_B.Input00[7] =
         plxGetProgrammableValueUpdateFlag(1);

      /* Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant))
      {
         sim_correnti_tensioni_X.Integrator7_x =
            sim_correnti_tensioni_B.Input00[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_x =
            sim_correnti_tensioni_X.Integrator7_x - span*floorf(
                                                                sim_correnti_tensioni_X.Integrator7_x/
                                                                span) + (0.f);
      }
      sim_correnti_tensioni_B.Integrator7 =
         sim_correnti_tensioni_X.Integrator7_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6 =
         sim_correnti_tensioni_X.Integrator6_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_x =
            sim_correnti_tensioni_X.Integrator4_x - span*floorf(
                                                                sim_correnti_tensioni_X.Integrator4_x/
                                                                span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4 =
         sim_correnti_tensioni_X.Integrator4_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder62/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4)
         sim_correnti_tensioni_B.Comparator1 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4)
         sim_correnti_tensioni_B.Comparator1 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder62/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1 &&
          (sim_correnti_tensioni_B.Comparator1))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[0] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[0] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[0] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder62/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder62/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder62/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder62/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder62/Product1'
       */
      sim_correnti_tensioni_B.Sum1 =
         (sim_correnti_tensioni_B.Input00[0] *
          sinf(sim_correnti_tensioni_B.Integrator7) *
          sim_correnti_tensioni_B.Integrator6) +
         (sim_correnti_tensioni_B.Input00[4] *
          sim_correnti_tensioni_B.Monoflop1 *
          sim_correnti_tensioni_B.Integrator6) +
         (sim_correnti_tensioni_B.Input00[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6);

      /* Programmable Value : 'sim_correnti_tensioni/Input01' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[2];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input01[0] = plxGetProgrammableValueData(2, 0);
      sim_correnti_tensioni_B.Input01[1] = plxGetProgrammableValueData(2, 1);
      sim_correnti_tensioni_B.Input01[2] = plxGetProgrammableValueData(2, 2);
      sim_correnti_tensioni_B.Input01[3] = plxGetProgrammableValueData(2, 3);
      sim_correnti_tensioni_B.Input01[4] = plxGetProgrammableValueData(2, 4);
      sim_correnti_tensioni_B.Input01[5] = plxGetProgrammableValueData(2, 5);
      sim_correnti_tensioni_B.Input01[6] = plxGetProgrammableValueData(2, 6);
      sim_correnti_tensioni_B.Input01[7] =
         plxGetProgrammableValueUpdateFlag(2);

      /* Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_1_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_1_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_1))
      {
         sim_correnti_tensioni_X.Integrator7_1_x =
            sim_correnti_tensioni_B.Input01[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_1_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_1_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_1_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_1_x =
            sim_correnti_tensioni_X.Integrator7_1_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_1_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_1 =
         sim_correnti_tensioni_X.Integrator7_1_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_1_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_1_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_1_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_1_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_1 =
         sim_correnti_tensioni_X.Integrator6_1_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_1_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_1_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_1_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_1_x =
            sim_correnti_tensioni_X.Integrator4_1_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_1_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_1 =
         sim_correnti_tensioni_X.Integrator4_1_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder61/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_1)
         sim_correnti_tensioni_B.Comparator1_1 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_1)
         sim_correnti_tensioni_B.Comparator1_1 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder61/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_1 &&
          (sim_correnti_tensioni_B.Comparator1_1))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[1] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[1] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_1 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[1] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_1 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder61/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder61/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder61/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder61/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder61/Product1'
       */
      sim_correnti_tensioni_B.Sum1_1 =
         (sim_correnti_tensioni_B.Input01[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_1) *
          sim_correnti_tensioni_B.Integrator6_1) +
         (sim_correnti_tensioni_B.Input01[4] *
          sim_correnti_tensioni_B.Monoflop1_1 *
          sim_correnti_tensioni_B.Integrator6_1) +
         (sim_correnti_tensioni_B.Input01[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_1);

      /* Programmable Value : 'sim_correnti_tensioni/Input02' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[3];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input02[0] = plxGetProgrammableValueData(3, 0);
      sim_correnti_tensioni_B.Input02[1] = plxGetProgrammableValueData(3, 1);
      sim_correnti_tensioni_B.Input02[2] = plxGetProgrammableValueData(3, 2);
      sim_correnti_tensioni_B.Input02[3] = plxGetProgrammableValueData(3, 3);
      sim_correnti_tensioni_B.Input02[4] = plxGetProgrammableValueData(3, 4);
      sim_correnti_tensioni_B.Input02[5] = plxGetProgrammableValueData(3, 5);
      sim_correnti_tensioni_B.Input02[6] = plxGetProgrammableValueData(3, 6);
      sim_correnti_tensioni_B.Input02[7] =
         plxGetProgrammableValueUpdateFlag(3);

      /* Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_2_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_2_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_2))
      {
         sim_correnti_tensioni_X.Integrator7_2_x =
            sim_correnti_tensioni_B.Input02[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_2_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_2_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_2_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_2_x =
            sim_correnti_tensioni_X.Integrator7_2_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_2_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_2 =
         sim_correnti_tensioni_X.Integrator7_2_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_2_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_2_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_2_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_2_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_2 =
         sim_correnti_tensioni_X.Integrator6_2_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_2_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_2_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_2_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_2_x =
            sim_correnti_tensioni_X.Integrator4_2_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_2_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_2 =
         sim_correnti_tensioni_X.Integrator4_2_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder63/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_2)
         sim_correnti_tensioni_B.Comparator1_2 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_2)
         sim_correnti_tensioni_B.Comparator1_2 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder63/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_2 &&
          (sim_correnti_tensioni_B.Comparator1_2))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[2] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[2] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_2 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[2] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_2 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder63/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder63/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder63/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder63/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder63/Product1'
       */
      sim_correnti_tensioni_B.Sum1_2 =
         (sim_correnti_tensioni_B.Input02[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_2) *
          sim_correnti_tensioni_B.Integrator6_2) +
         (sim_correnti_tensioni_B.Input02[4] *
          sim_correnti_tensioni_B.Monoflop1_2 *
          sim_correnti_tensioni_B.Integrator6_2) +
         (sim_correnti_tensioni_B.Input02[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_2);
      /* Analog Out : 'sim_correnti_tensioni/Analog Out4' */
      setAnalogOut(0, sim_correnti_tensioni_B.Sum1);
      /* Programmable Value : 'sim_correnti_tensioni/Input11' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[4];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      /* Programmable Value : 'sim_correnti_tensioni/Input03' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[5];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input03[0] = plxGetProgrammableValueData(5, 0);
      sim_correnti_tensioni_B.Input03[1] = plxGetProgrammableValueData(5, 1);
      sim_correnti_tensioni_B.Input03[2] = plxGetProgrammableValueData(5, 2);
      sim_correnti_tensioni_B.Input03[3] = plxGetProgrammableValueData(5, 3);
      sim_correnti_tensioni_B.Input03[4] = plxGetProgrammableValueData(5, 4);
      sim_correnti_tensioni_B.Input03[5] = plxGetProgrammableValueData(5, 5);
      sim_correnti_tensioni_B.Input03[6] = plxGetProgrammableValueData(5, 6);
      sim_correnti_tensioni_B.Input03[7] =
         plxGetProgrammableValueUpdateFlag(5);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder64/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_3 =
         sim_correnti_tensioni_B.Input10[3] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_3_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_3_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_3))
      {
         sim_correnti_tensioni_X.Integrator7_3_x =
            sim_correnti_tensioni_B.Input03[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_3_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_3_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_3_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_3_x =
            sim_correnti_tensioni_X.Integrator7_3_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_3_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_3 =
         sim_correnti_tensioni_X.Integrator7_3_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_3_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_3_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_3_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_3_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_3 =
         sim_correnti_tensioni_X.Integrator6_3_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_3_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_3_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_3_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_3_x =
            sim_correnti_tensioni_X.Integrator4_3_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_3_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_3 =
         sim_correnti_tensioni_X.Integrator4_3_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder64/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_3)
         sim_correnti_tensioni_B.Comparator1_3 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_3)
         sim_correnti_tensioni_B.Comparator1_3 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder64/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_3 &&
          (sim_correnti_tensioni_B.Comparator1_3))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[3] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[3] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_3 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[3] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_3 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder64/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder64/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder64/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder64/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder64/Product1'
       */
      sim_correnti_tensioni_B.Sum1_3 =
         (sim_correnti_tensioni_B.Input03[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_3) *
          sim_correnti_tensioni_B.Integrator6_3) +
         (sim_correnti_tensioni_B.Input03[4] *
          sim_correnti_tensioni_B.Monoflop1_3 *
          sim_correnti_tensioni_B.Integrator6_3) +
         (sim_correnti_tensioni_B.Input03[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_3);

      /* Programmable Value : 'sim_correnti_tensioni/Input04' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[6];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input04[0] = plxGetProgrammableValueData(6, 0);
      sim_correnti_tensioni_B.Input04[1] = plxGetProgrammableValueData(6, 1);
      sim_correnti_tensioni_B.Input04[2] = plxGetProgrammableValueData(6, 2);
      sim_correnti_tensioni_B.Input04[3] = plxGetProgrammableValueData(6, 3);
      sim_correnti_tensioni_B.Input04[4] = plxGetProgrammableValueData(6, 4);
      sim_correnti_tensioni_B.Input04[5] = plxGetProgrammableValueData(6, 5);
      sim_correnti_tensioni_B.Input04[6] = plxGetProgrammableValueData(6, 6);
      sim_correnti_tensioni_B.Input04[7] =
         plxGetProgrammableValueUpdateFlag(6);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder65/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_4 =
         sim_correnti_tensioni_B.Input10[4] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_4_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_4_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_4))
      {
         sim_correnti_tensioni_X.Integrator7_4_x =
            sim_correnti_tensioni_B.Input04[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_4_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_4_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_4_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_4_x =
            sim_correnti_tensioni_X.Integrator7_4_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_4_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_4 =
         sim_correnti_tensioni_X.Integrator7_4_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_4_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_4_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_4_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_4_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_4 =
         sim_correnti_tensioni_X.Integrator6_4_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_4_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_4_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_4_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_4_x =
            sim_correnti_tensioni_X.Integrator4_4_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_4_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_4 =
         sim_correnti_tensioni_X.Integrator4_4_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder65/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_4)
         sim_correnti_tensioni_B.Comparator1_4 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_4)
         sim_correnti_tensioni_B.Comparator1_4 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder65/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_4 &&
          (sim_correnti_tensioni_B.Comparator1_4))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[4] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[4] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_4 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[4] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_4 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder65/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder65/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder65/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder65/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder65/Product1'
       */
      sim_correnti_tensioni_B.Sum1_4 =
         (sim_correnti_tensioni_B.Input04[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_4) *
          sim_correnti_tensioni_B.Integrator6_4) +
         (sim_correnti_tensioni_B.Input04[4] *
          sim_correnti_tensioni_B.Monoflop1_4 *
          sim_correnti_tensioni_B.Integrator6_4) +
         (sim_correnti_tensioni_B.Input04[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_4);

      /* Programmable Value : 'sim_correnti_tensioni/Input05' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[7];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input05[0] = plxGetProgrammableValueData(7, 0);
      sim_correnti_tensioni_B.Input05[1] = plxGetProgrammableValueData(7, 1);
      sim_correnti_tensioni_B.Input05[2] = plxGetProgrammableValueData(7, 2);
      sim_correnti_tensioni_B.Input05[3] = plxGetProgrammableValueData(7, 3);
      sim_correnti_tensioni_B.Input05[4] = plxGetProgrammableValueData(7, 4);
      sim_correnti_tensioni_B.Input05[5] = plxGetProgrammableValueData(7, 5);
      sim_correnti_tensioni_B.Input05[6] = plxGetProgrammableValueData(7, 6);
      sim_correnti_tensioni_B.Input05[7] =
         plxGetProgrammableValueUpdateFlag(7);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder66/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_5 =
         sim_correnti_tensioni_B.Input10[5] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_5_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_5_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_5))
      {
         sim_correnti_tensioni_X.Integrator7_5_x =
            sim_correnti_tensioni_B.Input05[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_5_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_5_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_5_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_5_x =
            sim_correnti_tensioni_X.Integrator7_5_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_5_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_5 =
         sim_correnti_tensioni_X.Integrator7_5_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_5_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_5_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_5_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_5_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_5 =
         sim_correnti_tensioni_X.Integrator6_5_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_5_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_5_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_5_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_5_x =
            sim_correnti_tensioni_X.Integrator4_5_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_5_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_5 =
         sim_correnti_tensioni_X.Integrator4_5_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder66/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_5)
         sim_correnti_tensioni_B.Comparator1_5 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_5)
         sim_correnti_tensioni_B.Comparator1_5 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder66/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_5 &&
          (sim_correnti_tensioni_B.Comparator1_5))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[5] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[5] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_5 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[5] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_5 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder66/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder66/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder66/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder66/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder66/Product1'
       */
      sim_correnti_tensioni_B.Sum1_5 =
         (sim_correnti_tensioni_B.Input05[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_5) *
          sim_correnti_tensioni_B.Integrator6_5) +
         (sim_correnti_tensioni_B.Input05[4] *
          sim_correnti_tensioni_B.Monoflop1_5 *
          sim_correnti_tensioni_B.Integrator6_5) +
         (sim_correnti_tensioni_B.Input05[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_5);

      /* Programmable Value : 'sim_correnti_tensioni/Input06' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[8];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input06[0] = plxGetProgrammableValueData(8, 0);
      sim_correnti_tensioni_B.Input06[1] = plxGetProgrammableValueData(8, 1);
      sim_correnti_tensioni_B.Input06[2] = plxGetProgrammableValueData(8, 2);
      sim_correnti_tensioni_B.Input06[3] = plxGetProgrammableValueData(8, 3);
      sim_correnti_tensioni_B.Input06[4] = plxGetProgrammableValueData(8, 4);
      sim_correnti_tensioni_B.Input06[5] = plxGetProgrammableValueData(8, 5);
      sim_correnti_tensioni_B.Input06[6] = plxGetProgrammableValueData(8, 6);
      sim_correnti_tensioni_B.Input06[7] =
         plxGetProgrammableValueUpdateFlag(8);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder67/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_6 =
         sim_correnti_tensioni_B.Input10[6] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_6_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_6_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_6))
      {
         sim_correnti_tensioni_X.Integrator7_6_x =
            sim_correnti_tensioni_B.Input06[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_6_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_6_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_6_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_6_x =
            sim_correnti_tensioni_X.Integrator7_6_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_6_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_6 =
         sim_correnti_tensioni_X.Integrator7_6_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_6_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_6_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_6_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_6_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_6 =
         sim_correnti_tensioni_X.Integrator6_6_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_6_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_6_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_6_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_6_x =
            sim_correnti_tensioni_X.Integrator4_6_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_6_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_6 =
         sim_correnti_tensioni_X.Integrator4_6_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder67/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_6)
         sim_correnti_tensioni_B.Comparator1_6 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_6)
         sim_correnti_tensioni_B.Comparator1_6 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder67/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_6 &&
          (sim_correnti_tensioni_B.Comparator1_6))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[6] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[6] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_6 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[6] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_6 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder67/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder67/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder67/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder67/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder67/Product1'
       */
      sim_correnti_tensioni_B.Sum1_6 =
         (sim_correnti_tensioni_B.Input06[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_6) *
          sim_correnti_tensioni_B.Integrator6_6) +
         (sim_correnti_tensioni_B.Input06[4] *
          sim_correnti_tensioni_B.Monoflop1_6 *
          sim_correnti_tensioni_B.Integrator6_6) +
         (sim_correnti_tensioni_B.Input06[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_6);

      /* Programmable Value : 'sim_correnti_tensioni/Input07' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[9];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input07[0] = plxGetProgrammableValueData(9, 0);
      sim_correnti_tensioni_B.Input07[1] = plxGetProgrammableValueData(9, 1);
      sim_correnti_tensioni_B.Input07[2] = plxGetProgrammableValueData(9, 2);
      sim_correnti_tensioni_B.Input07[3] = plxGetProgrammableValueData(9, 3);
      sim_correnti_tensioni_B.Input07[4] = plxGetProgrammableValueData(9, 4);
      sim_correnti_tensioni_B.Input07[5] = plxGetProgrammableValueData(9, 5);
      sim_correnti_tensioni_B.Input07[6] = plxGetProgrammableValueData(9, 6);
      sim_correnti_tensioni_B.Input07[7] =
         plxGetProgrammableValueUpdateFlag(9);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder68/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_7 =
         sim_correnti_tensioni_B.Input10[7] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_7_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_7_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_7))
      {
         sim_correnti_tensioni_X.Integrator7_7_x =
            sim_correnti_tensioni_B.Input07[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_7_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_7_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_7_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_7_x =
            sim_correnti_tensioni_X.Integrator7_7_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_7_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_7 =
         sim_correnti_tensioni_X.Integrator7_7_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_7_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_7_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_7_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_7_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_7 =
         sim_correnti_tensioni_X.Integrator6_7_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_7_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_7_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_7_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_7_x =
            sim_correnti_tensioni_X.Integrator4_7_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_7_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_7 =
         sim_correnti_tensioni_X.Integrator4_7_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder68/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_7)
         sim_correnti_tensioni_B.Comparator1_7 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_7)
         sim_correnti_tensioni_B.Comparator1_7 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder68/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_7 &&
          (sim_correnti_tensioni_B.Comparator1_7))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[7] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[7] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_7 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[7] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_7 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder68/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder68/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder68/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder68/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder68/Product1'
       */
      sim_correnti_tensioni_B.Sum1_7 =
         (sim_correnti_tensioni_B.Input07[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_7) *
          sim_correnti_tensioni_B.Integrator6_7) +
         (sim_correnti_tensioni_B.Input07[4] *
          sim_correnti_tensioni_B.Monoflop1_7 *
          sim_correnti_tensioni_B.Integrator6_7) +
         (sim_correnti_tensioni_B.Input07[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_7);

      /* Programmable Value : 'sim_correnti_tensioni/Input08' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[10];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input08[0] = plxGetProgrammableValueData(10, 0);
      sim_correnti_tensioni_B.Input08[1] = plxGetProgrammableValueData(10, 1);
      sim_correnti_tensioni_B.Input08[2] = plxGetProgrammableValueData(10, 2);
      sim_correnti_tensioni_B.Input08[3] = plxGetProgrammableValueData(10, 3);
      sim_correnti_tensioni_B.Input08[4] = plxGetProgrammableValueData(10, 4);
      sim_correnti_tensioni_B.Input08[5] = plxGetProgrammableValueData(10, 5);
      sim_correnti_tensioni_B.Input08[6] = plxGetProgrammableValueData(10, 6);
      sim_correnti_tensioni_B.Input08[7] = plxGetProgrammableValueUpdateFlag(
                                                                             10);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder69/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_8 =
         sim_correnti_tensioni_B.Input10[8] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_8_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_8_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_8))
      {
         sim_correnti_tensioni_X.Integrator7_8_x =
            sim_correnti_tensioni_B.Input08[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_8_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_8_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_8_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_8_x =
            sim_correnti_tensioni_X.Integrator7_8_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_8_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_8 =
         sim_correnti_tensioni_X.Integrator7_8_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_8_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_8_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_8_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_8_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_8 =
         sim_correnti_tensioni_X.Integrator6_8_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_8_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_8_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_8_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_8_x =
            sim_correnti_tensioni_X.Integrator4_8_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_8_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_8 =
         sim_correnti_tensioni_X.Integrator4_8_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder69/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_8)
         sim_correnti_tensioni_B.Comparator1_8 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_8)
         sim_correnti_tensioni_B.Comparator1_8 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder69/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_8 &&
          (sim_correnti_tensioni_B.Comparator1_8))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[8] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[8] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_8 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[8] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_8 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder69/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder69/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder69/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder69/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder69/Product1'
       */
      sim_correnti_tensioni_B.Sum1_8 =
         (sim_correnti_tensioni_B.Input08[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_8) *
          sim_correnti_tensioni_B.Integrator6_8) +
         (sim_correnti_tensioni_B.Input08[4] *
          sim_correnti_tensioni_B.Monoflop1_8 *
          sim_correnti_tensioni_B.Integrator6_8) +
         (sim_correnti_tensioni_B.Input08[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_8);

      /* Programmable Value : 'sim_correnti_tensioni/Input09' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[11];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input09[0] = plxGetProgrammableValueData(11, 0);
      sim_correnti_tensioni_B.Input09[1] = plxGetProgrammableValueData(11, 1);
      sim_correnti_tensioni_B.Input09[2] = plxGetProgrammableValueData(11, 2);
      sim_correnti_tensioni_B.Input09[3] = plxGetProgrammableValueData(11, 3);
      sim_correnti_tensioni_B.Input09[4] = plxGetProgrammableValueData(11, 4);
      sim_correnti_tensioni_B.Input09[5] = plxGetProgrammableValueData(11, 5);
      sim_correnti_tensioni_B.Input09[6] = plxGetProgrammableValueData(11, 6);
      sim_correnti_tensioni_B.Input09[7] = plxGetProgrammableValueUpdateFlag(
                                                                             11);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder70/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_9 =
         sim_correnti_tensioni_B.Input10[9] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_9_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_9_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_9))
      {
         sim_correnti_tensioni_X.Integrator7_9_x =
            sim_correnti_tensioni_B.Input09[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_9_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_9_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_9_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_9_x =
            sim_correnti_tensioni_X.Integrator7_9_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator7_9_x/
                                                                  span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_9 =
         sim_correnti_tensioni_X.Integrator7_9_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_9_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_9_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_9_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_9_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_9 =
         sim_correnti_tensioni_X.Integrator6_9_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_9_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_9_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_9_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_9_x =
            sim_correnti_tensioni_X.Integrator4_9_x - span*floorf(
                                                                  sim_correnti_tensioni_X.Integrator4_9_x/
                                                                  span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_9 =
         sim_correnti_tensioni_X.Integrator4_9_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder70/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_9)
         sim_correnti_tensioni_B.Comparator1_9 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_9)
         sim_correnti_tensioni_B.Comparator1_9 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder70/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_9 &&
          (sim_correnti_tensioni_B.Comparator1_9))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[9] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[9] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_9 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[9] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_9 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder70/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder70/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder70/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder70/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder70/Product1'
       */
      sim_correnti_tensioni_B.Sum1_9 =
         (sim_correnti_tensioni_B.Input09[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_9) *
          sim_correnti_tensioni_B.Integrator6_9) +
         (sim_correnti_tensioni_B.Input09[4] *
          sim_correnti_tensioni_B.Monoflop1_9 *
          sim_correnti_tensioni_B.Integrator6_9) +
         (sim_correnti_tensioni_B.Input09[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_9);

      /* Programmable Value : 'sim_correnti_tensioni/Input0A' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[12];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0A[0] = plxGetProgrammableValueData(12, 0);
      sim_correnti_tensioni_B.Input0A[1] = plxGetProgrammableValueData(12, 1);
      sim_correnti_tensioni_B.Input0A[2] = plxGetProgrammableValueData(12, 2);
      sim_correnti_tensioni_B.Input0A[3] = plxGetProgrammableValueData(12, 3);
      sim_correnti_tensioni_B.Input0A[4] = plxGetProgrammableValueData(12, 4);
      sim_correnti_tensioni_B.Input0A[5] = plxGetProgrammableValueData(12, 5);
      sim_correnti_tensioni_B.Input0A[6] = plxGetProgrammableValueData(12, 6);
      sim_correnti_tensioni_B.Input0A[7] = plxGetProgrammableValueUpdateFlag(
                                                                             12);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder71/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_10 =
         sim_correnti_tensioni_B.Input10[10] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_10_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_10_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_10))
      {
         sim_correnti_tensioni_X.Integrator7_10_x =
            sim_correnti_tensioni_B.Input0A[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_10_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_10_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_10_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_10_x =
            sim_correnti_tensioni_X.Integrator7_10_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_10_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_10 =
         sim_correnti_tensioni_X.Integrator7_10_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_10_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_10_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_10_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_10_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_10 =
         sim_correnti_tensioni_X.Integrator6_10_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_10_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_10_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_10_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_10_x =
            sim_correnti_tensioni_X.Integrator4_10_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_10_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_10 =
         sim_correnti_tensioni_X.Integrator4_10_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder71/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_10)
         sim_correnti_tensioni_B.Comparator1_10 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_10)
         sim_correnti_tensioni_B.Comparator1_10 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder71/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_10 &&
          (sim_correnti_tensioni_B.Comparator1_10))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[10] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[10] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_10 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[10] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_10 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder71/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder71/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder71/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder71/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder71/Product1'
       */
      sim_correnti_tensioni_B.Sum1_10 =
         (sim_correnti_tensioni_B.Input0A[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_10) *
          sim_correnti_tensioni_B.Integrator6_10) +
         (sim_correnti_tensioni_B.Input0A[4] *
          sim_correnti_tensioni_B.Monoflop1_10 *
          sim_correnti_tensioni_B.Integrator6_10) +
         (sim_correnti_tensioni_B.Input0A[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_10);

      /* Programmable Value : 'sim_correnti_tensioni/Input0B' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[13];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0B[0] = plxGetProgrammableValueData(13, 0);
      sim_correnti_tensioni_B.Input0B[1] = plxGetProgrammableValueData(13, 1);
      sim_correnti_tensioni_B.Input0B[2] = plxGetProgrammableValueData(13, 2);
      sim_correnti_tensioni_B.Input0B[3] = plxGetProgrammableValueData(13, 3);
      sim_correnti_tensioni_B.Input0B[4] = plxGetProgrammableValueData(13, 4);
      sim_correnti_tensioni_B.Input0B[5] = plxGetProgrammableValueData(13, 5);
      sim_correnti_tensioni_B.Input0B[6] = plxGetProgrammableValueData(13, 6);
      sim_correnti_tensioni_B.Input0B[7] = plxGetProgrammableValueUpdateFlag(
                                                                             13);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder72/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_11 =
         sim_correnti_tensioni_B.Input10[11] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_11_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_11_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_11))
      {
         sim_correnti_tensioni_X.Integrator7_11_x =
            sim_correnti_tensioni_B.Input0B[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_11_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_11_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_11_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_11_x =
            sim_correnti_tensioni_X.Integrator7_11_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_11_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_11 =
         sim_correnti_tensioni_X.Integrator7_11_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_11_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_11_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_11_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_11_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_11 =
         sim_correnti_tensioni_X.Integrator6_11_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_11_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_11_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_11_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_11_x =
            sim_correnti_tensioni_X.Integrator4_11_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_11_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_11 =
         sim_correnti_tensioni_X.Integrator4_11_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder72/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_11)
         sim_correnti_tensioni_B.Comparator1_11 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_11)
         sim_correnti_tensioni_B.Comparator1_11 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder72/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_11 &&
          (sim_correnti_tensioni_B.Comparator1_11))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[11] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[11] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_11 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[11] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_11 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder72/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder72/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder72/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder72/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder72/Product1'
       */
      sim_correnti_tensioni_B.Sum1_11 =
         (sim_correnti_tensioni_B.Input0B[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_11) *
          sim_correnti_tensioni_B.Integrator6_11) +
         (sim_correnti_tensioni_B.Input0B[4] *
          sim_correnti_tensioni_B.Monoflop1_11 *
          sim_correnti_tensioni_B.Integrator6_11) +
         (sim_correnti_tensioni_B.Input0B[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_11);

      /* Programmable Value : 'sim_correnti_tensioni/Input0C' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[14];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0C[0] = plxGetProgrammableValueData(14, 0);
      sim_correnti_tensioni_B.Input0C[1] = plxGetProgrammableValueData(14, 1);
      sim_correnti_tensioni_B.Input0C[2] = plxGetProgrammableValueData(14, 2);
      sim_correnti_tensioni_B.Input0C[3] = plxGetProgrammableValueData(14, 3);
      sim_correnti_tensioni_B.Input0C[4] = plxGetProgrammableValueData(14, 4);
      sim_correnti_tensioni_B.Input0C[5] = plxGetProgrammableValueData(14, 5);
      sim_correnti_tensioni_B.Input0C[6] = plxGetProgrammableValueData(14, 6);
      sim_correnti_tensioni_B.Input0C[7] = plxGetProgrammableValueUpdateFlag(
                                                                             14);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder73/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_12 =
         sim_correnti_tensioni_B.Input10[12] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_12_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_12_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_12))
      {
         sim_correnti_tensioni_X.Integrator7_12_x =
            sim_correnti_tensioni_B.Input0C[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_12_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_12_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_12_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_12_x =
            sim_correnti_tensioni_X.Integrator7_12_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_12_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_12 =
         sim_correnti_tensioni_X.Integrator7_12_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_12_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_12_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_12_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_12_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_12 =
         sim_correnti_tensioni_X.Integrator6_12_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_12_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_12_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_12_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_12_x =
            sim_correnti_tensioni_X.Integrator4_12_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_12_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_12 =
         sim_correnti_tensioni_X.Integrator4_12_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder73/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_12)
         sim_correnti_tensioni_B.Comparator1_12 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_12)
         sim_correnti_tensioni_B.Comparator1_12 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder73/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_12 &&
          (sim_correnti_tensioni_B.Comparator1_12))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[12] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[12] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_12 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[12] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_12 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder73/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder73/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder73/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder73/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder73/Product1'
       */
      sim_correnti_tensioni_B.Sum1_12 =
         (sim_correnti_tensioni_B.Input0C[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_12) *
          sim_correnti_tensioni_B.Integrator6_12) +
         (sim_correnti_tensioni_B.Input0C[4] *
          sim_correnti_tensioni_B.Monoflop1_12 *
          sim_correnti_tensioni_B.Integrator6_12) +
         (sim_correnti_tensioni_B.Input0C[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_12);

      /* Programmable Value : 'sim_correnti_tensioni/Input0D' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[15];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0D[0] = plxGetProgrammableValueData(15, 0);
      sim_correnti_tensioni_B.Input0D[1] = plxGetProgrammableValueData(15, 1);
      sim_correnti_tensioni_B.Input0D[2] = plxGetProgrammableValueData(15, 2);
      sim_correnti_tensioni_B.Input0D[3] = plxGetProgrammableValueData(15, 3);
      sim_correnti_tensioni_B.Input0D[4] = plxGetProgrammableValueData(15, 4);
      sim_correnti_tensioni_B.Input0D[5] = plxGetProgrammableValueData(15, 5);
      sim_correnti_tensioni_B.Input0D[6] = plxGetProgrammableValueData(15, 6);
      sim_correnti_tensioni_B.Input0D[7] = plxGetProgrammableValueUpdateFlag(
                                                                             15);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder74/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_13 =
         sim_correnti_tensioni_B.Input10[13] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_13_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_13_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_13))
      {
         sim_correnti_tensioni_X.Integrator7_13_x =
            sim_correnti_tensioni_B.Input0D[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_13_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_13_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_13_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_13_x =
            sim_correnti_tensioni_X.Integrator7_13_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_13_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_13 =
         sim_correnti_tensioni_X.Integrator7_13_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_13_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_13_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_13_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_13_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_13 =
         sim_correnti_tensioni_X.Integrator6_13_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_13_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_13_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_13_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_13_x =
            sim_correnti_tensioni_X.Integrator4_13_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_13_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_13 =
         sim_correnti_tensioni_X.Integrator4_13_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder74/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_13)
         sim_correnti_tensioni_B.Comparator1_13 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_13)
         sim_correnti_tensioni_B.Comparator1_13 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder74/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_13 &&
          (sim_correnti_tensioni_B.Comparator1_13))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[13] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[13] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_13 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[13] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_13 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder74/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder74/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder74/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder74/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder74/Product1'
       */
      sim_correnti_tensioni_B.Sum1_13 =
         (sim_correnti_tensioni_B.Input0D[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_13) *
          sim_correnti_tensioni_B.Integrator6_13) +
         (sim_correnti_tensioni_B.Input0D[4] *
          sim_correnti_tensioni_B.Monoflop1_13 *
          sim_correnti_tensioni_B.Integrator6_13) +
         (sim_correnti_tensioni_B.Input0D[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_13);

      /* Programmable Value : 'sim_correnti_tensioni/Input0E' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[16];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0E[0] = plxGetProgrammableValueData(16, 0);
      sim_correnti_tensioni_B.Input0E[1] = plxGetProgrammableValueData(16, 1);
      sim_correnti_tensioni_B.Input0E[2] = plxGetProgrammableValueData(16, 2);
      sim_correnti_tensioni_B.Input0E[3] = plxGetProgrammableValueData(16, 3);
      sim_correnti_tensioni_B.Input0E[4] = plxGetProgrammableValueData(16, 4);
      sim_correnti_tensioni_B.Input0E[5] = plxGetProgrammableValueData(16, 5);
      sim_correnti_tensioni_B.Input0E[6] = plxGetProgrammableValueData(16, 6);
      sim_correnti_tensioni_B.Input0E[7] = plxGetProgrammableValueUpdateFlag(
                                                                             16);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder75/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_14 =
         sim_correnti_tensioni_B.Input10[14] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_14_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_14_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_14))
      {
         sim_correnti_tensioni_X.Integrator7_14_x =
            sim_correnti_tensioni_B.Input0E[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_14_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_14_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_14_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_14_x =
            sim_correnti_tensioni_X.Integrator7_14_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_14_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_14 =
         sim_correnti_tensioni_X.Integrator7_14_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_14_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_14_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_14_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_14_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_14 =
         sim_correnti_tensioni_X.Integrator6_14_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_14_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_14_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_14_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_14_x =
            sim_correnti_tensioni_X.Integrator4_14_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_14_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_14 =
         sim_correnti_tensioni_X.Integrator4_14_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder75/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_14)
         sim_correnti_tensioni_B.Comparator1_14 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_14)
         sim_correnti_tensioni_B.Comparator1_14 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder75/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_14 &&
          (sim_correnti_tensioni_B.Comparator1_14))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[14] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[14] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_14 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[14] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_14 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder75/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder75/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder75/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder75/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder75/Product1'
       */
      sim_correnti_tensioni_B.Sum1_14 =
         (sim_correnti_tensioni_B.Input0E[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_14) *
          sim_correnti_tensioni_B.Integrator6_14) +
         (sim_correnti_tensioni_B.Input0E[4] *
          sim_correnti_tensioni_B.Monoflop1_14 *
          sim_correnti_tensioni_B.Integrator6_14) +
         (sim_correnti_tensioni_B.Input0E[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_14);

      /* Programmable Value : 'sim_correnti_tensioni/Input0F' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[17];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      sim_correnti_tensioni_B.Input0F[0] = plxGetProgrammableValueData(17, 0);
      sim_correnti_tensioni_B.Input0F[1] = plxGetProgrammableValueData(17, 1);
      sim_correnti_tensioni_B.Input0F[2] = plxGetProgrammableValueData(17, 2);
      sim_correnti_tensioni_B.Input0F[3] = plxGetProgrammableValueData(17, 3);
      sim_correnti_tensioni_B.Input0F[4] = plxGetProgrammableValueData(17, 4);
      sim_correnti_tensioni_B.Input0F[5] = plxGetProgrammableValueData(17, 5);
      sim_correnti_tensioni_B.Input0F[6] = plxGetProgrammableValueData(17, 6);
      sim_correnti_tensioni_B.Input0F[7] = plxGetProgrammableValueUpdateFlag(
                                                                             17);

      /* Compare to Constant : 'sim_correnti_tensioni/Signal Builder76/Compare to\nConstant' */
      sim_correnti_tensioni_B.CompareToConstant_15 =
         sim_correnti_tensioni_B.Input10[15] != 1.f;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator7' */
      if (sim_correnti_tensioni_X.Integrator7_15_i1_first ||
          (sim_correnti_tensioni_X.Integrator7_15_i2_prevReset &&
           !sim_correnti_tensioni_B.CompareToConstant_15))
      {
         sim_correnti_tensioni_X.Integrator7_15_x =
            sim_correnti_tensioni_B.Input0F[2];
      }
      if (sim_correnti_tensioni_X.Integrator7_15_x > 6.28318531f ||
          sim_correnti_tensioni_X.Integrator7_15_x < 0.f)
      {
         float span = 6.28318531f - (0.f);
         sim_correnti_tensioni_X.Integrator7_15_x -= 0.f;
         sim_correnti_tensioni_X.Integrator7_15_x =
            sim_correnti_tensioni_X.Integrator7_15_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator7_15_x/
                                                                   span) +
            (0.f);
      }
      sim_correnti_tensioni_B.Integrator7_15 =
         sim_correnti_tensioni_X.Integrator7_15_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator6' */
      if (sim_correnti_tensioni_X.Integrator6_15_x > 1.f)
      {
         sim_correnti_tensioni_X.Integrator6_15_x = 1.f;
      }
      else if (sim_correnti_tensioni_X.Integrator6_15_x < 0.f)
      {
         sim_correnti_tensioni_X.Integrator6_15_x = 0.f;
      }
      sim_correnti_tensioni_B.Integrator6_15 =
         sim_correnti_tensioni_X.Integrator6_15_x;

      /* Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator4' */
      if (sim_correnti_tensioni_X.Integrator4_15_x > 0.5f ||
          sim_correnti_tensioni_X.Integrator4_15_x < -0.5f)
      {
         float span = 0.5f - (-0.5f);
         sim_correnti_tensioni_X.Integrator4_15_x -= -0.5f;
         sim_correnti_tensioni_X.Integrator4_15_x =
            sim_correnti_tensioni_X.Integrator4_15_x - span*floorf(
                                                                   sim_correnti_tensioni_X.Integrator4_15_x/
                                                                   span) +
            (-0.5f);
      }
      sim_correnti_tensioni_B.Integrator4_15 =
         sim_correnti_tensioni_X.Integrator4_15_x;

      /* Comparator : 'sim_correnti_tensioni/Signal Builder76/Comparator1' */
      if (0.f > sim_correnti_tensioni_B.Integrator4_15)
         sim_correnti_tensioni_B.Comparator1_15 = 1;
      else if (0.f < sim_correnti_tensioni_B.Integrator4_15)
         sim_correnti_tensioni_B.Comparator1_15 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Signal Builder76/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_15 &&
          (sim_correnti_tensioni_B.Comparator1_15))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[15] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[15] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_15 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[15] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_15 = 0;
      }

      /* Sum : 'sim_correnti_tensioni/Signal Builder76/Sum1'
       * incorporates
       *  Product : 'sim_correnti_tensioni/Signal Builder76/Product'
       *  Trigonometric Function : 'sim_correnti_tensioni/Signal Builder76/Trigonometric\nFunction'
       *  Product : 'sim_correnti_tensioni/Signal Builder76/Product13'
       *  Product : 'sim_correnti_tensioni/Signal Builder76/Product1'
       */
      sim_correnti_tensioni_B.Sum1_15 =
         (sim_correnti_tensioni_B.Input0F[0] *
          sinf(sim_correnti_tensioni_B.Integrator7_15) *
          sim_correnti_tensioni_B.Integrator6_15) +
         (sim_correnti_tensioni_B.Input0F[4] *
          sim_correnti_tensioni_B.Monoflop1_15 *
          sim_correnti_tensioni_B.Integrator6_15) +
         (sim_correnti_tensioni_B.Input0F[6] *
          sim_correnti_tensioni_B.sim_correnti_tensioni *
          sim_correnti_tensioni_B.Integrator6_15);

      /* Multiport Signal Switch : 'sim_correnti_tensioni/Multiport Signal Switch'
       * incorporates
       *  Programmable Value : 'sim_correnti_tensioni/Input11'
       */
      sim_correnti_tensioni_B.MultiportSignalSwitch_bool = false;
      sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t =
         (int32_t)(plxGetProgrammableValueData(4, 0));
      switch (sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t)
      {
      default:
         sim_correnti_tensioni_B.MultiportSignalSwitch_bool = true;
         sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t = 1;

      // Fall through, no break;
      case 1:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1;
         break;

      case 2:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_1;
         break;

      case 3:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_2;
         break;

      case 4:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_3;
         break;

      case 5:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_4;
         break;

      case 6:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_5;
         break;

      case 7:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_6;
         break;

      case 8:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_7;
         break;

      case 9:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_8;
         break;

      case 10:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_9;
         break;

      case 11:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_10;
         break;

      case 12:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_11;
         break;

      case 13:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_12;
         break;

      case 14:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_13;
         break;

      case 15:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_14;
         break;

      case 16:
         sim_correnti_tensioni_B.MultiportSignalSwitch_float =
            sim_correnti_tensioni_B.Sum1_15;
         break;
      }

      /* Programmable Value : 'sim_correnti_tensioni/Input14' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[18];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      /* Programmable Value : 'sim_correnti_tensioni/Input12' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[19];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      /* Multiport Signal Switch : 'sim_correnti_tensioni/Multiport Signal Switch2'
       * incorporates
       *  Programmable Value : 'sim_correnti_tensioni/Input12'
       */
      sim_correnti_tensioni_B.MultiportSignalSwitch2_bool = false;
      sim_correnti_tensioni_B.MultiportSignalSwitch2_int32_t =
         (int32_t)(plxGetProgrammableValueData(19, 0));
      switch (sim_correnti_tensioni_B.MultiportSignalSwitch2_int32_t)
      {
      default:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_bool = true;
         sim_correnti_tensioni_B.MultiportSignalSwitch2_int32_t = 1;

      // Fall through, no break;
      case 1:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1;
         break;

      case 2:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_1;
         break;

      case 3:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_2;
         break;

      case 4:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_3;
         break;

      case 5:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_4;
         break;

      case 6:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_5;
         break;

      case 7:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_6;
         break;

      case 8:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_7;
         break;

      case 9:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_8;
         break;

      case 10:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_9;
         break;

      case 11:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_10;
         break;

      case 12:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_11;
         break;

      case 13:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_12;
         break;

      case 14:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_13;
         break;

      case 15:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_14;
         break;

      case 16:
         sim_correnti_tensioni_B.MultiportSignalSwitch2_float =
            sim_correnti_tensioni_B.Sum1_15;
         break;
      }

      /* Programmable Value : 'sim_correnti_tensioni/Input13' */
      {
         struct PlxProgrammableValueRegistry* regEntry =
            &plxProgrammableValueRegistry[20];
         int currReadBufferIdx = regEntry->readBufferIdx;
         int newReadBufferIdx = !currReadBufferIdx;
         regEntry->bufferFull[currReadBufferIdx] = 0;
         if (regEntry->bufferFull[newReadBufferIdx])
         {
            regEntry->currentReadBuffer=
               &regEntry->dataBuffer[newReadBufferIdx*regEntry->width];
            regEntry->readBufferIdx=newReadBufferIdx;
         }
      }
      /* Multiport Signal Switch : 'sim_correnti_tensioni/Multiport Signal Switch3'
       * incorporates
       *  Programmable Value : 'sim_correnti_tensioni/Input13'
       */
      sim_correnti_tensioni_B.MultiportSignalSwitch3_bool = false;
      sim_correnti_tensioni_B.MultiportSignalSwitch3_int32_t =
         (int32_t)(plxGetProgrammableValueData(20, 0));
      switch (sim_correnti_tensioni_B.MultiportSignalSwitch3_int32_t)
      {
      default:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_bool = true;
         sim_correnti_tensioni_B.MultiportSignalSwitch3_int32_t = 1;

      // Fall through, no break;
      case 1:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1;
         break;

      case 2:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_1;
         break;

      case 3:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_2;
         break;

      case 4:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_3;
         break;

      case 5:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_4;
         break;

      case 6:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_5;
         break;

      case 7:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_6;
         break;

      case 8:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_7;
         break;

      case 9:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_8;
         break;

      case 10:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_9;
         break;

      case 11:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_10;
         break;

      case 12:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_11;
         break;

      case 13:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_12;
         break;

      case 14:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_13;
         break;

      case 15:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_14;
         break;

      case 16:
         sim_correnti_tensioni_B.MultiportSignalSwitch3_float =
            sim_correnti_tensioni_B.Sum1_15;
         break;
      }

      /* Multiport Signal Switch : 'sim_correnti_tensioni/Multiport Signal Switch1'
       * incorporates
       *  Programmable Value : 'sim_correnti_tensioni/Input14'
       */
      sim_correnti_tensioni_B.MultiportSignalSwitch1_bool = false;
      sim_correnti_tensioni_B.MultiportSignalSwitch1_int32_t =
         (int32_t)(plxGetProgrammableValueData(18, 0));
      switch (sim_correnti_tensioni_B.MultiportSignalSwitch1_int32_t)
      {
      default:
         sim_correnti_tensioni_B.MultiportSignalSwitch1_bool = true;
         sim_correnti_tensioni_B.MultiportSignalSwitch1_int32_t = 1;

      // Fall through, no break;
      case 1:
         sim_correnti_tensioni_B.MultiportSignalSwitch1_float =
            sim_correnti_tensioni_B.MultiportSignalSwitch_float;
         break;

      case 2:
         sim_correnti_tensioni_B.MultiportSignalSwitch1_float =
            sim_correnti_tensioni_B.MultiportSignalSwitch2_float;
         break;

      case 3:
         sim_correnti_tensioni_B.MultiportSignalSwitch1_float =
            sim_correnti_tensioni_B.MultiportSignalSwitch3_float;
         break;
      }

      /* Comparator : 'sim_correnti_tensioni/Comparator1' */
      if (sim_correnti_tensioni_B.MultiportSignalSwitch1_float > 0.f)
         sim_correnti_tensioni_B.Comparator1_16 = 1;
      else if (sim_correnti_tensioni_B.MultiportSignalSwitch1_float < 0.f)
         sim_correnti_tensioni_B.Comparator1_16 = 0;
      /* Monoflop : 'sim_correnti_tensioni/Monoflop1'
       * incorporates
       *  Constant : 'sim_correnti_tensioni/Constant6'
       */
      if (!sim_correnti_tensioni_X.Monoflop1_16 &&
          (sim_correnti_tensioni_B.Comparator1_16))
      {
         float ticks = (0.0001f)/1e-05f;
         if (ticks < 0)
         {
            ticks = 0;
         }
         else if (ticks > UINT32_MAX)
         {
            ticks = UINT32_MAX;
         }
         sim_correnti_tensioni_D_uint32_t[16] = floorf(ticks);
         if (sim_correnti_tensioni_D_uint32_t[16] > 0)
         {
            sim_correnti_tensioni_B.Monoflop1_16 = 1;
         }
      }
      else if (sim_correnti_tensioni_D_uint32_t[16] == 0)
      {
         sim_correnti_tensioni_B.Monoflop1_16 = 0;
      }
      /* Data Capture : 'sim_correnti_tensioni/Capture1' */
      {
         double data[] = {
            sim_correnti_tensioni_B.MultiportSignalSwitch_float
         };
         plxUpdateDataCapture(0, sim_correnti_tensioni_B.Monoflop1_16, data);
      }

      /* Analog Out : 'sim_correnti_tensioni/Analog Out5' */
      setAnalogOut(1, sim_correnti_tensioni_B.Sum1_1);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out6' */
      setAnalogOut(2, sim_correnti_tensioni_B.Sum1_2);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out7' */
      setAnalogOut(3, sim_correnti_tensioni_B.Sum1_3);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out8' */
      setAnalogOut(4, sim_correnti_tensioni_B.Sum1_4);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out9' */
      setAnalogOut(5, sim_correnti_tensioni_B.Sum1_5);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out10' */
      setAnalogOut(6, sim_correnti_tensioni_B.Sum1_6);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out11' */
      setAnalogOut(7, sim_correnti_tensioni_B.Sum1_7);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out13' */
      setAnalogOut(8, sim_correnti_tensioni_B.Sum1_8);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out14' */
      setAnalogOut(9, sim_correnti_tensioni_B.Sum1_9);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out15' */
      setAnalogOut(10, sim_correnti_tensioni_B.Sum1_10);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out16' */
      setAnalogOut(11, sim_correnti_tensioni_B.Sum1_11);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out17' */
      setAnalogOut(12, sim_correnti_tensioni_B.Sum1_12);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out18' */
      setAnalogOut(13, sim_correnti_tensioni_B.Sum1_13);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out19' */
      setAnalogOut(14, sim_correnti_tensioni_B.Sum1_14);

      /* Analog Out : 'sim_correnti_tensioni/Analog Out20' */
      setAnalogOut(15, sim_correnti_tensioni_B.Sum1_15);

      /* Data Capture : 'sim_correnti_tensioni/Capture2' */
      {
         double data[] = {
            sim_correnti_tensioni_B.MultiportSignalSwitch2_float
         };
         plxUpdateDataCapture(1, sim_correnti_tensioni_B.Monoflop1_16, data);
      }

      /* Data Capture : 'sim_correnti_tensioni/Capture3' */
      {
         double data[] = {
            sim_correnti_tensioni_B.MultiportSignalSwitch3_float
         };
         plxUpdateDataCapture(2, sim_correnti_tensioni_B.Monoflop1_16, data);
      }
      /* Product : 'sim_correnti_tensioni/Signal Builder62/Product19' */
      sim_correnti_tensioni_B.Product19 = sim_correnti_tensioni_B.Input10[0] *
                                          sim_correnti_tensioni_B.Input00[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder61/Product19' */
      sim_correnti_tensioni_B.Product19_1 =
         sim_correnti_tensioni_B.Input10[1] *
         sim_correnti_tensioni_B.Input01[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder63/Product19' */
      sim_correnti_tensioni_B.Product19_2 =
         sim_correnti_tensioni_B.Input10[2] *
         sim_correnti_tensioni_B.Input02[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder64/Product19' */
      sim_correnti_tensioni_B.Product19_3 =
         sim_correnti_tensioni_B.Input10[3] *
         sim_correnti_tensioni_B.Input03[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder65/Product19' */
      sim_correnti_tensioni_B.Product19_4 =
         sim_correnti_tensioni_B.Input10[4] *
         sim_correnti_tensioni_B.Input04[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder66/Product19' */
      sim_correnti_tensioni_B.Product19_5 =
         sim_correnti_tensioni_B.Input10[5] *
         sim_correnti_tensioni_B.Input05[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder67/Product19' */
      sim_correnti_tensioni_B.Product19_6 =
         sim_correnti_tensioni_B.Input10[6] *
         sim_correnti_tensioni_B.Input06[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder68/Product19' */
      sim_correnti_tensioni_B.Product19_7 =
         sim_correnti_tensioni_B.Input10[7] *
         sim_correnti_tensioni_B.Input07[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder69/Product19' */
      sim_correnti_tensioni_B.Product19_8 =
         sim_correnti_tensioni_B.Input10[8] *
         sim_correnti_tensioni_B.Input08[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder70/Product19' */
      sim_correnti_tensioni_B.Product19_9 =
         sim_correnti_tensioni_B.Input10[9] *
         sim_correnti_tensioni_B.Input09[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder71/Product19' */
      sim_correnti_tensioni_B.Product19_10 =
         sim_correnti_tensioni_B.Input10[10] *
         sim_correnti_tensioni_B.Input0A[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder72/Product19' */
      sim_correnti_tensioni_B.Product19_11 =
         sim_correnti_tensioni_B.Input10[11] *
         sim_correnti_tensioni_B.Input0B[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder73/Product19' */
      sim_correnti_tensioni_B.Product19_12 =
         sim_correnti_tensioni_B.Input10[12] *
         sim_correnti_tensioni_B.Input0C[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder74/Product19' */
      sim_correnti_tensioni_B.Product19_13 =
         sim_correnti_tensioni_B.Input10[13] *
         sim_correnti_tensioni_B.Input0D[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder75/Product19' */
      sim_correnti_tensioni_B.Product19_14 =
         sim_correnti_tensioni_B.Input10[14] *
         sim_correnti_tensioni_B.Input0E[3];

      /* Product : 'sim_correnti_tensioni/Signal Builder76/Product19' */
      sim_correnti_tensioni_B.Product19_15 =
         sim_correnti_tensioni_B.Input10[15] *
         sim_correnti_tensioni_B.Input0F[3];
      if (sim_correnti_tensioni_subTaskHit[0])
      {

         /* Task transfer to '[0.0001, 0]' (Zero-Order Hold) */
         sim_correnti_tensioni_B.sim_correnti_tensioni_i1 = 2.0001f;
      }

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
      sim_correnti_tensioni_ExtModeBuffer[0] =
         sim_correnti_tensioni_B.CompareToConstant;
      sim_correnti_tensioni_ExtModeBuffer[1] =
         sim_correnti_tensioni_B.CompareToConstant_1;
      sim_correnti_tensioni_ExtModeBuffer[2] =
         sim_correnti_tensioni_B.CompareToConstant_2;
#endif /* defined(EXTERNAL_MODE) */

      if (sim_correnti_tensioni_errorStatus)
      {
         return;
      }

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder62/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[0] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[0] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1 = sim_correnti_tensioni_B.Comparator1;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_1_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_1_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_1);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder61/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[1] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[1] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_1 =
         sim_correnti_tensioni_B.Comparator1_1;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_2_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_2_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_2);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder63/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[2] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[2] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_2 =
         sim_correnti_tensioni_B.Comparator1_2;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_3_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_3_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_3);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder64/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[3] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[3] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_3 =
         sim_correnti_tensioni_B.Comparator1_3;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_4_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_4_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_4);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder65/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[4] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[4] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_4 =
         sim_correnti_tensioni_B.Comparator1_4;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_5_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_5_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_5);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder66/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[5] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[5] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_5 =
         sim_correnti_tensioni_B.Comparator1_5;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_6_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_6_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_6);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder67/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[6] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[6] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_6 =
         sim_correnti_tensioni_B.Comparator1_6;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_7_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_7_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_7);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder68/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[7] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[7] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_7 =
         sim_correnti_tensioni_B.Comparator1_7;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_8_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_8_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_8);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder69/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[8] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[8] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_8 =
         sim_correnti_tensioni_B.Comparator1_8;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_9_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_9_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_9);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder70/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[9] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[9] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_9 =
         sim_correnti_tensioni_B.Comparator1_9;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_10_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_10_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_10);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder71/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[10] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[10] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_10 =
         sim_correnti_tensioni_B.Comparator1_10;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_11_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_11_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_11);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder72/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[11] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[11] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_11 =
         sim_correnti_tensioni_B.Comparator1_11;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_12_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_12_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_12);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder73/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[12] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[12] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_12 =
         sim_correnti_tensioni_B.Comparator1_12;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_13_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_13_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_13);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder74/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[13] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[13] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_13 =
         sim_correnti_tensioni_B.Comparator1_13;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_14_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_14_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_14);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder75/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[14] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[14] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_14 =
         sim_correnti_tensioni_B.Comparator1_14;

      /* Update for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator7' */
      sim_correnti_tensioni_X.Integrator7_15_i1_first = 0;
      sim_correnti_tensioni_X.Integrator7_15_i2_prevReset =
         !!(sim_correnti_tensioni_B.CompareToConstant_15);

      /* Update for Monoflop : 'sim_correnti_tensioni/Signal Builder76/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[15] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[15] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_15 =
         sim_correnti_tensioni_B.Comparator1_15;

      /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
      if (sim_correnti_tensioni_D_uint32_t[16] > 0)
      {
         sim_correnti_tensioni_D_uint32_t[16] -= 1;
      }
      sim_correnti_tensioni_X.Monoflop1_16 =
         sim_correnti_tensioni_B.Comparator1_16;
      /* Increment sub-task tick counters */
      {
         size_t i;
         for (i = 0; i < 1; ++i)
         {
            sim_correnti_tensioni_subTaskTick[i]++;
            if (sim_correnti_tensioni_subTaskTick[i] >=
                sim_correnti_tensioni_subTaskPeriod[i])
            {
               sim_correnti_tensioni_subTaskTick[i] = 0;
            }
         }
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator7' */
      sim_correnti_tensioni_deriv[4] = sim_correnti_tensioni_B.Input00[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_x >= 1.f &&
           sim_correnti_tensioni_B.Product19 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_x <= 0.f &&
           sim_correnti_tensioni_B.Product19 < 0))
      {
         sim_correnti_tensioni_deriv[3] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[3] = sim_correnti_tensioni_B.Product19;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder62/Integrator4' */
      sim_correnti_tensioni_deriv[5] = sim_correnti_tensioni_B.Input00[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator7' */
      sim_correnti_tensioni_deriv[1] = sim_correnti_tensioni_B.Input01[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_1_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_1 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_1_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_1 < 0))
      {
         sim_correnti_tensioni_deriv[0] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[0] = sim_correnti_tensioni_B.Product19_1;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder61/Integrator4' */
      sim_correnti_tensioni_deriv[2] = sim_correnti_tensioni_B.Input01[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator7' */
      sim_correnti_tensioni_deriv[7] = sim_correnti_tensioni_B.Input02[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_2_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_2 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_2_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_2 < 0))
      {
         sim_correnti_tensioni_deriv[6] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[6] = sim_correnti_tensioni_B.Product19_2;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder63/Integrator4' */
      sim_correnti_tensioni_deriv[8] = sim_correnti_tensioni_B.Input02[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator7' */
      sim_correnti_tensioni_deriv[10] = sim_correnti_tensioni_B.Input03[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_3_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_3 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_3_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_3 < 0))
      {
         sim_correnti_tensioni_deriv[9] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[9] = sim_correnti_tensioni_B.Product19_3;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder64/Integrator4' */
      sim_correnti_tensioni_deriv[11] = sim_correnti_tensioni_B.Input03[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator7' */
      sim_correnti_tensioni_deriv[13] = sim_correnti_tensioni_B.Input04[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_4_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_4 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_4_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_4 < 0))
      {
         sim_correnti_tensioni_deriv[12] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[12] =
            sim_correnti_tensioni_B.Product19_4;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder65/Integrator4' */
      sim_correnti_tensioni_deriv[14] = sim_correnti_tensioni_B.Input04[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator7' */
      sim_correnti_tensioni_deriv[16] = sim_correnti_tensioni_B.Input05[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_5_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_5 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_5_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_5 < 0))
      {
         sim_correnti_tensioni_deriv[15] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[15] =
            sim_correnti_tensioni_B.Product19_5;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder66/Integrator4' */
      sim_correnti_tensioni_deriv[17] = sim_correnti_tensioni_B.Input05[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator7' */
      sim_correnti_tensioni_deriv[19] = sim_correnti_tensioni_B.Input06[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_6_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_6 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_6_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_6 < 0))
      {
         sim_correnti_tensioni_deriv[18] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[18] =
            sim_correnti_tensioni_B.Product19_6;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder67/Integrator4' */
      sim_correnti_tensioni_deriv[20] = sim_correnti_tensioni_B.Input06[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator7' */
      sim_correnti_tensioni_deriv[22] = sim_correnti_tensioni_B.Input07[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_7_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_7 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_7_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_7 < 0))
      {
         sim_correnti_tensioni_deriv[21] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[21] =
            sim_correnti_tensioni_B.Product19_7;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder68/Integrator4' */
      sim_correnti_tensioni_deriv[23] = sim_correnti_tensioni_B.Input07[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator7' */
      sim_correnti_tensioni_deriv[25] = sim_correnti_tensioni_B.Input08[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_8_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_8 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_8_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_8 < 0))
      {
         sim_correnti_tensioni_deriv[24] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[24] =
            sim_correnti_tensioni_B.Product19_8;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder69/Integrator4' */
      sim_correnti_tensioni_deriv[26] = sim_correnti_tensioni_B.Input08[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator7' */
      sim_correnti_tensioni_deriv[28] = sim_correnti_tensioni_B.Input09[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_9_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_9 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_9_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_9 < 0))
      {
         sim_correnti_tensioni_deriv[27] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[27] =
            sim_correnti_tensioni_B.Product19_9;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder70/Integrator4' */
      sim_correnti_tensioni_deriv[29] = sim_correnti_tensioni_B.Input09[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator7' */
      sim_correnti_tensioni_deriv[31] = sim_correnti_tensioni_B.Input0A[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_10_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_10 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_10_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_10 < 0))
      {
         sim_correnti_tensioni_deriv[30] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[30] =
            sim_correnti_tensioni_B.Product19_10;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder71/Integrator4' */
      sim_correnti_tensioni_deriv[32] = sim_correnti_tensioni_B.Input0A[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator7' */
      sim_correnti_tensioni_deriv[34] = sim_correnti_tensioni_B.Input0B[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_11_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_11 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_11_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_11 < 0))
      {
         sim_correnti_tensioni_deriv[33] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[33] =
            sim_correnti_tensioni_B.Product19_11;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder72/Integrator4' */
      sim_correnti_tensioni_deriv[35] = sim_correnti_tensioni_B.Input0B[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator7' */
      sim_correnti_tensioni_deriv[37] = sim_correnti_tensioni_B.Input0C[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_12_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_12 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_12_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_12 < 0))
      {
         sim_correnti_tensioni_deriv[36] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[36] =
            sim_correnti_tensioni_B.Product19_12;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder73/Integrator4' */
      sim_correnti_tensioni_deriv[38] = sim_correnti_tensioni_B.Input0C[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator7' */
      sim_correnti_tensioni_deriv[40] = sim_correnti_tensioni_B.Input0D[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_13_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_13 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_13_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_13 < 0))
      {
         sim_correnti_tensioni_deriv[39] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[39] =
            sim_correnti_tensioni_B.Product19_13;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder74/Integrator4' */
      sim_correnti_tensioni_deriv[41] = sim_correnti_tensioni_B.Input0D[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator7' */
      sim_correnti_tensioni_deriv[43] = sim_correnti_tensioni_B.Input0E[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_14_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_14 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_14_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_14 < 0))
      {
         sim_correnti_tensioni_deriv[42] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[42] =
            sim_correnti_tensioni_B.Product19_14;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder75/Integrator4' */
      sim_correnti_tensioni_deriv[44] = sim_correnti_tensioni_B.Input0E[5];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator7' */
      sim_correnti_tensioni_deriv[46] = sim_correnti_tensioni_B.Input0F[1];

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator6' */
      if ((sim_correnti_tensioni_X.Integrator6_15_x >= 1.f &&
           sim_correnti_tensioni_B.Product19_15 > 0) ||
          (sim_correnti_tensioni_X.Integrator6_15_x <= 0.f &&
           sim_correnti_tensioni_B.Product19_15 < 0))
      {
         sim_correnti_tensioni_deriv[45] = 0;
      }
      else
      {
         sim_correnti_tensioni_deriv[45] =
            sim_correnti_tensioni_B.Product19_15;
      }

      /* Derivatives for Integrator : 'sim_correnti_tensioni/Signal Builder76/Integrator4' */
      sim_correnti_tensioni_deriv[47] = sim_correnti_tensioni_B.Input0F[5];

      /* Update continuous states */
      sim_correnti_tensioni_X.Integrator7_x += 1e-05f*
                                               sim_correnti_tensioni_deriv[4];
      sim_correnti_tensioni_X.Integrator6_x += 1e-05f*
                                               sim_correnti_tensioni_deriv[3];
      sim_correnti_tensioni_X.Integrator4_x += 1e-05f*
                                               sim_correnti_tensioni_deriv[5];
      sim_correnti_tensioni_X.Integrator7_1_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[1
                                                 ];
      sim_correnti_tensioni_X.Integrator6_1_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[0
                                                 ];
      sim_correnti_tensioni_X.Integrator4_1_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[2
                                                 ];
      sim_correnti_tensioni_X.Integrator7_2_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[7
                                                 ];
      sim_correnti_tensioni_X.Integrator6_2_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[6
                                                 ];
      sim_correnti_tensioni_X.Integrator4_2_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[8
                                                 ];
      sim_correnti_tensioni_X.Integrator7_3_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         10];
      sim_correnti_tensioni_X.Integrator6_3_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[9
                                                 ];
      sim_correnti_tensioni_X.Integrator4_3_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         11];
      sim_correnti_tensioni_X.Integrator7_4_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         13];
      sim_correnti_tensioni_X.Integrator6_4_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         12];
      sim_correnti_tensioni_X.Integrator4_4_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         14];
      sim_correnti_tensioni_X.Integrator7_5_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         16];
      sim_correnti_tensioni_X.Integrator6_5_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         15];
      sim_correnti_tensioni_X.Integrator4_5_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         17];
      sim_correnti_tensioni_X.Integrator7_6_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         19];
      sim_correnti_tensioni_X.Integrator6_6_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         18];
      sim_correnti_tensioni_X.Integrator4_6_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         20];
      sim_correnti_tensioni_X.Integrator7_7_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         22];
      sim_correnti_tensioni_X.Integrator6_7_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         21];
      sim_correnti_tensioni_X.Integrator4_7_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         23];
      sim_correnti_tensioni_X.Integrator7_8_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         25];
      sim_correnti_tensioni_X.Integrator6_8_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         24];
      sim_correnti_tensioni_X.Integrator4_8_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         26];
      sim_correnti_tensioni_X.Integrator7_9_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         28];
      sim_correnti_tensioni_X.Integrator6_9_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         27];
      sim_correnti_tensioni_X.Integrator4_9_x += 1e-05f*
                                                 sim_correnti_tensioni_deriv[
         29];
      sim_correnti_tensioni_X.Integrator7_10_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         31];
      sim_correnti_tensioni_X.Integrator6_10_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         30];
      sim_correnti_tensioni_X.Integrator4_10_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         32];
      sim_correnti_tensioni_X.Integrator7_11_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         34];
      sim_correnti_tensioni_X.Integrator6_11_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         33];
      sim_correnti_tensioni_X.Integrator4_11_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         35];
      sim_correnti_tensioni_X.Integrator7_12_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         37];
      sim_correnti_tensioni_X.Integrator6_12_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         36];
      sim_correnti_tensioni_X.Integrator4_12_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         38];
      sim_correnti_tensioni_X.Integrator7_13_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         40];
      sim_correnti_tensioni_X.Integrator6_13_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         39];
      sim_correnti_tensioni_X.Integrator4_13_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         41];
      sim_correnti_tensioni_X.Integrator7_14_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         43];
      sim_correnti_tensioni_X.Integrator6_14_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         42];
      sim_correnti_tensioni_X.Integrator4_14_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         44];
      sim_correnti_tensioni_X.Integrator7_15_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         46];
      sim_correnti_tensioni_X.Integrator6_15_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         45];
      sim_correnti_tensioni_X.Integrator4_15_x += 1e-05f*
                                                  sim_correnti_tensioni_deriv[
         47];
      break;
   }

   case 1:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         /* Task "[0.0001, 0]" */
   {

      /* C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
      sim_correnti_tensioni_0_cScriptOutput(
                                            &sim_correnti_tensioni_cScriptStruct[
                                               0]);
      if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
         sim_correnti_tensioni_errorStatus =
            *sim_correnti_tensioni_cScriptStruct[0].errorStatus;
      /* Task transfer to '[0, 0]' (Unit Delay) */
      sim_correnti_tensioni_D_float[0] = sim_correnti_tensioni_B.C_Script;
      if (sim_correnti_tensioni_errorStatus)
      {
         return;
      }

      /* Update for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
      sim_correnti_tensioni_0_cScriptUpdate(
                                            &sim_correnti_tensioni_cScriptStruct[
                                               0]);
      if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
         sim_correnti_tensioni_errorStatus =
            *sim_correnti_tensioni_cScriptStruct[0].errorStatus;
      break;
   }
   }
}

void sim_correnti_tensioni_terminate()
{
   /* Termination for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_0_cScriptTerminate(
                                            &sim_correnti_tensioni_cScriptStruct[
                                               0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;
}
void sim_correnti_tensioni_sync()
{
   static size_t tick[0] = {  };
}
