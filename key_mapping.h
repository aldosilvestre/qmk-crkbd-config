//Estos mapeos representan las distribuciones de QWERTY y DVORAK con su capa inferio correspondiente

#pragma once
#include QMK_KEYBOARD_H
#include "oled.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  KC_RACL
};

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum {
	TD_CAPLOCK,
	TD_F11,
	TD_F12
};

// Define teclas tap dancing de doble toque
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
    [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
};

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

#define KC_XXXXX KC_NO
#define PREV_T KC_MEDIA_PREV_TRACK
#define PSCREEN KC_PSCREEN
#define NEXT_T KC_MEDIA_NEXT_TRACK
#define CAP_LOC TD(TD_CAPLOCK)
#define TD_F11 TD(TD_F11)
#define TD_F12 TD(TD_F12)
#define RALTENT RALT_T(KC_ENT)
#define KC_INS KC_INSERT

//botones de funciones inferiores teclado izquierdo
#define _FUN_INF_IZQ_ KC_LGUI, LOWER, KC_SPC,
//botones de funciones inferiores teclado derecho
#define _FUN_INF_DER_ RALTENT , RAISE, KC_LALT

//botones layout ADJUST izquierda
#define __________LY_ADJ_IZQ1__________ RESET   , RGBRST  , KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,
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
#define ______QWERTY_DER_DEFAULT3______ KC_N    ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,

// LAYOUT IZQ LOWER
#define _______QWERTY_IZQ_LOWER1_______ KC_TAB  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,
#define _______QWERTY_IZQ_LOWER2_______ KC_LCTL , KC_MUTE , KC_VOLD , KC_VOLU , KC_PGUP , KC_PGDN ,
#define _______QWERTY_IZQ_LOWER3_______ CAP_LOC , TD_F11  , TD_F12  , KC_F3   , KC_F4   , KC_F5   ,

// LAYOUT DER LOWER
#define _______QWERTY_DER_LOWER1_______ KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
#define _______QWERTY_DER_LOWER2_______ KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, KC_HOME , KC_END  ,
#define _______QWERTY_DER_LOWER3_______ KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_XXXXX,

// LAYOUT IZQ RAISE
#define _______QWERTY_IZQ_RAISE1_______ KC_ESC  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,
#define _______QWERTY_IZQ_RAISE2_______ KC_LCTL , KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,
#define _______QWERTY_IZQ_RAISE3_______ CAP_LOC , KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,

// LAYOUT DER RAISE
#define _______QWERTY_DER_RAISE1_______ KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL  ,
#define _______QWERTY_DER_RAISE2_______ KC_MINS , KC_EQL  , KC_LCBR , KC_RCBR , KC_PIPE , KC_GRV  ,
#define _______QWERTY_DER_RAISE3_______ KC_UNDS , KC_PLUS , KC_LBRC , KC_RBRC , KC_BSLS , KC_TILD ,
/* END QWERTY CONFIG KEYBOARD */


/*
[> DVORAK CONFIG KEYBOARD <]
// LAYOUT IZQ DEFAULT
#define ______DVORAK_IZQ_DEFAULT1______
#define ______DVORAK_IZQ_DEFAULT2______
#define ______DVORAK_IZQ_DEFAULT3______

// LAYOUT DER DEFAULT
#define ______DVORAK_DER_DEFAULT1______
#define ______DVORAK_DER_DEFAULT2______
#define ______DVORAK_DER_DEFAULT3______

// LAYOUT IZQ LOWER
#define _______DVORAK_IZQ_LOWER1_______
#define _______DVORAK_IZQ_LOWER2_______
#define _______DVORAK_IZQ_LOWER3_______

// LAYOUT DER LOWER
#define _______DVORAK_DER_LOWER1_______
#define _______DVORAK_DER_LOWER2_______
#define _______DVORAK_DER_LOWER3_______

// LAYOUT IZQ RAISE
#define _______DVORAK_IZQ_RAISE1_______
#define _______DVORAK_IZQ_RAISE2_______
#define _______DVORAK_IZQ_RAISE3_______

// LAYOUT DER RAISE
#define _______DVORAK_DER_RAISE1_______
#define _______DVORAK_DER_RAISE2_______
#define _______DVORAK_DER_RAISE3_______

[> END DVORAK CONFIG KEYBOARD <]
*/

