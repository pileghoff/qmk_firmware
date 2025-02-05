/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
// clang-format off

#include QMK_KEYBOARD_H
#include "keymap_danish.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_ESC,    DK_Q,   DK_W,   DK_F,    DK_P,     DK_B,                        DK_J,   DK_L,    DK_U,    DK_Y,   DK_OSTR, DK_ARNG,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_TAB,  DK_A,  DK_R,   DK_S,      DK_T,     DK_G,                         DK_M,   DK_N,    DK_E,    DK_I,   DK_O, DK_AE,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL,   DK_Z,   DK_X,   DK_C,   DK_D,    DK_V,                           DK_K,   DK_H,    DK_SCLN, DK_DOT, DK_DOT, CW_TOGG,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LGUI, MO(2),  KC_SPC,      KC_ENT, MO(1), KC_BSPC
        //                                    `--------------------------'  `--------------------------'

        ),

    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, DK_1,    DK_2,    DK_3,    DK_4,   DK_5,                          DK_6,   DK_7,    DK_8,    DK_9,    DK_0,    DK_PLUS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN,KC_UP, KC_RIGHT, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______,  _______, _______,                     _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______,  _______,   _______, _______, _______
        //                                    `--------------------------'  `--------------------------'
        ),

    /*
   _______, DK_1, DK_2,     DK_3,   DK_4, DK_5,      DK_6,  DK_7,   DK_8,   DK_9, DK_0,    DK_PLUS,
   _______, _______, _______, _______,  _______, _______,      _______,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
   _______, _______, _______,     _______,   _______, _______,      _______,  _______,   _______,   _______, _______,     _______,
                           _______, _______,  _______,   _______, _______,    _______
*/

    [2] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, DK_CIRC, DK_EXLM, DK_UNDS, DK_COLN, DK_QUOT,                      _______,DK_RPRN, DK_RBRC, DK_RCBR, DK_SCLN,  _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, DK_AT  , DK_HASH, DK_MINS,  DK_DOT, DK_TILD,                      _______,DK_LPRN, DK_LBRC, DK_LCBR, DK_COMM,  _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, DK_GRV , DK_ASTR, DK_LABK, DK_RABK, DK_DLR,                       _______,DK_SLSH, DK_BSLS, DK_PIPE, _______,  _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______,  _______,   _______, _______, _______
        //                                    `--------------------------'  `--------------------------'
       ),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DK_MINS:
        case DK_AE:
        case DK_ARNG:
        case DK_OSTR:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DK_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
