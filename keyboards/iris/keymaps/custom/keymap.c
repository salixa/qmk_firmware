#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _PATH 1
#define _SYM 2
#define _LSWAP 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PATH,
  SYM,
  LSWAP
};

#define KC_ KC_TRNS
#define _______ KC_TRNS


// Temporary (?) defines for PoE bindings
// Need: Skills x5, Potions x5, pickup, weapon, attack in place (how to do the numlock trick?), all UI elements
#define SKILL1 KC_A
#define SKILL2 KC_S
#define SKILL3 KC_D
#define SKILL4 KC_F
#define SKILL5 KC_G
#define POT1 KC_Q
#define POT2 KC_W
#define POT3 KC_E
#define POT4 KC_R
#define POT5 KC_T
#define PICKUP KC_LALT
#define WSWAP KC_X
#define MAP KC_TAB
#define MINES KC_V
#define HIGHLIGHT KC_Z
#define ATTACK_IN_PLACE KC_F10
#define INVENTORY KC_1
#define STATS KC_2
#define ATLAS KC_3
#define SOCIAL KC_4
#define PASSIVES KC_5
#define OPTIONS KC_PIPE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, OSL(_LSWAP), //name?
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LT(_SYM, KC_ENT),LSFT_T(KC_BSPC), KC_LCTL,       KC_LALT, RSFT_T(KC_SPC), LT(_SYM, KC_ENT)
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_PATH] = KEYMAP( 
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     _______, INVENTORY, STATS, ATLAS, SOCIAL, PASSIVES,         KC_6, KC_7, KC_8, KC_9, KC_0, _______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_F4, POT1, POT2, POT3, POT4, POT5,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LOCK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MAP, SKILL1, SKILL2, SKILL3, SKILL4, SKILL5,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     OPTIONS, HIGHLIGHT, WSWAP, KC_C, MINES, KC_B, KC_DEL,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ATTACK_IN_PLACE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       PICKUP, _______, _______,        _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_SYM] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      KC_GRV , _______, _______, KC_EQL , KC_MINS, _______,                            _______, KC_UNDS, KC_PLUS, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, KC_LT  , KC_LCBR, KC_LBRC, KC_LPRN, _______,                            _______, KC_RPRN, KC_RBRC, KC_LCBR, KC_GT,   _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, OSM(KC_LGUI),        OSM(KC_RGUI), _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),
  
  [_LSWAP] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      TO(_QWERTY), _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, TO(_PATH), _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, TO(_SYM), _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
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

