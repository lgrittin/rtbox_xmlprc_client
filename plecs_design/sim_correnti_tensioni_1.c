/*
 * C-Script file for: sim_correnti_tensioni/White Noise/C-Script
 * Generated with   : PLECS 4.7.1
 * Generated on     : 23 Mar 2023 09:59:48
 */
typedef double real_t;
#define REAL_MAX DBL_MAX
#define REAL_MIN DBL_MIN
#define REAL_EPSILON DBL_EPSILON
#include <stdlib.h>
#include <math.h>

#define N 624
#define MU(i)    ParamRealData(0, (i)%ParamDim(0, 1))
#define SIGMA(i) ParamRealData(1, (i)%ParamDim(1, 1))
#define SEED     ParamRealData(2, 0)

/* Mersenne Twister */
/* http://en.wikipedia.org/wiki/Mersenne_twister */

static unsigned int mt[N];
static int mt_idx = 0;

static void mt_initialize(unsigned int seed)
{
   mt[0] = seed;
   for (int i = 1; i < N; ++i)
      mt[i] = 1812433253UL * (mt[i-1] ^ (mt[i-1] >> 30)) + i;
}

static void mt_generate_numbers(void)
{
   for (int i = 0; i < N; ++i)
   {
      unsigned long y;

      y = mt[i] & 0x80000000;
      y += mt[(i+1)%N] & 0x7fffffff;
      mt[i] = mt[(i+397)%N] ^ (y >> 1);
      if (y & 0x1UL)
         mt[i] ^= 2567483615;
   }
}

static unsigned long mt_extract_number(void)
{
   unsigned long y;

   if (mt_idx == 0)
      mt_generate_numbers();
   y = mt[mt_idx];
   y ^= (y >> 11);
   y ^= (y << 7) & 2636928640UL;
   y ^= (y << 15) & 4022730752UL;
   y ^= (y >> 18);
   mt_idx = (mt_idx+1) % N;
   return y;
}

static double mt_extract_double(void)
{
   /* random number in [0, 1)-real-interval */

   return 2.32830643653869629e-10 * mt_extract_number();
}


/* Leva, J. L., "A Fast Normal Random Number Generator", ACM Transactions on
   Mathematical Sofware, vol. 18, no. 4, pp. 449-453, 1992
   http://saluc.engr.uconn.edu/refs/crypto/rng/leva92afast.pdf
 */

static double normaldev(double mu, double sigma)
{
   double u, v, x, y, Q;

   do
   {
      // u = ran();
      u = mt_extract_double();
      // v = 1.7156*(ran()-0.5);
      v = 1.7156*(mt_extract_double()-0.5);
      x = u - 0.449871;
      y = fabs(v) + 0.386595;
      Q = x*x + y*(0.19600*y - 0.25472*x);
      if (Q < 0.27597)
         break;
   }
   while (Q > 0.27846 || v*v > -4*u*u*log(u));
   return mu + sigma*v/u;
}
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
#define NumInputs cScriptStruct->numInputSignals[0]
#define NumOutputs cScriptStruct->numOutputSignals[0]
#define Input(signalIdx) (*cScriptStruct->inputs[0][signalIdx])
#define Output(signalIdx) (*cScriptStruct->outputs[0][signalIdx])
#define NumInputTerminals cScriptStruct->numInputTerminals
#define NumOutputTerminals cScriptStruct->numOutputTerminals
#define NumInputSignals(terminalIdx) cScriptStruct->numInputSignals[ \
      terminalIdx]
#define NumOutputSignals(terminalIdx) cScriptStruct->numOutputSignals[ \
      terminalIdx]
#define InputSignal(terminalIdx, \
                    signalIdx) (*cScriptStruct->inputs[terminalIdx][signalIdx])
#define OutputSignal(terminalIdx, \
                     signalIdx) (*cScriptStruct->outputs[terminalIdx][ \
                                    signalIdx])
