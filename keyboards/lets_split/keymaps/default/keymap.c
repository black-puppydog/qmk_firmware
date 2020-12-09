#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------|-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RS/Ret|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LC/Esc| Adj  | GUI  | Alt  |Lower |    Space    |Raise | Ralt | Menu |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,          KC_Q,    KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,     KC_DEL,     \
  KC_BSPC,         KC_A,    KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN,  KC_QUOT,    \
  KC_LSFT,         KC_Z,    KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_SFTENT,  \
  LCTL_T(KC_ESC),  ADJUST,  KC_LGUI,  KC_LALT,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_RALT,  KC_APP,  KC_DOWN,    KC_UP     \
),



/* Colemak
 * ,-----------------------------------------|-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |RS/Ret|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LC/Esc| Adj  | GUI  | Alt  |Lower |    Space    |Raise | Ralt | Menu |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  _______,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,    KC_J,    KC_L,     KC_U,     KC_Y,     KC_SCLN,  _______,  \
  _______,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,    KC_H,    KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,  \
  _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_K,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,  \
  _______,  _______,  _______,  _______,  _______,  KC_SPC,  KC_SPC,  _______,  _______,  _______,  _______,  _______   \
),
/* Dvorak
 * ,-----------------------------------------|-----------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bksp |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |RS/Ret|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LC/Esc| Adj  | GUI  | Alt  |Lower |    Space    |Raise | Ralt | Menu |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  _______,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,    KC_F,    KC_G,     KC_C,     KC_R,     KC_L,     _______,  \
  _______,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,    KC_D,    KC_H,     KC_T,     KC_N,     KC_S,     KC_SLSH,  \
  _______,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,    KC_B,    KC_M,     KC_W,     KC_V,     KC_Z,     _______,  \
  _______,  _______,  _______,  _______,  _______,  KC_SPC,  KC_SPC,  _______,  _______,  _______,  _______,  _______   \
),

/* Lower
 * ,-----------------------------------------|-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Home |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Alt1 | Alt2 | Alt3 | Alt4 | Alt5 | Alt6 |   ç  |   ß  |   ä  |   ü  |   ö  | PgUp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Alt7 | Alt8 | Alt9 | Alt0 | Alt[ | Alt] |   |  |   _  |   +  |   {  |   }  | PgDn |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   œ  |   æ  |  é   |      |             |      |circum|grave |aigue | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD,     KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,         KC_PERC,        KC_CIRC,     KC_AMPR,     KC_ASTR,     KC_LPRN,     KC_RPRN,        KC_MPLY,    \
  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5),     LALT(KC_6),     RALT(KC_C),  RALT(KC_S),  RALT(KC_Q),  RALT(KC_Y),  RALT(KC_SCLN),  KC_VOLU,    \
  LALT(KC_7),  LALT(KC_8),  LALT(KC_9),  LALT(KC_0),  LALT(KC_LBRC),  LALT(KC_RBRC),  KC_PIPE,     KC_UNDS,     KC_PLUS,     KC_LCBR,     KC_RCBR,        KC_VOLD,    \
  RALT(KC_E),  RALT(KC_V),  RALT(KC_Z),  _______,     _______,        _______,        _______,     _______,     RALT(KC_X),  RALT(KC_R),  RALT(KC_T),     KC_MNXT     \
),

/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ArrL | ArrD | ArrU | ArrR |   \  | Vol+ |
 * |------+------+------+------+------|------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  -   |   =  |   [  |   ]  | Vol+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |MouseL|MouseD|MouseU|MouseR|      |             |      |Mouse1|Mouse3|Mouse2| Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_HOME,  \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSLS,  KC_PGUP,  \
  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_PGDN,  \
  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,  _______,  _______,  KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_END    \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------|-----------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
