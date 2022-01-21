#include QMK_KEYBOARD_H
// #include keymap_swedish_osx_ansi.h

#define TG_NKRO MAGIC_TOGGLE_NKRO

// Tap Dance keycodes
enum td_keycodes {
    Q_TD,
    D_TD,
    R_TD,
    W_TD,
    F_TD,
    J_TD,
    A_TD,
    S_TD,
    H_TD,
    T_TD,
    N_TD,
    E_TD,
    O_TD,
    I_TD,
    LEFT_TD,
    DOWN_TD,
    UP_TD, 
    RIGHT_TD
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// arrows
void arrow_left_finished(qk_tap_dance_state_t *state, void *user_data);
void arrow_left_reset(qk_tap_dance_state_t *state, void *user_data);

void arrow_down_finished(qk_tap_dance_state_t *state, void *user_data);
void arrow_down_reset(qk_tap_dance_state_t *state, void *user_data);

void arrow_up_finished(qk_tap_dance_state_t *state, void *user_data);
void arrow_up_reset(qk_tap_dance_state_t *state, void *user_data);

void arrow_right_finished(qk_tap_dance_state_t *state, void *user_data);
void arrow_right_reset(qk_tap_dance_state_t *state, void *user_data);



// TOP ROW
// q
void q_td_finished(qk_tap_dance_state_t *state, void *user_data);
void q_td_reset(qk_tap_dance_state_t *state, void *user_data);

// d
void d_td_finished(qk_tap_dance_state_t *state, void *user_data);
void d_td_reset(qk_tap_dance_state_t *state, void *user_data);

// r
void r_td_finished(qk_tap_dance_state_t *state, void *user_data);
void r_td_reset(qk_tap_dance_state_t *state, void *user_data);

// w
void w_td_finished(qk_tap_dance_state_t *state, void *user_data);
void w_td_reset(qk_tap_dance_state_t *state, void *user_data);

// f
void f_td_finished(qk_tap_dance_state_t *state, void *user_data);
void f_td_reset(qk_tap_dance_state_t *state, void *user_data);



// HOME ROW
// a
void a_td_finished(qk_tap_dance_state_t *state, void *user_data);
void a_td_reset(qk_tap_dance_state_t *state, void *user_data);

// s
void s_td_finished(qk_tap_dance_state_t *state, void *user_data);
void s_td_reset(qk_tap_dance_state_t *state, void *user_data);

// h
void h_td_finished(qk_tap_dance_state_t *state, void *user_data);
void h_td_reset(qk_tap_dance_state_t *state, void *user_data);

// t
void t_td_finished(qk_tap_dance_state_t *state, void *user_data);
void t_td_reset(qk_tap_dance_state_t *state, void *user_data);

// n
void n_td_finished(qk_tap_dance_state_t *state, void *user_data);
void n_td_reset(qk_tap_dance_state_t *state, void *user_data);

// e
void e_td_finished(qk_tap_dance_state_t *state, void *user_data);
void e_td_reset(qk_tap_dance_state_t *state, void *user_data);

// o
void o_td_finished(qk_tap_dance_state_t *state, void *user_data);
void o_td_reset(qk_tap_dance_state_t *state, void *user_data);

// i
void i_td_finished(qk_tap_dance_state_t *state, void *user_data);
void i_td_reset(qk_tap_dance_state_t *state, void *user_data);


// Layer names

// TODO: Add hjkl arrows layer
enum layer_names {
    _WORKMAN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROWS
};

enum custom_keycodes {
  WORKMAN = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  ARROWS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |  L  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Adjust | Ctrl  |  Alt | GUI |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_ortho_4x12( \
  KC_TAB,  TD(Q_TD),    TD(D_TD),    TD(R_TD),    TD(W_TD),    KC_B,    KC_J,    TD(F_TD),    KC_U,    KC_P,    KC_SCLN,    KC_BSPC, \
  KC_GRAVE,  TD(A_TD),    TD(S_TD),    TD(H_TD),    TD(T_TD),    KC_G,    KC_Y,    TD(N_TD),    TD(E_TD),    TD(O_TD),    TD(I_TD), KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST, KC_LCTRL, KC_LALT, KC_LGUI,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   TD(LEFT_TD), TD(DOWN_TD), TD(UP_TD),   TD(RIGHT_TD) \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `    |  ~  |  {   |   [   |   )  |  '  |  "  |   )  |   ]  |   }   |  \|  |  '    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |RESET |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNKRO|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_GRAVE,  KC_TILD,   KC_LCBR,   KC_LBRC,   KC_LPRN,   KC_LT,   KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_QUOT, \
  RESET,   KC_F7,   KC_F8,   KC_F9,   KC_LBRACKET,  KC_F11,  KC_RBRACKET,S(KC_NUHS),S(KC_NUBS),_______,KC_EQL,_______, \
  TG_NKRO, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   _  |   -  |   7  |   8  |   9  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   +  |   4  |  5   |   6  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   0  |   1  |  2   |   3  |RESET |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  _______,    _______,    _______, _______,  KC_UNDERSCORE,    KC_MINUS,  KC_7, KC_8, KC_9, _______, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F6,   _______,   KC_UNDERSCORE,   KC_KP_PLUS,   KC_4, KC_5,  KC_6, _______, KC_BSLS, \
  _______, _______,   _______,   _______,   _______,  _______,  KC_0,  KC_1, KC_2,  KC_3, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | Mouse up|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Mouse left | Mouse down | Mouse right | Media play/pause | Mouse1     | Mouse 2|  |  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Reset    |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  WORKMAN, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV,KC_MNXT, _______,  _______, _______, \
  _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  RESET, _______, _______, _______, _______, AU_OFF,  AU_ON,   _______, _______, _______, _______, RESET \
),

/* Arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | left | down | up |  right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] =  LAYOUT_ortho_4x12( \
  WORKMAN, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  RESET, _______, _______, _______, _______, AU_OFF,  AU_ON,   _______, _______, _______, _______, RESET \
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case ARROWS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ARROWS);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}


// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_HOLD;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}



// TOP ROW
// q
void q_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_Q); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_Q);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void q_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_Q); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_Q);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

// d
void d_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_D); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_D);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void d_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_D); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_D);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

// r
void r_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_R); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_R);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void r_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_R); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_R);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

// w
void w_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_W); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_W);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void w_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_W); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_W);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

// f
void f_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_F); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_F);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void f_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_F); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_F);
            break;
        case TD_DOUBLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

// HOME ROW
// a
void a_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_A); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_A);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void a_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_A); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_A);
            break;
        case TD_UNKNOWN:
            break;
    }
}

// s
void s_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_S); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_S);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void s_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_S); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_S);
            break;
        case TD_UNKNOWN:
            break;
    }
}


// h
void h_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_H); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_H);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void h_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_H); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_H);
            break;
        case TD_UNKNOWN:
            break;
    }
}

// t
void t_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_T); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_T);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void t_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_T); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_T);
            break;
        case TD_UNKNOWN:
            break;
    }
}

// n
void n_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_N); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_N);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void n_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_N); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_N);
            break;
        case TD_UNKNOWN:
            break;
    }
}

// e
void e_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_E); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_E);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void e_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_E); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_E);
            break;
        case TD_UNKNOWN:
            break;
    }
}

// o
void o_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_O); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LALT);
            register_code(KC_O);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void o_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_O); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_O);
            break;
        case TD_UNKNOWN:
            break;
    }
}


// i
void i_td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_I); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_I);
            break;
        case TD_UNKNOWN:
            break;
    }
}

void i_td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_I); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_I);
            break;
        case TD_UNKNOWN:
            break;
    }
}


// ARROWS
void arrow_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_LEFT); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LALT);
            register_code(KC_LEFT);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_A);
        case TD_UNKNOWN:
            break;
    }
}


void arrow_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_LEFT); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LALT);
            unregister_code(KC_LEFT);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTRL);
            unregister_code(KC_A);
        case TD_UNKNOWN:
            break;
    }
}

void arrow_down_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_DOWN); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_DOWN);
        case TD_SINGLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void arrow_down_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOWN); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_DOWN);
        case TD_SINGLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void arrow_up_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_UP); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_UP);
        case TD_SINGLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void arrow_up_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_UP); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_UP);
        case TD_SINGLE_HOLD:
        case TD_UNKNOWN:
            break;
    }
}

void arrow_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_RGHT); break;
        case TD_SINGLE_HOLD:
            register_code(KC_LALT);
            register_code(KC_RGHT);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_E);
        case TD_UNKNOWN:
            break;
    }
}

void arrow_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_RGHT); break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LALT);
            unregister_code(KC_RGHT);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTRL);
            unregister_code(KC_E);
        case TD_UNKNOWN:
            break;
    }
}


// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    // top row
    [Q_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_td_finished, q_td_reset),
    [D_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_td_finished, d_td_reset),
    [R_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_td_finished, r_td_reset),
    [W_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_td_finished, w_td_reset),
    [F_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f_td_finished, f_td_reset),
    // home row
    [A_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_td_finished, a_td_reset),
    [S_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_td_finished, s_td_reset),
    [H_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_td_finished, h_td_reset),
    [T_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_td_finished, t_td_reset),
    [N_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n_td_finished, n_td_reset),
    [E_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_td_finished, e_td_reset),
    [O_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_td_finished, o_td_reset),
    [I_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, i_td_finished, i_td_reset),
    // TODO: Add bottom row
    // arrows
    [LEFT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, arrow_left_finished, arrow_left_reset),
    [DOWN_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, arrow_down_finished, arrow_down_reset),
    [UP_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, arrow_up_finished, arrow_up_reset),
    [RIGHT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, arrow_right_finished, arrow_right_reset),
};




