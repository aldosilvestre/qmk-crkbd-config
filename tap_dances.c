#include "tap_dances.h"
#include QMK_KEYBOARD_H

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F10),
    [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F11),
    [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F12)
};
