/*
 * Implementation file for: sim_correnti_tensioni
 * Generated with         : PLECS 4.7.1
 *                          PLECS RT Box 1 2.3.1
 * Generated on           : 23 Mar 2023 09:59:48
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
#include "plexim/hw_wrapper.h"
#include "plexim/DigitalOut.h"
#include "plexim/DigitalIn.h"
#include "plexim/AnalogIn.h"
#include "plexim/SFP.h"
#include "plexim/HIL_Framework.h"
#include "plexim/DataCapture.h"
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
static struct CScriptStruct sim_correnti_tensioni_cScriptStruct[2];
static char sim_correnti_tensioni_isMajorStep = '\001';
static const uint32_t sim_correnti_tensioni_subTaskPeriod[1]= {
   /* [0.01, 0], [0, 0] */
   1000
};
static uint32_t sim_correnti_tensioni_subTaskTick[1];
static char sim_correnti_tensioni_subTaskHit[1];
static const double sim_correnti_tensioni_UNCONNECTED = 0;
static double sim_correnti_tensioni_D_double[6];
static uint32_t sim_correnti_tensioni_D_uint32_t[3];
static double sim_correnti_tensioni_deriv[2] _ALIGN;
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
void sim_correnti_tensioni_1_cScriptStart(
                                          const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_1_cScriptOutput(
                                           const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_1_cScriptUpdate(
                                           const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_1_cScriptDerivative(
                                               const struct CScriptStruct *cScriptStruct);
void sim_correnti_tensioni_1_cScriptTerminate(
                                              const struct CScriptStruct *cScriptStruct);
static uint32_t sim_correnti_tensioni_tickLo;
static int32_t sim_correnti_tensioni_tickHi;
sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const sim_correnti_tensioni_ExtModeSignals[] = {
   &sim_correnti_tensioni_B.Sum16,
   &sim_correnti_tensioni_B.Sum17,
   &sim_correnti_tensioni_B.Sum18,
   &sim_correnti_tensioni_B.Sum7,
   &sim_correnti_tensioni_B.Sum8,
   &sim_correnti_tensioni_B.Sum9
};
#endif /* defined(EXTERNAL_MODE) */
sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X _ALIGN;
const char * sim_correnti_tensioni_errorStatus;
const double sim_correnti_tensioni_sampleTime = 1.00000000000000008e-05;
const char * const sim_correnti_tensioni_checksum =
   "4b4104fc37c7ab0dbe4c84c32cc35a2c95687aa6";
/* Target declarations */
struct PlxDataCaptureRegistry plxDataCaptureRegistry[1];
const int plxUseEthercat = 0;
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[8];
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
   plxSetupAnalogSampling(1, 0, 1.00000000000000008e-05);
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);


   /* Initialization for Programmable Value : 'sim_correnti_tensioni/InputDC3' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(0, "InputDC3", 3, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/InputDC2' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(1, "InputDC2", 3, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator4' */
   sim_correnti_tensioni_X.Integrator4_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
   sim_correnti_tensioni_X.Monoflop1 = 0.;
   sim_correnti_tensioni_D_uint32_t[0] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/InputDC1' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(2, "InputDC1", 2, programmableValueData,
                                bufferFull);
   };

   /* Initialization for C-Script : 'sim_correnti_tensioni/White Noise1/C-Script' */
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
         1e-05
      };
      static double sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      static const double paramData[] = {
         0.,2.,0.,1.00000000000000008e-05
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

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/InputDC' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(3, "InputDC", 4, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input3' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(4, "Input3", 3, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input2' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(5, "Input2", 3, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Integrator : 'sim_correnti_tensioni/Integrator3' */
   sim_correnti_tensioni_X.Integrator3_x = 0.;

   /* Initialization for Monoflop : 'sim_correnti_tensioni/Monoflop' */
   sim_correnti_tensioni_X.Monoflop = 0.;
   sim_correnti_tensioni_D_uint32_t[1] = 0;

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input1' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(6, "Input1", 2, programmableValueData,
                                bufferFull);
   };

   /* Initialization for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   {
      static int numInputSignals[] = {
         1
      };
      static const double* inputPtrs[] = {
         &sim_correnti_tensioni_B.Width_1
      };
      static const double** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static double* outputPtrs[] = {
         &sim_correnti_tensioni_B.C_Script_1
      };
      static double** outputs[] = {
         &outputPtrs[0]
      };
      static double nextSampleHit;
      static const char * sampleHits[] = {
         &sim_correnti_tensioni_isMajorStep
      };
      static double sampleTimePeriods[] = {
         1e-05
      };
      static double sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      static const double paramData[] = {
         0.,2.,0.,1.00000000000000008e-05
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
      sim_correnti_tensioni_cScriptStruct[1].isMajorTimeStep = 1;
      sim_correnti_tensioni_cScriptStruct[1].numInputTerminals = 1;
      sim_correnti_tensioni_cScriptStruct[1].numInputSignals =
         numInputSignals;
      sim_correnti_tensioni_cScriptStruct[1].inputs = inputs;
      sim_correnti_tensioni_cScriptStruct[1].numOutputTerminals = 1;
      sim_correnti_tensioni_cScriptStruct[1].numOutputSignals =
         numOutputSignals;
      sim_correnti_tensioni_cScriptStruct[1].outputs = outputs;
      sim_correnti_tensioni_cScriptStruct[1].numContStates = 0;
      sim_correnti_tensioni_cScriptStruct[1].contStates = NULL;
      sim_correnti_tensioni_cScriptStruct[1].contDerivs = NULL;
      sim_correnti_tensioni_cScriptStruct[1].numDiscStates = 1;
      sim_correnti_tensioni_cScriptStruct[1].discStates =
         &sim_correnti_tensioni_X.C_Script_1;
      sim_correnti_tensioni_cScriptStruct[1].numZCSignals = 0;
      sim_correnti_tensioni_cScriptStruct[1].numParameters = 4;
      sim_correnti_tensioni_cScriptStruct[1].paramNumDims = paramNumDims;
      sim_correnti_tensioni_cScriptStruct[1].paramDims = paramDimPtr;
      sim_correnti_tensioni_cScriptStruct[1].paramNumElements =
         paramNumElements;
      sim_correnti_tensioni_cScriptStruct[1].paramRealData = paramDataPtr;
      sim_correnti_tensioni_cScriptStruct[1].paramStringData =
         paramStringDataPtr;
      sim_correnti_tensioni_cScriptStruct[1].numSampleTimes = 1;
      sim_correnti_tensioni_cScriptStruct[1].sampleTimePeriods =
         sampleTimePeriods;
      sim_correnti_tensioni_cScriptStruct[1].sampleTimeOffsets =
         sampleTimeOffsets;
      sim_correnti_tensioni_cScriptStruct[1].numSampleTimes = 1;
      sim_correnti_tensioni_cScriptStruct[1].sampleHits = sampleHits;
      sim_correnti_tensioni_cScriptStruct[1].nextSampleHit = &nextSampleHit;
      sim_correnti_tensioni_cScriptStruct[1].errorStatus = &errorStatus;
      sim_correnti_tensioni_cScriptStruct[1].warningStatus = &warningStatus;
      sim_correnti_tensioni_cScriptStruct[1].rangeErrorMsg = &rangeErrorMsg;
      sim_correnti_tensioni_1_cScriptStart(
                                           &sim_correnti_tensioni_cScriptStruct[
                                              1]);
      if (*sim_correnti_tensioni_cScriptStruct[1].errorStatus)
         sim_correnti_tensioni_errorStatus =
            *sim_correnti_tensioni_cScriptStruct[1].errorStatus;
   }

   /* Initialization for Programmable Value : 'sim_correnti_tensioni/Input' */
   {
      static double programmableValueData[] = {
         1.00000000000000000e+00, 1.00000000000000000e+00,
         1.00000000000000000e+00, 1.00000000000000000e+00
      };
      static int bufferFull[2] = {
         0, 0
      };
      plxSetupProgrammableValue(7, "Input", 2, programmableValueData,
                                bufferFull);
   };

   /* Initialization for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave' */
   sim_correnti_tensioni_D_double[0] = sin(314.159265358979326*0.);
   sim_correnti_tensioni_D_double[1] = cos(314.159265358979326*0.);

   /* Initialization for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave1' */
   sim_correnti_tensioni_D_double[2] = sin(314.159265358979326*0.);
   sim_correnti_tensioni_D_double[3] = cos(314.159265358979326*0.);

   /* Initialization for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave2' */
   sim_correnti_tensioni_D_double[4] = sin(314.159265358979326*0.);
   sim_correnti_tensioni_D_double[5] = cos(314.159265358979326*0.);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out1' */
   setupAnalogOut(0, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out2' */
   setupAnalogOut(1, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out3' */
   setupAnalogOut(2, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out4' */
   setupAnalogOut(3, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out5' */
   setupAnalogOut(4, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out6' */
   setupAnalogOut(5, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);

   /* Initialization for Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
   sim_correnti_tensioni_D_uint32_t[2] = 0;

   /* Initialization for Analog Out : 'sim_correnti_tensioni/Analog Out7' */
   setupAnalogOut(15, 1.000000000e+00f, 0.000000000e+00f, -inf, inf);
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

   /* Programmable Value : 'sim_correnti_tensioni/InputDC3' */
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
   sim_correnti_tensioni_B.InputDC3[0] = plxGetProgrammableValueData(0, 0);
   sim_correnti_tensioni_B.InputDC3[1] = plxGetProgrammableValueData(0, 1);
   sim_correnti_tensioni_B.InputDC3[2] = plxGetProgrammableValueData(0, 2);
   sim_correnti_tensioni_B.InputDC3[3] = plxGetProgrammableValueUpdateFlag(0);

   /* Product : 'sim_correnti_tensioni/Product14' */
   sim_correnti_tensioni_B.Product14 = sim_correnti_tensioni_B.InputDC3[0] *
                                       sim_correnti_tensioni_B.InputDC3[2];

   /* Programmable Value : 'sim_correnti_tensioni/InputDC2' */
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
   sim_correnti_tensioni_B.InputDC2[0] = plxGetProgrammableValueData(1, 0);
   sim_correnti_tensioni_B.InputDC2[1] = plxGetProgrammableValueData(1, 1);
   sim_correnti_tensioni_B.InputDC2[2] = plxGetProgrammableValueData(1, 2);
   sim_correnti_tensioni_B.InputDC2[3] = plxGetProgrammableValueUpdateFlag(1);

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
      double ticks = (0.000100000000000000005)/1.00000000000000008e-05;
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

   /* Product : 'sim_correnti_tensioni/Product13' */
   sim_correnti_tensioni_B.Product13 = sim_correnti_tensioni_B.InputDC2[0] *
                                       sim_correnti_tensioni_B.InputDC2[2] *
                                       sim_correnti_tensioni_B.Monoflop1;

   /* Programmable Value : 'sim_correnti_tensioni/InputDC1' */
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
   /* C-Script : 'sim_correnti_tensioni/White Noise1/C-Script' */
   sim_correnti_tensioni_0_cScriptOutput(&sim_correnti_tensioni_cScriptStruct[
                                            0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;

   /* Product : 'sim_correnti_tensioni/Product10'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/InputDC1'
    */
   sim_correnti_tensioni_B.Product10 =
      (plxGetProgrammableValueData(2,
                                   0)) *
      (plxGetProgrammableValueData(2, 1)) * sim_correnti_tensioni_B.C_Script;

   /* Programmable Value : 'sim_correnti_tensioni/InputDC' */
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
   sim_correnti_tensioni_B.InputDC[0] = plxGetProgrammableValueData(3, 0);
   sim_correnti_tensioni_B.InputDC[1] = plxGetProgrammableValueData(3, 1);
   sim_correnti_tensioni_B.InputDC[2] = plxGetProgrammableValueData(3, 2);
   sim_correnti_tensioni_B.InputDC[3] = plxGetProgrammableValueData(3, 3);
   sim_correnti_tensioni_B.InputDC[4] = plxGetProgrammableValueUpdateFlag(3);

   /* Sum : 'sim_correnti_tensioni/Sum16'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product15'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant3'
    *  Sum : 'sim_correnti_tensioni/Sum13'
    *  Sum : 'sim_correnti_tensioni/Sum10'
    *  Product : 'sim_correnti_tensioni/Product9'
    */
   sim_correnti_tensioni_B.Sum16 =
      (sim_correnti_tensioni_B.Product14 *
       (sim_correnti_tensioni_B.InputDC3[1] ==
        1.)) +
      (sim_correnti_tensioni_B.Product13 +
       (sim_correnti_tensioni_B.Product10 +
        (sim_correnti_tensioni_B.InputDC[0] *
      sim_correnti_tensioni_B.InputDC[3])));

   /* Sum : 'sim_correnti_tensioni/Sum17'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product16'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant4'
    *  Sum : 'sim_correnti_tensioni/Sum14'
    *  Sum : 'sim_correnti_tensioni/Sum11'
    *  Product : 'sim_correnti_tensioni/Product11'
    */
   sim_correnti_tensioni_B.Sum17 =
      (sim_correnti_tensioni_B.Product14 *
       (sim_correnti_tensioni_B.InputDC3[1] ==
        2.)) +
      (sim_correnti_tensioni_B.Product13 +
       (sim_correnti_tensioni_B.Product10 +
        (sim_correnti_tensioni_B.InputDC[1] *
      sim_correnti_tensioni_B.InputDC[3])));

   /* Sum : 'sim_correnti_tensioni/Sum18'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product17'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant5'
    *  Sum : 'sim_correnti_tensioni/Sum15'
    *  Sum : 'sim_correnti_tensioni/Sum12'
    *  Product : 'sim_correnti_tensioni/Product12'
    */
   sim_correnti_tensioni_B.Sum18 =
      (sim_correnti_tensioni_B.Product14 *
       (sim_correnti_tensioni_B.InputDC3[1] ==
        3.)) +
      (sim_correnti_tensioni_B.Product13 +
       (sim_correnti_tensioni_B.Product10 +
        (sim_correnti_tensioni_B.InputDC[2] *
      sim_correnti_tensioni_B.InputDC[3])));

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
   sim_correnti_tensioni_B.Input3[3] = plxGetProgrammableValueUpdateFlag(4);

   /* Product : 'sim_correnti_tensioni/Product5' */
   sim_correnti_tensioni_B.Product5 = sim_correnti_tensioni_B.Input3[0] *
                                      sim_correnti_tensioni_B.Input3[2];

   /* Programmable Value : 'sim_correnti_tensioni/Input2' */
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
   sim_correnti_tensioni_B.Input2[0] = plxGetProgrammableValueData(5, 0);
   sim_correnti_tensioni_B.Input2[1] = plxGetProgrammableValueData(5, 1);
   sim_correnti_tensioni_B.Input2[2] = plxGetProgrammableValueData(5, 2);
   sim_correnti_tensioni_B.Input2[3] = plxGetProgrammableValueUpdateFlag(5);

   /* Integrator : 'sim_correnti_tensioni/Integrator3' */
   if (sim_correnti_tensioni_X.Integrator3_x > 0.5 ||
       sim_correnti_tensioni_X.Integrator3_x < -0.5)
   {
      double span = 0.5 - (-0.5);
      sim_correnti_tensioni_X.Integrator3_x -= -0.5;
      sim_correnti_tensioni_X.Integrator3_x =
         sim_correnti_tensioni_X.Integrator3_x - span*floor(
                                                            sim_correnti_tensioni_X.Integrator3_x/
                                                            span) + (-0.5);
   }
   sim_correnti_tensioni_B.Integrator3 =
      sim_correnti_tensioni_X.Integrator3_x;

   /* Comparator : 'sim_correnti_tensioni/Comparator' */
   if (0. > sim_correnti_tensioni_B.Integrator3)
      sim_correnti_tensioni_B.Comparator = 1;
   else if (0. < sim_correnti_tensioni_B.Integrator3)
      sim_correnti_tensioni_B.Comparator = 0;
   /* Monoflop : 'sim_correnti_tensioni/Monoflop'
    * incorporates
    *  Constant : 'sim_correnti_tensioni/Constant4'
    */
   if (!sim_correnti_tensioni_X.Monoflop &&
       (sim_correnti_tensioni_B.Comparator))
   {
      double ticks = (0.000100000000000000005)/1.00000000000000008e-05;
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
         sim_correnti_tensioni_B.Monoflop = 1;
      }
   }
   else if (sim_correnti_tensioni_D_uint32_t[1] == 0)
   {
      sim_correnti_tensioni_B.Monoflop = 0;
   }

   /* Product : 'sim_correnti_tensioni/Product4' */
   sim_correnti_tensioni_B.Product4 = sim_correnti_tensioni_B.Input2[0] *
                                      sim_correnti_tensioni_B.Input2[2] *
                                      sim_correnti_tensioni_B.Monoflop;

   /* Programmable Value : 'sim_correnti_tensioni/Input1' */
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
   /* C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_1_cScriptOutput(&sim_correnti_tensioni_cScriptStruct[
                                            1]);
   if (*sim_correnti_tensioni_cScriptStruct[1].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[1].errorStatus;

   /* Product : 'sim_correnti_tensioni/Product1'
    * incorporates
    *  Programmable Value : 'sim_correnti_tensioni/Input1'
    */
   sim_correnti_tensioni_B.Product1 =
      (plxGetProgrammableValueData(6,
                                   0)) *
      (plxGetProgrammableValueData(6,
                                   1)) * sim_correnti_tensioni_B.C_Script_1;

   /* Programmable Value : 'sim_correnti_tensioni/Input' */
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
   sim_correnti_tensioni_B.Input[0] = plxGetProgrammableValueData(7, 0);
   sim_correnti_tensioni_B.Input[1] = plxGetProgrammableValueData(7, 1);
   sim_correnti_tensioni_B.Input[2] = plxGetProgrammableValueUpdateFlag(7);

   /* Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave' */
   sim_correnti_tensioni_B.SineWave = 0. + 1. *
                                      (1.*sim_correnti_tensioni_D_double[0] +
                                       0.*
                                       sim_correnti_tensioni_D_double[1]);

   /* Sum : 'sim_correnti_tensioni/Sum7'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product6'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant'
    *  Sum : 'sim_correnti_tensioni/Sum4'
    *  Sum : 'sim_correnti_tensioni/Sum1'
    *  Product : 'sim_correnti_tensioni/Product'
    */
   sim_correnti_tensioni_B.Sum7 =
      (sim_correnti_tensioni_B.Product5 *
       (sim_correnti_tensioni_B.Input3[1] ==
        1.)) +
      (sim_correnti_tensioni_B.Product4 +
       (sim_correnti_tensioni_B.Product1 +
        (sim_correnti_tensioni_B.Input[0] * sim_correnti_tensioni_B.SineWave *
      sim_correnti_tensioni_B.Input[1])));

   /* Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave1' */
   sim_correnti_tensioni_B.SineWave1 = 0. + 1. *
                                       (-0.499999999999999778*
                                        sim_correnti_tensioni_D_double[2] +
                                        -0.866025403784438708*
                                        sim_correnti_tensioni_D_double[3]);

   /* Sum : 'sim_correnti_tensioni/Sum8'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product7'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant1'
    *  Sum : 'sim_correnti_tensioni/Sum5'
    *  Sum : 'sim_correnti_tensioni/Sum2'
    *  Product : 'sim_correnti_tensioni/Product2'
    */
   sim_correnti_tensioni_B.Sum8 =
      (sim_correnti_tensioni_B.Product5 *
       (sim_correnti_tensioni_B.Input3[1] ==
        2.)) +
      (sim_correnti_tensioni_B.Product4 +
       (sim_correnti_tensioni_B.Product1 +
        (sim_correnti_tensioni_B.Input[0] *
   sim_correnti_tensioni_B.SineWave1 *
      sim_correnti_tensioni_B.Input[1])));

   /* Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave2' */
   sim_correnti_tensioni_B.SineWave2 = 0. + 1. *
                                       (-0.500000000000000444*
                                        sim_correnti_tensioni_D_double[4] +
                                        0.866025403784438486*
                                        sim_correnti_tensioni_D_double[5]);

   /* Sum : 'sim_correnti_tensioni/Sum9'
    * incorporates
    *  Product : 'sim_correnti_tensioni/Product8'
    *  Compare to Constant : 'sim_correnti_tensioni/Compare to\nConstant2'
    *  Sum : 'sim_correnti_tensioni/Sum6'
    *  Sum : 'sim_correnti_tensioni/Sum3'
    *  Product : 'sim_correnti_tensioni/Product3'
    */
   sim_correnti_tensioni_B.Sum9 =
      (sim_correnti_tensioni_B.Product5 *
       (sim_correnti_tensioni_B.Input3[1] ==
        3.)) +
      (sim_correnti_tensioni_B.Product4 +
       (sim_correnti_tensioni_B.Product1 +
        (sim_correnti_tensioni_B.Input[0] *
   sim_correnti_tensioni_B.SineWave2 *
      sim_correnti_tensioni_B.Input[1])));
   /* Analog Out : 'sim_correnti_tensioni/Analog Out1' */
   setAnalogOut(0, sim_correnti_tensioni_B.Sum7);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out2' */
   setAnalogOut(1, sim_correnti_tensioni_B.Sum8);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out3' */
   setAnalogOut(2, sim_correnti_tensioni_B.Sum9);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out4' */
   setAnalogOut(3, sim_correnti_tensioni_B.Sum16);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out5' */
   setAnalogOut(4, sim_correnti_tensioni_B.Sum17);

   /* Analog Out : 'sim_correnti_tensioni/Analog Out6' */
   setAnalogOut(5, sim_correnti_tensioni_B.Sum18);
   if (sim_correnti_tensioni_subTaskHit[0])
   {
      /* Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
      sim_correnti_tensioni_B.PulseGenerator =
         sim_correnti_tensioni_D_uint32_t[2] < 1 ? 5. : -5.;
   }

   /* Analog Out : 'sim_correnti_tensioni/Analog Out7' */
   setAnalogOut(15, sim_correnti_tensioni_B.PulseGenerator);
   /* Constant : 'sim_correnti_tensioni/White Noise1/Width' */
   sim_correnti_tensioni_B.Width = 2.00001000000000007;

   /* Constant : 'sim_correnti_tensioni/White Noise/Width' */
   sim_correnti_tensioni_B.Width_1 = 2.00001000000000007;
   if (sim_correnti_tensioni_errorStatus)
   {
      return;
   }

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop1' */
   if (sim_correnti_tensioni_D_uint32_t[0] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[0] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop1 = sim_correnti_tensioni_B.Comparator1;

   /* Update for C-Script : 'sim_correnti_tensioni/White Noise1/C-Script' */
   sim_correnti_tensioni_0_cScriptUpdate(&sim_correnti_tensioni_cScriptStruct[
                                            0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;

   /* Update for Monoflop : 'sim_correnti_tensioni/Monoflop' */
   if (sim_correnti_tensioni_D_uint32_t[1] > 0)
   {
      sim_correnti_tensioni_D_uint32_t[1] -= 1;
   }
   sim_correnti_tensioni_X.Monoflop = sim_correnti_tensioni_B.Comparator;

   /* Update for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_1_cScriptUpdate(&sim_correnti_tensioni_cScriptStruct[
                                            1]);
   if (*sim_correnti_tensioni_cScriptStruct[1].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[1].errorStatus;

   /* Update for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave' */
   {
      double scaling, scaledX, scaledY;
      scaling = 1. +
                (0.5 *
                 (sim_correnti_tensioni_D_double[0]*
                  sim_correnti_tensioni_D_double[0] +
                  sim_correnti_tensioni_D_double[1]*
      sim_correnti_tensioni_D_double[1] -
                  1.));
      scaledX = sim_correnti_tensioni_D_double[0] / scaling;
      scaledY = sim_correnti_tensioni_D_double[1] / scaling;
      sim_correnti_tensioni_D_double[0] = 0.999995065201858213 * scaledX +
                                          0.00314158748587956352 * scaledY;
      sim_correnti_tensioni_D_double[1] = -0.00314158748587956352 * scaledX +
                                          0.999995065201858213 * scaledY;
   }

   /* Update for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave1' */
   {
      double scaling, scaledX, scaledY;
      scaling = 1. +
                (0.5 *
                 (sim_correnti_tensioni_D_double[2]*
                  sim_correnti_tensioni_D_double[2] +
                  sim_correnti_tensioni_D_double[3]*
      sim_correnti_tensioni_D_double[3] -
                  1.));
      scaledX = sim_correnti_tensioni_D_double[2] / scaling;
      scaledY = sim_correnti_tensioni_D_double[3] / scaling;
      sim_correnti_tensioni_D_double[2] = 0.999995065201858213 * scaledX +
                                          0.00314158748587956352 * scaledY;
      sim_correnti_tensioni_D_double[3] = -0.00314158748587956352 * scaledX +
                                          0.999995065201858213 * scaledY;
   }

   /* Update for Sine Wave Generator : 'sim_correnti_tensioni/Sine Wave2' */
   {
      double scaling, scaledX, scaledY;
      scaling = 1. +
                (0.5 *
                 (sim_correnti_tensioni_D_double[4]*
                  sim_correnti_tensioni_D_double[4] +
                  sim_correnti_tensioni_D_double[5]*
      sim_correnti_tensioni_D_double[5] -
                  1.));
      scaledX = sim_correnti_tensioni_D_double[4] / scaling;
      scaledY = sim_correnti_tensioni_D_double[5] / scaling;
      sim_correnti_tensioni_D_double[4] = 0.999995065201858213 * scaledX +
                                          0.00314158748587956352 * scaledY;
      sim_correnti_tensioni_D_double[5] = -0.00314158748587956352 * scaledX +
                                          0.999995065201858213 * scaledY;
   }
   if (sim_correnti_tensioni_subTaskHit[0])
   {
      /* Update for Pulse Generator : 'sim_correnti_tensioni/Pulse\nGenerator' */
      sim_correnti_tensioni_D_uint32_t[2] += 1;
      if (sim_correnti_tensioni_D_uint32_t[2] > 1)
      {
         sim_correnti_tensioni_D_uint32_t[2] = 0;
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

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator4' */
   sim_correnti_tensioni_deriv[1] = sim_correnti_tensioni_B.InputDC2[1];

   /* Derivatives for Integrator : 'sim_correnti_tensioni/Integrator3' */
   sim_correnti_tensioni_deriv[0] = sim_correnti_tensioni_B.Input2[1];

   /* Update continuous states */
   sim_correnti_tensioni_X.Integrator4_x += 1.00000000000000008e-05*
                                            sim_correnti_tensioni_deriv[1];
   sim_correnti_tensioni_X.Integrator3_x += 1.00000000000000008e-05*
                                            sim_correnti_tensioni_deriv[0];
}

void sim_correnti_tensioni_terminate()
{
   /* Termination for C-Script : 'sim_correnti_tensioni/White Noise1/C-Script' */
   sim_correnti_tensioni_0_cScriptTerminate(
                                            &sim_correnti_tensioni_cScriptStruct[
                                               0]);
   if (*sim_correnti_tensioni_cScriptStruct[0].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[0].errorStatus;
   /* Termination for C-Script : 'sim_correnti_tensioni/White Noise/C-Script' */
   sim_correnti_tensioni_1_cScriptTerminate(
                                            &sim_correnti_tensioni_cScriptStruct[
                                               1]);
   if (*sim_correnti_tensioni_cScriptStruct[1].errorStatus)
      sim_correnti_tensioni_errorStatus =
         *sim_correnti_tensioni_cScriptStruct[1].errorStatus;
}
