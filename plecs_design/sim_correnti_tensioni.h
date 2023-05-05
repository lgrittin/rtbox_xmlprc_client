/*
 * Header file for: sim_correnti_tensioni
 * Generated with : PLECS 4.7.3
 *                  PLECS RT Box 3 2.3.6
 * Generated on   : 5 May 2023 16:38:23
 */
#ifndef PLECS_HEADER_sim_correnti_tensioni_h_
#define PLECS_HEADER_sim_correnti_tensioni_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef float sim_correnti_tensioni_FloatType;

/* Model checksum */
extern const char * const sim_correnti_tensioni_checksum;

/* Model error status */
extern const char * sim_correnti_tensioni_errorStatus;


/* Model sample time */
extern const float sim_correnti_tensioni_sampleTime[2][2];


/*
 * Model states */
typedef struct
{
   float Integrator7_x;             /* sim_correnti_tensioni/Signal Builder62/Integrator7 */
   bool Integrator7_i1_first;       /* sim_correnti_tensioni/Signal Builder62/Integrator7 */
   bool Integrator7_i2_prevReset;   /* sim_correnti_tensioni/Signal Builder62/Integrator7 */
   float Integrator6_x;             /* sim_correnti_tensioni/Signal Builder62/Integrator6 */
   float Integrator4_x;             /* sim_correnti_tensioni/Signal Builder62/Integrator4 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Signal Builder62/Monoflop1 */
   float Integrator7_1_x;           /* sim_correnti_tensioni/Signal Builder61/Integrator7 */
   bool Integrator7_1_i1_first;     /* sim_correnti_tensioni/Signal Builder61/Integrator7 */
   bool Integrator7_1_i2_prevReset; /* sim_correnti_tensioni/Signal Builder61/Integrator7 */
   float Integrator6_1_x;           /* sim_correnti_tensioni/Signal Builder61/Integrator6 */
   float Integrator4_1_x;           /* sim_correnti_tensioni/Signal Builder61/Integrator4 */
   bool Monoflop1_1;                /* sim_correnti_tensioni/Signal Builder61/Monoflop1 */
   float Integrator7_2_x;           /* sim_correnti_tensioni/Signal Builder63/Integrator7 */
   bool Integrator7_2_i1_first;     /* sim_correnti_tensioni/Signal Builder63/Integrator7 */
   bool Integrator7_2_i2_prevReset; /* sim_correnti_tensioni/Signal Builder63/Integrator7 */
   float Integrator6_2_x;           /* sim_correnti_tensioni/Signal Builder63/Integrator6 */
   float Integrator4_2_x;           /* sim_correnti_tensioni/Signal Builder63/Integrator4 */
   bool Monoflop1_2;                /* sim_correnti_tensioni/Signal Builder63/Monoflop1 */
   float Integrator7_3_x;           /* sim_correnti_tensioni/Signal Builder64/Integrator7 */
   bool Integrator7_3_i1_first;     /* sim_correnti_tensioni/Signal Builder64/Integrator7 */
   bool Integrator7_3_i2_prevReset; /* sim_correnti_tensioni/Signal Builder64/Integrator7 */
   float Integrator6_3_x;           /* sim_correnti_tensioni/Signal Builder64/Integrator6 */
   float Integrator4_3_x;           /* sim_correnti_tensioni/Signal Builder64/Integrator4 */
   bool Monoflop1_3;                /* sim_correnti_tensioni/Signal Builder64/Monoflop1 */
   float Integrator7_4_x;           /* sim_correnti_tensioni/Signal Builder65/Integrator7 */
   bool Integrator7_4_i1_first;     /* sim_correnti_tensioni/Signal Builder65/Integrator7 */
   bool Integrator7_4_i2_prevReset; /* sim_correnti_tensioni/Signal Builder65/Integrator7 */
   float Integrator6_4_x;           /* sim_correnti_tensioni/Signal Builder65/Integrator6 */
   float Integrator4_4_x;           /* sim_correnti_tensioni/Signal Builder65/Integrator4 */
   bool Monoflop1_4;                /* sim_correnti_tensioni/Signal Builder65/Monoflop1 */
   float Integrator7_5_x;           /* sim_correnti_tensioni/Signal Builder66/Integrator7 */
   bool Integrator7_5_i1_first;     /* sim_correnti_tensioni/Signal Builder66/Integrator7 */
   bool Integrator7_5_i2_prevReset; /* sim_correnti_tensioni/Signal Builder66/Integrator7 */
   float Integrator6_5_x;           /* sim_correnti_tensioni/Signal Builder66/Integrator6 */
   float Integrator4_5_x;           /* sim_correnti_tensioni/Signal Builder66/Integrator4 */
   bool Monoflop1_5;                /* sim_correnti_tensioni/Signal Builder66/Monoflop1 */
   float Integrator7_6_x;           /* sim_correnti_tensioni/Signal Builder67/Integrator7 */
   bool Integrator7_6_i1_first;     /* sim_correnti_tensioni/Signal Builder67/Integrator7 */
   bool Integrator7_6_i2_prevReset; /* sim_correnti_tensioni/Signal Builder67/Integrator7 */
   float Integrator6_6_x;           /* sim_correnti_tensioni/Signal Builder67/Integrator6 */
   float Integrator4_6_x;           /* sim_correnti_tensioni/Signal Builder67/Integrator4 */
   bool Monoflop1_6;                /* sim_correnti_tensioni/Signal Builder67/Monoflop1 */
   float Integrator7_7_x;           /* sim_correnti_tensioni/Signal Builder68/Integrator7 */
   bool Integrator7_7_i1_first;     /* sim_correnti_tensioni/Signal Builder68/Integrator7 */
   bool Integrator7_7_i2_prevReset; /* sim_correnti_tensioni/Signal Builder68/Integrator7 */
   float Integrator6_7_x;           /* sim_correnti_tensioni/Signal Builder68/Integrator6 */
   float Integrator4_7_x;           /* sim_correnti_tensioni/Signal Builder68/Integrator4 */
   bool Monoflop1_7;                /* sim_correnti_tensioni/Signal Builder68/Monoflop1 */
   float Integrator7_8_x;           /* sim_correnti_tensioni/Signal Builder69/Integrator7 */
   bool Integrator7_8_i1_first;     /* sim_correnti_tensioni/Signal Builder69/Integrator7 */
   bool Integrator7_8_i2_prevReset; /* sim_correnti_tensioni/Signal Builder69/Integrator7 */
   float Integrator6_8_x;           /* sim_correnti_tensioni/Signal Builder69/Integrator6 */
   float Integrator4_8_x;           /* sim_correnti_tensioni/Signal Builder69/Integrator4 */
   bool Monoflop1_8;                /* sim_correnti_tensioni/Signal Builder69/Monoflop1 */
   float Integrator7_9_x;           /* sim_correnti_tensioni/Signal Builder70/Integrator7 */
   bool Integrator7_9_i1_first;     /* sim_correnti_tensioni/Signal Builder70/Integrator7 */
   bool Integrator7_9_i2_prevReset; /* sim_correnti_tensioni/Signal Builder70/Integrator7 */
   float Integrator6_9_x;           /* sim_correnti_tensioni/Signal Builder70/Integrator6 */
   float Integrator4_9_x;           /* sim_correnti_tensioni/Signal Builder70/Integrator4 */
   bool Monoflop1_9;                /* sim_correnti_tensioni/Signal Builder70/Monoflop1 */
   float Integrator7_10_x;          /* sim_correnti_tensioni/Signal Builder71/Integrator7 */
   bool Integrator7_10_i1_first;    /* sim_correnti_tensioni/Signal Builder71/Integrator7 */
   bool Integrator7_10_i2_prevReset; /* sim_correnti_tensioni/Signal Builder71/Integrator7 */
   float Integrator6_10_x;          /* sim_correnti_tensioni/Signal Builder71/Integrator6 */
   float Integrator4_10_x;          /* sim_correnti_tensioni/Signal Builder71/Integrator4 */
   bool Monoflop1_10;               /* sim_correnti_tensioni/Signal Builder71/Monoflop1 */
   float Integrator7_11_x;          /* sim_correnti_tensioni/Signal Builder72/Integrator7 */
   bool Integrator7_11_i1_first;    /* sim_correnti_tensioni/Signal Builder72/Integrator7 */
   bool Integrator7_11_i2_prevReset; /* sim_correnti_tensioni/Signal Builder72/Integrator7 */
   float Integrator6_11_x;          /* sim_correnti_tensioni/Signal Builder72/Integrator6 */
   float Integrator4_11_x;          /* sim_correnti_tensioni/Signal Builder72/Integrator4 */
   bool Monoflop1_11;               /* sim_correnti_tensioni/Signal Builder72/Monoflop1 */
   float Integrator7_12_x;          /* sim_correnti_tensioni/Signal Builder73/Integrator7 */
   bool Integrator7_12_i1_first;    /* sim_correnti_tensioni/Signal Builder73/Integrator7 */
   bool Integrator7_12_i2_prevReset; /* sim_correnti_tensioni/Signal Builder73/Integrator7 */
   float Integrator6_12_x;          /* sim_correnti_tensioni/Signal Builder73/Integrator6 */
   float Integrator4_12_x;          /* sim_correnti_tensioni/Signal Builder73/Integrator4 */
   bool Monoflop1_12;               /* sim_correnti_tensioni/Signal Builder73/Monoflop1 */
   float Integrator7_13_x;          /* sim_correnti_tensioni/Signal Builder74/Integrator7 */
   bool Integrator7_13_i1_first;    /* sim_correnti_tensioni/Signal Builder74/Integrator7 */
   bool Integrator7_13_i2_prevReset; /* sim_correnti_tensioni/Signal Builder74/Integrator7 */
   float Integrator6_13_x;          /* sim_correnti_tensioni/Signal Builder74/Integrator6 */
   float Integrator4_13_x;          /* sim_correnti_tensioni/Signal Builder74/Integrator4 */
   bool Monoflop1_13;               /* sim_correnti_tensioni/Signal Builder74/Monoflop1 */
   float Integrator7_14_x;          /* sim_correnti_tensioni/Signal Builder75/Integrator7 */
   bool Integrator7_14_i1_first;    /* sim_correnti_tensioni/Signal Builder75/Integrator7 */
   bool Integrator7_14_i2_prevReset; /* sim_correnti_tensioni/Signal Builder75/Integrator7 */
   float Integrator6_14_x;          /* sim_correnti_tensioni/Signal Builder75/Integrator6 */
   float Integrator4_14_x;          /* sim_correnti_tensioni/Signal Builder75/Integrator4 */
   bool Monoflop1_14;               /* sim_correnti_tensioni/Signal Builder75/Monoflop1 */
   float Integrator7_15_x;          /* sim_correnti_tensioni/Signal Builder76/Integrator7 */
   bool Integrator7_15_i1_first;    /* sim_correnti_tensioni/Signal Builder76/Integrator7 */
   bool Integrator7_15_i2_prevReset; /* sim_correnti_tensioni/Signal Builder76/Integrator7 */
   float Integrator6_15_x;          /* sim_correnti_tensioni/Signal Builder76/Integrator6 */
   float Integrator4_15_x;          /* sim_correnti_tensioni/Signal Builder76/Integrator4 */
   bool Monoflop1_15;               /* sim_correnti_tensioni/Signal Builder76/Monoflop1 */
   bool Monoflop1_16;               /* sim_correnti_tensioni/Monoflop1 */
   float C_Script;                  /* sim_correnti_tensioni/White Noise/C-Script */
} sim_correnti_tensioni_ModelStates;
extern sim_correnti_tensioni_ModelStates sim_correnti_tensioni_X;


