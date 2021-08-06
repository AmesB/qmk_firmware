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
#include "muse.h"

#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO

// led color definitions
#define GAME_COLOR 0x0a, 0x00, 0x0c
#define MUS_COLOR 0x00, 0x00, 0x0c
#define MIDI_COLOR 0x00, 0x0c, 0x0a
#define OCTAVE_COLOR 0xaa, 0x00, 0x00

enum planck_layers {
  _BASE,
//  _MEDIA,
  _NAV,
//  _MOUSE,
//  _SYM,
  _NUM,
  _FUN,
  _GAME,
  _GAME_ALT,
  _MUS,
  _MIDI
};

enum planck_keycodes {
  GAME = SAFE_RANGE,
  GAME_EXIT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,             KC_LEFT, KC_RGHT, KC_J,    KC_L,             KC_U,         KC_Y,           KC_QUOT,
    LSFT_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LGUI_T(KC_T), KC_G,             KC_UP,   KC_DOWN, KC_M,    RGUI_T(KC_N),     RCTL_T(KC_E), RALT_T(KC_I),   RSFT_T(KC_O),
    KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,             XXXXXXX, XXXXXXX, KC_K,    KC_H,             KC_COMM,      KC_DOT,         KC_SLSH,
    MU_ON,        MI_ON,        KC_ESC,       KC_SPC,       LT(_NAV, KC_TAB), KC_MINS, KC_CAPS, KC_BSPC, LT(_NUM, KC_DEL), KC_ENT,       KC_PSCR,        GAME
),

[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, _______, _______, _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_DEL,  _______, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______, _______, _______, _______, _______, _______, RESET,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______, _______, _______, KC_RGUI, KC_RCTL, KC_RALT, KC_RSFT,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, MO(_FUN),KC_0,    KC_MINS, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_FUN] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______, _______, _______, _______, _______, _______, RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, _______, _______, _______, KC_RGUI, KC_RCTL, KC_RALT, KC_RSFT,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_GAME] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC,  KC_DEL,  KC_PSCR, KC_LALT, KC_SPC,  MO(_GAME_ALT), KC_PSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GAME_EXIT
),

[_GAME_ALT] = LAYOUT_planck_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_GRV,
  KC_RSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_BSLS, _______,
  KC_RCTL, KC_INS,  KC_RGUI, KC_LALT, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______
),

[_MUS] = LAYOUT_planck_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    MU_OFF,MU_MOD,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),

[_MIDI] = LAYOUT_planck_grid(
    MI_B_2,    MI_C_3,    MI_Cs_3,   MI_D_3,    MI_Ds_3,   MI_E_3,   MI_F_3,   MI_Fs_3,  MI_G_3,   MI_Gs_3,  MI_A_3,   MI_As_3,
    MI_B_1,    MI_C_2,    MI_Cs_2,   MI_D_2,    MI_Ds_2,   MI_E_2,   MI_F_2,   MI_Fs_2,  MI_G_2,   MI_Gs_2,  MI_A_2,   MI_As_2,
    MI_B,      MI_C_1,    MI_Cs_1,   MI_D_1,    MI_Ds_1,   MI_E_1,   MI_F_1,   MI_Fs_1,  MI_G_1,   MI_Gs_1,  MI_A_1,   MI_As_1,
    MI_OCT_0,  MI_OCT_1,  MI_OCT_2,  MI_OCT_3,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MI_ALLOFF, MI_OFF
),

};

int midi_octave_led = 7;

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _GAME:
            for (uint8_t i = led_min; i <= led_max; i++) {
                rgb_matrix_set_color(i, GAME_COLOR);
            }
            break;
        case _MUS:
            for (uint8_t i = led_min; i <= led_max; i++) {
                rgb_matrix_set_color(i, MUS_COLOR);
            }
            break;
        case _MIDI:
            for (uint8_t i = led_min; i <= led_max; i++) {
                rgb_matrix_set_color(i, MIDI_COLOR);
            }
            rgb_matrix_set_color(midi_octave_led, OCTAVE_COLOR);
            break;
        default:
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 6; i <= 7; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0xaa, 0x00, 0x00);
            }
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // mode swaps
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
      }
      return false;
      break;
    case GAME_EXIT:
      if (record->event.pressed) {
        layer_off(_GAME);
      }
      return false;
      break;
    case MU_ON:
      if (record->event.pressed) {
        layer_on(_MUS);
      }
      return true;
    case MU_OFF:
      if (record->event.pressed) {
        layer_off(_MUS);
      }
      return true;
    case MI_ON:
      if (record->event.pressed) {
        layer_on(_MIDI);
      }
      return true;
    case MI_OFF:
      if (record->event.pressed) {
        layer_off(_MIDI);
      }
      return true;

    // custom led indicator handling
    case MI_OCT_0:
      if (record->event.pressed) {
        midi_octave_led = 7;
      }
      return true;
    case MI_OCT_1:
      if (record->event.pressed) {
        midi_octave_led = 8;
      }
      return true;
    case MI_OCT_2:
      if (record->event.pressed) {
        midi_octave_led = 1;
      }
      return true;
    case MI_OCT_3:
      if (record->event.pressed) {
        midi_octave_led = 2;
      }
      return true;
  }
  return true;
}
