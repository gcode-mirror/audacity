/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2001             *
 * by the XIPHOPHORUS Company http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: key psychoacoustic settings for 44.1/48kHz
 last mod: $Id: psych_44.h,v 1.1.1.1 2002-04-21 23:36:46 habes Exp $

 ********************************************************************/


/* preecho trigger settings *****************************************/

static vorbis_info_psy_global _psy_global_44[3]={

  {8,   /* lines per eighth octave */
   /*{990.f,990.f,990.f,990.f}, {-990.f,-990.f,-990.f,-990.f}, -90.f,
   {0.f,0.f,0.f,0.f}, {-0.f,-0.f,-0.f,-0.f}, -90.f,*/
   {30.f,30.f,30.f,34.f}, {-990.f,-990.f,-990.f,-990.f}, -90.f,
   -6.f, 0,
  },
  {8,   /* lines per eighth octave */
   /*{990.f,990.f,990.f,990.f}, {-990.f,-990.f,-990.f,-990.f}, -90.f,*/
   {26.f,26.f,26.f,30.f}, {-90.f,-90.f,-90.f,-90.f}, -90.f,
   -6.f, 0,
  },
  {8,   /* lines per eighth octave */
   {26.f,26.f,26.f,30.f}, {-26.f,-26.f,-26.f,-30.f}, -90.f,
   -6.f, 0,
  }
};

/* noise compander lookups * low, mid, high quality ****************/

static float _psy_compand_44_short[3][NOISE_COMPAND_LEVELS]={
  /* sub-mode Z */
  {
    0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f,  7.f,     /* 7dB */
    8.f, 9.f,10.f,11.f,12.f,13.f,14.f, 15.f,     /* 15dB */
    16.f,17.f,18.f,19.f,20.f,21.f,22.f, 23.f,     /* 23dB */
    24.f,25.f,26.f,27.f,28.f,29.f,30.f, 31.f,     /* 31dB */
    32.f,33.f,34.f,35.f,36.f,37.f,38.f, 39.f,     /* 39dB */
  },
  /* mode_Z nominal */
  {
     0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f,  6.f,     /* 7dB */
     7.f, 7.f, 7.f, 7.f, 6.f, 6.f, 6.f,  7.f,     /* 15dB */
     7.f, 8.f, 9.f,10.f,11.f,12.f,13.f, 14.f,     /* 23dB */
    15.f,16.f,17.f,17.f,17.f,18.f,18.f, 19.f,     /* 31dB */
    19.f,19.f,20.f,21.f,22.f,23.f,24.f, 25.f,     /* 39dB */
  },
  /* mode A */
  {
    0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 5.f,  5.f,     /* 7dB */
    6.f, 6.f, 6.f, 5.f, 4.f, 4.f, 4.f,  4.f,     /* 15dB */
    4.f, 4.f, 5.f, 5.f, 5.f, 6.f, 6.f,  6.f,     /* 23dB */
    7.f, 7.f, 7.f, 8.f, 8.f, 8.f, 9.f, 10.f,     /* 31dB */
    11.f,12.f,13.f,14.f,15.f,16.f,17.f, 18.f,     /* 39dB */
  }
};

static float _psy_compand_44[3][NOISE_COMPAND_LEVELS]={
  /* sub-mode Z */
  {
     0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f,  7.f,     /* 7dB */
     8.f, 9.f,10.f,11.f,12.f,13.f,14.f, 15.f,     /* 15dB */
    16.f,17.f,18.f,19.f,20.f,21.f,22.f, 23.f,     /* 23dB */
    24.f,25.f,26.f,27.f,28.f,29.f,30.f, 31.f,     /* 31dB */
    32.f,33.f,34.f,35.f,36.f,37.f,38.f, 39.f,     /* 39dB */
  },
  /* mode_Z nominal */
  {
    0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f,  7.f,     /* 7dB */
    8.f, 9.f,10.f,11.f,12.f,12.f,13.f, 13.f,     /* 15dB */
    13.f,14.f,14.f,14.f,15.f,15.f,15.f, 15.f,     /* 23dB */
    16.f,16.f,17.f,17.f,17.f,18.f,18.f, 19.f,     /* 31dB */
    19.f,19.f,20.f,21.f,22.f,23.f,24.f, 25.f,     /* 39dB */
  },
  /* mode A */
  {
    0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f,  7.f,     /* 7dB */
    8.f, 8.f, 7.f, 6.f, 5.f, 4.f, 4.f,  4.f,     /* 15dB */
    4.f, 4.f, 5.f, 5.f, 5.f, 6.f, 6.f,  6.f,     /* 23dB */
    7.f, 7.f, 7.f, 8.f, 8.f, 8.f, 9.f, 10.f,     /* 31dB */
    11.f,12.f,13.f,14.f,15.f,16.f,17.f, 18.f,     /* 39dB */
  }
};

