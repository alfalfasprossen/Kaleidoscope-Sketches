// -*- mode: c++ -*-

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include <Kaleidoscope-OneShot.h>

enum { MACRO_NEXT_PREV_LED_MODE };

// *INDENT-OFF*
KEYMAPS(
  [0] = KEYMAP_STACKED
  (Key_NoKey, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_NEXT_PREV_LED_MODE),
   Key_Backtick,      Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,        Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown,      Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,

   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   OSM(LeftShift),

   LSHIFT(M(MACRO_NEXT_PREV_LED_MODE)),  Key_6, Key_7, Key_8,     Key_9,      Key_0,         Key_skip,
   Key_Enter, Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
              Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   Key_skip,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,

   Key_RightShift, Key_RightAlt, Key_Spacebar, Key_RightControl,
   XXX),
)
// *INDENT-ON*


static void nextPrevLEDModeMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    if (kaleidoscope::Runtime.hid().keyboard().isModifierKeyActive(Key_LeftShift) ||
        kaleidoscope::Runtime.hid().keyboard().isModifierKeyActive(Key_RightShift))
    {
      LEDControl.prev_mode();
    } else {
      LEDControl.next_mode();
    }
  }
}


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_NEXT_PREV_LED_MODE:
    nextPrevLEDModeMacro(keyState);
    break;

  }
  return MACRO_NONE;
}

static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

KALEIDOSCOPE_INIT_PLUGINS(
  OneShot,
  LEDControl,
  solidYellow, solidGreen, solidViolet,
  Macros
);

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
