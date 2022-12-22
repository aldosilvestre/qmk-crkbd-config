#include "key_mapping.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_wrapper(
  //,-----------------------------.            ,-----------------------------.
    ______QWERTY_IZQ_DEFAULT1______            ______QWERTY_DER_DEFAULT1______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    ______QWERTY_IZQ_DEFAULT2______            ______QWERTY_DER_DEFAULT2______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    ______QWERTY_IZQ_DEFAULT3______            ______QWERTY_DER_DEFAULT3______
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                          _FUN_INF_IZQ_     _FUN_INF_DER_
                       //`-------------'  `--------------'
  ),

  [_LOWER] = LAYOUT_wrapper(
  //,-----------------------------.            ,-----------------------------.
    _______QWERTY_IZQ_LOWER1_______            _______QWERTY_DER_LOWER1_______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    _______QWERTY_IZQ_LOWER2_______            _______QWERTY_DER_LOWER2_______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    _______QWERTY_IZQ_LOWER3_______            _______QWERTY_DER_LOWER3_______
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                          _FUN_INF_IZQ_     _FUN_INF_DER_
                       //`-------------'  `--------------'
  ),

  [_RAISE] = LAYOUT_wrapper(
  //,-----------------------------.            ,-----------------------------.
    _______QWERTY_IZQ_RAISE1_______            _______QWERTY_DER_RAISE1_______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    _______QWERTY_IZQ_RAISE2_______            _______QWERTY_DER_RAISE2_______
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    _______QWERTY_IZQ_RAISE3_______            _______QWERTY_DER_RAISE3_______
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                          _FUN_INF_IZQ_     _FUN_INF_DER_
                       //`-------------'  `--------------'
 ),

  [_ADJUST] = LAYOUT_wrapper(
  //,-----------------------------.            ,-----------------------------.
    __________LY_ADJ_IZQ1__________            __________LY_ADJ_DER1__________
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    __________LY_ADJ_IZQ2__________            __________LY_ADJ_DER2__________
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
    __________LY_ADJ_IZQ3__________            __________LY_ADJ_DER3__________
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                          _FUN_INF_IZQ_     _FUN_INF_DER_
                       //`-------------'  `--------------'
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
  }
	return process_record_oled(keycode, record);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  #if defined(RGB_MATRIX_ENABLE)
		if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
			rgb_matrix_set_color_all(0,255,0);
		}
		/* switch (biton32(layer_state)) {
			case _LOWER:
				for(int i = 0; i < RGB_MATRIX_LED_COUNT ; i++){
					rgb_matrix_set_color(i, RGB_BLUE);
				}
				break;
			case _RAISE:
				for(int i = 0; i < RGB_MATRIX_LED_COUNT; i++){
					rgb_matrix_set_color(i, RGB_RED);
				}
				break;
			default:
				if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
					rgb_matrix_set_color_all(0,255,0);
				}
				break;
		} */
	#endif
	return false;
}

