/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"



#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,
        KC_DEL,   KC_A,     KC_S,     KC_D,     KC_F,    KC_G,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_LBRC,
                            KC_LGUI , KC_LCTL,  KC_LALT, LAYER_3, KC_SPC
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}

void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_L1, _L2, _L3);
}
#endif


#if KEYBOARD_SIDE == LEFT

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
        KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
        KC_DEL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     WJ_LBRC,
                           KC_LGUI,  KC_LCTL,  KC_LALT,  LAYER_1,  KC_SPC
    )};
    

 
void setupKeymap() {


    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______
);

    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        _______,  _______, _______,  _______,  _______,  _______,
        _______,  _______, _______,  _______,  _______,  _______,
        _______,  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,
        _______,  KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
                           _______,  _______,  _______,  _______,  _______
);


    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, BAT_TST, BAT_CLC,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______
);

    uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, KC_ZKHK, _______
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, adjust[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::DT_TAP, tap[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_L1, _L2, _L3);
}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
                 KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_GRV,
                 KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_JYEN,
                 KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_BSPC,
        WJ_RBRC, KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_ENT,  LAYER_2, KC_MINS,KC_EQL,  KC_LBRC
    )};


void setupKeymap() {


    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INT1, _______,
        _______, _______, _______, _______,  _______
);


    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F12,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______
);


    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 BLEPRF1, BLEPRF2, BLEPRF3, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
);

    uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_ZKHK, _______, _______, _______
);


    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, adjust[row][col]);
            matrix[row][col].addActivation(_QWERTY, Method::DT_TAP, tap[row][col]);
        }
    }
}

void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_L1, _L2, _L3);
}


#endif




