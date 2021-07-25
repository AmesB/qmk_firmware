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

enum preonic_layers {
  _BASE,
  _MEDIA,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _FUN,
  _GAME,
  _GAME_ALT
};

enum preonic_keycodes {
  GAME = SAFE_RANGE,
  GAME_EXIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              GAME,              U_NA,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              U_NA,              U_NA,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              U_NA,              U_NA,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    U_NA,              U_NA,              LT(_MEDIA, KC_ESC),LT(_NAV, KC_SPC),  LT(_MOUSE, KC_TAB),U_NA,              U_NA,              LT(_SYM, KC_ENT),  LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL),   U_NA,              U_NA
),

[_NAV] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_ENT,  KC_BSPC, KC_DEL,  U_NA,    U_NA
),

[_MOUSE] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_BTN1, KC_BTN3, KC_BTN2, U_NA,    U_NA
),

[_MEDIA] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NA,   U_NA,   U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   KC_MSTP, KC_MPLY, KC_MUTE, U_NA,    U_NA
),

[_NUM] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_DOT,  KC_0,    KC_MINS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_SYM] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_FUN] = LAYOUT_preonic_grid(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,   U_NA,   U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NA,    U_NA,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,   U_NA,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA
),

[_GAME] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_DEL,  KC_LGUI, KC_LALT, KC_SPC,  MO(_GAME_ALT), KC_PSCR, KC_RSFT, KC_RCTL, KC_HOME, KC_END, GAME_EXIT
),

[_GAME_ALT] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_UP,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F5,   KC_F6,   _______,   _______, _______, _______, _______, _______,
  KC_ENT,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
  _______, KC_INS,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_DEL, KC_LALT, KC_LGUI,  LOWER,   KC_SPC,OSM(MOD_RSFT),RAISE, KC_HOME, KC_END, KC_PSCR,   OSM(MOD_RCTL)
),
*/

/*
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_DEL,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,OSM(MOD_RSFT),RAISE, KC_HOME, KC_END,  KC_PSCR, OSM(MOD_RCTL)
),
*/

/*
[_DVORAK] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS,
  KC_BSPC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  KC_LCTL, KC_DEL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,OSM(MOD_RSFT),RAISE,  KC_HOME, KC_END, KC_PSCR,   OSM(MOD_RCTL)
),

// Lower (unused)
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LBRC, KC_RBRC,  _______, _______, _______,
  _______, KC_INS,  _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,  _______
),
*/

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down | Up   | Right|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Insert|      |      |      |             |      | Pg Up| Pg Dn|      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LBRC, KC_RBRC,  _______, _______, _______,
  _______, KC_INS,  _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,  _______
),
*/

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |Print |Scroll|Pause | Menu |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|VolUp|VolDown| Next | Prev |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_APP, _______,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  KC_CAPS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPRV, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
*/


};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _GAME:
                rgb_matrix_set_color(i, 0x05, 0x00, 0x0c);
                break;
            default:
                break;
        }
    }
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 5; i <= 8; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0x33, 0x00, 0x00);
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
/*
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
	  */
      }
    return true;
};

/*
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

*/
