/*
 * Implementation file for: sim_correnti_tensioni
 * Generated with         : PLECS 4.7.1
 *                          PLECS RT Box 1 2.3.1
 * Generated on           : 6 Apr 2023 18:46:55
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
   double time;
   const double ***inputs;
   double ***outputs;
   double *contStates;
   double *contDerivs;
   double *discStates;
   double *zCSignals;
   const int *paramNumDims;
   const int **paramDims;
   const int *paramNumElements;
   const double **paramRealData;
   const char **paramStringData;
   const char * const *sampleHits;
   const double *sampleTimePeriods;
   const double *sampleTimeOffsets;
   double *nextSampleHit;
   const char** errorStatus;
   const char** warningStatus;
   const char** rangeErrorMsg;
   int* rangeErrorLine;
   void (*writeCustomStateDouble)(void*, double);
   double (*readCustomStateDouble)(void*);
   void (*writeCustomStateInt)(void*, int);
   void (*writeCustomStateData)(void*, const void*, int);
   void (*readCustomStateData)(void*, void*, int);
};
static struct CScriptStruct sim_correnti_tensioni_cScriptStruct[1];
static char sim_correnti_tensioni_isMajorStep = '\001';
static const uint32_t sim_correnti_tensioni_subTaskPeriod[1]= {
   /* [0.01, 0], [0, 0] */
   100
};
static uint32_t sim_correnti_tensioni_subTaskTick[1];
static char sim_correnti_tensioni_subTaskHit[1];
static const double sim_correnti_tensioni_UNCONNECTED = 0;
static uint32_t sim_correnti_tensioni_D_uint32_t[17];
static double sim_correnti_tensioni_deriv[48] _ALIGN;
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
static uint32_t sim_correnti_tensioni_tickLo;
static int32_t sim_correnti_tensioni_tickHi;
sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const sim_correnti_tensioni_ExtModeSignals[] = {

};
#endif /* defined(EXTERNAL_MODE) */
sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X _ALIGN;
const char * sim_correnti_tensioni_errorStatus;
const double sim_correnti_tensioni_sampleTime = 0.000100000000000000005;
const char * const sim_correnti_tensioni_checksum =
   "610659e2fd2e81f0b163c8273c232cd9c1a92fbe";
/* Target declarations */
struct PlxDataCaptureRegistry plxDataCaptureRegistry[1];
const int plxUseEthercat = 0;
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[18];
struct PlxToFileRegistry plxToFileRegistry[1];

