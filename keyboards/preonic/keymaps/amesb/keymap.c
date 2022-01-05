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

// led color definitions
#define GAME_COLOR 0x0a, 0x00, 0x0c
#define NAV_COLOR 0x00, 0x88, 0x00
#define NUM_COLOR 0x00, 0x00, 0x88
#define FUN_COLOR 0x00, 0x44, 0x44
#define CAPS_COLOR 0x0c, 0x00, 0x00
#define MACRO1_COLOR 0x0f, 0x0c, 0x00
#define MACRO2_COLOR 0x09, 0x0a, 0x0c
#define MUS_COLOR 0x00, 0x00, 0x0c
#define MIDI_COLOR 0x00, 0x0c, 0x0a
#define OCTAVE_COLOR 0xaa, 0x00, 0x00

enum preonic_layers {
  _BASE,
  _GAME,
  _ALT,
  _FUN,
  _GAME_ALT,
  _MUS,
  _MIDI
};

enum preonic_keycodes {
  GAME = SAFE_RANGE,
  GAME_EXIT,
  ALT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,          KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_J,     KC_L,          KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     KC_M,     KC_N,          KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_K,     KC_H,          KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_ESC,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  ALT,      ALT,      OSM(MOD_LSFT), KC_PSCR, KC_LBRC, KC_RBRC, KC_ENT
),

[_GAME] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,          KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_J,     KC_L,          KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     KC_M,     KC_N,          KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_K,     KC_H,          KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_ESC,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  ALT,      ALT,      OSM(MOD_LSFT), KC_PSCR, KC_LBRC, KC_RBRC, KC_ENT
),

[_ALT] = LAYOUT_preonic_grid(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MPLY, KC_CAPS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, KC_DEL,  KC_INS,  _______, _______, MO(_FUN),MO(_FUN),_______, _______, _______, _______, _______
),

[_FUN] = LAYOUT_preonic_grid(
    KC_F12,  KC_F13,   KC_F14,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MPRV, KC_MNXT, _______, _______, KC_SLCK, KC_PAUS, _______,
    RESET,   _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, GAME,    MI_ON
),

[_GAME_ALT] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_1,    KC_2,    KC_UP,   KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_F1,   KC_LEFT, KC_DOWN, KC_RGHT, KC_F2,   KC_F3,  _______, _______, _______, _______, _______, _______,
    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MUS] = LAYOUT_preonic_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    MU_OFF,MU_MOD,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),

[_MIDI] = LAYOUT_preonic_grid(
    MI_B_3,    MI_C_4,    MI_Cs_4,   MI_D_4,    MI_Ds_4,   MI_E_4,   MI_F_4,   MI_Fs_4,  MI_G_4,   MI_Gs_4,  MI_A_4,   MI_As_4,
    MI_B_2,    MI_C_3,    MI_Cs_3,   MI_D_3,    MI_Ds_3,   MI_E_3,   MI_F_3,   MI_Fs_3,  MI_G_3,   MI_Gs_3,  MI_A_3,   MI_As_3,
    MI_B_1,    MI_C_2,    MI_Cs_2,   MI_D_2,    MI_Ds_2,   MI_E_2,   MI_F_2,   MI_Fs_2,  MI_G_2,   MI_Gs_2,  MI_A_2,   MI_As_2,
    MI_B,      MI_C_1,    MI_Cs_1,   MI_D_1,    MI_Ds_1,   MI_E_1,   MI_F_1,   MI_Fs_1,  MI_G_1,   MI_Gs_1,  MI_A_1,   MI_As_1,
    MI_OCT_0,  MI_OCT_1,  MI_OCT_2,  MI_OCT_3,  KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MI_ALLOFF, MI_OFF
),

};

static int midi_octave_led = 7;

static int macro_id = 0;

static bool kc_a_state = false;
static bool kc_r_state = false;
static bool kc_s_state = false;
static bool kc_t_state = false;
static bool kc_n_state = false;
static bool kc_e_state = false;
static bool kc_i_state = false;
static bool kc_o_state = false;

