#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _SWAG 4
#define _DISC 5
#define _ROUND 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
  DIS_A,
  DIS_B,
  DIS_C,
  DIS_D,
  DIS_E,
  DIS_F,
  DIS_G,
  DIS_H,
  DIS_I,
  DIS_J,
  DIS_K,
  DIS_L,
  DIS_M,
  DIS_N,
  DIS_O,
  DIS_P,
  DIS_Q,
  DIS_R,
  DIS_S,
  DIS_T,
  DIS_U,
  DIS_V,
  DIS_W,
  DIS_X,
  DIS_Y,
  DIS_Z,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,  LOWER,  KC_RALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,      KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_DISC),                    KC_LEFT,   KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_DELETE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, TG(_ROUND), TG(_SWAG),                    KC_HOME, KC_PGDOWN, KC_PGUP,  KC_END, XXXXXXX,    KC_INS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,UC(0xe7),UC(0xe8),UC(0xe9),UC(0xe0),UC(0xea),                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST,   KC_F1,   KC_F2,   KC_F3,   KC_F4,                        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),



  [_SWAG] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, UC(0x0556), UC(0x0D27), UC(0x0A9B), UC(0x0B6E), UC(0x1350),                      UC(0x0728), UC(0x0BAA), UC(0x0719), UC(0x1368), UC(0x12E8), KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, UC(0x0467), UC(0x0ABD), UC(0x10E8), UC(0x0D3D), UC(0x13B6),                      UC(0x12E0), UC(0x0575), UC(0x051F), UC(0x13DD), KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, UC(0x1358), UC(0x04C2), UC(0x062D), UC(0x13D9), UC(0x0551),                      UC(0x12B0), UC(0x0D6F), KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, TG(_SWAG) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ROUND] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, UC(0x24C6), UC(0x24CC), UC(0x24BA), UC(0x24C7), UC(0x24C9),                      UC(0x24CE), UC(0x24CA), UC(0x24BE), UC(0x24C4), UC(0x24C5), KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, UC(0x24B6), UC(0x24C8), UC(0x24B9), UC(0x24BB), UC(0x24BC),                      UC(0x24BD), UC(0x24BF), UC(0x24C0), UC(0x24C1), KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, UC(0x24CF), UC(0x24CD), UC(0x24B8), UC(0x24CB), UC(0x24B7),                      UC(0x24C3), UC(0x24C2), KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, TG(_ROUND) \
                                      //`--------------------------'  `--------------------------'
  ),


  [_DISC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DIS_Q, DIS_W, DIS_E, DIS_R, DIS_T,                      DIS_Y, DIS_U, DIS_I, DIS_O, DIS_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, DIS_A, DIS_S, DIS_D, DIS_F, DIS_G,                      DIS_H, DIS_J, DIS_K, DIS_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, DIS_Z, DIS_X, DIS_C, DIS_V, DIS_B,                      DIS_N, DIS_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  KC_SPC,     KC_ENT,   LOWER, TG(_DISC) \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
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
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;

    case DIS_A:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_a:");
      }
      break;
    case DIS_B:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_b:");
      }
      break;
    case DIS_C:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_c:");
      }
      break;
    case DIS_D:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_d:");
      }
      break;
    case DIS_E:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_e:");
      }
      break;
    case DIS_F:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_f:");
      }
      break;
    case DIS_G:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_g:");
      }
      break;
    case DIS_H:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_h:");
      }
      break;
    case DIS_I:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_i:");
      }
      break;
    case DIS_J:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_j:");
      }
      break;
    case DIS_K:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_k:");
      }
      break;
    case DIS_L:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_l:");
      }
      break;
    case DIS_M:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_m:");
      }
      break;
    case DIS_N:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_n:");
      }
      break;
    case DIS_O:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_o:");
      }
      break;
    case DIS_P:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_p:");
      }
      break;
    case DIS_Q:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_q:");
      }
      break;
    case DIS_R:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_r:");
      }
      break;
    case DIS_S:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_s:");
      }
      break;
    case DIS_T:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_t:");
      }
      break;
    case DIS_U:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_u:");
      }
      break;
    case DIS_V:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_v:");
      }
      break;
    case DIS_W:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_w:");
      }
      break;
    case DIS_X:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_x:");
      }
      break;
    case DIS_Y:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_y:");
      }
      break;
    case DIS_Z:
      if (record->event.pressed) {
        SEND_STRING(":regional_indicator_z:");
      }
      break;


  }
  return true;
}
