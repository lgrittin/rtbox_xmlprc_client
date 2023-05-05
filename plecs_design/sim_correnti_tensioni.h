/*
 * Header file for: sim_correnti_tensioni
 * Generated with : PLECS 4.7.1
 *                  PLECS RT Box 1 2.3.1
 * Generated on   : 6 Apr 2023 18:46:55
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
   double C_Script;                 /* sim_correnti_tensioni/White Noise/C-Script */
   double Integrator7_x;            /* sim_correnti_tensioni/Integrator7 */
   bool Integrator7_i1_first;       /* sim_correnti_tensioni/Integrator7 */
   double Integrator6_x;            /* sim_correnti_tensioni/Integrator6 */
   double Integrator4_x;            /* sim_correnti_tensioni/Integrator4 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Monoflop1 */
   double Integrator9_x;            /* sim_correnti_tensioni/Integrator9 */
   bool Integrator9_i1_first;       /* sim_correnti_tensioni/Integrator9 */
   double Integrator8_x;            /* sim_correnti_tensioni/Integrator8 */
   double Integrator5_x;            /* sim_correnti_tensioni/Integrator5 */
   bool Monoflop2;                  /* sim_correnti_tensioni/Monoflop2 */
   double Integrator11_x;           /* sim_correnti_tensioni/Integrator11 */
   bool Integrator11_i1_first;      /* sim_correnti_tensioni/Integrator11 */
   double Integrator10_x;           /* sim_correnti_tensioni/Integrator10 */
   double Integrator12_x;           /* sim_correnti_tensioni/Integrator12 */
   bool Monoflop3;                  /* sim_correnti_tensioni/Monoflop3 */
   double Integrator14_x;           /* sim_correnti_tensioni/Integrator14 */
   bool Integrator14_i1_first;      /* sim_correnti_tensioni/Integrator14 */
   double Integrator13_x;           /* sim_correnti_tensioni/Integrator13 */
   double Integrator15_x;           /* sim_correnti_tensioni/Integrator15 */
   bool Monoflop4;                  /* sim_correnti_tensioni/Monoflop4 */
   double Integrator17_x;           /* sim_correnti_tensioni/Integrator17 */
   bool Integrator17_i1_first;      /* sim_correnti_tensioni/Integrator17 */
   double Integrator16_x;           /* sim_correnti_tensioni/Integrator16 */
   double Integrator18_x;           /* sim_correnti_tensioni/Integrator18 */
   bool Monoflop5;                  /* sim_correnti_tensioni/Monoflop5 */
   double Integrator20_x;           /* sim_correnti_tensioni/Integrator20 */
   bool Integrator20_i1_first;      /* sim_correnti_tensioni/Integrator20 */
   double Integrator19_x;           /* sim_correnti_tensioni/Integrator19 */
   double Integrator21_x;           /* sim_correnti_tensioni/Integrator21 */
   bool Monoflop6;                  /* sim_correnti_tensioni/Monoflop6 */
   double Integrator23_x;           /* sim_correnti_tensioni/Integrator23 */
   bool Integrator23_i1_first;      /* sim_correnti_tensioni/Integrator23 */
   double Integrator22_x;           /* sim_correnti_tensioni/Integrator22 */
   double Integrator24_x;           /* sim_correnti_tensioni/Integrator24 */
   bool Monoflop7;                  /* sim_correnti_tensioni/Monoflop7 */
   double Integrator26_x;           /* sim_correnti_tensioni/Integrator26 */
   bool Integrator26_i1_first;      /* sim_correnti_tensioni/Integrator26 */
   double Integrator25_x;           /* sim_correnti_tensioni/Integrator25 */
   double Integrator27_x;           /* sim_correnti_tensioni/Integrator27 */
   bool Monoflop8;                  /* sim_correnti_tensioni/Monoflop8 */
   double Integrator29_x;           /* sim_correnti_tensioni/Integrator29 */
   bool Integrator29_i1_first;      /* sim_correnti_tensioni/Integrator29 */
   double Integrator28_x;           /* sim_correnti_tensioni/Integrator28 */
   double Integrator30_x;           /* sim_correnti_tensioni/Integrator30 */
   bool Monoflop9;                  /* sim_correnti_tensioni/Monoflop9 */
   double Integrator32_x;           /* sim_correnti_tensioni/Integrator32 */
   bool Integrator32_i1_first;      /* sim_correnti_tensioni/Integrator32 */
   double Integrator31_x;           /* sim_correnti_tensioni/Integrator31 */
   double Integrator33_x;           /* sim_correnti_tensioni/Integrator33 */
   bool Monoflop10;                 /* sim_correnti_tensioni/Monoflop10 */
   double Integrator35_x;           /* sim_correnti_tensioni/Integrator35 */
   bool Integrator35_i1_first;      /* sim_correnti_tensioni/Integrator35 */
   double Integrator34_x;           /* sim_correnti_tensioni/Integrator34 */
   double Integrator36_x;           /* sim_correnti_tensioni/Integrator36 */
   bool Monoflop11;                 /* sim_correnti_tensioni/Monoflop11 */
   double Integrator38_x;           /* sim_correnti_tensioni/Integrator38 */
   bool Integrator38_i1_first;      /* sim_correnti_tensioni/Integrator38 */
   double Integrator37_x;           /* sim_correnti_tensioni/Integrator37 */
   double Integrator39_x;           /* sim_correnti_tensioni/Integrator39 */
   bool Monoflop12;                 /* sim_correnti_tensioni/Monoflop12 */
   double Integrator41_x;           /* sim_correnti_tensioni/Integrator41 */
   bool Integrator41_i1_first;      /* sim_correnti_tensioni/Integrator41 */
   double Integrator40_x;           /* sim_correnti_tensioni/Integrator40 */
   double Integrator42_x;           /* sim_correnti_tensioni/Integrator42 */
   bool Monoflop13;                 /* sim_correnti_tensioni/Monoflop13 */
   double Integrator44_x;           /* sim_correnti_tensioni/Integrator44 */
   bool Integrator44_i1_first;      /* sim_correnti_tensioni/Integrator44 */
   double Integrator43_x;           /* sim_correnti_tensioni/Integrator43 */
   double Integrator45_x;           /* sim_correnti_tensioni/Integrator45 */
   bool Monoflop14;                 /* sim_correnti_tensioni/Monoflop14 */
   double Integrator47_x;           /* sim_correnti_tensioni/Integrator47 */
   bool Integrator47_i1_first;      /* sim_correnti_tensioni/Integrator47 */
   double Integrator46_x;           /* sim_correnti_tensioni/Integrator46 */
   double Integrator48_x;           /* sim_correnti_tensioni/Integrator48 */
   bool Monoflop15;                 /* sim_correnti_tensioni/Monoflop15 */
   double Integrator50_x;           /* sim_correnti_tensioni/Integrator50 */
   bool Integrator50_i1_first;      /* sim_correnti_tensioni/Integrator50 */
   double Integrator49_x;           /* sim_correnti_tensioni/Integrator49 */
   double Integrator51_x;           /* sim_correnti_tensioni/Integrator51 */
   bool Monoflop16;                 /* sim_correnti_tensioni/Monoflop16 */
} sim_correnti_tensioni_ModelStates;
extern sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X;


