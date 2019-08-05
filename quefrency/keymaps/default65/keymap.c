#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define LAYER_BASE 0
#define LAYER_FROW 1
#define LAYER_RGB  2

#define LSA_D LSFT(LALT(KC_D))
#define LT_SPC LT(LAYER_FROW, KC_SPC)
#define MO_RGB MO(LAYER_RGB)
#define CTL_T_ESC CTL_T(KC_ESCAPE)
#define LCS_C LSFT(LCTL(KC_C))
#define LCS_V LSFT(LCTL(KC_V))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_65(
	KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, KC_HOME, \
	KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \
	CTL_T_ESC,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,   KC_SLASH, KC_RSFT, KC_UP,   KC_PGDN, \
	LCAG(KC_H), KC_LCTL, KC_LGUI, KC_LALT, LT_SPC,     LT_SPC,  KC_NO,   KC_RALT, KC_RCTL,  MO_RGB,   KC_LEFT,  KC_DOWN, KC_RGHT
  ),
  [LAYER_FROW] = LAYOUT_65(
    KC_MUTE,    KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_NO,   KC_DEL,  _______, \
    _______,    KC_VOLD, _______, KC_VOLU, _______,    _______, _______, _______, _______,  _______,  _______,  KC_HOME, KC_END,  _______, _______, \
    _______,    _______, _______, LSA_D,   LCAG(KC_F), _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, _______,  _______, _______, _______, \
    _______,    _______, _______, LCS_C,   LCS_V,      _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  KC_PGUP,  _______,  KC_PGDN, _______
  ),
  [LAYER_RGB] = LAYOUT_65(
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, \
    _______,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, \
    _______,    _______, _______, RGB_SAI, RGB_SAD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, \
    _______,    _______, _______, RGB_VAI, RGB_VAD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______
  )

};
