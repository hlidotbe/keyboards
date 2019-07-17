/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "sp60l.h"

#define LAYER_BASE 0
#define LAYER_FROW 1
#define LAYER_FROW2 2
#define LAYER_MOUSE 3

#define HYPER MT((MOD_LGUI|MOD_LCTL), KC_NO)
#define ALL_T_NO ALL_T(KC_NO)
#define CAM_C LCTL(LALT(LGUI(KC_C)))
#define CAM_F LCTL(LALT(LGUI(KC_F)))
#define SA_D LSFT(LALT(KC_D))
#define HYPER_L LSFT(LCTL(LALT(LGUI(KC_LEFT))))
#define HYPER_R LSFT(LCTL(LALT(LGUI(KC_RIGHT))))
#define XXXXX KC_NO
#define LT_SPC LT(LAYER_FROW, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = KEYMAP(
  BL_TOGG,         KC_GRAVE,         KC_1,            KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_7,    KC_8,      KC_9,    KC_0,     KC_MINS, XXXXX,   KC_EQL,  KC_BSPC, \
  BL_STEP,         KC_TAB,           KC_Q,            KC_W,    KC_E,    KC_R,    KC_T,    XXXXX, KC_Y,    KC_U,      KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  TG(LAYER_MOUSE), CTL_T(KC_ESCAPE), KC_A,            KC_S,    KC_D,    KC_F,    KC_G,    XXXXX, KC_H,    KC_J,      KC_K,    KC_L,     KC_SCLN, XXXXX,   KC_QUOT, KC_ENT,  \
  BL_INC,          KC_LSFT,          XXXXX,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,    KC_M,      KC_COMM, KC_DOT,   KC_SLSH, XXXXX,   XXXXX,   KC_RSFT, \
  BL_DEC,          XXXXX,            MO(LAYER_FROW2), KC_LALT, KC_LGUI, XXXXX,   LT_SPC,  XXXXX, LT_SPC,  XXXXX,     XXXXX,   KC_RGUI,  HYPER,   XXXXX,   KC_RCTL, KC_RALT   \
),
[LAYER_FROW] = KEYMAP(
  XXXXX,           KC_MUTE,          KC_F1,           KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,     KC_F9,   KC_F10,   KC_F11,  XXXXX,   KC_F12,  KC_DEL,  \
  XXXXX,           KC_TAB,           KC_VOLD,         KC_MPLY, KC_VOLU, KC_R,    KC_T,    XXXXX, KC_Y,    KC_U,      KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  XXXXX,           CTL_T(KC_ESCAPE), KC_MRWD,         KC_S,    KC_MFFD, CAM_F,   KC_G,    XXXXX, KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, KC_SCLN, XXXXX,   KC_QUOT, KC_PENT, \
  XXXXX,           KC_LSFT,          XXXXX,           KC_Z,    KC_X,    CAM_C,   KC_V,    KC_B,  KC_N,    KC_M,      KC_COMM, KC_DOT,   KC_SLSH, XXXXX,   XXXXX,   KC_RSFT, \
  XXXXX,           XXXXX,            MO(LAYER_FROW2), KC_LALT, KC_LGUI, XXXXX,   KC_TRNS, XXXXX, KC_TRNS, XXXXX,     XXXXX,   KC_RGUI,  HYPER,   XXXXX,   KC_RCTL, KC_RALT  \
),
[LAYER_FROW2] = KEYMAP(
  XXXXX,           KC_MUTE,          KC_F1,           KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,     KC_F9,   KC_F10,   KC_F11,  XXXXX,   KC_F12,  KC_DEL,  \
  XXXXX,           KC_TAB,           KC_VOLD,         KC_MPLY, SA_D,    KC_R,    KC_T,    XXXXX, KC_Y,    KC_U,      KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  XXXXX,           CTL_T(KC_ESCAPE), KC_MRWD,         KC_S,    KC_MFFD, CAM_F,   KC_G,    XXXXX, HYPER_L, KC_PGDOWN, KC_PGUP, HYPER_R,  KC_SCLN, XXXXX,   KC_QUOT, KC_PENT, \
  XXXXX,           KC_LSFT,          XXXXX,           KC_Z,    KC_X,    CAM_C,   KC_V,    KC_B,  KC_N,    KC_M,      KC_COMM, KC_DOT,   KC_SLSH, XXXXX,   XXXXX,   KC_RSFT, \
  XXXXX,           MO(LAYER_FROW),   MO(LAYER_FROW2), KC_LALT, KC_LGUI, XXXXX,   KC_SPC,  XXXXX, KC_SPC,  XXXXX,     XXXXX,   KC_RGUI,  HYPER,   XXXXX,   KC_RCTL, KC_RALT  \
),
[LAYER_MOUSE] = KEYMAP(
  BL_TOGG,         XXXXX,            XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, XXXXX,   XXXXX,     XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   \
  BL_STEP,         XXXXX,            KC_BTN2,         KC_MS_U, KC_BTN1, XXXXX,   XXXXX,   XXXXX, XXXXX,   XXXXX,     XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   \
  TG(LAYER_MOUSE), TG(LAYER_MOUSE),  KC_MS_L,         KC_MS_D, KC_MS_R, XXXXX,   XXXXX,   XXXXX, KC_ACL0, KC_ACL2,   XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   \
  BL_INC,          XXXXX,            XXXXX,           KC_WH_U, XXXXX,   KC_WH_D, XXXXX,   XXXXX, XXXXX,   XXXXX,     XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   \
  BL_DEC,          MO(LAYER_FROW),   MO(LAYER_FROW2), XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, XXXXX,   XXXXX,     XXXXX,   XXXXX,    XXXXX,   XXXXX,   XXXXX,   XXXXX\
),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
