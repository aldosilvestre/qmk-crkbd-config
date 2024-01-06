#pragma once
#include "keycodes.h"
#include "tap_dances.h"
#include "oled.h"
#include "keylogger.h"

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

//botones de funciones inferiores teclado izquierdo
#define _FUN_INF_IZQ_ KC_LGUI  , LOWER, KC_SPC,
//botones de funciones inferiores teclado derecho
#define _FUN_INF_DER_ KC_ENTER , RAISE, KC_LALT

//botones layout ADJUST izquierda
#define __________LY_ADJ_IZQ1__________ RESET   , KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,
#define __________LY_ADJ_IZQ2__________ RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , RGB_SPI , KC_BRIU ,
#define __________LY_ADJ_IZQ3__________ RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , RGB_SPD , KC_BRID ,

//botones layout ADJUST derecha
#define __________LY_ADJ_DER1__________ PSCREEN , KC_APP  , KC_INS  , KC_XXXXX, KC_XXXXX, KC_XXXXX,
#define __________LY_ADJ_DER2__________ PREV_T  , KC_MPLY , NEXT_T  , KC_XXXXX, KC_XXXXX, KC_XXXXX,
#define __________LY_ADJ_DER3__________ KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, RGB_RMOD,


/* QWERTY CONFIG KEYBOARD */
// LAYOUT IZQ DEFAULT
#define ______QWERTY_IZQ_DEFAULT1______ KC_ESC  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,
#define ______QWERTY_IZQ_DEFAULT2______ KC_LCTL ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,
#define ______QWERTY_IZQ_DEFAULT3______ CAP_LOC ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,

// LAYOUT DER DEFAULT
#define ______QWERTY_DER_DEFAULT1______ KC_Y    ,  KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC ,
#define ______QWERTY_DER_DEFAULT2______ KC_H    ,  KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
#define ______QWERTY_DER_DEFAULT3______ KC_N    ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , SC_RSPC ,

// LAYOUT IZQ LOWER
#define _______QWERTY_IZQ_LOWER1_______ KC_TAB  , F10_TD  , F11_TD  , F12_TD  , KC_HOME , KC_END  ,
#define _______QWERTY_IZQ_LOWER2_______ KC_LCTL , KC_F4   , KC_F5   , KC_F6   , KC_RALT , KC_XXXXX,
#define _______QWERTY_IZQ_LOWER3_______ CAP_LOC , KC_F7   , KC_F8   , KC_F9   , KC_PGUP , KC_PGDN ,

// LAYOUT DER LOWER
#define _______QWERTY_DER_LOWER1_______ KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_BSPC ,
#define _______QWERTY_DER_LOWER2_______ KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, KC_XXXXX, KC_XXXXX,
#define _______QWERTY_DER_LOWER3_______ KC_XXXXX, KC_MUTE , KC_VOLD , KC_VOLU , KC_XXXXX, KC_XXXXX,

// LAYOUT IZQ RAISE
#define _______QWERTY_IZQ_RAISE1_______ KC_ESC  , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,
#define _______QWERTY_IZQ_RAISE2_______ KC_LCTL , KC_DLR  , KC_PERC , KC_CIRC , KC_LCBR , KC_RCBR ,
#define _______QWERTY_IZQ_RAISE3_______ CAP_LOC , KC_EXLM , KC_AT   , KC_HASH , KC_LBRC , KC_RBRC ,

// LAYOUT DER RAISE
#define _______QWERTY_DER_RAISE1_______ KC_PLUS , KC_7    , KC_8    , KC_9    , KC_TILD , KC_DEL  ,
#define _______QWERTY_DER_RAISE2_______ KC_MINS , KC_4    , KC_5    , KC_6    , KC_0    , KC_GRV  ,
#define _______QWERTY_DER_RAISE3_______ KC_EQL  , KC_1    , KC_2    , KC_3    , KC_UNDS , KC_BSLS ,
/* END QWERTY CONFIG KEYBOARD */

/* DVORAK CONFIG KEYBOARD */
// LAYOUT IZQ DEFAULT
#define ______DVORAK_IZQ_DEFAULT1______ KC_ESC  ,  KC_SCLN,  KC_COMM,  KC_DOT ,  KC_P   ,  KC_Y   ,
#define ______DVORAK_IZQ_DEFAULT2______ KC_LCTL ,  KC_A   ,  KC_O   ,  KC_E   ,  KC_U   ,  KC_I   ,
#define ______DVORAK_IZQ_DEFAULT3______ KC_LOC  ,  KC_QUOT,  KC_Q   ,  KC_J   ,  KC_K   ,  KC_X   ,

// LAYOUT DER DEFAULT
#define ______DVORAK_DER_DEFAULT1______ KC_F    ,  KC_G   , KC_C    , KC_R    , KC_L    , KC_BSPC ,
#define ______DVORAK_DER_DEFAULT2______ KC_D    ,  KC_H   , KC_T    , KC_N    , KC_S    , KC_SLSH ,
#define ______DVORAK_DER_DEFAULT3______ KC_B    ,  KC_M   , KC_W    , KC_V    , KC_Z    , KC_RSPC ,

// LAYOUT IZQ LOWER
#define _______DVORAK_IZQ_LOWER1_______ KC_TAB  , KC_7    , KC_5    , KC_3    , KC_1    , KC_9    ,

// LAYOUT DER LOWER
#define _______DVORAK_DER_LOWER1_______ KC_0    , KC_2    , KC_4    , KC_6    , KC_8    , KC_PERC ,

// LAYOUT IZQ RAISE
#define _______DVORAK_IZQ_RAISE1_______ KC_ESC  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,

// LAYOUT DER RAISE
#define _______DVORAK_DER_RAISE1_______ KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL  ,
/* END DVORAK CONFIG KEYBOARD */


/* COLEMAK CONFIG KEYBOARD */
// LAYOUT IZQ DEFAULT
#define _____COLEMAK_IZQ_DEFAULT1______ KC_ESC  ,  KC_Q   ,  KC_W   ,  KC_F   ,  KC_P   ,  KC_G   ,
#define _____COLEMAK_IZQ_DEFAULT2______ KC_LCTL ,  KC_A   ,  KC_R   ,  KC_S   ,  KC_T   ,  KC_D   ,
#define _____COLEMAK_IZQ_DEFAULT3______ CAP_LOC ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,

// LAYOUT DER DEFAULT
#define _____COLEMAK_DER_DEFAULT1______ KC_J    ,  KC_L   , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
#define _____COLEMAK_DER_DEFAULT2______ KC_H    ,  KC_N   , KC_E    , KC_I    , KC_O    , KC_QUOT ,
#define _____COLEMAK_DER_DEFAULT3______ KC_K    ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,
/* END COLEMAK CONFIG KEYBOARD */