void sim_correnti_tensioni_initialize()
{
   sim_correnti_tensioni_tickHi = 0;
   sim_correnti_tensioni_tickLo = 0;
   /* Initialize sub-task tick counters */
   sim_correnti_tensioni_subTaskTick[0] = 0; /* [0, 0], [0.01, 0] */


   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(3);
   setDigitalOutVoltage(0);
   plxInitDigitalOut();
   initPWMCapture();
   plxSetupAnalogSampling(1, 0, 1.00000000000000005e-04);
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);


   /* Initialization for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   {
      static int numInputSignals[] = {
         1
      };
      static const double* inputPtrs[] = {
         &sim_correnti_tensioni_B.Width
      };
      static const double** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static double* outputPtrs[] = {
         &sim_correnti_tensioni_B.C_Script
      };
      static double** outputs[] = {
         &outputPtrs[0]
      };
      static double nextSampleHit;
      static const char * sampleHits[] = {
         &sim_correnti_tensioni_isMajorStep
      };
      static double sampleTimePeriods[] = {
         0.0001
      };
      static double sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      static const double paramData[] = {
         0.,2.,0.,0.000100000000000000005
      };
      static const double* paramDataPtr[] = {
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

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input0' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(0, "Input0", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_x = 0;
   sim_correnti_tensioni_X.Integrator7_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator6' */
   sim_correnti_tensioni_X.Integrator6_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1 = 0.;
   sim_correnti_tensioni_D_uint32_t[0] = 0;

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out4' */
   setupAnalogOut(0, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input17' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(1, "Input17", 1, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input1' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(2, "Input1", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator9' */
   sim_correnti_tensioni_X.Integrator9_x = 0;
   sim_correnti_tensioni_X.Integrator9_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator8' */
   sim_correnti_tensioni_X.Integrator8_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator5' */
   sim_correnti_tensioni_X.Integrator5_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop2' */
   sim_correnti_tensioni_X.Monoflop2 = 0.;
   sim_correnti_tensioni_D_uint32_t[1] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input2' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(3, "Input2", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator11' */
   sim_correnti_tensioni_X.Integrator11_x = 0;
   sim_correnti_tensioni_X.Integrator11_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator10' */
   sim_correnti_tensioni_X.Integrator10_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator12' */
   sim_correnti_tensioni_X.Integrator12_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop3' */
   sim_correnti_tensioni_X.Monoflop3 = 0.;
   sim_correnti_tensioni_D_uint32_t[2] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input3' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(4, "Input3", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator14' */
   sim_correnti_tensioni_X.Integrator14_x = 0;
   sim_correnti_tensioni_X.Integrator14_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator13' */
   sim_correnti_tensioni_X.Integrator13_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator15' */
   sim_correnti_tensioni_X.Integrator15_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop4' */
   sim_correnti_tensioni_X.Monoflop4 = 0.;
   sim_correnti_tensioni_D_uint32_t[3] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input4' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(5, "Input4", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator17' */
   sim_correnti_tensioni_X.Integrator17_x = 0;
   sim_correnti_tensioni_X.Integrator17_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator16' */
   sim_correnti_tensioni_X.Integrator16_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator18' */
   sim_correnti_tensioni_X.Integrator18_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop5' */
   sim_correnti_tensioni_X.Monoflop5 = 0.;
   sim_correnti_tensioni_D_uint32_t[4] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input5' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(6, "Input5", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator20' */
   sim_correnti_tensioni_X.Integrator20_x = 0;
   sim_correnti_tensioni_X.Integrator20_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator19' */
   sim_correnti_tensioni_X.Integrator19_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator21' */
   sim_correnti_tensioni_X.Integrator21_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop6' */
   sim_correnti_tensioni_X.Monoflop6 = 0.;
   sim_correnti_tensioni_D_uint32_t[5] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input6' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(7, "Input6", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator23' */
   sim_correnti_tensioni_X.Integrator23_x = 0;
   sim_correnti_tensioni_X.Integrator23_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator22' */
   sim_correnti_tensioni_X.Integrator22_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator24' */
   sim_correnti_tensioni_X.Integrator24_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop7' */
   sim_correnti_tensioni_X.Monoflop7 = 0.;
   sim_correnti_tensioni_D_uint32_t[6] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input7' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(8, "Input7", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator26' */
   sim_correnti_tensioni_X.Integrator26_x = 0;
   sim_correnti_tensioni_X.Integrator26_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator25' */
   sim_correnti_tensioni_X.Integrator25_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator27' */
   sim_correnti_tensioni_X.Integrator27_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop8' */
   sim_correnti_tensioni_X.Monoflop8 = 0.;
   sim_correnti_tensioni_D_uint32_t[7] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input8' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(9, "Input8", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator29' */
   sim_correnti_tensioni_X.Integrator29_x = 0;
   sim_correnti_tensioni_X.Integrator29_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator28' */
   sim_correnti_tensioni_X.Integrator28_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator30' */
   sim_correnti_tensioni_X.Integrator30_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop9' */
   sim_correnti_tensioni_X.Monoflop9 = 0.;
   sim_correnti_tensioni_D_uint32_t[8] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input9' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(10, "Input9", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator32' */
   sim_correnti_tensioni_X.Integrator32_x = 0;
   sim_correnti_tensioni_X.Integrator32_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator31' */
   sim_correnti_tensioni_X.Integrator31_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator33' */
   sim_correnti_tensioni_X.Integrator33_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop10' */
   sim_correnti_tensioni_X.Monoflop10 = 0.;
   sim_correnti_tensioni_D_uint32_t[9] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input10' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(11, "Input10", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator35' */
   sim_correnti_tensioni_X.Integrator35_x = 0;
   sim_correnti_tensioni_X.Integrator35_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator34' */
   sim_correnti_tensioni_X.Integrator34_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator36' */
   sim_correnti_tensioni_X.Integrator36_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop11' */
   sim_correnti_tensioni_X.Monoflop11 = 0.;
   sim_correnti_tensioni_D_uint32_t[10] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input11' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(12, "Input11", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator38' */
   sim_correnti_tensioni_X.Integrator38_x = 0;
   sim_correnti_tensioni_X.Integrator38_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator37' */
   sim_correnti_tensioni_X.Integrator37_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator39' */
   sim_correnti_tensioni_X.Integrator39_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop12' */
   sim_correnti_tensioni_X.Monoflop12 = 0.;
   sim_correnti_tensioni_D_uint32_t[11] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input12' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(13, "Input12", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator41' */
   sim_correnti_tensioni_X.Integrator41_x = 0;
   sim_correnti_tensioni_X.Integrator41_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator40' */
   sim_correnti_tensioni_X.Integrator40_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator42' */
   sim_correnti_tensioni_X.Integrator42_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop13' */
   sim_correnti_tensioni_X.Monoflop13 = 0.;
   sim_correnti_tensioni_D_uint32_t[12] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input13' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(14, "Input13", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator44' */
   sim_correnti_tensioni_X.Integrator44_x = 0;
   sim_correnti_tensioni_X.Integrator44_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator43' */
   sim_correnti_tensioni_X.Integrator43_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator45' */
   sim_correnti_tensioni_X.Integrator45_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop14' */
   sim_correnti_tensioni_X.Monoflop14 = 0.;
   sim_correnti_tensioni_D_uint32_t[13] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input14' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(15, "Input14", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator47' */
   sim_correnti_tensioni_X.Integrator47_x = 0;
   sim_correnti_tensioni_X.Integrator47_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator46' */
   sim_correnti_tensioni_X.Integrator46_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator48' */
   sim_correnti_tensioni_X.Integrator48_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop15' */
   sim_correnti_tensioni_X.Monoflop15 = 0.;
   sim_correnti_tensioni_D_uint32_t[14] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input15' */
   {
      static double programmableValueData[] = {
         5.00000000000000000e-01, 0.00000000000000000e+00,
         3.14160000000000025e+02, 0.00000000000000000e+00,
         0.00000000000000000e+00, 2.00000000000000000e+02,
         0.00000000000000000e+00, 5.00000000000000000e-01,
         0.00000000000000000e+00, 3.14160000000000025e+02,
         0.00000000000000000e+00, 0.00000000000000000e+00,
         2.00000000000000000e+02, 0.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(16, "Input15", 7, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator50' */
   sim_correnti_tensioni_X.Integrator50_x = 0;
   sim_correnti_tensioni_X.Integrator50_i1_first = 1;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator49' */
   sim_correnti_tensioni_X.Integrator49_x = 0.;

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator51' */
   sim_correnti_tensioni_X.Integrator51_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop16' */
   sim_correnti_tensioni_X.Monoflop16 = 0.;
   sim_correnti_tensioni_D_uint32_t[15] = 0;

   /* Initialization for Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
   sim_correnti_tensioni_D_uint32_t[16] = 0;

   /* Initialization for Data Capture : 'sim_correnti_tensioni/Capture1' */
   {
      static double dataBuffer[20];
      plxSetupDataCapture(0, "Capture1", 1, 10, dataBuffer, 1,
                          0.00000000000000000e+00, 1.00000000000000005e-04);
   }


   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out5' */
   setupAnalogOut(1, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out6' */
   setupAnalogOut(2, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

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

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out12' */
   setupAnalogOut(8, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out13' */
   setupAnalogOut(9, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out14' */
   setupAnalogOut(10, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out15' */
   setupAnalogOut(11, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out16' */
   setupAnalogOut(12, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out17' */
   setupAnalogOut(13, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out18' */
   setupAnalogOut(14, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out19' */
   setupAnalogOut(15, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input16' */
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
      plxSetupProgrammableValue(17, "Input16", 16, programmableValueData,
                                bufferFull);
   };
}

void sim_correnti_tensioni_step(void)
{
   if (sim_correnti_tensioni_errorStatus)
   {
      return;
   }
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         sim_correnti_tensioni_subTaskHit[i] =
            (sim_correnti_tensioni_subTaskTick[i] == 0);
      }
   }

   /* C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_0_cScriptOutput(&sim_correnti_tensioni_cScriptStruct[
                                            0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;

   /* Programmable Value : 'sim_correnti_tensioni/Input0' */
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
   sim_correnti_tensioni_B.Input0[0] = plxGetProgrammableValueData(0, 0);
   sim_correnti_tensioni_B.Input0[1] = plxGetProgrammableValueData(0, 1);
   sim_correnti_tensioni_B.Input0[2] = plxGetProgrammableValueData(0, 2);
   sim_correnti_tensioni_B.Input0[3] = plxGetProgrammableValueData(0, 3);
   sim_correnti_tensioni_B.Input0[4] = plxGetProgrammableValueData(0, 4);
   sim_correnti_tensioni_B.Input0[5] = plxGetProgrammableValueData(0, 5);
   sim_correnti_tensioni_B.Input0[6] = plxGetProgrammableValueData(0, 6);
   sim_correnti_tensioni_B.Input0[7] = plxGetProgrammableValueUpdateFlag(0);

   /* Integrator : 'sim_correnti_tensioni/Integrator7' */
   if (sim_correnti_tensioni_X.Integrator7_i1_first)
   {
      sim_correnti_tensioni_X.Integrator7_x =
         sim_correnti_tensioni_B.Input0[3];
   }
   if (sim_correnti_tensioni_X.Integrator7_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator7_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator7_x -= 0.;
      sim_correnti_tensioni_X.Integrator7_x =
         sim_correnti_tensioni_X.Integrator7_x - span*floor(
                                                            sim_correnti_tensioni_X.Integrator7_x/
                                                            span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator7 =
      sim_correnti_tensioni_X.Integrator7_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator6' */
   if (sim_correnti_tensioni_X.Integrator6_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator6_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator6_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator6_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator6 =
      sim_correnti_tensioni_X.Integrator6_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator4' */
   if (sim_correnti_tensioni_X.Integrator4_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator4_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator4_x -= -0.5;
      sim_correnti_tensioni_X.Integrator4_x =
         sim_correnti_tensioni_X.Integrator4_x - span*floor(
                                                            sim_correnti_tensioni_X.Integrator4_x/
                                                            span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator4 =
      sim_correnti_tensioni_X.Integrator4_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator1' */
   if (0. > sim_correnti_tensioni_B.Integrator4)
      sim_correnti_tensioni_B.Comparator1 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator4)
      sim_correnti_tensioni_B.Comparator1 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop1'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop1 &&
       (sim_correnti_tensioni_B.Comparator1))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[0] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[0] > 0)
      {
         sim_correnti_tensioni_B.Monoflop1 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[0] == 0)
   {
      sim_correnti_tensioni_B.Monoflop1 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum1'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction'
    *  Product : 'sim_correnti_tensioni/Product13'
    *  Product : 'sim_correnti_tensioni/Product1'
    */
   sim_correnti_tensioni_B.Sum1 =
      (sim_correnti_tensioni_B.Input0[1] *
       sin(sim_correnti_tensioni_B.Integrator7) *
       sim_correnti_tensioni_B.Integrator6) +
      (sim_correnti_tensioni_B.Input0[4] * sim_correnti_tensioni_B.Monoflop1 *
       sim_correnti_tensioni_B.Integrator6) +
      (sim_correnti_tensioni_B.Input0[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator6);
   /* Analog Out : 'sim_correnti_tensioni/Analog Out4' */
   setAnalogOut(0, sim_correnti_tensioni_B.Sum1);
   /* Programmable Value : 'sim_correnti_tensioni/Input17' */
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
   /* Programmable Value : 'sim_correnti_tensioni/Input1' */
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
   sim_correnti_tensioni_B.Input1[0] = plxGetProgrammableValueData(2, 0);
   sim_correnti_tensioni_B.Input1[1] = plxGetProgrammableValueData(2, 1);
   sim_correnti_tensioni_B.Input1[2] = plxGetProgrammableValueData(2, 2);
   sim_correnti_tensioni_B.Input1[3] = plxGetProgrammableValueData(2, 3);
   sim_correnti_tensioni_B.Input1[4] = plxGetProgrammableValueData(2, 4);
   sim_correnti_tensioni_B.Input1[5] = plxGetProgrammableValueData(2, 5);
   sim_correnti_tensioni_B.Input1[6] = plxGetProgrammableValueData(2, 6);
   sim_correnti_tensioni_B.Input1[7] = plxGetProgrammableValueUpdateFlag(2);

   /* Integrator : 'sim_correnti_tensioni/Integrator9' */
   if (sim_correnti_tensioni_X.Integrator9_i1_first)
   {
      sim_correnti_tensioni_X.Integrator9_x =
         sim_correnti_tensioni_B.Input1[3];
   }
   if (sim_correnti_tensioni_X.Integrator9_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator9_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator9_x -= 0.;
      sim_correnti_tensioni_X.Integrator9_x =
         sim_correnti_tensioni_X.Integrator9_x - span*floor(
                                                            sim_correnti_tensioni_X.Integrator9_x/
                                                            span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator9 =
      sim_correnti_tensioni_X.Integrator9_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator8' */
   if (sim_correnti_tensioni_X.Integrator8_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator8_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator8_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator8_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator8 =
      sim_correnti_tensioni_X.Integrator8_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator5' */
   if (sim_correnti_tensioni_X.Integrator5_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator5_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator5_x -= -0.5;
      sim_correnti_tensioni_X.Integrator5_x =
         sim_correnti_tensioni_X.Integrator5_x - span*floor(
                                                            sim_correnti_tensioni_X.Integrator5_x/
                                                            span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator5 =
      sim_correnti_tensioni_X.Integrator5_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator2' */
   if (0. > sim_correnti_tensioni_B.Integrator5)
      sim_correnti_tensioni_B.Comparator2 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator5)
      sim_correnti_tensioni_B.Comparator2 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop2'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop2 &&
       (sim_correnti_tensioni_B.Comparator2))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[1] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[1] > 0)
      {
         sim_correnti_tensioni_B.Monoflop2 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[1] == 0)
   {
      sim_correnti_tensioni_B.Monoflop2 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum2'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product2'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction1'
    *  Product : 'sim_correnti_tensioni/Product14'
    *  Product : 'sim_correnti_tensioni/Product3'
    */
   sim_correnti_tensioni_B.Sum2 =
      (sim_correnti_tensioni_B.Input1[1] *
       sin(sim_correnti_tensioni_B.Integrator9) *
       sim_correnti_tensioni_B.Integrator8) +
      (sim_correnti_tensioni_B.Input1[4] * sim_correnti_tensioni_B.Monoflop2 *
       sim_correnti_tensioni_B.Integrator8) +
      (sim_correnti_tensioni_B.Input1[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator8);

   /* Programmable Value : 'sim_correnti_tensioni/Input2' */
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
   sim_correnti_tensioni_B.Input2[0] = plxGetProgrammableValueData(3, 0);
   sim_correnti_tensioni_B.Input2[1] = plxGetProgrammableValueData(3, 1);
   sim_correnti_tensioni_B.Input2[2] = plxGetProgrammableValueData(3, 2);
   sim_correnti_tensioni_B.Input2[3] = plxGetProgrammableValueData(3, 3);
   sim_correnti_tensioni_B.Input2[4] = plxGetProgrammableValueData(3, 4);
   sim_correnti_tensioni_B.Input2[5] = plxGetProgrammableValueData(3, 5);
   sim_correnti_tensioni_B.Input2[6] = plxGetProgrammableValueData(3, 6);
   sim_correnti_tensioni_B.Input2[7] = plxGetProgrammableValueUpdateFlag(3);

   /* Integrator : 'sim_correnti_tensioni/Integrator11' */
   if (sim_correnti_tensioni_X.Integrator11_i1_first)
   {
      sim_correnti_tensioni_X.Integrator11_x =
         sim_correnti_tensioni_B.Input2[3];
   }
   if (sim_correnti_tensioni_X.Integrator11_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator11_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator11_x -= 0.;
      sim_correnti_tensioni_X.Integrator11_x =
         sim_correnti_tensioni_X.Integrator11_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator11_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator11 =
      sim_correnti_tensioni_X.Integrator11_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator10' */
   if (sim_correnti_tensioni_X.Integrator10_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator10_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator10_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator10_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator10 =
      sim_correnti_tensioni_X.Integrator10_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator12' */
   if (sim_correnti_tensioni_X.Integrator12_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator12_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator12_x -= -0.5;
      sim_correnti_tensioni_X.Integrator12_x =
         sim_correnti_tensioni_X.Integrator12_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator12_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator12 =
      sim_correnti_tensioni_X.Integrator12_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator3' */
   if (0. > sim_correnti_tensioni_B.Integrator12)
      sim_correnti_tensioni_B.Comparator3 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator12)
      sim_correnti_tensioni_B.Comparator3 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop3'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop3 &&
       (sim_correnti_tensioni_B.Comparator3))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[2] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[2] > 0)
      {
         sim_correnti_tensioni_B.Monoflop3 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[2] == 0)
   {
      sim_correnti_tensioni_B.Monoflop3 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum3'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product4'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction2'
    *  Product : 'sim_correnti_tensioni/Product15'
    *  Product : 'sim_correnti_tensioni/Product5'
    */
   sim_correnti_tensioni_B.Sum3 =
      (sim_correnti_tensioni_B.Input2[1] *
       sin(sim_correnti_tensioni_B.Integrator11) *
       sim_correnti_tensioni_B.Integrator10) +
      (sim_correnti_tensioni_B.Input2[4] * sim_correnti_tensioni_B.Monoflop3 *
       sim_correnti_tensioni_B.Integrator10) +
      (sim_correnti_tensioni_B.Input2[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator10);

   /* Programmable Value : 'sim_correnti_tensioni/Input3' */
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
   sim_correnti_tensioni_B.Input3[0] = plxGetProgrammableValueData(4, 0);
   sim_correnti_tensioni_B.Input3[1] = plxGetProgrammableValueData(4, 1);
   sim_correnti_tensioni_B.Input3[2] = plxGetProgrammableValueData(4, 2);
   sim_correnti_tensioni_B.Input3[3] = plxGetProgrammableValueData(4, 3);
   sim_correnti_tensioni_B.Input3[4] = plxGetProgrammableValueData(4, 4);
   sim_correnti_tensioni_B.Input3[5] = plxGetProgrammableValueData(4, 5);
   sim_correnti_tensioni_B.Input3[6] = plxGetProgrammableValueData(4, 6);
   sim_correnti_tensioni_B.Input3[7] = plxGetProgrammableValueUpdateFlag(4);

   /* Integrator : 'sim_correnti_tensioni/Integrator14' */
   if (sim_correnti_tensioni_X.Integrator14_i1_first)
   {
      sim_correnti_tensioni_X.Integrator14_x =
         sim_correnti_tensioni_B.Input3[3];
   }
   if (sim_correnti_tensioni_X.Integrator14_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator14_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator14_x -= 0.;
      sim_correnti_tensioni_X.Integrator14_x =
         sim_correnti_tensioni_X.Integrator14_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator14_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator14 =
      sim_correnti_tensioni_X.Integrator14_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator13' */
   if (sim_correnti_tensioni_X.Integrator13_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator13_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator13_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator13_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator13 =
      sim_correnti_tensioni_X.Integrator13_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator15' */
   if (sim_correnti_tensioni_X.Integrator15_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator15_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator15_x -= -0.5;
      sim_correnti_tensioni_X.Integrator15_x =
         sim_correnti_tensioni_X.Integrator15_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator15_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator15 =
      sim_correnti_tensioni_X.Integrator15_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator4' */
   if (0. > sim_correnti_tensioni_B.Integrator15)
      sim_correnti_tensioni_B.Comparator4 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator15)
      sim_correnti_tensioni_B.Comparator4 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop4'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop4 &&
       (sim_correnti_tensioni_B.Comparator4))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[3] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[3] > 0)
      {
         sim_correnti_tensioni_B.Monoflop4 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[3] == 0)
   {
      sim_correnti_tensioni_B.Monoflop4 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum4'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product6'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction3'
    *  Product : 'sim_correnti_tensioni/Product16'
    *  Product : 'sim_correnti_tensioni/Product7'
    */
   sim_correnti_tensioni_B.Sum4 =
      (sim_correnti_tensioni_B.Input3[1] *
       sin(sim_correnti_tensioni_B.Integrator14) *
       sim_correnti_tensioni_B.Integrator13) +
      (sim_correnti_tensioni_B.Input3[4] * sim_correnti_tensioni_B.Monoflop4 *
       sim_correnti_tensioni_B.Integrator13) +
      (sim_correnti_tensioni_B.Input3[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator13);

   /* Programmable Value : 'sim_correnti_tensioni/Input4' */
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
   sim_correnti_tensioni_B.Input4[0] = plxGetProgrammableValueData(5, 0);
   sim_correnti_tensioni_B.Input4[1] = plxGetProgrammableValueData(5, 1);
   sim_correnti_tensioni_B.Input4[2] = plxGetProgrammableValueData(5, 2);
   sim_correnti_tensioni_B.Input4[3] = plxGetProgrammableValueData(5, 3);
   sim_correnti_tensioni_B.Input4[4] = plxGetProgrammableValueData(5, 4);
   sim_correnti_tensioni_B.Input4[5] = plxGetProgrammableValueData(5, 5);
   sim_correnti_tensioni_B.Input4[6] = plxGetProgrammableValueData(5, 6);
   sim_correnti_tensioni_B.Input4[7] = plxGetProgrammableValueUpdateFlag(5);

   /* Integrator : 'sim_correnti_tensioni/Integrator17' */
   if (sim_correnti_tensioni_X.Integrator17_i1_first)
   {
      sim_correnti_tensioni_X.Integrator17_x =
         sim_correnti_tensioni_B.Input4[3];
   }
   if (sim_correnti_tensioni_X.Integrator17_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator17_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator17_x -= 0.;
      sim_correnti_tensioni_X.Integrator17_x =
         sim_correnti_tensioni_X.Integrator17_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator17_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator17 =
      sim_correnti_tensioni_X.Integrator17_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator16' */
   if (sim_correnti_tensioni_X.Integrator16_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator16_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator16_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator16_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator16 =
      sim_correnti_tensioni_X.Integrator16_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator18' */
   if (sim_correnti_tensioni_X.Integrator18_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator18_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator18_x -= -0.5;
      sim_correnti_tensioni_X.Integrator18_x =
         sim_correnti_tensioni_X.Integrator18_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator18_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator18 =
      sim_correnti_tensioni_X.Integrator18_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator5' */
   if (0. > sim_correnti_tensioni_B.Integrator18)
      sim_correnti_tensioni_B.Comparator5 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator18)
      sim_correnti_tensioni_B.Comparator5 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop5'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop5 &&
       (sim_correnti_tensioni_B.Comparator5))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[4] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[4] > 0)
      {
         sim_correnti_tensioni_B.Monoflop5 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[4] == 0)
   {
      sim_correnti_tensioni_B.Monoflop5 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum5'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product8'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction4'
    *  Product : 'sim_correnti_tensioni/Product17'
    *  Product : 'sim_correnti_tensioni/Product9'
    */
   sim_correnti_tensioni_B.Sum5 =
      (sim_correnti_tensioni_B.Input4[1] *
       sin(sim_correnti_tensioni_B.Integrator17) *
       sim_correnti_tensioni_B.Integrator16) +
      (sim_correnti_tensioni_B.Input4[4] * sim_correnti_tensioni_B.Monoflop5 *
       sim_correnti_tensioni_B.Integrator16) +
      (sim_correnti_tensioni_B.Input4[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator16);

   /* Programmable Value : 'sim_correnti_tensioni/Input5' */
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
   sim_correnti_tensioni_B.Input5[0] = plxGetProgrammableValueData(6, 0);
   sim_correnti_tensioni_B.Input5[1] = plxGetProgrammableValueData(6, 1);
   sim_correnti_tensioni_B.Input5[2] = plxGetProgrammableValueData(6, 2);
   sim_correnti_tensioni_B.Input5[3] = plxGetProgrammableValueData(6, 3);
   sim_correnti_tensioni_B.Input5[4] = plxGetProgrammableValueData(6, 4);
   sim_correnti_tensioni_B.Input5[5] = plxGetProgrammableValueData(6, 5);
   sim_correnti_tensioni_B.Input5[6] = plxGetProgrammableValueData(6, 6);
   sim_correnti_tensioni_B.Input5[7] = plxGetProgrammableValueUpdateFlag(6);

   /* Integrator : 'sim_correnti_tensioni/Integrator20' */
   if (sim_correnti_tensioni_X.Integrator20_i1_first)
   {
      sim_correnti_tensioni_X.Integrator20_x =
         sim_correnti_tensioni_B.Input5[3];
   }
   if (sim_correnti_tensioni_X.Integrator20_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator20_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator20_x -= 0.;
      sim_correnti_tensioni_X.Integrator20_x =
         sim_correnti_tensioni_X.Integrator20_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator20_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator20 =
      sim_correnti_tensioni_X.Integrator20_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator19' */
   if (sim_correnti_tensioni_X.Integrator19_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator19_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator19_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator19_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator19 =
      sim_correnti_tensioni_X.Integrator19_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator21' */
   if (sim_correnti_tensioni_X.Integrator21_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator21_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator21_x -= -0.5;
      sim_correnti_tensioni_X.Integrator21_x =
         sim_correnti_tensioni_X.Integrator21_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator21_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator21 =
      sim_correnti_tensioni_X.Integrator21_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator6' */
   if (0. > sim_correnti_tensioni_B.Integrator21)
      sim_correnti_tensioni_B.Comparator6 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator21)
      sim_correnti_tensioni_B.Comparator6 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop6'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop6 &&
       (sim_correnti_tensioni_B.Comparator6))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[5] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[5] > 0)
      {
         sim_correnti_tensioni_B.Monoflop6 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[5] == 0)
   {
      sim_correnti_tensioni_B.Monoflop6 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum6'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product10'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction5'
    *  Product : 'sim_correnti_tensioni/Product18'
    *  Product : 'sim_correnti_tensioni/Product11'
    */
   sim_correnti_tensioni_B.Sum6 =
      (sim_correnti_tensioni_B.Input5[1] *
       sin(sim_correnti_tensioni_B.Integrator20) *
       sim_correnti_tensioni_B.Integrator19) +
      (sim_correnti_tensioni_B.Input5[4] * sim_correnti_tensioni_B.Monoflop6 *
       sim_correnti_tensioni_B.Integrator19) +
      (sim_correnti_tensioni_B.Input5[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator19);

   /* Programmable Value : 'sim_correnti_tensioni/Input6' */
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
   sim_correnti_tensioni_B.Input6[0] = plxGetProgrammableValueData(7, 0);
   sim_correnti_tensioni_B.Input6[1] = plxGetProgrammableValueData(7, 1);
   sim_correnti_tensioni_B.Input6[2] = plxGetProgrammableValueData(7, 2);
   sim_correnti_tensioni_B.Input6[3] = plxGetProgrammableValueData(7, 3);
   sim_correnti_tensioni_B.Input6[4] = plxGetProgrammableValueData(7, 4);
   sim_correnti_tensioni_B.Input6[5] = plxGetProgrammableValueData(7, 5);
   sim_correnti_tensioni_B.Input6[6] = plxGetProgrammableValueData(7, 6);
   sim_correnti_tensioni_B.Input6[7] = plxGetProgrammableValueUpdateFlag(7);

   /* Integrator : 'sim_correnti_tensioni/Integrator23' */
   if (sim_correnti_tensioni_X.Integrator23_i1_first)
   {
      sim_correnti_tensioni_X.Integrator23_x =
         sim_correnti_tensioni_B.Input6[3];
   }
   if (sim_correnti_tensioni_X.Integrator23_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator23_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator23_x -= 0.;
      sim_correnti_tensioni_X.Integrator23_x =
         sim_correnti_tensioni_X.Integrator23_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator23_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator23 =
      sim_correnti_tensioni_X.Integrator23_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator22' */
   if (sim_correnti_tensioni_X.Integrator22_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator22_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator22_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator22_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator22 =
      sim_correnti_tensioni_X.Integrator22_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator24' */
   if (sim_correnti_tensioni_X.Integrator24_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator24_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator24_x -= -0.5;
      sim_correnti_tensioni_X.Integrator24_x =
         sim_correnti_tensioni_X.Integrator24_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator24_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator24 =
      sim_correnti_tensioni_X.Integrator24_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator7' */
   if (0. > sim_correnti_tensioni_B.Integrator24)
      sim_correnti_tensioni_B.Comparator7 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator24)
      sim_correnti_tensioni_B.Comparator7 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop7'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop7 &&
       (sim_correnti_tensioni_B.Comparator7))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[6] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[6] > 0)
      {
         sim_correnti_tensioni_B.Monoflop7 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[6] == 0)
   {
      sim_correnti_tensioni_B.Monoflop7 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum7'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product12'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction6'
    *  Product : 'sim_correnti_tensioni/Product26'
    *  Product : 'sim_correnti_tensioni/Product27'
    */
   sim_correnti_tensioni_B.Sum7 =
      (sim_correnti_tensioni_B.Input6[1] *
       sin(sim_correnti_tensioni_B.Integrator23) *
       sim_correnti_tensioni_B.Integrator22) +
      (sim_correnti_tensioni_B.Input6[4] * sim_correnti_tensioni_B.Monoflop7 *
       sim_correnti_tensioni_B.Integrator22) +
      (sim_correnti_tensioni_B.Input6[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator22);

   /* Programmable Value : 'sim_correnti_tensioni/Input7' */
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
   sim_correnti_tensioni_B.Input7[0] = plxGetProgrammableValueData(8, 0);
   sim_correnti_tensioni_B.Input7[1] = plxGetProgrammableValueData(8, 1);
   sim_correnti_tensioni_B.Input7[2] = plxGetProgrammableValueData(8, 2);
   sim_correnti_tensioni_B.Input7[3] = plxGetProgrammableValueData(8, 3);
   sim_correnti_tensioni_B.Input7[4] = plxGetProgrammableValueData(8, 4);
   sim_correnti_tensioni_B.Input7[5] = plxGetProgrammableValueData(8, 5);
   sim_correnti_tensioni_B.Input7[6] = plxGetProgrammableValueData(8, 6);
   sim_correnti_tensioni_B.Input7[7] = plxGetProgrammableValueUpdateFlag(8);

   /* Integrator : 'sim_correnti_tensioni/Integrator26' */
   if (sim_correnti_tensioni_X.Integrator26_i1_first)
   {
      sim_correnti_tensioni_X.Integrator26_x =
         sim_correnti_tensioni_B.Input7[3];
   }
   if (sim_correnti_tensioni_X.Integrator26_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator26_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator26_x -= 0.;
      sim_correnti_tensioni_X.Integrator26_x =
         sim_correnti_tensioni_X.Integrator26_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator26_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator26 =
      sim_correnti_tensioni_X.Integrator26_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator25' */
   if (sim_correnti_tensioni_X.Integrator25_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator25_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator25_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator25_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator25 =
      sim_correnti_tensioni_X.Integrator25_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator27' */
   if (sim_correnti_tensioni_X.Integrator27_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator27_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator27_x -= -0.5;
      sim_correnti_tensioni_X.Integrator27_x =
         sim_correnti_tensioni_X.Integrator27_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator27_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator27 =
      sim_correnti_tensioni_X.Integrator27_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator8' */
   if (0. > sim_correnti_tensioni_B.Integrator27)
      sim_correnti_tensioni_B.Comparator8 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator27)
      sim_correnti_tensioni_B.Comparator8 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop8'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop8 &&
       (sim_correnti_tensioni_B.Comparator8))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[7] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[7] > 0)
      {
         sim_correnti_tensioni_B.Monoflop8 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[7] == 0)
   {
      sim_correnti_tensioni_B.Monoflop8 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum8'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product29'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction7'
    *  Product : 'sim_correnti_tensioni/Product30'
    *  Product : 'sim_correnti_tensioni/Product31'
    */
   sim_correnti_tensioni_B.Sum8 =
      (sim_correnti_tensioni_B.Input7[1] *
       sin(sim_correnti_tensioni_B.Integrator26) *
       sim_correnti_tensioni_B.Integrator25) +
      (sim_correnti_tensioni_B.Input7[4] * sim_correnti_tensioni_B.Monoflop8 *
       sim_correnti_tensioni_B.Integrator25) +
      (sim_correnti_tensioni_B.Input7[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator25);

   /* Programmable Value : 'sim_correnti_tensioni/Input8' */
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
   sim_correnti_tensioni_B.Input8[0] = plxGetProgrammableValueData(9, 0);
   sim_correnti_tensioni_B.Input8[1] = plxGetProgrammableValueData(9, 1);
   sim_correnti_tensioni_B.Input8[2] = plxGetProgrammableValueData(9, 2);
   sim_correnti_tensioni_B.Input8[3] = plxGetProgrammableValueData(9, 3);
   sim_correnti_tensioni_B.Input8[4] = plxGetProgrammableValueData(9, 4);
   sim_correnti_tensioni_B.Input8[5] = plxGetProgrammableValueData(9, 5);
   sim_correnti_tensioni_B.Input8[6] = plxGetProgrammableValueData(9, 6);
   sim_correnti_tensioni_B.Input8[7] = plxGetProgrammableValueUpdateFlag(9);

   /* Integrator : 'sim_correnti_tensioni/Integrator29' */
   if (sim_correnti_tensioni_X.Integrator29_i1_first)
   {
      sim_correnti_tensioni_X.Integrator29_x =
         sim_correnti_tensioni_B.Input8[3];
   }
   if (sim_correnti_tensioni_X.Integrator29_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator29_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator29_x -= 0.;
      sim_correnti_tensioni_X.Integrator29_x =
         sim_correnti_tensioni_X.Integrator29_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator29_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator29 =
      sim_correnti_tensioni_X.Integrator29_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator28' */
   if (sim_correnti_tensioni_X.Integrator28_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator28_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator28_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator28_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator28 =
      sim_correnti_tensioni_X.Integrator28_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator30' */
   if (sim_correnti_tensioni_X.Integrator30_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator30_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator30_x -= -0.5;
      sim_correnti_tensioni_X.Integrator30_x =
         sim_correnti_tensioni_X.Integrator30_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator30_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator30 =
      sim_correnti_tensioni_X.Integrator30_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator9' */
   if (0. > sim_correnti_tensioni_B.Integrator30)
      sim_correnti_tensioni_B.Comparator9 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator30)
      sim_correnti_tensioni_B.Comparator9 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop9'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop9 &&
       (sim_correnti_tensioni_B.Comparator9))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[8] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[8] > 0)
      {
         sim_correnti_tensioni_B.Monoflop9 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[8] == 0)
   {
      sim_correnti_tensioni_B.Monoflop9 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum9'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product33'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction8'
    *  Product : 'sim_correnti_tensioni/Product34'
    *  Product : 'sim_correnti_tensioni/Product35'
    */
   sim_correnti_tensioni_B.Sum9 =
      (sim_correnti_tensioni_B.Input8[1] *
       sin(sim_correnti_tensioni_B.Integrator29) *
       sim_correnti_tensioni_B.Integrator28) +
      (sim_correnti_tensioni_B.Input8[4] * sim_correnti_tensioni_B.Monoflop9 *
       sim_correnti_tensioni_B.Integrator28) +
      (sim_correnti_tensioni_B.Input8[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator28);

   /* Programmable Value : 'sim_correnti_tensioni/Input9' */
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
   sim_correnti_tensioni_B.Input9[0] = plxGetProgrammableValueData(10, 0);
   sim_correnti_tensioni_B.Input9[1] = plxGetProgrammableValueData(10, 1);
   sim_correnti_tensioni_B.Input9[2] = plxGetProgrammableValueData(10, 2);
   sim_correnti_tensioni_B.Input9[3] = plxGetProgrammableValueData(10, 3);
   sim_correnti_tensioni_B.Input9[4] = plxGetProgrammableValueData(10, 4);
   sim_correnti_tensioni_B.Input9[5] = plxGetProgrammableValueData(10, 5);
   sim_correnti_tensioni_B.Input9[6] = plxGetProgrammableValueData(10, 6);
   sim_correnti_tensioni_B.Input9[7] = plxGetProgrammableValueUpdateFlag(10);

   /* Integrator : 'sim_correnti_tensioni/Integrator32' */
   if (sim_correnti_tensioni_X.Integrator32_i1_first)
   {
      sim_correnti_tensioni_X.Integrator32_x =
         sim_correnti_tensioni_B.Input9[3];
   }
   if (sim_correnti_tensioni_X.Integrator32_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator32_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator32_x -= 0.;
      sim_correnti_tensioni_X.Integrator32_x =
         sim_correnti_tensioni_X.Integrator32_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator32_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator32 =
      sim_correnti_tensioni_X.Integrator32_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator31' */
   if (sim_correnti_tensioni_X.Integrator31_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator31_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator31_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator31_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator31 =
      sim_correnti_tensioni_X.Integrator31_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator33' */
   if (sim_correnti_tensioni_X.Integrator33_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator33_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator33_x -= -0.5;
      sim_correnti_tensioni_X.Integrator33_x =
         sim_correnti_tensioni_X.Integrator33_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator33_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator33 =
      sim_correnti_tensioni_X.Integrator33_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator10' */
   if (0. > sim_correnti_tensioni_B.Integrator33)
      sim_correnti_tensioni_B.Comparator10 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator33)
      sim_correnti_tensioni_B.Comparator10 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop10'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop10 &&
       (sim_correnti_tensioni_B.Comparator10))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[9] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[9] > 0)
      {
         sim_correnti_tensioni_B.Monoflop10 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[9] == 0)
   {
      sim_correnti_tensioni_B.Monoflop10 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum10'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product37'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction9'
    *  Product : 'sim_correnti_tensioni/Product38'
    *  Product : 'sim_correnti_tensioni/Product39'
    */
   sim_correnti_tensioni_B.Sum10 =
      (sim_correnti_tensioni_B.Input9[1] *
       sin(sim_correnti_tensioni_B.Integrator32) *
       sim_correnti_tensioni_B.Integrator31) +
      (sim_correnti_tensioni_B.Input9[4] *
       sim_correnti_tensioni_B.Monoflop10 *
       sim_correnti_tensioni_B.Integrator31) +
      (sim_correnti_tensioni_B.Input9[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator31);

   /* Programmable Value : 'sim_correnti_tensioni/Input10' */
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
   sim_correnti_tensioni_B.Input10[0] = plxGetProgrammableValueData(11, 0);
   sim_correnti_tensioni_B.Input10[1] = plxGetProgrammableValueData(11, 1);
   sim_correnti_tensioni_B.Input10[2] = plxGetProgrammableValueData(11, 2);
   sim_correnti_tensioni_B.Input10[3] = plxGetProgrammableValueData(11, 3);
   sim_correnti_tensioni_B.Input10[4] = plxGetProgrammableValueData(11, 4);
   sim_correnti_tensioni_B.Input10[5] = plxGetProgrammableValueData(11, 5);
   sim_correnti_tensioni_B.Input10[6] = plxGetProgrammableValueData(11, 6);
   sim_correnti_tensioni_B.Input10[7] = plxGetProgrammableValueUpdateFlag(11);

   /* Integrator : 'sim_correnti_tensioni/Integrator35' */
   if (sim_correnti_tensioni_X.Integrator35_i1_first)
   {
      sim_correnti_tensioni_X.Integrator35_x =
         sim_correnti_tensioni_B.Input10[3];
   }
   if (sim_correnti_tensioni_X.Integrator35_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator35_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator35_x -= 0.;
      sim_correnti_tensioni_X.Integrator35_x =
         sim_correnti_tensioni_X.Integrator35_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator35_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator35 =
      sim_correnti_tensioni_X.Integrator35_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator34' */
   if (sim_correnti_tensioni_X.Integrator34_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator34_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator34_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator34_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator34 =
      sim_correnti_tensioni_X.Integrator34_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator36' */
   if (sim_correnti_tensioni_X.Integrator36_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator36_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator36_x -= -0.5;
      sim_correnti_tensioni_X.Integrator36_x =
         sim_correnti_tensioni_X.Integrator36_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator36_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator36 =
      sim_correnti_tensioni_X.Integrator36_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator11' */
   if (0. > sim_correnti_tensioni_B.Integrator36)
      sim_correnti_tensioni_B.Comparator11 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator36)
      sim_correnti_tensioni_B.Comparator11 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop11'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop11 &&
       (sim_correnti_tensioni_B.Comparator11))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[10] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[10] > 0)
      {
         sim_correnti_tensioni_B.Monoflop11 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[10] == 0)
   {
      sim_correnti_tensioni_B.Monoflop11 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum11'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product41'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction10'
    *  Product : 'sim_correnti_tensioni/Product42'
    *  Product : 'sim_correnti_tensioni/Product43'
    */
   sim_correnti_tensioni_B.Sum11 =
      (sim_correnti_tensioni_B.Input10[1] *
       sin(sim_correnti_tensioni_B.Integrator35) *
       sim_correnti_tensioni_B.Integrator34) +
      (sim_correnti_tensioni_B.Input10[4] *
       sim_correnti_tensioni_B.Monoflop11 *
       sim_correnti_tensioni_B.Integrator34) +
      (sim_correnti_tensioni_B.Input10[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator34);

   /* Programmable Value : 'sim_correnti_tensioni/Input11' */
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
   sim_correnti_tensioni_B.Input11[0] = plxGetProgrammableValueData(12, 0);
   sim_correnti_tensioni_B.Input11[1] = plxGetProgrammableValueData(12, 1);
   sim_correnti_tensioni_B.Input11[2] = plxGetProgrammableValueData(12, 2);
   sim_correnti_tensioni_B.Input11[3] = plxGetProgrammableValueData(12, 3);
   sim_correnti_tensioni_B.Input11[4] = plxGetProgrammableValueData(12, 4);
   sim_correnti_tensioni_B.Input11[5] = plxGetProgrammableValueData(12, 5);
   sim_correnti_tensioni_B.Input11[6] = plxGetProgrammableValueData(12, 6);
   sim_correnti_tensioni_B.Input11[7] = plxGetProgrammableValueUpdateFlag(12);

   /* Integrator : 'sim_correnti_tensioni/Integrator38' */
   if (sim_correnti_tensioni_X.Integrator38_i1_first)
   {
      sim_correnti_tensioni_X.Integrator38_x =
         sim_correnti_tensioni_B.Input11[3];
   }
   if (sim_correnti_tensioni_X.Integrator38_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator38_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator38_x -= 0.;
      sim_correnti_tensioni_X.Integrator38_x =
         sim_correnti_tensioni_X.Integrator38_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator38_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator38 =
      sim_correnti_tensioni_X.Integrator38_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator37' */
   if (sim_correnti_tensioni_X.Integrator37_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator37_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator37_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator37_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator37 =
      sim_correnti_tensioni_X.Integrator37_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator39' */
   if (sim_correnti_tensioni_X.Integrator39_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator39_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator39_x -= -0.5;
      sim_correnti_tensioni_X.Integrator39_x =
         sim_correnti_tensioni_X.Integrator39_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator39_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator39 =
      sim_correnti_tensioni_X.Integrator39_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator12' */
   if (0. > sim_correnti_tensioni_B.Integrator39)
      sim_correnti_tensioni_B.Comparator12 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator39)
      sim_correnti_tensioni_B.Comparator12 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop12'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop12 &&
       (sim_correnti_tensioni_B.Comparator12))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[11] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[11] > 0)
      {
         sim_correnti_tensioni_B.Monoflop12 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[11] == 0)
   {
      sim_correnti_tensioni_B.Monoflop12 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum12'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product45'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction11'
    *  Product : 'sim_correnti_tensioni/Product46'
    *  Product : 'sim_correnti_tensioni/Product47'
    */
   sim_correnti_tensioni_B.Sum12 =
      (sim_correnti_tensioni_B.Input11[1] *
       sin(sim_correnti_tensioni_B.Integrator38) *
       sim_correnti_tensioni_B.Integrator37) +
      (sim_correnti_tensioni_B.Input11[4] *
       sim_correnti_tensioni_B.Monoflop12 *
       sim_correnti_tensioni_B.Integrator37) +
      (sim_correnti_tensioni_B.Input11[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator37);

   /* Programmable Value : 'sim_correnti_tensioni/Input12' */
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
   sim_correnti_tensioni_B.Input12[0] = plxGetProgrammableValueData(13, 0);
   sim_correnti_tensioni_B.Input12[1] = plxGetProgrammableValueData(13, 1);
   sim_correnti_tensioni_B.Input12[2] = plxGetProgrammableValueData(13, 2);
   sim_correnti_tensioni_B.Input12[3] = plxGetProgrammableValueData(13, 3);
   sim_correnti_tensioni_B.Input12[4] = plxGetProgrammableValueData(13, 4);
   sim_correnti_tensioni_B.Input12[5] = plxGetProgrammableValueData(13, 5);
   sim_correnti_tensioni_B.Input12[6] = plxGetProgrammableValueData(13, 6);
   sim_correnti_tensioni_B.Input12[7] = plxGetProgrammableValueUpdateFlag(13);

   /* Integrator : 'sim_correnti_tensioni/Integrator41' */
   if (sim_correnti_tensioni_X.Integrator41_i1_first)
   {
      sim_correnti_tensioni_X.Integrator41_x =
         sim_correnti_tensioni_B.Input12[3];
   }
   if (sim_correnti_tensioni_X.Integrator41_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator41_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator41_x -= 0.;
      sim_correnti_tensioni_X.Integrator41_x =
         sim_correnti_tensioni_X.Integrator41_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator41_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator41 =
      sim_correnti_tensioni_X.Integrator41_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator40' */
   if (sim_correnti_tensioni_X.Integrator40_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator40_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator40_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator40_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator40 =
      sim_correnti_tensioni_X.Integrator40_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator42' */
   if (sim_correnti_tensioni_X.Integrator42_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator42_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator42_x -= -0.5;
      sim_correnti_tensioni_X.Integrator42_x =
         sim_correnti_tensioni_X.Integrator42_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator42_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator42 =
      sim_correnti_tensioni_X.Integrator42_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator13' */
   if (0. > sim_correnti_tensioni_B.Integrator42)
      sim_correnti_tensioni_B.Comparator13 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator42)
      sim_correnti_tensioni_B.Comparator13 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop13'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop13 &&
       (sim_correnti_tensioni_B.Comparator13))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[12] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[12] > 0)
      {
         sim_correnti_tensioni_B.Monoflop13 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[12] == 0)
   {
      sim_correnti_tensioni_B.Monoflop13 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum13'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product49'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction12'
    *  Product : 'sim_correnti_tensioni/Product50'
    *  Product : 'sim_correnti_tensioni/Product51'
    */
   sim_correnti_tensioni_B.Sum13 =
      (sim_correnti_tensioni_B.Input12[1] *
       sin(sim_correnti_tensioni_B.Integrator41) *
       sim_correnti_tensioni_B.Integrator40) +
      (sim_correnti_tensioni_B.Input12[4] *
       sim_correnti_tensioni_B.Monoflop13 *
       sim_correnti_tensioni_B.Integrator40) +
      (sim_correnti_tensioni_B.Input12[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator40);

   /* Programmable Value : 'sim_correnti_tensioni/Input13' */
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
   sim_correnti_tensioni_B.Input13[0] = plxGetProgrammableValueData(14, 0);
   sim_correnti_tensioni_B.Input13[1] = plxGetProgrammableValueData(14, 1);
   sim_correnti_tensioni_B.Input13[2] = plxGetProgrammableValueData(14, 2);
   sim_correnti_tensioni_B.Input13[3] = plxGetProgrammableValueData(14, 3);
   sim_correnti_tensioni_B.Input13[4] = plxGetProgrammableValueData(14, 4);
   sim_correnti_tensioni_B.Input13[5] = plxGetProgrammableValueData(14, 5);
   sim_correnti_tensioni_B.Input13[6] = plxGetProgrammableValueData(14, 6);
   sim_correnti_tensioni_B.Input13[7] = plxGetProgrammableValueUpdateFlag(14);

   /* Integrator : 'sim_correnti_tensioni/Integrator44' */
   if (sim_correnti_tensioni_X.Integrator44_i1_first)
   {
      sim_correnti_tensioni_X.Integrator44_x =
         sim_correnti_tensioni_B.Input13[3];
   }
   if (sim_correnti_tensioni_X.Integrator44_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator44_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator44_x -= 0.;
      sim_correnti_tensioni_X.Integrator44_x =
         sim_correnti_tensioni_X.Integrator44_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator44_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator44 =
      sim_correnti_tensioni_X.Integrator44_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator43' */
   if (sim_correnti_tensioni_X.Integrator43_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator43_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator43_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator43_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator43 =
      sim_correnti_tensioni_X.Integrator43_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator45' */
   if (sim_correnti_tensioni_X.Integrator45_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator45_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator45_x -= -0.5;
      sim_correnti_tensioni_X.Integrator45_x =
         sim_correnti_tensioni_X.Integrator45_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator45_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator45 =
      sim_correnti_tensioni_X.Integrator45_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator14' */
   if (0. > sim_correnti_tensioni_B.Integrator45)
      sim_correnti_tensioni_B.Comparator14 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator45)
      sim_correnti_tensioni_B.Comparator14 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop14'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop14 &&
       (sim_correnti_tensioni_B.Comparator14))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[13] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[13] > 0)
      {
         sim_correnti_tensioni_B.Monoflop14 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[13] == 0)
   {
      sim_correnti_tensioni_B.Monoflop14 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum14'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product53'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction13'
    *  Product : 'sim_correnti_tensioni/Product54'
    *  Product : 'sim_correnti_tensioni/Product55'
    */
   sim_correnti_tensioni_B.Sum14 =
      (sim_correnti_tensioni_B.Input13[1] *
       sin(sim_correnti_tensioni_B.Integrator44) *
       sim_correnti_tensioni_B.Integrator43) +
      (sim_correnti_tensioni_B.Input13[4] *
       sim_correnti_tensioni_B.Monoflop14 *
       sim_correnti_tensioni_B.Integrator43) +
      (sim_correnti_tensioni_B.Input13[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator43);

   /* Programmable Value : 'sim_correnti_tensioni/Input14' */
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
   sim_correnti_tensioni_B.Input14[0] = plxGetProgrammableValueData(15, 0);
   sim_correnti_tensioni_B.Input14[1] = plxGetProgrammableValueData(15, 1);
   sim_correnti_tensioni_B.Input14[2] = plxGetProgrammableValueData(15, 2);
   sim_correnti_tensioni_B.Input14[3] = plxGetProgrammableValueData(15, 3);
   sim_correnti_tensioni_B.Input14[4] = plxGetProgrammableValueData(15, 4);
   sim_correnti_tensioni_B.Input14[5] = plxGetProgrammableValueData(15, 5);
   sim_correnti_tensioni_B.Input14[6] = plxGetProgrammableValueData(15, 6);
   sim_correnti_tensioni_B.Input14[7] = plxGetProgrammableValueUpdateFlag(15);

   /* Integrator : 'sim_correnti_tensioni/Integrator47' */
   if (sim_correnti_tensioni_X.Integrator47_i1_first)
   {
      sim_correnti_tensioni_X.Integrator47_x =
         sim_correnti_tensioni_B.Input14[3];
   }
   if (sim_correnti_tensioni_X.Integrator47_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator47_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator47_x -= 0.;
      sim_correnti_tensioni_X.Integrator47_x =
         sim_correnti_tensioni_X.Integrator47_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator47_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator47 =
      sim_correnti_tensioni_X.Integrator47_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator46' */
   if (sim_correnti_tensioni_X.Integrator46_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator46_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator46_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator46_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator46 =
      sim_correnti_tensioni_X.Integrator46_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator48' */
   if (sim_correnti_tensioni_X.Integrator48_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator48_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator48_x -= -0.5;
      sim_correnti_tensioni_X.Integrator48_x =
         sim_correnti_tensioni_X.Integrator48_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator48_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator48 =
      sim_correnti_tensioni_X.Integrator48_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator15' */
   if (0. > sim_correnti_tensioni_B.Integrator48)
      sim_correnti_tensioni_B.Comparator15 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator48)
      sim_correnti_tensioni_B.Comparator15 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop15'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop15 &&
       (sim_correnti_tensioni_B.Comparator15))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[14] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[14] > 0)
      {
         sim_correnti_tensioni_B.Monoflop15 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[14] == 0)
   {
      sim_correnti_tensioni_B.Monoflop15 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum15'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product57'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction14'
    *  Product : 'sim_correnti_tensioni/Product58'
    *  Product : 'sim_correnti_tensioni/Product59'
    */
   sim_correnti_tensioni_B.Sum15 =
      (sim_correnti_tensioni_B.Input14[1] *
       sin(sim_correnti_tensioni_B.Integrator47) *
       sim_correnti_tensioni_B.Integrator46) +
      (sim_correnti_tensioni_B.Input14[4] *
       sim_correnti_tensioni_B.Monoflop15 *
       sim_correnti_tensioni_B.Integrator46) +
      (sim_correnti_tensioni_B.Input14[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator46);

   /* Programmable Value : 'sim_correnti_tensioni/Input15' */
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
   sim_correnti_tensioni_B.Input15[0] = plxGetProgrammableValueData(16, 0);
   sim_correnti_tensioni_B.Input15[1] = plxGetProgrammableValueData(16, 1);
   sim_correnti_tensioni_B.Input15[2] = plxGetProgrammableValueData(16, 2);
   sim_correnti_tensioni_B.Input15[3] = plxGetProgrammableValueData(16, 3);
   sim_correnti_tensioni_B.Input15[4] = plxGetProgrammableValueData(16, 4);
   sim_correnti_tensioni_B.Input15[5] = plxGetProgrammableValueData(16, 5);
   sim_correnti_tensioni_B.Input15[6] = plxGetProgrammableValueData(16, 6);
   sim_correnti_tensioni_B.Input15[7] = plxGetProgrammableValueUpdateFlag(16);

   /* Integrator : 'sim_correnti_tensioni/Integrator50' */
   if (sim_correnti_tensioni_X.Integrator50_i1_first)
   {
      sim_correnti_tensioni_X.Integrator50_x =
         sim_correnti_tensioni_B.Input15[3];
   }
   if (sim_correnti_tensioni_X.Integrator50_x > 6.28318530717958623 ||
       sim_correnti_tensioni_X.Integrator50_x < 0.)
   {
      double span = 6.28318530717958623 - (0.);
      sim_correnti_tensioni_X.Integrator50_x -= 0.;
      sim_correnti_tensioni_X.Integrator50_x =
         sim_correnti_tensioni_X.Integrator50_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator50_x/
                                                             span) + (0.);
   }
   sim_correnti_tensioni_B.Integrator50 =
      sim_correnti_tensioni_X.Integrator50_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator49' */
   if (sim_correnti_tensioni_X.Integrator49_x > 1.)
   {
      sim_correnti_tensioni_X.Integrator49_x = 1.;
   }
   else if (sim_correnti_tensioni_X.Integrator49_x < 0.)
   {
      sim_correnti_tensioni_X.Integrator49_x = 0.;
   }
   sim_correnti_tensioni_B.Integrator49 =
      sim_correnti_tensioni_X.Integrator49_x;

   /* Integrator : 'sim_correnti_tensioni/Integrator51' */
   if (sim_correnti_tensioni_X.Integrator51_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator51_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator51_x -= -0.5;
      sim_correnti_tensioni_X.Integrator51_x =
         sim_correnti_tensioni_X.Integrator51_x - span*floor(
                                                             sim_correnti_tensioni_X.Integrator51_x/
                                                             span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator51 =
      sim_correnti_tensioni_X.Integrator51_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator16' */
   if (0. > sim_correnti_tensioni_B.Integrator51)
      sim_correnti_tensioni_B.Comparator16 = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator51)
      sim_correnti_tensioni_B.Comparator16 = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop16'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant6'
    */
   if (!sim_correnti_tensioni_X.Monoflop16 &&
       (sim_correnti_tensioni_B.Comparator16))
   {
      double ticks = (0.000100000000000000005)/0.000100000000000000005;
      if (ticks < 0)
      {
         ticks = 0;
      }
      else if (ticks > UINT32_MAX)
      {
         ticks = UINT32_MAX;
      }
      sim_correnti_tensioni_D_uint32_t[15] = floor(ticks);
      if (sim_correnti_tensioni_D_uint32_t[15] > 0)
      {
         sim_correnti_tensioni_B.Monoflop16 = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[15] == 0)
   {
      sim_correnti_tensioni_B.Monoflop16 = 0;
   }

   /* Sum : 'sim_correnti_tensioni/Sum16'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product61'
    *  Trigonometric Function : 'sim_correnti_tensioni/Trigonometric\nFunction15'
    *  Product : 'sim_correnti_tensioni/Product62'
    *  Product : 'sim_correnti_tensioni/Product63'
    */
   sim_correnti_tensioni_B.Sum16 =
      (sim_correnti_tensioni_B.Input15[1] *
       sin(sim_correnti_tensioni_B.Integrator50) *
       sim_correnti_tensioni_B.Integrator49) +
      (sim_correnti_tensioni_B.Input15[4] *
       sim_correnti_tensioni_B.Monoflop16 *
       sim_correnti_tensioni_B.Integrator49) +
      (sim_correnti_tensioni_B.Input15[6] * sim_correnti_tensioni_B.C_Script *
       sim_correnti_tensioni_B.Integrator49);

   /* Multiport Signal Switch : 'sim_correnti_tensioni/Multiport Signal Switch'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input17'
    */
   sim_correnti_tensioni_B.MultiportSignalSwitch_bool = false;
   sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t =
      (int32_t)(plxGetProgrammableValueData(1, 0));
   switch (sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t)
   {
   default:
      sim_correnti_tensioni_B.MultiportSignalSwitch_bool = true;
      sim_correnti_tensioni_B.MultiportSignalSwitch_int32_t = 1;

   // Fall through, no break;
   case 1:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum1;
      break;

   case 2:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum2;
      break;

   case 3:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum3;
      break;

   case 4:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum4;
      break;

   case 5:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum5;
      break;

   case 6:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum6;
      break;

   case 7:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum7;
      break;

   case 8:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum8;
      break;

   case 9:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum9;
      break;

   case 10:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum10;
      break;

   case 11:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum11;
      break;

   case 12:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum12;
      break;

   case 13:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum13;
      break;

   case 14:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum14;
      break;

   case 15:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum15;
      break;

   case 16:
      sim_correnti_tensioni_B.MultiportSignalSwitch_double =
         sim_correnti_tensioni_B.Sum16;
      break;
   }
   if (sim_correnti_tensioni_subTaskHit[0])
   {
      /* Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
      sim_correnti_tensioni_B.PulseGenerator =
         sim_correnti_tensioni_D_uint32_t[16] < 1 ? 5. : -5.;
   }

   /* Data Capture : 'sim_correnti_tensioni/Capture1' */
   {
      double data[] = {
         sim_correnti_tensioni_B.MultiportSignalSwitch_double
      };
      plxUpdateDataCapture(0, sim_correnti_tensioni_B.PulseGenerator, data);
   }

   /* Analog Out : 'sim_correnti_tensioni/Analog Out5' */
   setAnalogOut(1, sim_correnti_tensioni_B.Sum2);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out6' */
   setAnalogOut(2, sim_correnti_tensioni_B.Sum3);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out7' */
   setAnalogOut(3, sim_correnti_tensioni_B.Sum4);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out8' */
   setAnalogOut(4, sim_correnti_tensioni_B.Sum5);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out9' */
   setAnalogOut(5, sim_correnti_tensioni_B.Sum6);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out10' */
   setAnalogOut(6, sim_correnti_tensioni_B.Sum7);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out11' */
   setAnalogOut(7, sim_correnti_tensioni_B.Sum8);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out12' */
   setAnalogOut(8, sim_correnti_tensioni_B.Sum9);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out13' */
   setAnalogOut(9, sim_correnti_tensioni_B.Sum10);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out14' */
   setAnalogOut(10, sim_correnti_tensioni_B.Sum11);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out15' */
   setAnalogOut(11, sim_correnti_tensioni_B.Sum12);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out16' */
   setAnalogOut(12, sim_correnti_tensioni_B.Sum13);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out17' */
   setAnalogOut(13, sim_correnti_tensioni_B.Sum14);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out18' */
   setAnalogOut(14, sim_correnti_tensioni_B.Sum15);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out19' */
   setAnalogOut(15, sim_correnti_tensioni_B.Sum16);
   /* Programmable Value : 'sim_correnti_tensioni/Input16' */
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
   /* Constant : 'sim_correnti_tensioni/White Noise/Width' */
   sim_correnti_tensioni_B.Width = 2.00010000000000021;

   /* Product : 'sim_correnti_tensioni/Product19'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product19 =
      (plxGetProgrammableValueData(17,
                                   0)) * sim_correnti_tensioni_B.Input0[0];

   /* Product : 'sim_correnti_tensioni/Product20'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product20 =
      (plxGetProgrammableValueData(17,
                                   1)) * sim_correnti_tensioni_B.Input1[0];

   /* Product : 'sim_correnti_tensioni/Product21'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product21 =
      (plxGetProgrammableValueData(17,
                                   2)) * sim_correnti_tensioni_B.Input2[0];

   /* Product : 'sim_correnti_tensioni/Product22'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product22 =
      (plxGetProgrammableValueData(17,
                                   3)) * sim_correnti_tensioni_B.Input3[0];

   /* Product : 'sim_correnti_tensioni/Product23'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product23 =
      (plxGetProgrammableValueData(17,
                                   4)) * sim_correnti_tensioni_B.Input4[0];

   /* Product : 'sim_correnti_tensioni/Product24'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product24 =
      (plxGetProgrammableValueData(17,
                                   5)) * sim_correnti_tensioni_B.Input5[0];

   /* Product : 'sim_correnti_tensioni/Product25'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product25 =
      (plxGetProgrammableValueData(17,
                                   6)) * sim_correnti_tensioni_B.Input6[0];

   /* Product : 'sim_correnti_tensioni/Product28'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product28 =
      (plxGetProgrammableValueData(17,
                                   7)) * sim_correnti_tensioni_B.Input7[0];

   /* Product : 'sim_correnti_tensioni/Product32'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product32 =
      (plxGetProgrammableValueData(17,
                                   8)) * sim_correnti_tensioni_B.Input8[0];

   /* Product : 'sim_correnti_tensioni/Product36'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product36 =
      (plxGetProgrammableValueData(17,
                                   9)) * sim_correnti_tensioni_B.Input9[0];

   /* Product : 'sim_correnti_tensioni/Product40'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product40 =
      (plxGetProgrammableValueData(17,
                                   10)) * sim_correnti_tensioni_B.Input10[0];

   /* Product : 'sim_correnti_tensioni/Product44'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product44 =
      (plxGetProgrammableValueData(17,
                                   11)) * sim_correnti_tensioni_B.Input11[0];

   /* Product : 'sim_correnti_tensioni/Product48'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product48 =
      (plxGetProgrammableValueData(17,
                                   12)) * sim_correnti_tensioni_B.Input12[0];

   /* Product : 'sim_correnti_tensioni/Product52'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product52 =
      (plxGetProgrammableValueData(17,
                                   13)) * sim_correnti_tensioni_B.Input13[0];

   /* Product : 'sim_correnti_tensioni/Product56'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product56 =
      (plxGetProgrammableValueData(17,
                                   14)) * sim_correnti_tensioni_B.Input14[0];

   /* Product : 'sim_correnti_tensioni/Product60'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input16'
    */
   sim_correnti_tensioni_B.Product60 =
      (plxGetProgrammableValueData(17,
                                   15)) * sim_correnti_tensioni_B.Input15[0];
   if (sim_correnti_tensioni_errorStatus)
   {
      return;
   }

   /* Update for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_0_cScriptUpdate(&sim_correnti_tensioni_cScriptStruct[
                                            0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator7' */
   sim_correnti_tensioni_X.Integrator7_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
   if (sim_correnti_tensioni_D_uint32_t[0] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[0] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop1 = sim_correnti_tensioni_B.Comparator1;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator9' */
   sim_correnti_tensioni_X.Integrator9_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop2' */
   if (sim_correnti_tensioni_D_uint32_t[1] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[1] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop2 = sim_correnti_tensioni_B.Comparator2;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator11' */
   sim_correnti_tensioni_X.Integrator11_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop3' */
   if (sim_correnti_tensioni_D_uint32_t[2] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[2] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop3 = sim_correnti_tensioni_B.Comparator3;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator14' */
   sim_correnti_tensioni_X.Integrator14_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop4' */
   if (sim_correnti_tensioni_D_uint32_t[3] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[3] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop4 = sim_correnti_tensioni_B.Comparator4;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator17' */
   sim_correnti_tensioni_X.Integrator17_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop5' */
   if (sim_correnti_tensioni_D_uint32_t[4] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[4] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop5 = sim_correnti_tensioni_B.Comparator5;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator20' */
   sim_correnti_tensioni_X.Integrator20_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop6' */
   if (sim_correnti_tensioni_D_uint32_t[5] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[5] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop6 = sim_correnti_tensioni_B.Comparator6;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator23' */
   sim_correnti_tensioni_X.Integrator23_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop7' */
   if (sim_correnti_tensioni_D_uint32_t[6] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[6] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop7 = sim_correnti_tensioni_B.Comparator7;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator26' */
   sim_correnti_tensioni_X.Integrator26_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop8' */
   if (sim_correnti_tensioni_D_uint32_t[7] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[7] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop8 = sim_correnti_tensioni_B.Comparator8;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator29' */
   sim_correnti_tensioni_X.Integrator29_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop9' */
   if (sim_correnti_tensioni_D_uint32_t[8] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[8] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop9 = sim_correnti_tensioni_B.Comparator9;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator32' */
   sim_correnti_tensioni_X.Integrator32_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop10' */
   if (sim_correnti_tensioni_D_uint32_t[9] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[9] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop10 = sim_correnti_tensioni_B.Comparator10;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator35' */
   sim_correnti_tensioni_X.Integrator35_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop11' */
   if (sim_correnti_tensioni_D_uint32_t[10] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[10] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop11 = sim_correnti_tensioni_B.Comparator11;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator38' */
   sim_correnti_tensioni_X.Integrator38_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop12' */
   if (sim_correnti_tensioni_D_uint32_t[11] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[11] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop12 = sim_correnti_tensioni_B.Comparator12;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator41' */
   sim_correnti_tensioni_X.Integrator41_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop13' */
   if (sim_correnti_tensioni_D_uint32_t[12] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[12] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop13 = sim_correnti_tensioni_B.Comparator13;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator44' */
   sim_correnti_tensioni_X.Integrator44_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop14' */
   if (sim_correnti_tensioni_D_uint32_t[13] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[13] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop14 = sim_correnti_tensioni_B.Comparator14;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator47' */
   sim_correnti_tensioni_X.Integrator47_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop15' */
   if (sim_correnti_tensioni_D_uint32_t[14] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[14] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop15 = sim_correnti_tensioni_B.Comparator15;

   /* Update for Integrator : 'sim_correnti_tensioni/Integrator50' */
   sim_correnti_tensioni_X.Integrator50_i1_first = 0;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop16' */
   if (sim_correnti_tensioni_D_uint32_t[15] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[15] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop16 = sim_correnti_tensioni_B.Comparator16;
   if (sim_correnti_tensioni_subTaskHit[0])
   {
      /* Update for Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
      sim_correnti_tensioni_D_uint32_t[16] += 1;
      if (sim_correnti_tensioni_D_uint32_t[16] > 1)
      {
         sim_correnti_tensioni_D_uint32_t[16] = 0;
      }
   }

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

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator7' */
   sim_correnti_tensioni_deriv[1] = sim_correnti_tensioni_B.Input0[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator6' */
   if ((sim_correnti_tensioni_X.Integrator6_x >= 1. &&
        sim_correnti_tensioni_B.Product19 > 0) ||
       (sim_correnti_tensioni_X.Integrator6_x <= 0. &&
        sim_correnti_tensioni_B.Product19 < 0))
   {
      sim_correnti_tensioni_deriv[0] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[0] = sim_correnti_tensioni_B.Product19;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator4' */
   sim_correnti_tensioni_deriv[2] = sim_correnti_tensioni_B.Input0[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator9' */
   sim_correnti_tensioni_deriv[4] = sim_correnti_tensioni_B.Input1[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator8' */
   if ((sim_correnti_tensioni_X.Integrator8_x >= 1. &&
        sim_correnti_tensioni_B.Product20 > 0) ||
       (sim_correnti_tensioni_X.Integrator8_x <= 0. &&
        sim_correnti_tensioni_B.Product20 < 0))
   {
      sim_correnti_tensioni_deriv[3] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[3] = sim_correnti_tensioni_B.Product20;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator5' */
   sim_correnti_tensioni_deriv[5] = sim_correnti_tensioni_B.Input1[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator11' */
   sim_correnti_tensioni_deriv[7] = sim_correnti_tensioni_B.Input2[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator10' */
   if ((sim_correnti_tensioni_X.Integrator10_x >= 1. &&
        sim_correnti_tensioni_B.Product21 > 0) ||
       (sim_correnti_tensioni_X.Integrator10_x <= 0. &&
        sim_correnti_tensioni_B.Product21 < 0))
   {
      sim_correnti_tensioni_deriv[6] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[6] = sim_correnti_tensioni_B.Product21;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator12' */
   sim_correnti_tensioni_deriv[8] = sim_correnti_tensioni_B.Input2[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator14' */
   sim_correnti_tensioni_deriv[10] = sim_correnti_tensioni_B.Input3[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator13' */
   if ((sim_correnti_tensioni_X.Integrator13_x >= 1. &&
        sim_correnti_tensioni_B.Product22 > 0) ||
       (sim_correnti_tensioni_X.Integrator13_x <= 0. &&
        sim_correnti_tensioni_B.Product22 < 0))
   {
      sim_correnti_tensioni_deriv[9] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[9] = sim_correnti_tensioni_B.Product22;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator15' */
   sim_correnti_tensioni_deriv[11] = sim_correnti_tensioni_B.Input3[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator17' */
   sim_correnti_tensioni_deriv[13] = sim_correnti_tensioni_B.Input4[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator16' */
   if ((sim_correnti_tensioni_X.Integrator16_x >= 1. &&
        sim_correnti_tensioni_B.Product23 > 0) ||
       (sim_correnti_tensioni_X.Integrator16_x <= 0. &&
        sim_correnti_tensioni_B.Product23 < 0))
   {
      sim_correnti_tensioni_deriv[12] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[12] = sim_correnti_tensioni_B.Product23;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator18' */
   sim_correnti_tensioni_deriv[14] = sim_correnti_tensioni_B.Input4[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator20' */
   sim_correnti_tensioni_deriv[16] = sim_correnti_tensioni_B.Input5[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator19' */
   if ((sim_correnti_tensioni_X.Integrator19_x >= 1. &&
        sim_correnti_tensioni_B.Product24 > 0) ||
       (sim_correnti_tensioni_X.Integrator19_x <= 0. &&
        sim_correnti_tensioni_B.Product24 < 0))
   {
      sim_correnti_tensioni_deriv[15] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[15] = sim_correnti_tensioni_B.Product24;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator21' */
   sim_correnti_tensioni_deriv[17] = sim_correnti_tensioni_B.Input5[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator23' */
   sim_correnti_tensioni_deriv[19] = sim_correnti_tensioni_B.Input6[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator22' */
   if ((sim_correnti_tensioni_X.Integrator22_x >= 1. &&
        sim_correnti_tensioni_B.Product25 > 0) ||
       (sim_correnti_tensioni_X.Integrator22_x <= 0. &&
        sim_correnti_tensioni_B.Product25 < 0))
   {
      sim_correnti_tensioni_deriv[18] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[18] = sim_correnti_tensioni_B.Product25;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator24' */
   sim_correnti_tensioni_deriv[20] = sim_correnti_tensioni_B.Input6[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator26' */
   sim_correnti_tensioni_deriv[22] = sim_correnti_tensioni_B.Input7[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator25' */
   if ((sim_correnti_tensioni_X.Integrator25_x >= 1. &&
        sim_correnti_tensioni_B.Product28 > 0) ||
       (sim_correnti_tensioni_X.Integrator25_x <= 0. &&
        sim_correnti_tensioni_B.Product28 < 0))
   {
      sim_correnti_tensioni_deriv[21] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[21] = sim_correnti_tensioni_B.Product28;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator27' */
   sim_correnti_tensioni_deriv[23] = sim_correnti_tensioni_B.Input7[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator29' */
   sim_correnti_tensioni_deriv[25] = sim_correnti_tensioni_B.Input8[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator28' */
   if ((sim_correnti_tensioni_X.Integrator28_x >= 1. &&
        sim_correnti_tensioni_B.Product32 > 0) ||
       (sim_correnti_tensioni_X.Integrator28_x <= 0. &&
        sim_correnti_tensioni_B.Product32 < 0))
   {
      sim_correnti_tensioni_deriv[24] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[24] = sim_correnti_tensioni_B.Product32;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator30' */
   sim_correnti_tensioni_deriv[26] = sim_correnti_tensioni_B.Input8[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator32' */
   sim_correnti_tensioni_deriv[28] = sim_correnti_tensioni_B.Input9[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator31' */
   if ((sim_correnti_tensioni_X.Integrator31_x >= 1. &&
        sim_correnti_tensioni_B.Product36 > 0) ||
       (sim_correnti_tensioni_X.Integrator31_x <= 0. &&
        sim_correnti_tensioni_B.Product36 < 0))
   {
      sim_correnti_tensioni_deriv[27] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[27] = sim_correnti_tensioni_B.Product36;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator33' */
   sim_correnti_tensioni_deriv[29] = sim_correnti_tensioni_B.Input9[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator35' */
   sim_correnti_tensioni_deriv[31] = sim_correnti_tensioni_B.Input10[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator34' */
   if ((sim_correnti_tensioni_X.Integrator34_x >= 1. &&
        sim_correnti_tensioni_B.Product40 > 0) ||
       (sim_correnti_tensioni_X.Integrator34_x <= 0. &&
        sim_correnti_tensioni_B.Product40 < 0))
   {
      sim_correnti_tensioni_deriv[30] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[30] = sim_correnti_tensioni_B.Product40;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator36' */
   sim_correnti_tensioni_deriv[32] = sim_correnti_tensioni_B.Input10[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator38' */
   sim_correnti_tensioni_deriv[34] = sim_correnti_tensioni_B.Input11[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator37' */
   if ((sim_correnti_tensioni_X.Integrator37_x >= 1. &&
        sim_correnti_tensioni_B.Product44 > 0) ||
       (sim_correnti_tensioni_X.Integrator37_x <= 0. &&
        sim_correnti_tensioni_B.Product44 < 0))
   {
      sim_correnti_tensioni_deriv[33] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[33] = sim_correnti_tensioni_B.Product44;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator39' */
   sim_correnti_tensioni_deriv[35] = sim_correnti_tensioni_B.Input11[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator41' */
   sim_correnti_tensioni_deriv[37] = sim_correnti_tensioni_B.Input12[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator40' */
   if ((sim_correnti_tensioni_X.Integrator40_x >= 1. &&
        sim_correnti_tensioni_B.Product48 > 0) ||
       (sim_correnti_tensioni_X.Integrator40_x <= 0. &&
        sim_correnti_tensioni_B.Product48 < 0))
   {
      sim_correnti_tensioni_deriv[36] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[36] = sim_correnti_tensioni_B.Product48;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator42' */
   sim_correnti_tensioni_deriv[38] = sim_correnti_tensioni_B.Input12[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator44' */
   sim_correnti_tensioni_deriv[40] = sim_correnti_tensioni_B.Input13[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator43' */
   if ((sim_correnti_tensioni_X.Integrator43_x >= 1. &&
        sim_correnti_tensioni_B.Product52 > 0) ||
       (sim_correnti_tensioni_X.Integrator43_x <= 0. &&
        sim_correnti_tensioni_B.Product52 < 0))
   {
      sim_correnti_tensioni_deriv[39] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[39] = sim_correnti_tensioni_B.Product52;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator45' */
   sim_correnti_tensioni_deriv[41] = sim_correnti_tensioni_B.Input13[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator47' */
   sim_correnti_tensioni_deriv[43] = sim_correnti_tensioni_B.Input14[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator46' */
   if ((sim_correnti_tensioni_X.Integrator46_x >= 1. &&
        sim_correnti_tensioni_B.Product56 > 0) ||
       (sim_correnti_tensioni_X.Integrator46_x <= 0. &&
        sim_correnti_tensioni_B.Product56 < 0))
   {
      sim_correnti_tensioni_deriv[42] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[42] = sim_correnti_tensioni_B.Product56;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator48' */
   sim_correnti_tensioni_deriv[44] = sim_correnti_tensioni_B.Input14[5];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator50' */
   sim_correnti_tensioni_deriv[46] = sim_correnti_tensioni_B.Input15[2];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator49' */
   if ((sim_correnti_tensioni_X.Integrator49_x >= 1. &&
        sim_correnti_tensioni_B.Product60 > 0) ||
       (sim_correnti_tensioni_X.Integrator49_x <= 0. &&
        sim_correnti_tensioni_B.Product60 < 0))
   {
      sim_correnti_tensioni_deriv[45] = 0;
   }
   else
   {
      sim_correnti_tensioni_deriv[45] = sim_correnti_tensioni_B.Product60;
   }

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator51' */
   sim_correnti_tensioni_deriv[47] = sim_correnti_tensioni_B.Input15[5];

   /* Update continuous states */
   sim_correnti_tensioni_X.Integrator7_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[1];
   sim_correnti_tensioni_X.Integrator6_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[0];
   sim_correnti_tensioni_X.Integrator4_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[2];
   sim_correnti_tensioni_X.Integrator9_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[4];
   sim_correnti_tensioni_X.Integrator8_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[3];
   sim_correnti_tensioni_X.Integrator5_x += 0.000100000000000000005*
                                            sim_correnti_tensioni_deriv[5];
   sim_correnti_tensioni_X.Integrator11_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[7];
   sim_correnti_tensioni_X.Integrator10_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[6];
   sim_correnti_tensioni_X.Integrator12_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[8];
   sim_correnti_tensioni_X.Integrator14_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[10];
   sim_correnti_tensioni_X.Integrator13_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[9];
   sim_correnti_tensioni_X.Integrator15_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[11];
   sim_correnti_tensioni_X.Integrator17_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[13];
   sim_correnti_tensioni_X.Integrator16_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[12];
   sim_correnti_tensioni_X.Integrator18_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[14];
   sim_correnti_tensioni_X.Integrator20_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[16];
   sim_correnti_tensioni_X.Integrator19_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[15];
   sim_correnti_tensioni_X.Integrator21_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[17];
   sim_correnti_tensioni_X.Integrator23_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[19];
   sim_correnti_tensioni_X.Integrator22_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[18];
   sim_correnti_tensioni_X.Integrator24_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[20];
   sim_correnti_tensioni_X.Integrator26_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[22];
   sim_correnti_tensioni_X.Integrator25_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[21];
   sim_correnti_tensioni_X.Integrator27_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[23];
   sim_correnti_tensioni_X.Integrator29_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[25];
   sim_correnti_tensioni_X.Integrator28_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[24];
   sim_correnti_tensioni_X.Integrator30_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[26];
   sim_correnti_tensioni_X.Integrator32_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[28];
   sim_correnti_tensioni_X.Integrator31_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[27];
   sim_correnti_tensioni_X.Integrator33_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[29];
   sim_correnti_tensioni_X.Integrator35_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[31];
   sim_correnti_tensioni_X.Integrator34_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[30];
   sim_correnti_tensioni_X.Integrator36_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[32];
   sim_correnti_tensioni_X.Integrator38_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[34];
   sim_correnti_tensioni_X.Integrator37_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[33];
   sim_correnti_tensioni_X.Integrator39_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[35];
   sim_correnti_tensioni_X.Integrator41_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[37];
   sim_correnti_tensioni_X.Integrator40_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[36];
   sim_correnti_tensioni_X.Integrator42_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[38];
   sim_correnti_tensioni_X.Integrator44_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[40];
   sim_correnti_tensioni_X.Integrator43_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[39];
   sim_correnti_tensioni_X.Integrator45_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[41];
   sim_correnti_tensioni_X.Integrator47_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[43];
   sim_correnti_tensioni_X.Integrator46_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[42];
   sim_correnti_tensioni_X.Integrator48_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[44];
   sim_correnti_tensioni_X.Integrator50_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[46];
   sim_correnti_tensioni_X.Integrator49_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[45];
   sim_correnti_tensioni_X.Integrator51_x += 0.000100000000000000005*
                                             sim_correnti_tensioni_deriv[47];
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
