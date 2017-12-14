#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, KC_ESC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RGHT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       KC_LCTL,KC_RALT,LSFT_T(KC_BSPC),        RSFT_T(KC_SPC), KC_RALT, KC_RCTL
  //                  `----+----+----'        `----+----+----'
  )
};
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
