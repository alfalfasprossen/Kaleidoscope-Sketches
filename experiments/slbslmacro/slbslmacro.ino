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
#include "Kaleidoscope-Macros.h"

enum {
  MACRO_SL_BSL
};

/* *INDENT-OFF* */
KEYMAPS(
  [0] = KEYMAP_STACKED
  (
   Key_Q,            Key_W,       Key_E,       Key_R,                Key_T,
   Key_A,            Key_S,       Key_D,       Key_F,                Key_G,
   Key_Z,            Key_X,       Key_C,       Key_V,                Key_B,              Key_Tab,
   Key_Esc,          XXX,         Key_LeftGui, Key_LeftControl,      Key_Backspace,      Key_LeftAlt,

                    Key_Y,     Key_U,            Key_I,               Key_O,      Key_P,
                    Key_H,     Key_J,            Key_K,               Key_L,      Key_Semicolon,
   Key_Enter,       Key_N,     Key_M,            Key_Comma,           Key_Period, Key_Slash,
   Key_RightShift,  Key_Space, Key_LeftControl,  XXX,                 XXX,        M(MACRO_SL_BSL)
  )
)
/* *INDENT-ON* */

const macro_t *slBslMacro(uint8_t keyState) {
  // Macro to send Slash when pressed and Backslash when pressed shifted.
  if (keyToggledOn(keyState)) {
    if (kaleidoscope::Runtime.hid().keyboard().wasModifierKeyActive(Key_LeftShift) ||
        kaleidoscope::Runtime.hid().keyboard().wasModifierKeyActive(Key_RightShift))
    {
      // If Shift is held, release them first so we get a Backslash
      // and not a Pipe.
      return MACRODOWN(
        U(LeftShift),
        U(RightShift),
        T(Backslash));
    } else {
      return MACRODOWN(T(Slash));
    }
  }
  return MACRO_NONE;
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_SL_BSL:
      return slBslMacro(keyState);
  }
  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
  Macros
);

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
