/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-Leader.h"


enum {
  MACRO_ARROW
};

#define Key_Excl LSHIFT(Key_1) // !
#define Key_At LSHIFT(Key_2) // @
#define Key_Hash LSHIFT(Key_3) // #
#define Key_Dollar LSHIFT(Key_4) // $
#define Key_Percent LSHIFT(Key_5) // %
#define Key_Caret LSHIFT(Key_6) // ^
#define Key_And LSHIFT(Key_7) // $
#define Key_Star LSHIFT(Key_8) // *
#define Key_Plus LSHIFT(Key_Equals) // +
#define Key_Tilde LSHIFT(Key_Backtick) // ~
#define Key_Less LSHIFT(Key_Comma) // <
#define Key_Great LSHIFT(Key_Period) // >
#define Key_DblQuote LSHIFT(Key_Quote) // "
#define Key_Underscr LSHIFT(Key_Minus) // _

enum {
  QWERTY,
  COLEMAK,
  NUMBER,
  SYMBOL,
  NAV,
  SUPER
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
   Key_Q,            Key_W,       Key_E,       Key_R,                Key_T,
   Key_A,            Key_S,       Key_D,       LT(NAV, F),           Key_G,
   Key_Z,            Key_X,       Key_C,       Key_V,                Key_B,              Key_Tab,
   Key_Esc,          OSL(NUMBER), Key_LeftGui, Key_LeftControl,      LT(NAV, Backspace), Key_LeftAlt,

