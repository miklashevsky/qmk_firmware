/*
Copyright 2020 MechMerlin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum custom_keycodes {
  SOCD_W = 0x7E40,//QK_KB, //QK_USER
  SOCD_A,
  SOCD_S,
  SOCD_D
};

bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SOCD_W:
        if (record->event.pressed) {
            if (s_down) {
                unregister_code(KC_S);
            }
            register_code(KC_W);
            w_down = true;
        } else {
            unregister_code(KC_W);
            w_down = false;

            if (s_down) {
                register_code(KC_S);
            }

        }
        return false;
        break;
    case SOCD_A:
        if (record->event.pressed) {
            if (d_down) {
                unregister_code(KC_D);
            }
            register_code(KC_A);
            a_down = true;
        } else {
            unregister_code(KC_A);
            a_down = false;

            if (d_down) {
                register_code(KC_D);
            }

        }
        return false;
        break;
    case SOCD_S:
        if (record->event.pressed) {
            if (w_down) {
                unregister_code(KC_W);
            }
            register_code(KC_S);
            s_down = true;
        } else {
            unregister_code(KC_S);
            s_down = false;

            if (w_down) {
                register_code(KC_W);
            }

        }
        return false;
        break;
    case SOCD_D:
        if (record->event.pressed) {
            if (a_down) {
                unregister_code(KC_A);
            }
            register_code(KC_D);
            d_down = true;
        } else {
            unregister_code(KC_D);
            d_down = false;

            if (a_down) {
                register_code(KC_A);
            }
        }
        return false;
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_tsangan_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                                      KC_RGUI, KC_RALT, KC_RCTL
    ),

    [1] = LAYOUT_60_tsangan_hhkb(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
        KC_CAPS, BL_TOGG, BL_DOWN, BL_UP,   BL_STEP, _______, _______, _______, _______, KC_SCRL, KC_PAUS, KC_UP,   _______, KC_CLR,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, RGB_VAD, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          _______,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, KC_END,  KC_PGDN, KC_DOWN, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    ),

    [2] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    ),

    [3] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
};
