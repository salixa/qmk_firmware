#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _PATH 1
#define _SYM 2
#define _NUMPAD 3
#define _NAV 4
#define _LSWAP 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PATH,
  SYM,
  NAV,
  LSWAP
};

enum tap_dance_actions {
  MOD_DANCE = 0
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
#define PICKUP KC_LSFT
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

#define WORD_FW LCTL(KC_RIGHT)
#define WORD_BW LCTL(KC_LEFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, OSL(_LSWAP), //name?
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     OSL(_NUMPAD), KC_Q, KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       OSL(_NAV), KC_BSPC, TD(MOD_DANCE),       TD(MOD_DANCE), KC_SPC, OSL(_SYM)
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_PATH] = KEYMAP( 
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     _______, INVENTORY, STATS, ATLAS, SOCIAL, PASSIVES,         KC_6, KC_7, KC_8, KC_9, KC_0, _______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______, POT1, POT2, POT3, POT4, POT5,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LOCK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MAP, SKILL1, SKILL2, SKILL3, SKILL4, SKILL5,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     OPTIONS, HIGHLIGHT, WSWAP, KC_C, MINES, KC_B, KC_ENT,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ATTACK_IN_PLACE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       PICKUP, _______, _______,        _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_SYM] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, KC_MINS, KC_UNDS, _______,                            _______, KC_EQL , KC_PLUS, _______, _______, KC_SLCK,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT  ,                            KC_GT  , KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,         KC_F7  ,  KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, OSM(KC_LGUI),        OSM(KC_RGUI), _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),
  
  [_NUMPAD] = KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _______, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, OSL(_LSWAP), //name?
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______,                             _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______,                             _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______, _______,           _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                                      _______, _______, _______,                  _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_NAV] = KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, OSL(_LSWAP), //name?
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, _______, _______, WORD_FW, _______, _______,                            _______, KC_PGUP, _______, _______, _______, _______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, KC_HOME, _______, KC_PGDN, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , _______,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _______, _______, _______, _______, _______, WORD_BW, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                                      _______, _______, _______,                  _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_LSWAP] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      TO(_QWERTY), _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL,                         _______, _______, _______, _______, _______, _______,
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

void mod_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case(1):
      register_code(KC_LCTL);
      break;
    case(2):
      register_code(KC_LALT);
      break;
    case(3):
      register_code(KC_LCTL);
      register_code(KC_LALT);
      break;
    default:
      break;
  }   
}

void mod_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case(1):
      unregister_code(KC_LCTL);
      break;
    case(2):
      unregister_code(KC_LALT);
      break;
    case(3):
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      break;
    default:
      break;
  }   
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [MOD_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mod_dance_finished, mod_dance_reset)
};