/* Block outputs */
typedef struct
{
   double C_Script;                 /* sim_correnti_tensioni/White Noise/C-Script */
   bool Comparator1;                /* sim_correnti_tensioni/Comparator1 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Monoflop1 */
   bool Comparator2;                /* sim_correnti_tensioni/Comparator2 */
   bool Monoflop2;                  /* sim_correnti_tensioni/Monoflop2 */
   bool Comparator3;                /* sim_correnti_tensioni/Comparator3 */
   bool Monoflop3;                  /* sim_correnti_tensioni/Monoflop3 */
   bool Comparator4;                /* sim_correnti_tensioni/Comparator4 */
   bool Monoflop4;                  /* sim_correnti_tensioni/Monoflop4 */
   bool Comparator5;                /* sim_correnti_tensioni/Comparator5 */
   bool Monoflop5;                  /* sim_correnti_tensioni/Monoflop5 */
   bool Comparator6;                /* sim_correnti_tensioni/Comparator6 */
   bool Monoflop6;                  /* sim_correnti_tensioni/Monoflop6 */
   bool Comparator7;                /* sim_correnti_tensioni/Comparator7 */
   bool Monoflop7;                  /* sim_correnti_tensioni/Monoflop7 */
   bool Comparator8;                /* sim_correnti_tensioni/Comparator8 */
   bool Monoflop8;                  /* sim_correnti_tensioni/Monoflop8 */
   bool Comparator9;                /* sim_correnti_tensioni/Comparator9 */
   bool Monoflop9;                  /* sim_correnti_tensioni/Monoflop9 */
   bool Comparator10;               /* sim_correnti_tensioni/Comparator10 */
   bool Monoflop10;                 /* sim_correnti_tensioni/Monoflop10 */
   bool Comparator11;               /* sim_correnti_tensioni/Comparator11 */
   bool Monoflop11;                 /* sim_correnti_tensioni/Monoflop11 */
   bool Comparator12;               /* sim_correnti_tensioni/Comparator12 */
   bool Monoflop12;                 /* sim_correnti_tensioni/Monoflop12 */
   bool Comparator13;               /* sim_correnti_tensioni/Comparator13 */
   bool Monoflop13;                 /* sim_correnti_tensioni/Monoflop13 */
   bool Comparator14;               /* sim_correnti_tensioni/Comparator14 */
   bool Monoflop14;                 /* sim_correnti_tensioni/Monoflop14 */
   bool Comparator15;               /* sim_correnti_tensioni/Comparator15 */
   bool Monoflop15;                 /* sim_correnti_tensioni/Monoflop15 */
   bool Comparator16;               /* sim_correnti_tensioni/Comparator16 */
   bool Monoflop16;                 /* sim_correnti_tensioni/Monoflop16 */
   bool MultiportSignalSwitch_bool; /* sim_correnti_tensioni/Multiport Signal Switch */
   int32_t MultiportSignalSwitch_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch */
   double MultiportSignalSwitch_double; /* sim_correnti_tensioni/Multiport Signal Switch */
   double PulseGenerator;           /* sim_correnti_tensioni/Pulse Generator */
   double Input0[8];                /* sim_correnti_tensioni/Input0 */
   double Integrator7;              /* sim_correnti_tensioni/Integrator7 */
   double Integrator6;              /* sim_correnti_tensioni/Integrator6 */
   double Integrator4;              /* sim_correnti_tensioni/Integrator4 */
   double Sum1;                     /* sim_correnti_tensioni/Sum1 */
   double Input1[8];                /* sim_correnti_tensioni/Input1 */
   double Integrator9;              /* sim_correnti_tensioni/Integrator9 */
   double Integrator8;              /* sim_correnti_tensioni/Integrator8 */
   double Integrator5;              /* sim_correnti_tensioni/Integrator5 */
   double Sum2;                     /* sim_correnti_tensioni/Sum2 */
   double Input2[8];                /* sim_correnti_tensioni/Input2 */
   double Integrator11;             /* sim_correnti_tensioni/Integrator11 */
   double Integrator10;             /* sim_correnti_tensioni/Integrator10 */
   double Integrator12;             /* sim_correnti_tensioni/Integrator12 */
   double Sum3;                     /* sim_correnti_tensioni/Sum3 */
   double Input3[8];                /* sim_correnti_tensioni/Input3 */
   double Integrator14;             /* sim_correnti_tensioni/Integrator14 */
   double Integrator13;             /* sim_correnti_tensioni/Integrator13 */
   double Integrator15;             /* sim_correnti_tensioni/Integrator15 */
   double Sum4;                     /* sim_correnti_tensioni/Sum4 */
   double Input4[8];                /* sim_correnti_tensioni/Input4 */
   double Integrator17;             /* sim_correnti_tensioni/Integrator17 */
   double Integrator16;             /* sim_correnti_tensioni/Integrator16 */
   double Integrator18;             /* sim_correnti_tensioni/Integrator18 */
   double Sum5;                     /* sim_correnti_tensioni/Sum5 */
   double Input5[8];                /* sim_correnti_tensioni/Input5 */
   double Integrator20;             /* sim_correnti_tensioni/Integrator20 */
   double Integrator19;             /* sim_correnti_tensioni/Integrator19 */
   double Integrator21;             /* sim_correnti_tensioni/Integrator21 */
   double Sum6;                     /* sim_correnti_tensioni/Sum6 */
   double Input6[8];                /* sim_correnti_tensioni/Input6 */
   double Integrator23;             /* sim_correnti_tensioni/Integrator23 */
   double Integrator22;             /* sim_correnti_tensioni/Integrator22 */
   double Integrator24;             /* sim_correnti_tensioni/Integrator24 */
   double Sum7;                     /* sim_correnti_tensioni/Sum7 */
   double Input7[8];                /* sim_correnti_tensioni/Input7 */
   double Integrator26;             /* sim_correnti_tensioni/Integrator26 */
   double Integrator25;             /* sim_correnti_tensioni/Integrator25 */
   double Integrator27;             /* sim_correnti_tensioni/Integrator27 */
   double Sum8;                     /* sim_correnti_tensioni/Sum8 */
   double Input8[8];                /* sim_correnti_tensioni/Input8 */
   double Integrator29;             /* sim_correnti_tensioni/Integrator29 */
   double Integrator28;             /* sim_correnti_tensioni/Integrator28 */
   double Integrator30;             /* sim_correnti_tensioni/Integrator30 */
   double Sum9;                     /* sim_correnti_tensioni/Sum9 */
   double Input9[8];                /* sim_correnti_tensioni/Input9 */
   double Integrator32;             /* sim_correnti_tensioni/Integrator32 */
   double Integrator31;             /* sim_correnti_tensioni/Integrator31 */
   double Integrator33;             /* sim_correnti_tensioni/Integrator33 */
   double Sum10;                    /* sim_correnti_tensioni/Sum10 */
   double Input10[8];               /* sim_correnti_tensioni/Input10 */
   double Integrator35;             /* sim_correnti_tensioni/Integrator35 */
   double Integrator34;             /* sim_correnti_tensioni/Integrator34 */
   double Integrator36;             /* sim_correnti_tensioni/Integrator36 */
   double Sum11;                    /* sim_correnti_tensioni/Sum11 */
   double Input11[8];               /* sim_correnti_tensioni/Input11 */
   double Integrator38;             /* sim_correnti_tensioni/Integrator38 */
   double Integrator37;             /* sim_correnti_tensioni/Integrator37 */
   double Integrator39;             /* sim_correnti_tensioni/Integrator39 */
   double Sum12;                    /* sim_correnti_tensioni/Sum12 */
   double Input12[8];               /* sim_correnti_tensioni/Input12 */
   double Integrator41;             /* sim_correnti_tensioni/Integrator41 */
   double Integrator40;             /* sim_correnti_tensioni/Integrator40 */
   double Integrator42;             /* sim_correnti_tensioni/Integrator42 */
   double Sum13;                    /* sim_correnti_tensioni/Sum13 */
   double Input13[8];               /* sim_correnti_tensioni/Input13 */
   double Integrator44;             /* sim_correnti_tensioni/Integrator44 */
   double Integrator43;             /* sim_correnti_tensioni/Integrator43 */
   double Integrator45;             /* sim_correnti_tensioni/Integrator45 */
   double Sum14;                    /* sim_correnti_tensioni/Sum14 */
   double Input14[8];               /* sim_correnti_tensioni/Input14 */
   double Integrator47;             /* sim_correnti_tensioni/Integrator47 */
   double Integrator46;             /* sim_correnti_tensioni/Integrator46 */
   double Integrator48;             /* sim_correnti_tensioni/Integrator48 */
   double Sum15;                    /* sim_correnti_tensioni/Sum15 */
   double Input15[8];               /* sim_correnti_tensioni/Input15 */
   double Integrator50;             /* sim_correnti_tensioni/Integrator50 */
   double Integrator49;             /* sim_correnti_tensioni/Integrator49 */
   double Integrator51;             /* sim_correnti_tensioni/Integrator51 */
   double Sum16;                    /* sim_correnti_tensioni/Sum16 */
   double Width;                    /* sim_correnti_tensioni/White Noise/Width */
   double Product19;                /* sim_correnti_tensioni/Product19 */
   double Product20;                /* sim_correnti_tensioni/Product20 */
   double Product21;                /* sim_correnti_tensioni/Product21 */
   double Product22;                /* sim_correnti_tensioni/Product22 */
   double Product23;                /* sim_correnti_tensioni/Product23 */
   double Product24;                /* sim_correnti_tensioni/Product24 */
   double Product25;                /* sim_correnti_tensioni/Product25 */
   double Product28;                /* sim_correnti_tensioni/Product28 */
   double Product32;                /* sim_correnti_tensioni/Product32 */
   double Product36;                /* sim_correnti_tensioni/Product36 */
   double Product40;                /* sim_correnti_tensioni/Product40 */
   double Product44;                /* sim_correnti_tensioni/Product44 */
   double Product48;                /* sim_correnti_tensioni/Product48 */
   double Product52;                /* sim_correnti_tensioni/Product52 */
   double Product56;                /* sim_correnti_tensioni/Product56 */
   double Product60;                /* sim_correnti_tensioni/Product60 */
} sim_correnti_tensioni_BlockOutputs;
extern sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define sim_correnti_tensioni_NumExtModeSignals 0
extern const double * const sim_correnti_tensioni_ExtModeSignals[];
/* Tunable parameters */
#define sim_correnti_tensioni_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void sim_correnti_tensioni_initialize();
void sim_correnti_tensioni_step(void);
void sim_correnti_tensioni_terminate(void);

#endif /* PLECS_HEADER_sim_correnti_tensioni_h_ */
