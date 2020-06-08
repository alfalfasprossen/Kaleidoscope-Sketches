// -*- mode: c++ -*-

#include "Kaleidoscope.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include <Kaleidoscope-OneShot.h>

// *INDENT-OFF*
KEYMAPS(
  [0] = KEYMAP_STACKED
  (Key_NoKey, Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick,      Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,        Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown,      Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,

   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   OSM(LeftShift),

   // Note: LSHIFT does NOT work as it modifies the key to not be
   // recognized as a LEDControl key. In theory the bit that shift
   // sets is safe for that purpose - it is currently not used by
   // anything other than expressing the shift modifier being held,
   // however some other plugin that makes use of that flag and is
   // SYNTHETIC and IS_INTERNAL might come up and allowing LEDControl
   // to use this bit optionally may cause conflicts later on.
   LSHIFT(Key_LEDEffectNext), Key_6, Key_7, Key_8, Key_9, Key_0,  Key_skip,
   Key_Enter, Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
              Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   Key_skip,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,

   Key_RightShift, Key_RightAlt, Key_Spacebar, Key_RightControl,
   XXX)
)
// *INDENT-ON*

static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 0, 160);

KALEIDOSCOPE_INIT_PLUGINS(
  OneShot,
  LEDControl,
  solidRed, solidGreen, solidBlue
);

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