/* Block outputs */
typedef struct
{
   float sim_correnti_tensioni;     /* sim_correnti_tensioni */
   bool Comparator1;                /* sim_correnti_tensioni/Signal Builder62/Comparator1 */
   bool Monoflop1;                  /* sim_correnti_tensioni/Signal Builder62/Monoflop1 */
   bool Comparator1_1;              /* sim_correnti_tensioni/Signal Builder61/Comparator1 */
   bool Monoflop1_1;                /* sim_correnti_tensioni/Signal Builder61/Monoflop1 */
   bool Comparator1_2;              /* sim_correnti_tensioni/Signal Builder63/Comparator1 */
   bool Monoflop1_2;                /* sim_correnti_tensioni/Signal Builder63/Monoflop1 */
   bool Comparator1_3;              /* sim_correnti_tensioni/Signal Builder64/Comparator1 */
   bool Monoflop1_3;                /* sim_correnti_tensioni/Signal Builder64/Monoflop1 */
   bool Comparator1_4;              /* sim_correnti_tensioni/Signal Builder65/Comparator1 */
   bool Monoflop1_4;                /* sim_correnti_tensioni/Signal Builder65/Monoflop1 */
   bool Comparator1_5;              /* sim_correnti_tensioni/Signal Builder66/Comparator1 */
   bool Monoflop1_5;                /* sim_correnti_tensioni/Signal Builder66/Monoflop1 */
   bool Comparator1_6;              /* sim_correnti_tensioni/Signal Builder67/Comparator1 */
   bool Monoflop1_6;                /* sim_correnti_tensioni/Signal Builder67/Monoflop1 */
   bool Comparator1_7;              /* sim_correnti_tensioni/Signal Builder68/Comparator1 */
   bool Monoflop1_7;                /* sim_correnti_tensioni/Signal Builder68/Monoflop1 */
   bool Comparator1_8;              /* sim_correnti_tensioni/Signal Builder69/Comparator1 */
   bool Monoflop1_8;                /* sim_correnti_tensioni/Signal Builder69/Monoflop1 */
   bool Comparator1_9;              /* sim_correnti_tensioni/Signal Builder70/Comparator1 */
   bool Monoflop1_9;                /* sim_correnti_tensioni/Signal Builder70/Monoflop1 */
   bool Comparator1_10;             /* sim_correnti_tensioni/Signal Builder71/Comparator1 */
   bool Monoflop1_10;               /* sim_correnti_tensioni/Signal Builder71/Monoflop1 */
   bool Comparator1_11;             /* sim_correnti_tensioni/Signal Builder72/Comparator1 */
   bool Monoflop1_11;               /* sim_correnti_tensioni/Signal Builder72/Monoflop1 */
   bool Comparator1_12;             /* sim_correnti_tensioni/Signal Builder73/Comparator1 */
   bool Monoflop1_12;               /* sim_correnti_tensioni/Signal Builder73/Monoflop1 */
   bool Comparator1_13;             /* sim_correnti_tensioni/Signal Builder74/Comparator1 */
   bool Monoflop1_13;               /* sim_correnti_tensioni/Signal Builder74/Monoflop1 */
   bool Comparator1_14;             /* sim_correnti_tensioni/Signal Builder75/Comparator1 */
   bool Monoflop1_14;               /* sim_correnti_tensioni/Signal Builder75/Monoflop1 */
   bool Comparator1_15;             /* sim_correnti_tensioni/Signal Builder76/Comparator1 */
   bool Monoflop1_15;               /* sim_correnti_tensioni/Signal Builder76/Monoflop1 */
   bool MultiportSignalSwitch_bool; /* sim_correnti_tensioni/Multiport Signal Switch */
   int32_t MultiportSignalSwitch_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch */
   float MultiportSignalSwitch_float; /* sim_correnti_tensioni/Multiport Signal Switch */
   bool MultiportSignalSwitch2_bool; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   int32_t MultiportSignalSwitch2_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   float MultiportSignalSwitch2_float; /* sim_correnti_tensioni/Multiport Signal Switch2 */
   bool MultiportSignalSwitch3_bool; /* sim_correnti_tensioni/Multiport Signal Switch3 */
   int32_t MultiportSignalSwitch3_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch3 */
   float MultiportSignalSwitch3_float; /* sim_correnti_tensioni/Multiport Signal Switch3 */
   bool MultiportSignalSwitch1_bool; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   int32_t MultiportSignalSwitch1_int32_t; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   float MultiportSignalSwitch1_float; /* sim_correnti_tensioni/Multiport Signal Switch1 */
   bool Comparator1_16;             /* sim_correnti_tensioni/Comparator1 */
   bool Monoflop1_16;               /* sim_correnti_tensioni/Monoflop1 */
   float sim_correnti_tensioni_i1;  /* sim_correnti_tensioni */
   float C_Script;                  /* sim_correnti_tensioni/White Noise/C-Script */
   float Input10[17];               /* sim_correnti_tensioni/Input10 */
   bool CompareToConstant;          /* sim_correnti_tensioni/Signal Builder62/Compare to Constant */
   bool CompareToConstant_1;        /* sim_correnti_tensioni/Signal Builder61/Compare to Constant */
   bool CompareToConstant_2;        /* sim_correnti_tensioni/Signal Builder63/Compare to Constant */
   float Input00[8];                /* sim_correnti_tensioni/Input00 */
   float Integrator7;               /* sim_correnti_tensioni/Signal Builder62/Integrator7 */
   float Integrator6;               /* sim_correnti_tensioni/Signal Builder62/Integrator6 */
   float Integrator4;               /* sim_correnti_tensioni/Signal Builder62/Integrator4 */
   float Sum1;                      /* sim_correnti_tensioni/Signal Builder62/Sum1 */
   float Input01[8];                /* sim_correnti_tensioni/Input01 */
   float Integrator7_1;             /* sim_correnti_tensioni/Signal Builder61/Integrator7 */
   float Integrator6_1;             /* sim_correnti_tensioni/Signal Builder61/Integrator6 */
   float Integrator4_1;             /* sim_correnti_tensioni/Signal Builder61/Integrator4 */
   float Sum1_1;                    /* sim_correnti_tensioni/Signal Builder61/Sum1 */
   float Input02[8];                /* sim_correnti_tensioni/Input02 */
   float Integrator7_2;             /* sim_correnti_tensioni/Signal Builder63/Integrator7 */
   float Integrator6_2;             /* sim_correnti_tensioni/Signal Builder63/Integrator6 */
   float Integrator4_2;             /* sim_correnti_tensioni/Signal Builder63/Integrator4 */
   float Sum1_2;                    /* sim_correnti_tensioni/Signal Builder63/Sum1 */
   float Input03[8];                /* sim_correnti_tensioni/Input03 */
   bool CompareToConstant_3;        /* sim_correnti_tensioni/Signal Builder64/Compare to Constant */
   float Integrator7_3;             /* sim_correnti_tensioni/Signal Builder64/Integrator7 */
   float Integrator6_3;             /* sim_correnti_tensioni/Signal Builder64/Integrator6 */
   float Integrator4_3;             /* sim_correnti_tensioni/Signal Builder64/Integrator4 */
   float Sum1_3;                    /* sim_correnti_tensioni/Signal Builder64/Sum1 */
   float Input04[8];                /* sim_correnti_tensioni/Input04 */
   bool CompareToConstant_4;        /* sim_correnti_tensioni/Signal Builder65/Compare to Constant */
   float Integrator7_4;             /* sim_correnti_tensioni/Signal Builder65/Integrator7 */
   float Integrator6_4;             /* sim_correnti_tensioni/Signal Builder65/Integrator6 */
   float Integrator4_4;             /* sim_correnti_tensioni/Signal Builder65/Integrator4 */
   float Sum1_4;                    /* sim_correnti_tensioni/Signal Builder65/Sum1 */
   float Input05[8];                /* sim_correnti_tensioni/Input05 */
   bool CompareToConstant_5;        /* sim_correnti_tensioni/Signal Builder66/Compare to Constant */
   float Integrator7_5;             /* sim_correnti_tensioni/Signal Builder66/Integrator7 */
   float Integrator6_5;             /* sim_correnti_tensioni/Signal Builder66/Integrator6 */
   float Integrator4_5;             /* sim_correnti_tensioni/Signal Builder66/Integrator4 */
   float Sum1_5;                    /* sim_correnti_tensioni/Signal Builder66/Sum1 */
   float Input06[8];                /* sim_correnti_tensioni/Input06 */
   bool CompareToConstant_6;        /* sim_correnti_tensioni/Signal Builder67/Compare to Constant */
   float Integrator7_6;             /* sim_correnti_tensioni/Signal Builder67/Integrator7 */
   float Integrator6_6;             /* sim_correnti_tensioni/Signal Builder67/Integrator6 */
   float Integrator4_6;             /* sim_correnti_tensioni/Signal Builder67/Integrator4 */
   float Sum1_6;                    /* sim_correnti_tensioni/Signal Builder67/Sum1 */
   float Input07[8];                /* sim_correnti_tensioni/Input07 */
   bool CompareToConstant_7;        /* sim_correnti_tensioni/Signal Builder68/Compare to Constant */
   float Integrator7_7;             /* sim_correnti_tensioni/Signal Builder68/Integrator7 */
   float Integrator6_7;             /* sim_correnti_tensioni/Signal Builder68/Integrator6 */
   float Integrator4_7;             /* sim_correnti_tensioni/Signal Builder68/Integrator4 */
   float Sum1_7;                    /* sim_correnti_tensioni/Signal Builder68/Sum1 */
   float Input08[8];                /* sim_correnti_tensioni/Input08 */
   bool CompareToConstant_8;        /* sim_correnti_tensioni/Signal Builder69/Compare to Constant */
   float Integrator7_8;             /* sim_correnti_tensioni/Signal Builder69/Integrator7 */
   float Integrator6_8;             /* sim_correnti_tensioni/Signal Builder69/Integrator6 */
   float Integrator4_8;             /* sim_correnti_tensioni/Signal Builder69/Integrator4 */
   float Sum1_8;                    /* sim_correnti_tensioni/Signal Builder69/Sum1 */
   float Input09[8];                /* sim_correnti_tensioni/Input09 */
   bool CompareToConstant_9;        /* sim_correnti_tensioni/Signal Builder70/Compare to Constant */
   float Integrator7_9;             /* sim_correnti_tensioni/Signal Builder70/Integrator7 */
   float Integrator6_9;             /* sim_correnti_tensioni/Signal Builder70/Integrator6 */
   float Integrator4_9;             /* sim_correnti_tensioni/Signal Builder70/Integrator4 */
   float Sum1_9;                    /* sim_correnti_tensioni/Signal Builder70/Sum1 */
   float Input0A[8];                /* sim_correnti_tensioni/Input0A */
   bool CompareToConstant_10;       /* sim_correnti_tensioni/Signal Builder71/Compare to Constant */
   float Integrator7_10;            /* sim_correnti_tensioni/Signal Builder71/Integrator7 */
   float Integrator6_10;            /* sim_correnti_tensioni/Signal Builder71/Integrator6 */
   float Integrator4_10;            /* sim_correnti_tensioni/Signal Builder71/Integrator4 */
   float Sum1_10;                   /* sim_correnti_tensioni/Signal Builder71/Sum1 */
   float Input0B[8];                /* sim_correnti_tensioni/Input0B */
   bool CompareToConstant_11;       /* sim_correnti_tensioni/Signal Builder72/Compare to Constant */
   float Integrator7_11;            /* sim_correnti_tensioni/Signal Builder72/Integrator7 */
   float Integrator6_11;            /* sim_correnti_tensioni/Signal Builder72/Integrator6 */
   float Integrator4_11;            /* sim_correnti_tensioni/Signal Builder72/Integrator4 */
   float Sum1_11;                   /* sim_correnti_tensioni/Signal Builder72/Sum1 */
   float Input0C[8];                /* sim_correnti_tensioni/Input0C */
   bool CompareToConstant_12;       /* sim_correnti_tensioni/Signal Builder73/Compare to Constant */
   float Integrator7_12;            /* sim_correnti_tensioni/Signal Builder73/Integrator7 */
   float Integrator6_12;            /* sim_correnti_tensioni/Signal Builder73/Integrator6 */
   float Integrator4_12;            /* sim_correnti_tensioni/Signal Builder73/Integrator4 */
   float Sum1_12;                   /* sim_correnti_tensioni/Signal Builder73/Sum1 */
   float Input0D[8];                /* sim_correnti_tensioni/Input0D */
   bool CompareToConstant_13;       /* sim_correnti_tensioni/Signal Builder74/Compare to Constant */
   float Integrator7_13;            /* sim_correnti_tensioni/Signal Builder74/Integrator7 */
   float Integrator6_13;            /* sim_correnti_tensioni/Signal Builder74/Integrator6 */
   float Integrator4_13;            /* sim_correnti_tensioni/Signal Builder74/Integrator4 */
   float Sum1_13;                   /* sim_correnti_tensioni/Signal Builder74/Sum1 */
   float Input0E[8];                /* sim_correnti_tensioni/Input0E */
   bool CompareToConstant_14;       /* sim_correnti_tensioni/Signal Builder75/Compare to Constant */
   float Integrator7_14;            /* sim_correnti_tensioni/Signal Builder75/Integrator7 */
   float Integrator6_14;            /* sim_correnti_tensioni/Signal Builder75/Integrator6 */
   float Integrator4_14;            /* sim_correnti_tensioni/Signal Builder75/Integrator4 */
   float Sum1_14;                   /* sim_correnti_tensioni/Signal Builder75/Sum1 */
   float Input0F[8];                /* sim_correnti_tensioni/Input0F */
   bool CompareToConstant_15;       /* sim_correnti_tensioni/Signal Builder76/Compare to Constant */
   float Integrator7_15;            /* sim_correnti_tensioni/Signal Builder76/Integrator7 */
   float Integrator6_15;            /* sim_correnti_tensioni/Signal Builder76/Integrator6 */
   float Integrator4_15;            /* sim_correnti_tensioni/Signal Builder76/Integrator4 */
   float Sum1_15;                   /* sim_correnti_tensioni/Signal Builder76/Sum1 */
   float Product19;                 /* sim_correnti_tensioni/Signal Builder62/Product19 */
   float Product19_1;               /* sim_correnti_tensioni/Signal Builder61/Product19 */
   float Product19_2;               /* sim_correnti_tensioni/Signal Builder63/Product19 */
   float Product19_3;               /* sim_correnti_tensioni/Signal Builder64/Product19 */
   float Product19_4;               /* sim_correnti_tensioni/Signal Builder65/Product19 */
   float Product19_5;               /* sim_correnti_tensioni/Signal Builder66/Product19 */
   float Product19_6;               /* sim_correnti_tensioni/Signal Builder67/Product19 */
   float Product19_7;               /* sim_correnti_tensioni/Signal Builder68/Product19 */
   float Product19_8;               /* sim_correnti_tensioni/Signal Builder69/Product19 */
   float Product19_9;               /* sim_correnti_tensioni/Signal Builder70/Product19 */
   float Product19_10;              /* sim_correnti_tensioni/Signal Builder71/Product19 */
   float Product19_11;              /* sim_correnti_tensioni/Signal Builder72/Product19 */
   float Product19_12;              /* sim_correnti_tensioni/Signal Builder73/Product19 */
   float Product19_13;              /* sim_correnti_tensioni/Signal Builder74/Product19 */
   float Product19_14;              /* sim_correnti_tensioni/Signal Builder75/Product19 */
   float Product19_15;              /* sim_correnti_tensioni/Signal Builder76/Product19 */
} sim_correnti_tensioni_BlockOutputs;
extern sim_correnti_tensioni_BlockOutputs sim_correnti_tensioni_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define sim_correnti_tensioni_NumExtModeSignals 6
extern const float * const sim_correnti_tensioni_ExtModeSignals[];
/* Tunable parameters */
#define sim_correnti_tensioni_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void sim_correnti_tensioni_initialize(float time);
void sim_correnti_tensioni_step(int task_id);
void sim_correnti_tensioni_terminate(void);
void sim_correnti_tensioni_sync(void);
#endif /* PLECS_HEADER_sim_correnti_tensioni_h_ */