/* tonal masking curve level adjustments *************************/
static vp_adjblock _vp_tonemask_adj_longblock[6]={
  /* adjust for mode zero */
  {{
    { 10, 10,  5,                               }, /*63*/
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 125 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 250 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 500 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 1000 */
    { 10, 10,  5,                               }, 

    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /* 2000 */
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /* 4000 */
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /* 8000 */
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 
    { 16, 16, 14, 12, 12, 15, 15, 15, 15, 15, 10}, /* 16000 */
  }},

  /* adjust for mode two */
  {{
    { 10, 10,  5,                               }, /*63*/
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 125 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 250 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 500 */
    { 10, 10,  5,                               }, 
    { 10, 10,  5,                               }, /* 1000 */
    { 10, 10,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    { 10,  5,  5,                               }, /* 4000 */
    { 10, 10,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  7,  5,  5, 10, 10, 10,  5,   }, 
    { 16, 16, 14,  8,  8,  8, 10, 10, 10,  5,   }, /* 16000 */
  }},

  /* adjust for mode four */
  {{
    { 10,  5,  5,                               }, /*63*/
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 125 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 250 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 500 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 1000 */
    { 10,  5,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    { 10,  5,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  5,  5,  5, 10, 10, 10,  5,   }, 
    { 16, 16, 14,  8,  8,  8, 10, 10, 10,  5,   }, /* 16000 */
  }},

  /* adjust for mode six */
  {{
    { 10,  5,  5,                               }, /*63*/
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 125 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 250 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 500 */
    { 10,  5,  5,                               }, 
    { 10,  5,  5,                               }, /* 1000 */
    { 10,  5,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    { 10,  5,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  5,  5,  5,  5,  5,  5,       }, 
    { 12, 10, 10,  5,  5,  5,  5,  5,  5,       }, /* 16000 */
  }},

  /* adjust for mode eight */
  {{
    {  0,                                       }, /*63*/
    {  0,                                       }, 
    {  0,                                       }, /* 125 */
    {  0,                                       }, 
    {  0,                                       }, /* 250 */
    {  0,                                       }, 
    {  0,                                       }, /* 500 */
    {  0,                                       }, 
    {  0,                                       }, /* 1000 */
    {  0,                                       }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    {  0,                                       },
    {  0,                                       }, /* 8000 */
    {  0,                                       }, 
    {  5,  5,  5,  5,  5,  5,  5,               }, /* 16000 */
  }},

  /* adjust for mode ten */
  {{
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*63*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*125*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*250*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15},
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*500*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*1000*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*2000*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*4000*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*8000*/
    {  0,  0,  0, -5,-10,-10,-10,-15,-15,-15,-15}, 
    {  0,  0,  0,  0,  0, -5, -5,-10,-15,-15,-15}, /*16000*/
  }},
};

static vp_adjblock _vp_tonemask_adj_otherblock[6]={
  /* adjust for mode zero */
  {{
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*63*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*125*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*250*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  5,  5,  5,  0, -5, -5, -5, -5, -5, -5, -5}, /*500*/
    {  5,  5,  5,  0, -5, -5, -5, -5, -5, -5, -5},

    {  5,  5,  5,                               }, /*1000*/
    {  5,  5,  5,                               }, 

    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /*2000*/
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /*4000*/
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, /*8000*/
    { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 
    { 16, 16, 14, 12, 12, 15, 15, 15, 15, 15, 10}, /*16000*/
  }},

  /* adjust for mode two */
  {{
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*63*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*125*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, /*250*/
    {  0,  0,  0,  0,-10,-10,-10,-10,-10,-10,-10}, 
    {  5,  5,  5,  0, -5, -5, -5, -5, -5, -5, -5}, /*500*/
    {  5,  5,  5,  0, -5, -5, -5, -5, -5, -5, -5},

    { 10, 10,  5,                               }, /* 1000 */
    { 10, 10,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    { 10,  5,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  7,  5,  5, 10, 10, 10,  5,   }, 
    { 16, 16, 14,  8,  8,  8, 10, 10, 10,  5,   }, /* 16000 */
  }},

  /* adjust for mode four */
  {{
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*63*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*125*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*250*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*500*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 

    {  5,  5,  5,                               }, /* 1000 */
    {  5,  5,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    { 10,  5,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  5,  5,  5, 10, 10, 10,  5,   }, 
    { 16, 16, 14,  8,  8,  8, 10, 10, 10,  5,   }, /* 16000 */
  }},

  /* adjust for mode six */
  {{
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*63*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*125*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*250*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*500*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 

    {  5,  5,  5,                               }, /* 1000 */
    {  5,  5,  5,                               }, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    { 10,  5,  5,                               },
    { 10, 10,  7,  5,                           }, /* 8000 */
    { 10, 10,  7,  5,  5,  5,  5,  5,  5,       }, 
    { 12, 10, 10,  5,  5,  5,  5,  5,  5,       }, /* 16000 */
  }},

  /* adjust for mode eight */
  {{
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, /*63*/
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, 
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, /*125*/
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, 
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, /*250*/
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, 
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, /*500*/
    {-10,-10,-10,-15,-15,-15,-15,-20,-20,-20,-20}, 

    {  0,-10,-10,-15,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,-10,-10,-15,-15,-15,-15,-15,-15,-15,-15}, 

    {  0,                                       }, /* 2000 */
    {  0,                                       },
    {  0,                                       }, /* 4000 */
    {  0,                                       },
    {  0,                                       }, /* 8000 */
    {  0,                                       }, 
    {  5,  5,  5,  5,  5,  5,  5,               }, /* 16000 */
  }},

  /* adjust for mode ten */
  {{
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, /*63*/
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, 
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, /*125*/
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, 
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, /*250*/
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20},
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, /*500*/
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, 
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, /*1000*/
    {  0,  0,  0, -5,-15,-20,-20,-20,-20,-20,-20}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*2000*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*4000*/
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, 
    {  0,  0,  0, -5,-15,-15,-15,-15,-15,-15,-15}, /*8000*/
    {  0,  0,  0, -5,-10,-10,-10,-15,-15,-15,-15}, 
    {  0,  0,  0,  0,  0, -5, -5,-10,-15,-15,-15}, /*16000*/
  }},
};

static vp_adjblock _vp_peakguard[6]={
  /* zero */
  {{
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},/*63*/
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},/*125*/
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},/*250*/
    {-14,-16,-18,-19,-24,-24,-24,-24,-24,-24,-24},
    {-10,-10,-10,-10,-16,-16,-18,-20,-22,-24,-24},/*500*/
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-24,-24},
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-24,-24},/*1000*/
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-24,-24},
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-24,-24},/*2000*/
    {-10,-10,-10,-12,-16,-16,-16,-20,-22,-24,-24},
    {-10,-10,-10,-12,-16,-16,-16,-20,-22,-24,-24},/*4000*/
    {-10,-10,-10,-12,-12,-14,-16,-18,-22,-24,-24},
    {-10,-10,-10,-10,-10,-14,-16,-18,-22,-24,-24},/*8000*/
    {-10,-10,-10,-10,-10,-14,-16,-18,-22,-24,-24},
    {-10,-10,-10,-10,-10,-12,-16,-18,-22,-24,-24},/*16000*/
  }},
  /* two */
  {{
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},/*63*/
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},/*125*/
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},/*250*/
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},
    {-14,-20,-20,-20,-26,-30,-30,-30,-30,-30,-30},/*500*/
    {-10,-10,-10,-10,-14,-14,-14,-20,-26,-30,-30},
    {-10,-10,-10,-10,-14,-14,-14,-20,-22,-30,-30},/*1000*/
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-30,-30},
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-30,-30},/*2000*/
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-30,-30},
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-30,-30},/*4000*/
    {-10,-10,-10,-10,-10,-11,-12,-13,-22,-30,-30},
    {-10,-10,-10,-10,-10,-11,-12,-13,-22,-30,-30},/*8000*/
    {-10,-10,-10,-10,-10,-10,-10,-11,-22,-30,-30},
    {-10,-10,-10,-10,-10,-10,-10,-10,-20,-30,-30},/*16000*/
  }},
  /* four */
  {{
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*63*/
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*125*/
    {-14,-20,-20,-20,-20,-20,-20,-30,-32,-32,-40},
    {-14,-20,-20,-20,-20,-20,-20,-30,-32,-32,-40},/*250*/
    {-14,-20,-20,-20,-20,-20,-20,-24,-32,-32,-40},
    {-14,-20,-20,-20,-20,-20,-20,-24,-32,-32,-40},/*500*/
    {-10,-10,-10,-10,-14,-16,-20,-24,-26,-32,-40},
    {-10,-10,-10,-10,-14,-16,-20,-24,-22,-32,-40},/*1000*/
    {-10,-10,-10,-10,-14,-16,-20,-24,-22,-32,-40},
    {-10,-10,-10,-10,-14,-16,-20,-24,-22,-32,-40},/*2000*/
    {-10,-10,-10,-10,-14,-16,-20,-24,-22,-32,-40},
    {-10,-10,-10,-10,-14,-14,-16,-20,-22,-32,-40},/*4000*/
    {-10,-10,-10,-10,-10,-11,-12,-13,-22,-32,-40},
    {-10,-10,-10,-10,-10,-11,-12,-13,-22,-32,-40},/*8000*/
    {-10,-10,-10,-10,-10,-10,-10,-11,-22,-32,-40},
    {-10,-10,-10,-10,-10,-10,-10,-10,-20,-32,-40},/*16000*/
  }},
  /* six */
  {{
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*63*/
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*125*/
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*250*/
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},
    {-14,-20,-20,-20,-26,-32,-32,-32,-32,-32,-40},/*500*/
    {-14,-14,-14,-16,-20,-22,-24,-24,-28,-32,-40},
    {-14,-14,-14,-16,-20,-22,-24,-24,-28,-32,-40},/*1000*/
    {-14,-14,-14,-16,-20,-22,-24,-24,-28,-32,-40},
    {-14,-14,-16,-20,-24,-26,-26,-28,-30,-32,-40},/*2000*/
    {-14,-14,-16,-20,-24,-26,-26,-28,-30,-32,-40},
    {-14,-14,-16,-20,-24,-26,-26,-28,-30,-32,-40},/*4000*/
    {-14,-14,-14,-20,-22,-22,-24,-24,-26,-32,-40},
    {-14,-14,-14,-18,-20,-20,-24,-24,-24,-32,-40},/*8000*/
    {-14,-14,-14,-18,-20,-20,-24,-24,-24,-32,-40},
    {-14,-14,-14,-18,-20,-20,-22,-24,-24,-32,-40},/*16000*/
  }},
  /* eight */
  {{
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*63*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*88*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*125*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*170*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*250*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*350*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*500*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*700*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*1000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*1400*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*2000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*2800*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*4000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*5600*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*8000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*11500*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-40,-40},/*16600*/
  }},
  /* ten */
  {{
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*63*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*88*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*125*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*170*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*250*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*350*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*500*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*700*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*1000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*1400*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*2000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*2800*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*4000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*5600*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*8000*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*11500*/
    {-14,-20,-24,-26,-32,-34,-36,-38,-40,-44,-46},/*16600*/
  }}
};

