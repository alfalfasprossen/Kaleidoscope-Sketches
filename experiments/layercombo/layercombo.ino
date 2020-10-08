// Atreus sketch

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"

enum {
  L0,
  L1,
  L2,
  L3
};

/* *INDENT-OFF* */
KEYMAPS(
  [L0] = KEYMAP_STACKED
  (
   Key_0, XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX, ___,
   ___,   ___, ___, ___, ShiftToLayer(L1), ___,

        XXX, XXX, XXX, XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,
   ___, XXX, XXX, XXX, XXX, XXX,
   ___, ShiftToLayer(L2), ___, ___, ___, ___
  ),

  [L1] = KEYMAP_STACKED
  (
   Key_1, XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX, ___,
   ___,   ___, ___, ___, ___, ___,

        XXX, XXX, XXX, XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,
   ___, XXX, XXX, XXX, XXX, XXX,
   ___, ShiftToLayer(L3), ___, ___, ___, ___
  ),

  [L2] = KEYMAP_STACKED
  (
   Key_2, XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX, ___,
   ___,   ___, ___, ___, ShiftToLayer(L3), ___,

        XXX, XXX, XXX, XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,
   ___, XXX, XXX, XXX, XXX, XXX,
   ___, ___, ___, ___, ___, ___
  ),
  
  [L3] = KEYMAP_STACKED
  (
   Key_3, XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX,
   XXX,   XXX, XXX, XXX, XXX, ___,
   ___,   ___, ___, ___, ___, ___,

        XXX, XXX, XXX, XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,
   ___, XXX, XXX, XXX, XXX, XXX,
   ___, ___, ___, ___, ___, ___
  )
)
/* *INDENT-ON* */

void setup() {
  Kaleidoscope.setup();
}
void loop() {
  Kaleidoscope.loop();
}