                    Key_Y,     Key_U,            Key_I,               Key_O,      Key_P,
                    Key_H,     LT(NAV, J),       Key_K,               Key_L,      Key_Semicolon,
   Key_Enter,       Key_N,     Key_M,            Key_Comma,           Key_Period, Key_Slash,
   OSM(RightShift), MT(LeftControl, Space), ShiftToLayer(SYMBOL), OSL(NUMBER), OSL(SUPER), LEAD(0)
  ),

  // A customized colemak layout: DH-mod, SR-swap
  [COLEMAK] = KEYMAP_STACKED
  (
   Key_Q,            Key_W,       Key_F,       Key_P,                Key_B,
   MT(LeftShift, A), Key_S,       Key_R,       LT(NAV, T),           Key_G,
   Key_Z,            Key_X,       Key_C,       Key_D,                Key_V, ___,
   ___,              ___,         ___,         ___,                  ___,   ___,

        Key_J,     Key_L,      Key_U,               Key_Y,      Key_Semicolon,
        Key_K,     LT(NAV, N), MT(RightControl, E), Key_I,      MT(RightShift, O),
   ___, Key_M,     Key_H,      Key_Comma,           Key_Period, Key_Slash,
   ___, ___,       ___,        ___,                 ___,        ___
  ),

  [NUMBER] = KEYMAP_STACKED
  (
   Key_KeypadAdd,      Key_7, Key_8, Key_9, Key_KeypadDivide,
   Key_KeypadDot,      Key_3, Key_2, Key_1, Key_0,
   Key_KeypadSubtract, Key_4, Key_5, Key_6, Key_KeypadDot,    ___,
   ___,                ___,   ___,   ___,   ___,              ___,

        XXX, XXX, XXX, XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,
   ___, XXX, XXX, XXX, XXX, XXX,
   ___, ___, ___, ___, ___, ___
  ),

  [SYMBOL] = KEYMAP_STACKED
  (
   Key_Percent, Key_Caret, Key_Star, Key_LeftBracket,      Key_RightBracket,
   Key_Dollar,  Key_At,    Key_Hash, Key_LeftParen,        Key_RightParen,
   Key_Less,    Key_Great, Key_Excl, Key_LeftCurlyBracket, Key_RightCurlyBracket, ___,
   ___,         ___,       ___,      ___,                  ___,                   ___,

        XXX,          XXX,          Key_And,   M(MACRO_ARROW), Key_Backslash,
        Key_Tilde,    Key_Underscr, Key_Minus, Key_Plus,       Key_Equals,
   ___, Key_Backtick, Key_DblQuote, Key_Quote, Key_Pipe,       Key_Slash,
   ___, ___, ___, ___, ___,  ___
  ),

  [NAV] = KEYMAP_STACKED
  (
   XXX, LCTRL(Key_Backspace), LCTRL(Key_Delete), LCTRL(Key_LeftBracket), LCTRL(Key_RightBracket),
   XXX, Key_Backspace,        Key_Delete,        LCTRL(Key_LeftParen),   LCTRL(Key_RightParen),
   XXX, XXX,                  XXX,               XXX,                    XXX,   ___,
   ___, ___, ___, ___, ___, ___,

   //   Key_F11,      LCTRL(Key_LeftArrow), Key_UpArrow,   LCTRL(Key_RightArrow), Key_PrintScreen,
   //   Key_Home, Key_LeftArrow,        Key_DownArrow, Key_RightArrow,        Key_End,
        Key_F11,           LCTRL(Key_LeftArrow), Key_Home,    LCTRL(Key_RightArrow), Key_PrintScreen,
        Key_LeftArrow, Key_DownArrow,        Key_UpArrow, Key_RightArrow,        Key_End,
   ___, Key_Enter,     Key_PageDown,         Key_PageUp,  XXX,                   XXX,
   ___, ___, ___, ___, ___,  ___
  ),

  [SUPER] = KEYMAP_STACKED
  (
   Key_1, Key_2, Key_3, Key_4, Key_5,
   Key_F1,      Key_F2,      Key_F3,      Key_F4,      Key_F5,
   Consumer_ScanPreviousTrack, Consumer_Play, Consumer_Mute, Consumer_VolumeDecrement, Consumer_VolumeIncrement, Consumer_ScanNextTrack,
   ___,          ___,        Key_LeftGui, ___,         ___,         ___,
   // One Shot interferes with the plain gui-key on double tap, as the
   // layer then locks. This maybe is controllable per layer. Also I
   // would need a macro for the 1-5 keys ans sending them as LGUI
   // will start over again each time - so instead of sending the keys
   // only we would have to have GUI held until we actually release
   // it, but only after first time hitting a number key on this
   // layer. - replacing the one-shot with a custom macro might be
   // simpler, the number keys would have to be a macro key then as
   // well though.
   //
   // It might just be simpler to keep it a default gui key and move
   // the F keys to the number layer and the other keys to wherever
   // there is space. Espcl F2 and F11 and PrintScr might get nicer
   // positions on the Nav layer or so.

        Key_F11, Key_F12,    XXX,    XXX,    Key_PrintScreen,
        Key_F6,  Key_F7, Key_F8, Key_F9, Key_F10,
   ___, XXX,     XXX,    XXX,    XXX,    XXX,
   ___, ___,     ___,    ___,    ___,    ___

  )
)
/* *INDENT-ON* */

static void arrowMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("->"));
  }
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_ARROW:
    arrowMacro(keyState);
    break;
  }
  return MACRO_NONE;
}

static void leadToggleColemakLayer(uint8_t seq_index) {
  if (Layer.isActive(COLEMAK)) {
    Layer.deactivate(COLEMAK);
  } else {
    Layer.activate(COLEMAK);
  }
}

// *INDENT-OFF*
static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
LEADER_DICT({LEADER_SEQ(LEAD(0), Key_T, Key_C), leadToggleColemakLayer});
// *INDENT-ON*

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Macros,
  Qukeys,
  OneShot,
  Leader
);

void setup() {
  Kaleidoscope.setup();
  // EEPROMKeymap.setup(10);
  Leader.dictionary = leader_dictionary;
  Qukeys.setOverlapThreshold(0);
  Qukeys.setHoldTimeout(150);
}

void loop() {
  Kaleidoscope.loop();
}