static int _psy_noisebias_long[11][17]={
  /*63     125     250     500      1k       2k      4k      8k     16k*/
  {-20,-20,-18,-18,-18,-16,-14, -8, -6, -2,  0,  2,  3,  3,  4,  4, 10},
  {-20,-20,-20,-20,-20,-20,-20,-10, -6, -2, -2, -2,  1,  1,  2,  2,  4},
  {-20,-20,-20,-20,-20,-20,-20,-10, -6, -2, -3, -3, -1, -1,  0,  1,  2},
  {-20,-20,-20,-20,-20,-20,-20,-10, -6, -2, -3, -3, -1, -1,  0,  1,  2},
  {-20,-20,-20,-20,-20,-20,-20,-10, -6, -3, -4, -4, -2, -1,  0,  0,  2},

  {-20,-20,-20,-20,-20,-20,-20,-18,-10, -4, -6, -6, -3, -2, -2, -2,  0},
  {-24,-24,-24,-24,-24,-24,-24,-18,-14, -8, -8, -8, -7, -7, -6, -6, -4},
  {-24,-24,-24,-24,-24,-24,-24,-18,-14,-14,-16,-16,-14,-12,-10,-10, -8},

  {-24,-24,-24,-24,-24,-24,-24,-20,-20,-20,-20,-20,-16,-16,-14,-14,-10},
  {-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-24,-24,-24,-24},
  {-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-46},
};