static bool kc_lgui_state = false;
static bool kc_lalt_state = false;
static bool kc_lctl_state = false;
static bool kc_lsft_state = false;
static bool kc_rsft_state = false;
static bool kc_rctl_state = false;
static bool kc_ralt_state = false;
static bool kc_rgui_state = false;

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _GAME:
            for (uint8_t i = led_min; i <= led_max; i++) {
                rgb_matrix_set_color(i, GAME_COLOR);
            }
            break;
        case _ALT:
            for (uint8_t i = 7; i <= 7; i++) {
                rgb_matrix_set_color(i, NAV_COLOR);
            }
            break;
        case _FUN:
            for (uint8_t i = 1; i <= 1; i++) {
                rgb_matrix_set_color(i, FUN_COLOR);
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
        //for (uint8_t i = 6; i <= 7; i++) {
        for (uint8_t i = 8; i <= 8; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, CAPS_COLOR);
            }
        }
    }
    
    if (macro_id == 1) {
      rgb_matrix_set_color(6, MACRO1_COLOR);
    }
    if (macro_id == 2) {
      rgb_matrix_set_color(5, MACRO2_COLOR);
    }
}

void handle_homerow_mods(void) {
  if (kc_a_state) {
    kc_a_state = false;
    kc_lgui_state = true;
    register_code(KC_LGUI);
    unregister_code(KC_A);
  }

  if (kc_r_state) {
    kc_r_state = false;
    kc_lalt_state = true;
    register_code(KC_LALT);
    unregister_code(KC_R);
  }

  if (kc_s_state) {
    kc_s_state = false;
    kc_lctl_state = true;
    register_code(KC_LCTL);
    unregister_code(KC_S);
  }

  if (kc_t_state) {
    kc_t_state = false;
    kc_lsft_state = true;
    register_code(KC_LSFT);
    unregister_code(KC_T);
  }

  if (kc_n_state) {
    kc_n_state = false;
    kc_rsft_state = true;
    register_code(KC_RSFT);
    unregister_code(KC_N);
  }

  if (kc_e_state) {
    kc_e_state = false;
    kc_rctl_state = true;
    register_code(KC_RCTL);
    unregister_code(KC_E);
  }

  if (kc_i_state) {
    kc_i_state = false;
    kc_ralt_state = true;
    register_code(KC_RALT);
    unregister_code(KC_I);
  }

  if (kc_o_state) {
    kc_o_state = false;
    kc_rgui_state = true;
    register_code(KC_RGUI);
    unregister_code(KC_O);
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

    // home row handling for home row mod implementation
    case KC_A:
      if (record->event.pressed) {
        kc_a_state = true;
      }
      else  {
        kc_a_state = false;
	if (kc_lgui_state) {
	  unregister_code(KC_LGUI);
	  kc_lgui_state = false;
	}
      }
      return true;

    case KC_R:
      if (record->event.pressed) {
        kc_r_state = true;
      }
      else  {
        kc_r_state = false;
	if (kc_lalt_state) {
	  unregister_code(KC_LALT);
	  kc_lalt_state = false;
        }
      }
      return true;

    case KC_S:
      if (record->event.pressed) {
        kc_s_state = true;
      }
      else  {
        kc_s_state = false;
	if (kc_lctl_state) {
	  unregister_code(KC_LCTL);
	  kc_lctl_state = false;
        }
      }
      return true;

    case KC_T:
      if (record->event.pressed) {
        kc_t_state = true;
      }
      else  {
        kc_t_state = false;
	if (kc_lsft_state) {
	  unregister_code(KC_LSFT);
	  kc_lsft_state = false;
        }
      }
      return true;

    case KC_N:
      if (record->event.pressed) {
        kc_n_state = true;
      }
      else  {
        kc_n_state = false;
	if (kc_rsft_state) {
	  unregister_code(KC_RSFT);
	  kc_rsft_state = false;
        }
      }
      return true;

    case KC_E:
      if (record->event.pressed) {
        kc_e_state = true;
      }
      else  {
        kc_e_state = false;
	if (kc_rctl_state) {
	  unregister_code(KC_RCTL);
	  kc_rctl_state = false;
        }
      }
      return true;

    case KC_I:
      if (record->event.pressed) {
        kc_i_state = true;
      }
      else  {
        kc_i_state = false;
	if (kc_ralt_state) {
	  unregister_code(KC_RALT);
	  kc_ralt_state = false;
        }
      }
      return true;

    case KC_O:
      if (record->event.pressed) {
        kc_o_state = true;
      }
      else  {
        kc_o_state = false;
	if (kc_rgui_state) {
	  unregister_code(KC_RGUI);
	  kc_rgui_state = false;
        }
      }
      return true;

    // mod key handling
    case ALT:
      if (record->event.pressed) {
        handle_homerow_mods();
	layer_on(_ALT);
      }
      else  {
        layer_off(_ALT);
      }
      return false;
  }
  return true;
}
