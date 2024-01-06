#pragma once
#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY,
  LOWER,
  RAISE,
  ADJUST
};

enum layers {
	_DEFAULT,
	_LOWER,
	_RAISE,
	_ADJUST
};

#define KC_XXXXX KC_NO
#define PREV_T KC_MRWD
#define PSCREEN KC_PSCR
#define NEXT_T KC_MFFD
#define RESET QK_REBOOT

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)
//#define ADJUST MO(_ADJUST)

