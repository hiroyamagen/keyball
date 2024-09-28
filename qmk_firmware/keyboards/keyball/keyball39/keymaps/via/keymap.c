/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"
#include "keymap_japanese.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    LALT_T(KC_Q) , KC_W     , KC_E      , KC_R        , KC_T     ,                                     KC_Y        , KC_U   , KC_I     , KC_O     , KC_P     ,
    LCTL_T(KC_A) , KC_S     , LT(3,KC_D), LT(2,KC_F)  , KC_G     ,                                     KC_H        , KC_J   , KC_K     , KC_L     , LCTL_T(KC_SCLN)  ,
    LSFT_T(KC_Z) , KC_X     , KC_C      , KC_V        , KC_B     ,                                     KC_N        , KC_M   , KC_COMM  , KC_DOT   , LSFT_T(KC_SLSH)  ,
    KC_LGUI      , KC_DELETE, KC_ESC    , LT(2,KC_TAB), LT(1,KC_SPACE) , LT(2,JP_ZKHK), LT(4,KC_BSPC), LT(1,KC_ENT), KC_NO  , KC_NO    , KC_NO    , TG(2)
  ),

  [1] = LAYOUT_universal(
    S(KC_1)     , S(KC_2) , S(KC_3)    , S(KC_4)    , S(KC_5)  ,                            S(KC_6)  , S(KC_7)    , S(KC_8)    , S(KC_9)    , KC_INT3  ,
    S(KC_MINS)  , KC_MINS , S(KC_SCLN) , S(KC_QUOT) , _______  ,                            KC_LBRC  , S(KC_LBRC) , S(KC_RBRC) , S(KC_BSLS) , KC_QUOT  ,
    _______     , _______ , S(KC_INT3) , S(KC_EQL)  , KC_EQL   ,                            _______  , S(KC_INT1) , KC_RBRC    , KC_BSLS    , _______  ,
    _______     , _______ , _______    , _______    , _______  , _______  ,      _______  , _______  , _______    , _______    , _______    , _______
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______        , _______  ,                            _______  , KC_LEFT  , KC_UP    , KC_RIGHT , _______  ,
    _______  , _______  , _______  , LWIN(KC_LCTL)  , _______  ,                            KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  ,
    _______  , _______  , _______  , _______        , _______  ,                            KC_PGDN  , KC_BTN4  , KC_BTN5  , _______  , _______  ,
    _______  , _______  , _______  , _______        , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , KC_LEFT  , KC_UP    , KC_RIGHT , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_PGUP  , _______  , KC_DOWN  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_PGDN  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