static int _psy_noisebias_impulse[11][17]={
  /*63     125     250     500      1k       2k      4k      8k     16k*/
  {-20,-20,-20,-20,-20,-18,-14,-10,-10, -2,  2,  2,  2,  2,  2,  3,  6},
  {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -4, -4, -2, -2, -2, -2,  2},
  {-30,-30,-30,-30,-26,-22,-20,-14,-10, -6, -6, -6, -4, -4, -4, -2,  0},
  {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -6, -6, -4, -4, -4, -2, -2},
  {-30,-30,-30,-30,-30,-24,-20,-14,-10, -6, -8, -8, -6, -6, -6, -4, -2},

  {-30,-30,-30,-30,-30,-30,-24,-20,-10,-12,-14,-14,-10, -9, -8, -6, -4},
  {-34,-34,-34,-34,-30,-30,-24,-20,-14,-14,-16,-16,-14,-12,-10,-10, -8},
  {-34,-34,-34,-34,-30,-30,-30,-24,-20,-20,-20,-20,-20,-18,-16,-16,-14},

  {-34,-34,-34,-34,-30,-30,-30,-30,-30,-26,-26,-26,-26,-22,-20,-20,-16},
  {-40,-40,-40,-40,-40,-40,-40,-40,-40,-36,-36,-36,-36,-36,-36,-30,-30},
  {-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50},
};

