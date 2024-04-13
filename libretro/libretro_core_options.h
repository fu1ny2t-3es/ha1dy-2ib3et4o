#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */


struct retro_core_option_v2_category option_cats_us[] = {
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_us[] = {
   {
      "handy_refresh_rate",
      "Video Refresh Rate",
      NULL,
      "Set video update frequency. Internally, the Lynx renders at a variable rate from 0 to 75Hz. Frames that occur between video update events will be dropped. Higher rates may increase video smoothness (depending on actual game frame rate) but can cause tearing on 60Hz displays.",
      NULL,
      NULL,
      {
         { "50",  "50Hz" },
         { "60",  "60Hz" },
         { "75",  "75Hz" },
         { "100", "100Hz" },
         { "120", "120Hz" },
         { NULL, NULL },
      },
      "75"
   },
   {
      "handy_rot",
      "Display Rotation",
      NULL,
      "Rotate the virtual console screen to achieve the correct layout of 'portrait' oriented games on a conventional (landscape) display.",
      NULL,
      NULL,
      {
         { "Auto", "Auto" },
         { "None", "Disabled" },
         { "270",  "Left" },
         { "180",  "Bottom" },
         { "90",   "Right" },
         { NULL, NULL },
      },
      "Auto"
   },
#if defined(FRONTEND_SUPPORTS_XRGB8888)
   {
      "handy_gfx_colors",
      "Color Depth (Restart Required)",
      NULL,
      "Specify number of colors to display on-screen. 24-bit significantly increases performance overheads and is not available on all platforms.",
      NULL,
      NULL,
      {
         { "16bit", "Thousands (16-bit)" },
         { "24bit", "Millions (24-bit)" },
         { NULL,    NULL },
      },
      "24bit"
   },
#endif
   {
      "handy_frameskip",
      "Frameskip",
      NULL,
      "Skip frames to avoid audio buffer under-run (crackling). Improves performance at the expense of visual smoothness. 'Auto' skips frames when advised by the frontend. 'Manual' utilizes the 'Frameskip Threshold (%)' setting.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     "Auto" },
         { "manual",   "Manual" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "handy_frameskip_threshold",
      "Frameskip Threshold (%)",
      NULL,
      "When 'Frameskip' is set to 'Manual', specifies the audio buffer occupancy threshold (percentage) below which frames will be skipped. Higher values reduce the risk of crackling by causing frames to be dropped more frequently.",
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "handy_crop_side",
      "Border Crop Left - Right",
      NULL,
      "Crop left and right sides of border.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "2",   NULL },
         { "4",   NULL },
         { "6",   NULL },
         { "8",   NULL },
         { "10",  NULL },
         { "12",  NULL },
         { "14",  NULL },
         { "16",  NULL },
         { "18",  NULL },
         { "20",  NULL },
         { "22",  NULL },
         { "24",  NULL },
         { "26",  NULL },
         { "28",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "handy_crop_top",
      "Border Crop Top - Bottom",
      NULL,
      "Crop top and bottom sides of border.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "2",   NULL },
         { "4",   NULL },
         { "6",   NULL },
         { "8",   NULL },
         { "10",  NULL },
         { "12",  NULL },
         { "14",  NULL },
         { "16",  NULL },
         { "18",  NULL },
         { "20",  NULL },
         { "22",  NULL },
         { "24",  NULL },
         { "26",  NULL },
         { "28",  NULL },
         { "30",  NULL },
         { "32",  NULL },
         { "34",  NULL },
         { "36",  NULL },
         { "38",  NULL },
         { "40",  NULL },
         { "42",  NULL },
         { "44",  NULL },
         { "46",  NULL },
         { "48",  NULL },
         { "50",  NULL },
         { "52",  NULL },
         { "54",  NULL },
         { "56",  NULL },
         { "58",  NULL },
         { "60",  NULL },
         { "62",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "handy_overclock",
      "CPU Overclock Multiplier",
      NULL,
      "Higher values can reduce slowdowns in games. WARNING: Can cause glitches and crashes.",
      NULL,
      NULL,
      {
         { "1", NULL },
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { NULL, NULL},
      },
      "1"
   },
   {
      "handy_lcd_ghosting",
      "LCD Ghosting Filter",
      NULL,
      "Apply an image 'ghosting' effect by blending multiple successive video frames. Mimics the display characteristics of the Lynx's LCD panel and helps to smooth the appearance of low frame rate games. Higher frame counts improve the effect at the expense of increased performance overheads.",
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "2frames",  "2 Frames" },
         { "3frames",  "3 Frames" },
         { "4frames",  "4 Frames" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "handy_master_volume",
      "Volume Level",
      NULL,
      NULL,
      NULL,
      NULL,
      {
         { "0", "0%" },
         { "1", "1%" },
         { "2", "2%" },
         { "3", "3%" },
         { "4", "4%" },
         { "5", "5%" },
         { "6", "6%" },
         { "7", "7%" },
         { "8", "8%" },
         { "9", "9%" },
         { "10", "10%" },
         { "11", "11%" },
         { "12", "12%" },
         { "13", "13%" },
         { "14", "14%" },
         { "15", "15%" },
         { "16", "16%" },
         { "17", "17%" },
         { "18", "18%" },
         { "19", "19%" },
         { "20", "20%" },
         { "21", "21%" },
         { "22", "22%" },
         { "23", "23%" },
         { "24", "24%" },
         { "25", "25%" },
         { "26", "26%" },
         { "27", "27%" },
         { "28", "28%" },
         { "29", "29%" },
         { "30", "30%" },
         { "31", "31%" },
         { "32", "32%" },
         { "33", "33%" },
         { "34", "34%" },
         { "35", "35%" },
         { "36", "36%" },
         { "37", "37%" },
         { "38", "38%" },
         { "39", "39%" },
         { "40", "40%" },
         { "41", "41%" },
         { "42", "42%" },
         { "43", "43%" },
         { "44", "44%" },
         { "45", "45%" },
         { "46", "46%" },
         { "47", "47%" },
         { "48", "48%" },
         { "49", "49%" },
         { "50", "50%" },
         { "51", "51%" },
         { "52", "52%" },
         { "53", "53%" },
         { "54", "54%" },
         { "55", "55%" },
         { "56", "56%" },
         { "57", "57%" },
         { "58", "58%" },
         { "59", "59%" },
         { "60", "60%" },
         { "61", "61%" },
         { "62", "62%" },
         { "63", "63%" },
         { "64", "64%" },
         { "65", "65%" },
         { "66", "66%" },
         { "67", "67%" },
         { "68", "68%" },
         { "69", "69%" },
         { "70", "70%" },
         { "71", "71%" },
         { "72", "72%" },
         { "73", "73%" },
         { "74", "74%" },
         { "75", "75%" },
         { "76", "76%" },
         { "77", "77%" },
         { "78", "78%" },
         { "79", "79%" },
         { "80", "80%" },
         { "81", "81%" },
         { "82", "82%" },
         { "83", "83%" },
         { "84", "84%" },
         { "85", "85%" },
         { "86", "86%" },
         { "87", "87%" },
         { "88", "88%" },
         { "89", "89%" },
         { "90", "90%" },
         { "91", "91%" },
         { "92", "92%" },
         { "93", "93%" },
         { "94", "94%" },
         { "95", "95%" },
         { "96", "96%" },
         { "97", "97%" },
         { "98", "98%" },
         { "99", "99%" },
         { "100", "100%" },
         { "101", "101%" },
         { "102", "102%" },
         { "103", "103%" },
         { "104", "104%" },
         { "105", "105%" },
         { "106", "106%" },
         { "107", "107%" },
         { "108", "108%" },
         { "109", "109%" },
         { "110", "110%" },
         { "111", "111%" },
         { "112", "112%" },
         { "113", "113%" },
         { "114", "114%" },
         { "115", "115%" },
         { "116", "116%" },
         { "117", "117%" },
         { "118", "118%" },
         { "119", "119%" },
         { "120", "120%" },
         { "121", "121%" },
         { "122", "122%" },
         { "123", "123%" },
         { "124", "124%" },
         { "125", "125%" },
         { "126", "126%" },
         { "127", "127%" },
         { "128", "128%" },
         { "129", "129%" },
         { "130", "130%" },
         { "131", "131%" },
         { "132", "132%" },
         { "133", "133%" },
         { "134", "134%" },
         { "135", "135%" },
         { "136", "136%" },
         { "137", "137%" },
         { "138", "138%" },
         { "139", "139%" },
         { "140", "140%" },
         { "141", "141%" },
         { "142", "142%" },
         { "143", "143%" },
         { "144", "144%" },
         { "145", "145%" },
         { "146", "146%" },
         { "147", "147%" },
         { "148", "148%" },
         { "149", "149%" },
         { "150", "150%" },
         { "151", "151%" },
         { "152", "152%" },
         { "153", "153%" },
         { "154", "154%" },
         { "155", "155%" },
         { "156", "156%" },
         { "157", "157%" },
         { "158", "158%" },
         { "159", "159%" },
         { "160", "160%" },
         { "161", "161%" },
         { "162", "162%" },
         { "163", "163%" },
         { "164", "164%" },
         { "165", "165%" },
         { "166", "166%" },
         { "167", "167%" },
         { "168", "168%" },
         { "169", "169%" },
         { "170", "170%" },
         { "171", "171%" },
         { "172", "172%" },
         { "173", "173%" },
         { "174", "174%" },
         { "175", "175%" },
         { "176", "176%" },
         { "177", "177%" },
         { "178", "178%" },
         { "179", "179%" },
         { "180", "180%" },
         { "181", "181%" },
         { "182", "182%" },
         { "183", "183%" },
         { "184", "184%" },
         { "185", "185%" },
         { "186", "186%" },
         { "187", "187%" },
         { "188", "188%" },
         { "189", "189%" },
         { "190", "190%" },
         { "191", "191%" },
         { "192", "192%" },
         { "193", "193%" },
         { "194", "194%" },
         { "195", "195%" },
         { "196", "196%" },
         { "197", "197%" },
         { "198", "198%" },
         { "199", "199%" },
         { "200", "200%" },
         { NULL, NULL },
      },
      "100"
   },
   {
      "handy_lowpass_filter",
      "Lowpass Filter",
      NULL,
      NULL,
      NULL,
      NULL,
      {
         { "0", "0%" },
         { "1", "1%" },
         { "2", "2%" },
         { "3", "3%" },
         { "4", "4%" },
         { "5", "5%" },
         { "6", "6%" },
         { "7", "7%" },
         { "8", "8%" },
         { "9", "9%" },
         { "10", "10%" },
         { "11", "11%" },
         { "12", "12%" },
         { "13", "13%" },
         { "14", "14%" },
         { "15", "15%" },
         { "16", "16%" },
         { "17", "17%" },
         { "18", "18%" },
         { "19", "19%" },
         { "20", "20%" },
         { "21", "21%" },
         { "22", "22%" },
         { "23", "23%" },
         { "24", "24%" },
         { "25", "25%" },
         { "26", "26%" },
         { "27", "27%" },
         { "28", "28%" },
         { "29", "29%" },
         { "30", "30%" },
         { "31", "31%" },
         { "32", "32%" },
         { "33", "33%" },
         { "34", "34%" },
         { "35", "35%" },
         { "36", "36%" },
         { "37", "37%" },
         { "38", "38%" },
         { "39", "39%" },
         { "40", "40%" },
         { "41", "41%" },
         { "42", "42%" },
         { "43", "43%" },
         { "44", "44%" },
         { "45", "45%" },
         { "46", "46%" },
         { "47", "47%" },
         { "48", "48%" },
         { "49", "49%" },
         { "50", "50%" },
         { "51", "51%" },
         { "52", "52%" },
         { "53", "53%" },
         { "54", "54%" },
         { "55", "55%" },
         { "56", "56%" },
         { "57", "57%" },
         { "58", "58%" },
         { "59", "59%" },
         { "60", "60%" },
         { "61", "61%" },
         { "62", "62%" },
         { "63", "63%" },
         { "64", "64%" },
         { "65", "65%" },
         { "66", "66%" },
         { "67", "67%" },
         { "68", "68%" },
         { "69", "69%" },
         { "70", "70%" },
         { "71", "71%" },
         { "72", "72%" },
         { "73", "73%" },
         { "74", "74%" },
         { "75", "75%" },
         { "76", "76%" },
         { "77", "77%" },
         { "78", "78%" },
         { "79", "79%" },
         { "80", "80%" },
         { "81", "81%" },
         { "82", "82%" },
         { "83", "83%" },
         { "84", "84%" },
         { "85", "85%" },
         { "86", "86%" },
         { "87", "87%" },
         { "88", "88%" },
         { "89", "89%" },
         { "90", "90%" },
         { "91", "91%" },
         { "92", "92%" },
         { "93", "93%" },
         { "94", "94%" },
         { "95", "95%" },
         { "96", "96%" },
         { "97", "97%" },
         { "98", "98%" },
         { "99", "99%" },
         { NULL, NULL },
      },
      "0"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us, /* RETRO_LANGUAGE_ENGLISH */
   &options_ja,      /* RETRO_LANGUAGE_JAPANESE */
   &options_fr,      /* RETRO_LANGUAGE_FRENCH */
   &options_es,      /* RETRO_LANGUAGE_SPANISH */
   &options_de,      /* RETRO_LANGUAGE_GERMAN */
   &options_it,      /* RETRO_LANGUAGE_ITALIAN */
   &options_nl,      /* RETRO_LANGUAGE_DUTCH */
   &options_pt_br,   /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   &options_pt_pt,   /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   &options_ru,      /* RETRO_LANGUAGE_RUSSIAN */
   &options_ko,      /* RETRO_LANGUAGE_KOREAN */
   &options_cht,     /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   &options_chs,     /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   &options_eo,      /* RETRO_LANGUAGE_ESPERANTO */
   &options_pl,      /* RETRO_LANGUAGE_POLISH */
   &options_vn,      /* RETRO_LANGUAGE_VIETNAMESE */
   &options_ar,      /* RETRO_LANGUAGE_ARABIC */
   &options_el,      /* RETRO_LANGUAGE_GREEK */
   &options_tr,      /* RETRO_LANGUAGE_TURKISH */
   &options_sk,      /* RETRO_LANGUAGE_SLOVAK */
   &options_fa,      /* RETRO_LANGUAGE_PERSIAN */
   &options_he,      /* RETRO_LANGUAGE_HEBREW */
   &options_ast,     /* RETRO_LANGUAGE_ASTURIAN */
   &options_fi,      /* RETRO_LANGUAGE_FINNISH */
   &options_id,      /* RETRO_LANGUAGE_INDONESIAN */
   &options_sv,      /* RETRO_LANGUAGE_SWEDISH */
   &options_uk,      /* RETRO_LANGUAGE_UKRAINIAN */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb,
      bool *categories_supported)
{
   unsigned version  = 0;
#ifndef HAVE_NO_LANGEXTRA
   unsigned language = 0;
#endif

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
#else
      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2,
            &options_us);
#endif
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
#ifndef HAVE_NO_LANGEXTRA
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
#endif
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

#ifndef HAVE_NO_LANGEXTRA
         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
#else
         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, option_v1_defs_us);
#endif
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

#ifndef HAVE_NO_LANGEXTRA
      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }
#endif

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
