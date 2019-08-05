#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define LAYER_BASE 0
#define LAYER_FROW 1
#define LAYER_NAV  2
#define LAYER_RGB  3

#define LSA_D LSFT(LALT(KC_D))
#define LT_SPC LT(LAYER_FROW, KC_SPC)
#define MO_RGB MO(LAYER_RGB)
#define CTL_T_ESC CTL_T(KC_ESCAPE)
#define LCS_C LSFT(LCTL(KC_C))
#define LCS_V LSFT(LCTL(KC_V))

#define ACTION_TAP_DANCE_FN_DATA(user_fn, data) {  \
  .fn = { NULL, user_fn, NULL }, \
  .user_data = (void *)data, \
}

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};
//
//Tap Dance Declarations
enum {
  ALT_QUOT    = 0,
  ALT_GRAVE   = 1,
  ALT_CIRC    = 2,
  LCAG_H      = 3,
  SWITCH_TAB1 = 4,
  SWITCH_TAB2 = 5,
  SWITCH_TAB3 = 6,
  SWITCH_TAB4 = 7,
  SWITCH_TAB5 = 8,
  SWITCH_TAB6 = 9,
  SWITCH_TAB7 = 10,
  SWITCH_TAB8 = 11,
  SWITCH_TAB9 = 12,
};

void dead_grave(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_RALT);
      register_code(KC_GRAVE);
      unregister_code(KC_GRAVE);
      unregister_code(KC_RALT);
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_GRAVE);
      unregister_code(KC_GRAVE);
    }
  }
  reset_tap_dance (state);
}

void dead_quot(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_RALT);
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
      unregister_code(KC_RALT);
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
    }
  }
  reset_tap_dance (state);
}

void dead_circ(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_RALT);
      register_code(KC_6);
      unregister_code(KC_6);
      unregister_code(KC_RALT);
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_6);
      unregister_code(KC_6);
    }
  }
  reset_tap_dance (state);
}

void lcag_h(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      register_code(KC_H);
      unregister_code(KC_H);
      unregister_code(KC_LGUI);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_H);
      unregister_code(KC_H);
    }
  }
  reset_tap_dance (state);
}

void fat_arrow(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    SEND_STRING ("=>");
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_SLASH);
      unregister_code(KC_SLASH);
    }
  }
  reset_tap_dance (state);
}

void more_than(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    SEND_STRING (">=");
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_DOT);
      unregister_code(KC_DOT);
    }
  }
  reset_tap_dance (state);
}

void less_than(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 2) {
    SEND_STRING ("<=");
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code(KC_COMMA);
      unregister_code(KC_COMMA);
    }
  }
  reset_tap_dance (state);
}

void switch_tab(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
      register_code(KC_LCTL);
      register_code(KC_SPC);
      unregister_code(KC_SPC);
      unregister_code(KC_LCTL);
      register_code((uint16_t)user_data);
      unregister_code((uint16_t)user_data);
  } else {
    for(int i = 0; i < state->count; i++) {
      register_code((uint16_t)user_data);
      unregister_code((uint16_t)user_data);
    }
  }
  reset_tap_dance (state);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [ALT_QUOT]    = ACTION_TAP_DANCE_FN(dead_quot),
  [ALT_GRAVE]   = ACTION_TAP_DANCE_FN(dead_grave),
  [ALT_CIRC]    = ACTION_TAP_DANCE_FN(dead_circ),
  [LCAG_H]      = ACTION_TAP_DANCE_FN(lcag_h),
  [SWITCH_TAB1] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_1),
  [SWITCH_TAB2] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_2),
  [SWITCH_TAB3] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_3),
  [SWITCH_TAB4] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_4),
  [SWITCH_TAB5] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_5),
  [SWITCH_TAB6] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_6),
  [SWITCH_TAB7] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_7),
  [SWITCH_TAB8] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_8),
  [SWITCH_TAB9] = ACTION_TAP_DANCE_FN_DATA(switch_tab, KC_9),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
	KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, \
	KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, \
	CTL_T_ESC,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, KC_ENT,  \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,   KC_SLASH, KC_RSFT, KC_UP,   \
	LCAG(KC_H), KC_LCTL, KC_LGUI, KC_LALT, LT_SPC,     LT_SPC,  KC_NO,   KC_RALT, MO_RGB,   KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [LAYER_FROW] = LAYOUT(
    KC_MUTE,    KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_NO,   KC_DEL,  \
    _______,    KC_VOLD, _______, KC_VOLU, _______,    _______, _______, _______, _______,  _______,  _______,  KC_HOME, KC_END,  _______, \
    _______,    _______, _______, LSA_D,   LCAG(KC_F), _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, _______,  _______, _______, \
    _______,    _______, _______, LCS_C,   LCS_V,      _______, _______, _______, _______,  _______,  _______,  _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  KC_PGUP,  _______,  KC_PGDN
  ),

  [LAYER_NAV] = LAYOUT(
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______
  ),

  [LAYER_RGB] = LAYOUT(
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, \
    _______,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______, \
    _______,    _______, _______, RGB_SAI, RGB_SAD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, \
    _______,    _______, _______, RGB_VAI, RGB_VAD,    _______, _______, _______, _______,  _______,  _______,  _______, _______, \
    _______,    _______, _______, _______, _______,    _______, _______, _______, _______,  _______,  _______,  _______
  )
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case LAYER_RGB:
        rgblight_sethsv_noeeprom_red();
        break;
    case LAYER_FROW:
        rgblight_sethsv_noeeprom(132, 102, 127);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(0, 0, 127);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
    case KC_LALT:
    case KC_LGUI:
    case KC_LSFT:
    case KC_RCTL:
    case KC_RALT:
    case KC_RGUI:
    case KC_RSFT:
      if (record->event.pressed) {
        rgblight_sethsv_noeeprom(30, 218, 109);

      } else {
        rgblight_sethsv_noeeprom(0, 0, 127);
      }
      return true; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
