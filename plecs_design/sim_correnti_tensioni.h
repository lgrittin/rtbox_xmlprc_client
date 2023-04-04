/*
 * Header file for: sim_correnti_tensioni
 * Generated with : PLECS 4.7.1
 *                  PLECS RT Box 1 2.3.1
 * Generated on   : 4 Apr 2023 16:17:10
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
   bool EdgeDetection3;             /* sim_correnti_tensioni/Edge Detection3 */
   bool EdgeDetection2;             /* sim_correnti_tensioni/Edge Detection2 */
   bool Memory;                     /* sim_correnti_tensioni/SR Flip-flop1/Memory */
   double Integrator5_x;            /* sim_correnti_tensioni/Integrator5 */
   double Integrator3_x;            /* sim_correnti_tensioni/Integrator3 */
   bool Monoflop;                   /* sim_correnti_tensioni/Monoflop */
   double C_Script_1;               /* sim_correnti_tensioni/White Noise/C-Script */
   bool EdgeDetection5;             /* sim_correnti_tensioni/Edge Detection5 */
   bool EdgeDetection4;             /* sim_correnti_tensioni/Edge Detection4 */
   bool Memory_1;                   /* sim_correnti_tensioni/SR Flip-flop2/Memory */
   double Integrator6_x;            /* sim_correnti_tensioni/Integrator6 */
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
   bool MultiportSignalSwitch_bool; /* sim_correnti_tensioni/Multiport Signal Switch */
   int32_t MultiportSignalSwitch_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch */
   double MultiportSignalSwitch_double; /* sim_correnti_tensioni/Multiport Signal Switch */
   bool MultiportSignalSwitch1_bool; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   int32_t MultiportSignalSwitch1_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   double MultiportSignalSwitch1_double; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   bool MultiportSignalSwitch2_bool; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   int32_t MultiportSignalSwitch2_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   double MultiportSignalSwitch2_double; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   double PulseGenerator;           /* sim_correnti_tensioni/Pulse Generator */
   double InputDC3[4];              /* sim_correnti_tensioni/InputDC3 */
   double Product14;                /* sim_correnti_tensioni/Product14 */
   double InputDC2[4];              /* sim_correnti_tensioni/InputDC2 */
   double Integrator4;              /* sim_correnti_tensioni/Integrator4 */
   double Product13;                /* sim_correnti_tensioni/Product13 */
   double Product10;                /* sim_correnti_tensioni/Product10 */
   double InputDC[6];               /* sim_correnti_tensioni/InputDC */
   bool EdgeDetection3;             /* sim_correnti_tensioni/Edge Detection3 */
   bool EdgeDetection2;             /* sim_correnti_tensioni/Edge Detection2 */
   bool Memory;                     /* sim_correnti_tensioni/SR Flip-flop1/Memory */
   bool LogicalOperator;            /* sim_correnti_tensioni/SR Flip-flop1/Logical Operator */
   bool LogicalOperator4;           /* sim_correnti_tensioni/SR Flip-flop1/Logical Operator4 */
   double Integrator5;              /* sim_correnti_tensioni/Integrator5 */
   double Sum16;                    /* sim_correnti_tensioni/Sum16 */
   double Sum17;                    /* sim_correnti_tensioni/Sum17 */
   double Sum18;                    /* sim_correnti_tensioni/Sum18 */
   double Input3[4];                /* sim_correnti_tensioni/Input3 */
   double Product5;                 /* sim_correnti_tensioni/Product5 */
   double Input2[4];                /* sim_correnti_tensioni/Input2 */
   double Integrator3;              /* sim_correnti_tensioni/Integrator3 */
   double Product4;                 /* sim_correnti_tensioni/Product4 */
   double Product1;                 /* sim_correnti_tensioni/Product1 */
   double Input[5];                 /* sim_correnti_tensioni/Input */
   bool CompareToConstant6;         /* sim_correnti_tensioni/Compare to Constant6 */
   double SineWave;                 /* sim_correnti_tensioni/Sine Wave */
   bool EdgeDetection5;             /* sim_correnti_tensioni/Edge Detection5 */
   bool EdgeDetection4;             /* sim_correnti_tensioni/Edge Detection4 */
   bool Memory_1;                   /* sim_correnti_tensioni/SR Flip-flop2/Memory */
   bool LogicalOperator_1;          /* sim_correnti_tensioni/SR Flip-flop2/Logical Operator */
   bool LogicalOperator4_1;         /* sim_correnti_tensioni/SR Flip-flop2/Logical Operator4 */
   double Integrator6;              /* sim_correnti_tensioni/Integrator6 */
   double Sum7;                     /* sim_correnti_tensioni/Sum7 */
   double SineWave1;                /* sim_correnti_tensioni/Sine Wave1 */
   double Sum8;                     /* sim_correnti_tensioni/Sum8 */
   double SineWave2;                /* sim_correnti_tensioni/Sine Wave2 */
   double Sum9;                     /* sim_correnti_tensioni/Sum9 */
   double Width;                    /* sim_correnti_tensioni/White Noise1/Width */
   double Product18;                /* sim_correnti_tensioni/Product18 */
   double Width_1;                  /* sim_correnti_tensioni/White Noise/Width */
   double Product19;                /* sim_correnti_tensioni/Product19 */
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