static int _psy_noisebias_other[11][17]={
  /*63     125     250     500      1k       2k      4k      8k     16k*/
  {-20,-20,-20,-20,-20,-18,-14,-10, -6, -2,  2,  2,  3,  3,  4,  4, 10},
  {-26,-26,-26,-26,-26,-22,-20,-14,-10, -2, -2, -2,  1,  1,  2,  2,  4},
  {-30,-30,-30,-30,-26,-22,-20,-14,-10, -2, -3, -3, -1, -1,  0,  1,  2},
  {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -3, -3, -1, -1,  0,  1,  2},
  {-30,-30,-30,-30,-26,-22,-20,-14,-10, -4, -4, -4, -2, -1,  0,  0,  2},

  {-30,-30,-30,-30,-30,-30,-24,-20,-10, -4, -6, -6, -3, -2, -2, -2,  0},
  {-34,-34,-34,-34,-30,-30,-24,-20,-14, -8, -8, -8, -7, -7, -6, -6, -4},
  {-34,-34,-34,-34,-30,-30,-24,-20,-14,-14,-16,-16,-14,-12,-10,-10, -8},

  {-34,-34,-34,-34,-30,-30,-30,-20,-20,-20,-20,-20,-16,-16,-14,-14,-10},
  {-40,-40,-40,-40,-40,-40,-40,-30,-30,-30,-30,-30,-30,-24,-24,-24,-24},
  {-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-50,-46},
};

