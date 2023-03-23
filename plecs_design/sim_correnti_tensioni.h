/*
 * Header file for: sim_correnti_tensioni
 * Generated with : PLECS 4.7.1
 *                  PLECS RT Box 1 2.3.1
 * Generated on   : 23 Mar 2023 09:59:48
 */
#ifndef PLECS_HEADER_sim_correnti_tensioni_h_
#define PLECS_HEADER_sim_correnti_tensioni_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double sim_correnti_tensioni_FloatType;

/* Model checksum */
extern const char * const sim_correnti_tensioni_checksum;

/* Model error status */
extern const char * sim_correnti_tensioni_errorStatus;


/* Model sample time */
extern const double sim_correnti_tensioni_sampleTime;


/*
 * Model states */
typedef struct
{
   double Integrator4_x;            /* sim_correnti_tensioni/Integrator4 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Monoflop1 */
   double C_Script;                 /* sim_correnti_tensioni/White Noise1/C-Script */
   double Integrator3_x;            /* sim_correnti_tensioni/Integrator3 */
   bool Monoflop;                   /* sim_correnti_tensioni/Monoflop */
   double C_Script_1;               /* sim_correnti_tensioni/White Noise/C-Script */
} sim_correnti_tensioni_ModelStates;
extern sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X;


/* Block outputs */
typedef struct
{
   bool Comparator1;                /* sim_correnti_tensioni/Comparator1 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Monoflop1 */
   double C_Script;                 /* sim_correnti_tensioni/White Noise1/C-Script */
   bool Comparator;                 /* sim_correnti_tensioni/Comparator */
   bool Monoflop;                   /* sim_correnti_tensioni/Monoflop */
   double C_Script_1;               /* sim_correnti_tensioni/White Noise/C-Script */
   double PulseGenerator;           /* sim_correnti_tensioni/Pulse Generator */
   double InputDC3[4];              /* sim_correnti_tensioni/InputDC3 */
   double Product14;                /* sim_correnti_tensioni/Product14 */
   double InputDC2[4];              /* sim_correnti_tensioni/InputDC2 */
   double Integrator4;              /* sim_correnti_tensioni/Integrator4 */
   double Product13;                /* sim_correnti_tensioni/Product13 */
   double Product10;                /* sim_correnti_tensioni/Product10 */
   double InputDC[5];               /* sim_correnti_tensioni/InputDC */
   double Sum16;                    /* sim_correnti_tensioni/Sum16 */
   double Sum17;                    /* sim_correnti_tensioni/Sum17 */
   double Sum18;                    /* sim_correnti_tensioni/Sum18 */
   double Input3[4];                /* sim_correnti_tensioni/Input3 */
   double Product5;                 /* sim_correnti_tensioni/Product5 */
   double Input2[4];                /* sim_correnti_tensioni/Input2 */
   double Integrator3;              /* sim_correnti_tensioni/Integrator3 */
   double Product4;                 /* sim_correnti_tensioni/Product4 */
   double Product1;                 /* sim_correnti_tensioni/Product1 */
   double Input[3];                 /* sim_correnti_tensioni/Input */
   double SineWave;                 /* sim_correnti_tensioni/Sine Wave */
   double Sum7;                     /* sim_correnti_tensioni/Sum7 */
   double SineWave1;                /* sim_correnti_tensioni/Sine Wave1 */
   double Sum8;                     /* sim_correnti_tensioni/Sum8 */
   double SineWave2;                /* sim_correnti_tensioni/Sine Wave2 */
   double Sum9;                     /* sim_correnti_tensioni/Sum9 */
   double Width;                    /* sim_correnti_tensioni/White Noise1/Width */
   double Width_1;                  /* sim_correnti_tensioni/White Noise/Width */
} sim_correnti_tensioni_BlockOutputs;
extern sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define sim_correnti_tensioni_NumExtModeSignals 6
extern const double * const sim_correnti_tensioni_ExtModeSignals[];
/* Tunable parameters */
#define sim_correnti_tensioni_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void sim_correnti_tensioni_initialize();
void sim_correnti_tensioni_step(void);
void sim_correnti_tensioni_terminate(void);

#endif /* PLECS_HEADER_sim_correnti_tensioni_h_ */
