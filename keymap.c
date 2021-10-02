#include "key_mapping.h"

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

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  #ifdef RGB_MATRIX_ENABLE
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(0,255,0);
    }

  /*switch (biton32(layer_state)) {
    case _RAISE:
      rgb_matrix_set_color_all(100, 0, 100);
      break;

    case _LOWER:
      rgb_matrix_set_color_all(100, 100, 0);
      break;

    default:
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
          rgb_matrix_set_color_all(0,255,0);
       }
      break;
  }*/
  #endif
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0};
    oled_write_P(PSTR("\n"), false);
    oled_write_P(corne_logo, false);
    //oled_write_P(PSTR("corne"), false);
}

void render_logger(void) {
    static const char PROGMEM logger_logo[] = {
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(logger_logo, false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

/*configuraciones key logger*/
#define ASCII_TABLE_LENGTH       (0x80)
#define KEYLOG_STRING_STARTUP    (KEYLOG_EOL_LEN+1)
#define ALT_CODE                 (0x7E)
#define SPECIAL_KEYS_SHIFT(kc)   (0x18+(kc))
#define RM_LSFT(kc)           ((uint8_t)(0x20)+(kc-0x200))

static char keylog_str[KEYLOG_EOL_LEN] = {' '};
static uint32_t standby_oled_timer = 0;
static uint16_t log_timer = 0;
static uint8_t current_cursor_pos=0;
static uint32_t cursor_oled_timer = 0;
static char last_c=' ';

/* Provides the ASCII value or the address of the character selected of the OLED font specified in glcfont.c */
static const char ascii_t[ASCII_TABLE_LENGTH] = {
        /*     0          1         2         3        4         5         6         7         8         9         A         B         C         D         E         F                */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
           0x0F,         0x1A,    0x1B,     0x19,    0x18,     0x0E,      ' ',      ' ',     0x11,      0x1C,    0x97,      ' ',      ' ',      ' ',      ' ',      ' ',         /* 0 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            ' ',         ' ',      ' ',      ' ',     ' ',      ' ',      ' ',      ' ',      ' ',       ' ',     ' ',     0x1D,      ' ',      ' ',      ' ',      ' ',         /* 1 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
           0x16,         '!',      '"',      '#',     '$',      '%',      '&',     '\'',      '(',       ')',     '*',      '+',      ',',      '-',      '.',      '/',         /* 2 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '0',         '1',      '2',      '3',     '4',      '5',      '6',      '7',      '8',       '9',     ':',      ';',      '<',      '=',      '>',      '?',         /* 3 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '@',         'A',      'B',      'C',     'D',      'E',      'F',      'G',      'H',       'I',     'J',      'K',      'L',      'M',      'N',      'O',         /* 4 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            'P',         'Q',      'R',      'S',     'T',      'U',      'V',      'W',      'X',       'Y',     'Z',      '[',      '\\',     ']',      '^',      '_',         /* 5 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '`',         'a',      'b',      'c',     'd',      'e',      'f',      'g',      'h',       'i',     'j',      'k',      'l',      'm',      'n',      'o',         /* 6 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            'p',         'q',      'r',      's',     't',      'u',      'v',      'w',      'x',       'y',     'z',      '{',      '|',      '}',      '~',     0x7F,         /* 7 */
};

/* This table is to remap and get the corresponding ASCII value based on the KEYCODE (taken as the index of the array) of quatum_keycodes.h module */
static const unsigned char code_to_ascii[ASCII_TABLE_LENGTH] = {
        /*     0          1         2         3        4         5         6         7         8         9         A         B         C         D         E         F                */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
           0x00,        0x00,     0x00,     0x00,      'a',      'b',     'c',      'd',      'e',       'f',     'g',      'h',      'i',      'j',      'k',      'l',         /* 0 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            'm',         'n',      'o',      'p',      'q',      'r',     's',      't',      'u',       'v',     'w',      'x',      'y',      'z',      '1',      '2',         /* 1 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '3',         '4',      '5',      '6',      '7',      '8',     '9',      '0',     0x0A,      0x1B,    0x08,     0x09,      ' ',      '-',      '=',      '[',         /* 2 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            ']',        '\\',     0x00,      ';',     '\'',      '`',     ',',      '.',      '/',      0x00,    0x00,     0x00,     0x00,     0x00,      '!',      '@',         /* 3 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '#',         '$',      '%',      '^',      '&',      '*',     '(',      ')',     0x00,      0x00,    0x00,     0x00,     0x00,      '_',      '+',      '{',         /* 4 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
            '}',         '|',     0x00,     0x00,     0x00,      '~',    0x00,     0x00,     0x00,      0x00,    0x00,     0x00,     0x00,     0x00,     0x00,     0x00,         /* 5 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
           0x00,        0x00,     0x00,     0x00,     0x7F,     0x00,    0x00,     0x01,     0x02,      0x03,    0x04,     0x00,     0x00,     0x00,     0x00,     0x00,         /* 6 */
        /*          |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |           */
           0x00,        0x00,     0x00,     0x00,     0x00,     0x00,    0x00,     0x00,     0x00,      0x00,    0x00,     0x00,     0x00,     0x00,     0x05,     0x00,         /* 7 */
};

inline static char get_ascii(int16_t keycode){
    uint8_t ascii_idx=0x00;

    if(keycode<KC_F1){
        ascii_idx=code_to_ascii[(uint8_t)keycode];
    }else if(keycode<KC_KP_ENTER){
        ascii_idx=code_to_ascii[SPECIAL_KEYS_SHIFT(keycode)];
    }else if(KC_LANG1==keycode){
        ascii_idx=code_to_ascii[ALT_CODE];
    }else if( QK_LSFT==(QK_LSFT&keycode) ){
        ascii_idx=code_to_ascii[RM_LSFT(keycode)];
    }
    return ascii_t[ascii_idx];
}

extern void add_keylog(uint16_t keycode){
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)){
        keycode&=0x00FF;
    }

    if(current_cursor_pos>(KEYLOG_LEN-1)||(current_cursor_pos>KEYLOG_STRING_STARTUP)){
        current_cursor_pos=0;
        last_c=get_ascii(keycode);
        current_cursor_pos++;
    }else{
        if(keycode <= KC_TILD){
            keylog_str[current_cursor_pos]=last_c;
            last_c=get_ascii(keycode);
            current_cursor_pos++;
        }
        keylog_str[current_cursor_pos] = '\0';
    }

    log_timer = timer_read();

    standby_oled_timer = timer_read32();
}

static void render_keylogger_status(void){
    static bool cursor_f=true;

    if(timer_elapsed32(cursor_oled_timer) > 300){
        cursor_oled_timer = timer_read32();
        cursor_f=!cursor_f;
    }
    oled_write_P(PSTR("\n>:"), false);
    if(current_cursor_pos>(KEYLOG_LEN-1)){
        current_cursor_pos=0;
        memset(keylog_str, ' ', sizeof(char)*KEYLOG_EOL_LEN);
        /* Here the EOL is to clear with white spaces all the keylog area */
        keylog_str[KEYLOG_EOL_LEN-1] = '\0';
        oled_write(keylog_str, false);
        /* Reset EOL to the begining of the keylog string */
        keylog_str[0] = '\0';
    }
    oled_write(keylog_str, false);
    oled_write_char(last_c, cursor_f);

}

/*fin configuracioens key logger*/


void render_status_main(void) {
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_logo();
    render_space();
    render_logger();
    //render_layer_state();
    render_space();
    render_keylogger_status();
    //render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    //render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#ifndef SPLIT_KEYBOARD
    else { oled_on(); }
#endif

    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
    // set_timelog();
  }

  if (record->event.pressed) {
    add_keylog(keycode);
  }

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGBRST:
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