static int _psy_noiseguards_short[33]={
  2,2,-1,
  4,4,-1,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
  4,4,15,
};
static int _psy_noiseguards_long[33]={
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
  10,10,100,
};

static double _psy_tone_masteratt[11]={
  3.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
};

static double _psy_tone_masterguard[11]={
  -18.,-24.,-24.,-24.,-26.,-40.,-40.,-40.,-45.,-45.,-45.,
};

static double _psy_tone_suppress[11]={
  -10.,-20.,-20.,-20.,-30.,-30.,-40.,-40.,-45.,-45.,-45.,
};

static double _psy_tone_0dB[11]={
  95.,95.,95.,95.,95.,105.,105.,105.,105.,105.,105.,
};

static double _psy_noise_suppress[11]={
   -0.,-24.,-24.,-24.,-24.,-30.,-40.,-40.,-45.,-45.,-45.,
};

static int _psy_ehmer_bandlimit[11]={
  0,0,0,0,4,4,30,30,30,30,30,
};

static vorbis_info_psy _psy_info_template={
    {-1},-110.,-140.,
    /* tonemask att,guard,suppr,curves  peakattp,curvelimitp,peaksettings*/
    0.f,            -40.f,-40.f, {{{0.}}},         1,          0,        {{{0.}}},
    
    /*noisemaskp,supp, low/high window, low/hi guard, minimum */
    1,          -0.f,         .5f, .5f,         0,0,0,
    {-1},{-1},105.f,{{-1,-1,{{-1,-1,-1,-1}}}}
};

/* ath ****************/

static double _psy_ath_floater[11]={
  -100.,-100.,-100.,-100.,-100.,-100.,-105.,-105.,-105.,-110.,-120.,
};

static double _psy_ath_abs[11]={
  -110.,-110.,-120.,-140.,-140.,-140.,-140.,-140.,-140.,-140.,-150.,
};

static float ATH_Bark_dB[][27]={
  {
     0.f,  15.f,  15.f,   15.f,   11.f,       10.f,   8.f,  7.f,   7.f,  7.f,
     6.f,   2.f,   0.f,    0.f,   -2.f,       -5.f,  -6.f, -6.f,  -4.f,  4.f,
    14.f,  20.f,  19.f,   17.f,   30.f,       60.f,  70.f,
  },
  {
    0.f,  15.f,  15.f,   15.f,   11.f,       10.f,   8.f,  7.f,   7.f,  7.f,
    6.f,   2.f,   0.f,    0.f,   -2.f,       -5.f,  -6.f, -6.f,  -4.f,  0.f,
    2.f,   6.f,   5.f,    5.f,   15.f,       30.f,  50.f,
  },
  {
    0.f,  15.f,  15.f,   15.f,   11.f,       10.f,   8.f,  7.f,   7.f,  7.f,
    6.f,   2.f,   0.f,    0.f,   -3.f,       -5.f,  -6.f, -6.f, -4.5f, -4.f,
    2.f,   6.f,   5.f,    5.f,   15.f,       20.f,  40.f,
  }
};

/* stereo ****************/
static int _psy_stereo_point_dB_44[11]={3,  3,  2,  2,   1,  0,  0,  0,  0,  0,  0};
static double _psy_stereo_point_kHz_44[2][11]={
  {4., 6., 6., 6., 10., 6., 6., 4., 4., 4., 4.},
  {6., 6., 6., 10., 10., 6., 6., 4., 4., 4., 4.}
};

/* lowpass **************/
static double _psy_lowpass_44[11]={
  15.1,15.8,16.5,17.9,20.5,48.,999.,999.,999.,999.,999.
};

/* management noise offset */

static double _bm_max_noise_offset[11]={
  1.,2.,3.,3.,4.,4.,4.,4.,4.,4.,4.
};