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

#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

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
  _MEDIA,
  _NAV,
  _MOUSE,
  _SYM,
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
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              U_NA,              U_NA,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              U_NA,              U_NA,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              U_NA,              U_NA,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    MU_ON,             MI_ON,             LT(_MEDIA, KC_ESC),LT(_NAV, KC_SPC),  LT(_MOUSE, KC_TAB),U_NA,              U_NA,              LT(_SYM, KC_ENT),  LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL),  U_NA,             GAME
),

[_NAV] = LAYOUT_planck_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_ENT,  KC_BSPC, KC_DEL,  U_NA,    U_NA
),

[_MOUSE] = LAYOUT_planck_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_BTN1, KC_BTN3, KC_BTN2, U_NA,    U_NA
),

[_MEDIA] = LAYOUT_planck_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_MSTP, KC_MPLY, KC_MUTE, U_NA,    U_NA
),

[_NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_DOT,  KC_0,    KC_MINS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_SYM] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_FUN] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_GAME] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_DEL,  KC_LGUI, KC_LALT, KC_SPC,  MO(_GAME_ALT), KC_PSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GAME_EXIT
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
