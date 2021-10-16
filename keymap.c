#include QMK_KEYBOARD_H
// #include keymap_swedish_osx_ansi.h

#define TG_NKRO MAGIC_TOGGLE_NKRO



// Tap Dance keycodes
enum td_keycodes {
    H_CTL
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void htcl_finished(qk_tap_dance_state_t *state, void *user_data);
void htcl_reset(qk_tap_dance_state_t *state, void *user_data);


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
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_BSPC, \
  KC_GRAVE,  KC_A,    KC_S,    TD(H_CTL),    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST, KC_LCTRL, KC_LALT, KC_LGUI,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | `    |  ~  |  {   |   [   |   )  |  '  |  "  |   )  |   ]  |   }   |  \|  |  '    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |RESET |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNKRO|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_GRAVE,  KC_TILD,   KC_LCBR,   KC_LBRC,   KC_LPRN,   KC_LT,   KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_QUOT, \
  RESET,   KC_F7,   KC_F8,   KC_F9,   KC_LBRACKET,  KC_F11,  KC_RBRACKET,S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
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
  WORKMAN, _______, _______, KC_MS_U, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV,KC_MNXT, _______,  _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPLY, _______, KC_BTN1, KC_BTN2, _______, _______, _______, \
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

void htcl_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_H);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_H);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

void htcl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_H);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_H);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [H_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, htcl_finished, htcl_reset)
};