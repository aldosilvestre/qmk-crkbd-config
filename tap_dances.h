#pragma once
#include QMK_KEYBOARD_H

enum {
	TD_CAPLOCK,
  TD_F10,
	TD_F11,
	TD_F12
};

#define CAP_LOC TD(TD_CAPLOCK)
#define F10_TD TD(TD_F10)
#define F11_TD TD(TD_F11)
#define F12_TD TD(TD_F12)

