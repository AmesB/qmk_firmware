/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#define GAME_COLOR 0x0a, 0x00, 0xff

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ESC,
  KC_BSPC,       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_CAPS,       KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  LOWER,   RAISE,   KC_BSPC, KC_DEL,  QWERTY,  KC_RCTL, KC_RSFT
),

[_QWERTY] = LAYOUT_preonic_grid(
  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
  KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_CAPS,       KC_LGUI, KC_ESC,  KC_LALT, KC_SPC,  LOWER,   RAISE,   KC_BSPC, KC_DEL,  COLEMAK, KC_RCTL, KC_RSFT
),


[_LOWER] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_0,    _______,
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_0,    _______,
  _______, _______, _______, _______, KC_PSCR, _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, RGB_MOD, RGB_SAI, RGB_SAI, RGB_VAI, RGB_TOG, _______,
  _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            for (uint8_t i = led_min; i <= led_max; i++) {
                rgb_matrix_set_color(i, GAME_COLOR);
            }
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0xff, 0x00, 0x00);
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case COLEMAK:
          if (record->event.pressed) {
            layer_off(_QWERTY);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            layer_on(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