#define NumContStates cScriptStruct->numContStates
#define NumDiscStates cScriptStruct->numDiscStates
#define NumZCSignals cScriptStruct->numZCSignals
#define NumParameters cScriptStruct->numParameters
#define NumSampleTimes cScriptStruct->numSampleTimes
#define IsMajorStep cScriptStruct->isMajorTimeStep
#define CurrentTime cScriptStruct->time
#define NextSampleHit (*cScriptStruct->nextSampleHit)
#define SetErrorMessage(string) { *cScriptStruct->errorStatus=(string); }
#define SetWarningMessage(string)
#define ContState(idx) cScriptStruct->contStates[idx]
#define ContDeriv(idx) cScriptStruct->contDerivs[idx]
#define DiscState(idx) cScriptStruct->discStates[idx]
#define ZCSignal(idx) cScriptStruct->zCSignals[idx]
#define IsSampleHit(idx) (*cScriptStruct->sampleHits[idx])
#define SampleTimePeriod(idx) cScriptStruct->sampleTimePeriods[idx]
#define SampleTimeOffset(idx) cScriptStruct->sampleTimeOffsets[idx]
#define ParamNumDims(idx) cScriptStruct->paramNumDims[idx]
#define ParamDim(pIdx, dIdx) cScriptStruct->paramDims[pIdx][dIdx]
#define ParamRealData(pIdx, dIdx) cScriptStruct->paramRealData[pIdx][dIdx]
#define ParamStringData(pIdx) cScriptStruct->paramStringData[pIdx]

void sim_correnti_tensioni_1_cScriptStart(
                                          const struct CScriptStruct *cScriptStruct)
{
   if (NumParameters != 4)
   {
      SetErrorMessage("Number of parameters does not match.");
      return;
   }

   /* Mean (mu) */
   if (ParamNumDims(0) != 2 ||
       ParamDim(0, 0) != 1 ||
       (ParamDim(0, 1) != 1 && ParamDim(0, 1) != NumOutputSignals(0)))
   {
      SetErrorMessage(
                      "Error in parameter 'Mean': scalar or vector matching output signal width expected.");
      return;
   }

   /* Standard deviation (sigma) */
   if (ParamNumDims(1) != 2 ||
       ParamDim(1, 0) != 1 ||
       (ParamDim(1, 1) != 1 && ParamDim(1, 1) != NumOutputSignals(0)))
   {
      SetErrorMessage(
                      "Error in parameter 'Standard deviation': scalar or vector matching output signal width expected.");
      return;
   }

   /* Seed */
   if (ParamNumDims(2) != 2 || ParamDim(2, 0) != 1 || ParamDim(2, 1) != 1)
   {
      SetErrorMessage("Error in parameter 'Seed': scalar expected.");
      return;
   }
   mt_initialize(SEED); /* Start value for random generator */


   /* Sample time */
   if (ParamNumDims(3) != 2 || ParamDim(3, 0) != 1 || ParamDim(3, 1) != 1
       || ParamRealData(3, 0) < 0.)
   {
      SetErrorMessage(
                      "Error in parameter 'Sampling time': positive number expected.");
      return;
   }

   /* Initialize for first output call */
   for (int i = 0; i < NumOutputSignals(0); ++i)
      DiscState(i) = normaldev(MU(i), SIGMA(i));
}

void sim_correnti_tensioni_1_cScriptOutput(
                                           const struct CScriptStruct *cScriptStruct)
{
   for (int i = 0; i < NumOutputSignals(0); ++i)
      OutputSignal(0, i) = DiscState(i);
}

void sim_correnti_tensioni_1_cScriptUpdate(
                                           const struct CScriptStruct *cScriptStruct)
{
   for (int i = 0; i < NumOutputSignals(0); ++i)
      DiscState(i) = normaldev(MU(i), SIGMA(i));
}

void sim_correnti_tensioni_1_cScriptDerivative(
                                               const struct CScriptStruct *cScriptStruct)
{
}

void sim_correnti_tensioni_1_cScriptTerminate(
                                              const struct CScriptStruct *cScriptStruct)
{
}
