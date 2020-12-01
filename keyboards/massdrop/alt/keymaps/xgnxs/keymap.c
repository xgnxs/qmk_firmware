#include QMK_KEYBOARD_H

enum alt_layers {
  _QWERTY,
  _SYMBOL,
  _NAV,
  _ADJUST
};

enum alt_keycodes
{
  U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
  U_T_AGCR,              //USB Toggle Automatic GCR control
  DBG_TOG,               //DEBUG Toggle On / Off
  DBG_MTRX,              //DEBUG Toggle Matrix Prints
  DBG_KBD,               //DEBUG Toggle Keyboard Prints
  DBG_MOU,               //DEBUG Toggle Mouse Prints
  MD_BOOT,               //Restart into bootloader after hold timeout
};

#define CTL_ESC LCTL_T(KC_ESC)
#define SPC_FN LT(_SYMBOL, KC_SPC)
#define WIN_TRM G(KC_1) 
#define ADMIN_WT C(S(G(KC_1))) // Ctrl+Shift+Win+1
#define WIN_CB G(KC_V)
#define ALT_F4 A(KC_F4)
#define SCL_NAV LT(_NAV, KC_SCLN)

keymap_config_t keymap_config;

// make ~ exist on top layer instead of esc (which is now caps lock / ctrl)
// 2nd layer, Esc and Caps are themselves
// add SPC_FN
// can also press (hold?) FN (one of the layer 1 keys) and MD_BOOT (B)
// add windows terminal shortcuts (normal and admin)
// add windows clipboard shortcut
// add windows calc shortcut
// make DEL FN be ALT+F4 instead of mute
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,  \
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME, \
        CTL_ESC,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     SCL_NAV,  KC_QUOT,            KC_ENT,   WIN_TRM, \
        KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    WIN_CB,  \
        KC_LCTL,    KC_LGUI,  KC_LALT,                                SPC_FN,                                 KC_RALT,  MO(_ADJUST),    KC_LEFT,  KC_DOWN,  KC_RGHT),\

    [_SYMBOL] = LAYOUT_65_ansi_blocker(
        KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  ALT_F4, \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LPRN,  KC_RPRN,  _______,  _______,  _______,  KC_END,  \
        KC_CAPS,    _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL,   KC_BSLS,            _______,  ADMIN_WT,\
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PGUP,  KC_CALC, \
        _______,    _______,  _______,                                _______,                                _______,  _______,  KC_HOME,  KC_PGDN,  KC_END), \

    [_NAV] = LAYOUT_65_ansi_blocker(
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,    _______,  _______,  _______,  _______,  KC_F5,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  \
        _______,    _______,  _______,  KC_END,   KC_HOME,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,  _______,\
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,    _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______), \
    
    [_ADJUST] = LAYOUT_65_ansi_blocker(
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,    RGB_SPD,  RGB_VAI,  RGB_SPI,  RGB_HUI,  RGB_SAI,  _______,  U_T_AUTO, U_T_AGCR, _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,  _______,  \
        _______,    RGB_RMOD, RGB_VAD,  RGB_MOD,  RGB_HUD,  RGB_SAD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,\
        _______,    RGB_TOG,  _______,  _______,  _______,  MD_BOOT,  NK_TOGG,  DBG_TOG,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,    _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______) \
    /*
    [X] = LAYOUT(
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______, \
        _______,    _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  static uint32_t key_timer;

  switch (keycode)
  {
  case U_T_AUTO:
    if (record->event.pressed && MODS_SHIFT && MODS_CTRL)
    {
      TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
    }
    return false;
  case U_T_AGCR:
    if (record->event.pressed && MODS_SHIFT && MODS_CTRL)
    {
      TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
    }
    return false;
  case DBG_TOG:
    if (record->event.pressed)
    {
      TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
    }
    return false;
  case DBG_MTRX:
    if (record->event.pressed)
    {
      TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
    }
    return false;
  case DBG_KBD:
    if (record->event.pressed)
    {
      TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
    }
    return false;
  case DBG_MOU:
    if (record->event.pressed)
    {
      TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
    }
    return false;
  case MD_BOOT:
    if (record->event.pressed)
    {
      key_timer = timer_read32();
    }
    else
    {
      if (timer_elapsed32(key_timer) >= 500)
      {
        reset_keyboard();
      }
    }
    return false;
  case RGB_TOG:
    if (record->event.pressed)
    {
      switch (rgb_matrix_get_flags())
      {
      case LED_FLAG_ALL:
      {
        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
        rgb_matrix_set_color_all(0, 0, 0);
      }
      break;
      case LED_FLAG_KEYLIGHT:
      {
        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
        rgb_matrix_set_color_all(0, 0, 0);
      }
      break;
      case LED_FLAG_UNDERGLOW:
      {
        rgb_matrix_set_flags(LED_FLAG_NONE);
        rgb_matrix_disable_noeeprom();
      }
      break;
      default:
      {
        rgb_matrix_set_flags(LED_FLAG_ALL);
        rgb_matrix_enable_noeeprom();
      }
      break;
      }
    }
    return false;
  default:
    return true; //Process all other keycodes normally
  }
}
