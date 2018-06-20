#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _SYM 2
#define _NAV 3
#define _LSWAP 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  SYM,
  NAV,
  LSWAP,
  M_TOGGLE_LOGGING
};

enum tap_dance_actions {
  MOD_DANCE = 0
}; 

#define _______ KC_TRNS

#define WORD_FW LCTL(KC_RIGHT)
#define WORD_BW LCTL(KC_LEFT)

bool log_enable = false;

LEADER_EXTERNS();

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, OSL(_LSWAP),
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEAD,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT),
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       OSL(_NAV), KC_BSPC, TD(MOD_DANCE),       TD(MOD_DANCE), KC_SPC, OSL(_SYM)
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_COLEMAK] = KEYMAP( 
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     _______, KC_1, KC_2, KC_3, KC_4, KC_5,         KC_6, KC_7, KC_8, KC_9, KC_0, _______, 
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______, KC_Q, KC_W, KC_F, KC_P, KC_G,         KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_ENT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______, KC_A, KC_R, KC_S, KC_T, KC_D,          KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______,     _______, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       _______, _______, _______,       _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_SYM] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, KC_MINS, KC_EQL , KC_PIPE,                            _______, _______, _______, _______, _______, KC_SLCK,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, KC_UNDS, KC_PLUS, KC_BSLS,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,         KC_F7  ,  KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),
  
  [_NAV] = KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, //name?
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______,                            WORD_BW, KC_PGDN, KC_PGUP, WORD_FW, KC_HOME, _______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , _______,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                                      _______, _______, _______,                  _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_LSWAP] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      TO(_QWERTY), _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL,                         _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, TO(_SYM), _______, _______, _______,                            _______, _______, _______, M_TOGGLE_LOGGING, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, TO(_COLEMAK), _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
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
  if (log_enable && record->event.pressed) {
    uint8_t layer = biton32(layer_state);
    xprintf ("KL: col=%02d, row=%02d, pressed=%d, layer=%02d\n", record->event.key.col,
            record->event.key.row, record->event.pressed, layer);
  }
  
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case M_TOGGLE_LOGGING:
      if (record->event.pressed) {
        log_enable = !log_enable;
      }
      return false;
      break;
  }
  return true;
}


void send_key(uint16_t code) {
  register_code(code);
  unregister_code(code);
}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      register_code(KC_LSFT);
      register_code(KC_9);
      unregister_code(KC_9);
      register_code(KC_0);
      unregister_code(KC_0);
      unregister_code(KC_LSFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_LBRC);
      unregister_code(KC_LBRC);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    
    SEQ_ONE_KEY(KC_G) {
      register_code(KC_LSFT);
      register_code(KC_COMM);
      unregister_code(KC_COMM);
      register_code(KC_DOT);
      unregister_code(KC_DOT);
      unregister_code(KC_LSFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    
    SEQ_ONE_KEY(KC_S) {
      register_code(KC_LSFT);
      register_code(KC_LBRC);
      unregister_code(KC_LBRC);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      unregister_code(KC_LSFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    
    SEQ_TWO_KEYS(KC_G, KC_A) {
      register_code(KC_LSFT);
      send_key(KC_COMM);
      unregister_code(KC_LSFT);
      
      send_key(KC_A);
      send_key(KC_S);
      send_key(KC_C);
      send_key(KC_I);
      send_key(KC_I);
      
      register_code(KC_LSFT);
      send_key(KC_DOT);
      unregister_code(KC_LSFT);
    }
    
    SEQ_THREE_KEYS(KC_G, KC_A, KC_S) {
      register_code(KC_LSFT);
      send_key(KC_COMM);
      unregister_code(KC_LSFT);
      
      send_key(KC_SLSH);
      send_key(KC_A);
      send_key(KC_S);
      send_key(KC_C);
      send_key(KC_I);
      send_key(KC_I);
      
      register_code(KC_LSFT);
      send_key(KC_DOT);
      unregister_code(KC_LSFT);
    }
    
    SEQ_TWO_KEYS(KC_G, KC_T) {
      register_code(KC_LSFT);
      send_key(KC_COMM);
      unregister_code(KC_LSFT);
      
      send_key(KC_T);
      send_key(KC_H);
      send_key(KC_R);
      send_key(KC_E);
      send_key(KC_E);
      register_code(KC_LSFT);
      send_key(KC_MINS);
      unregister_code(KC_LSFT);
      send_key(KC_D);
      send_key(KC_O);
      send_key(KC_T);
      send_key(KC_S);
      
      register_code(KC_LSFT);
      send_key(KC_DOT);
      unregister_code(KC_LSFT);
    }
    
    SEQ_TWO_KEYS(KC_G, KC_E) {
      register_code(KC_LSFT);
      send_key(KC_COMM);
      unregister_code(KC_LSFT);
      
      send_key(KC_E);
      send_key(KC_N);
      send_key(KC_D);
      register_code(KC_LSFT);
      send_key(KC_MINS);
      unregister_code(KC_LSFT);
      send_key(KC_L);
      send_key(KC_I);
      send_key(KC_N);
      send_key(KC_E);
      
      register_code(KC_LSFT);
      send_key(KC_DOT);
      unregister_code(KC_LSFT);
    }
    
    SEQ_TWO_KEYS(KC_G, KC_P) {
      register_code(KC_LSFT);
      send_key(KC_COMM);
      unregister_code(KC_LSFT);
      
      send_key(KC_P);
      send_key(KC_A);
      send_key(KC_R);
      send_key(KC_T);
      send_key(KC_N);
      send_key(KC_E);
      send_key(KC_R);
      
      register_code(KC_LSFT);
      send_key(KC_DOT);
      unregister_code(KC_LSFT);
    }
  }
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
