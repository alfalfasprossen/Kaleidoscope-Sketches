// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#include "Kaleidoscope.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-Colormap.h"
#include "Kaleidoscope-HardwareTestMode.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-USB-Quirks.h"

#include <Kaleidoscope-TopsyTurvy.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-LED-ActiveModColor.h>
#include <Kaleidoscope-Leader.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-Qukeys.h>

#include <Kaleidoscope-LED-LeaderSequenceColor.h>

// Macros
enum {
  MACRO_ARROW,
  MACRO_TOGGLE_RECENT_OR_DEFAULT
};

// Layers
enum { QWERTY, COLEMAK, MAC_MODIFIERS, GAMING, GAMING_TR1, GAMING_TR3, NUMBER, SYMBOL, FUNCTION };

// *INDENT-OFF*
KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_TOGGLE_RECENT_OR_DEFAULT),
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_Quote, Key_A, Key_S, Key_D, Key_F, Key_G,
   OSL(NUMBER), Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftGui,
   Key_LeftControl, LT(SYMBOL, Backspace), Key_LeftAlt, OSM(LeftShift),
   ShiftToLayer(FUNCTION),

   LEAD(0),  Key_6, Key_7, Key_8, Key_9, Key_0, XXX,
   Key_Enter, Key_Y, Key_U, Key_I, Key_O, Key_P, Key_Equals,
   Key_H, LT(NUMBER, J), Key_K, Key_L, Key_Semicolon, TOPSY(Quote),
   LSHIFT(Key_Minus), Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_Minus,
   OSL(SYMBOL), OSM(RightShift), Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

  // A customized colemak layout: DH-mod, SR-swap
  [COLEMAK] = KEYMAP_STACKED
  (Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_TOGGLE_RECENT_OR_DEFAULT),
   // Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_G, Key_Tab,
   // Key_Quote, Key_A, Key_S, Key_R, Key_T, Key_D,
   // OSL(NUMBER), Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftGui,
   Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_B, Key_Tab,
   Key_Quote, Key_A, Key_S, Key_R, Key_T, Key_G,
   OSL(NUMBER), Key_Z, Key_X, Key_C, Key_D, Key_V, Key_LeftGui,
   ___, ___, ___, ___,
   ___,

   LEAD(0),  Key_6, Key_7, Key_8, Key_9, Key_0, XXX,
   Key_Enter, Key_J, Key_L, Key_U, Key_Y, Key_Semicolon, Key_Equals,
   Key_K, LT(NUMBER, N), Key_E, Key_I, Key_O, TOPSY(Quote),
   LSHIFT(Key_Minus), Key_M, Key_H, Key_Comma, Key_Period, Key_Slash, Key_Minus,
   ___, ___, ___, ___,
   ___),

  [MAC_MODIFIERS] = KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, OSM(LeftAlt),
   ___, ___, OSM(LeftGui), ___,
   ___,

   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   OSM(LeftGui), ___, ___, ___,
   ___),

  [GAMING] = KEYMAP_STACKED
  (Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_TOGGLE_RECENT_OR_DEFAULT),
   Key_Quote, Key_T, Key_Q, Key_W, Key_E, Key_R, Key_Tab,
   Key_Backtick, Key_G, Key_A, Key_S, Key_D, Key_F,
   TOPSY(Backtick), Key_Z, Key_X, Key_C, Key_V, Key_B, Key_LeftGui,
   Key_LeftControl, Key_Spacebar, Key_LeftAlt, ShiftToLayer(FUNCTION),
   Key_LeftShift,

   XXX,  Key_6, Key_7, Key_8, Key_9, Key_0, Key_Minus,
   Key_Enter, Key_Y, Key_U, Key_I, Key_O, Key_P, Key_Equals,
   Key_H, Key_J, Key_K, Key_L, Key_Semicolon, TOPSY(Quote),
   TOPSY(Minus), Key_N, Key_M, Key_Comma, Key_Period, Key_Slash, Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

  [GAMING_TR1] = KEYMAP_STACKED
  (Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_TOGGLE_RECENT_OR_DEFAULT),
   Key_Quote, XXX, Key_Delete, Key_UpArrow, Key_PageDown, XXX, Key_Escape,
   Key_Backtick, Key_LeftControl, Key_LeftArrow, Key_DownArrow, Key_RightArrow, XXX,
   TOPSY(Backtick), Key_Keypad0, Key_Period, Key_End, Key_Slash /*Flare*/, XXX, Key_LeftGui,
   Key_LeftControl, Key_Spacebar, Key_LeftAlt, ShiftToLayer(FUNCTION),
   Key_LeftShift,

   XXX,  Key_6, Key_7, Key_8, Key_9, Key_0, Key_Minus,
   Key_Enter, XXX, Key_Delete, Key_UpArrow, Key_PageDown, XXX, XXX,
   XXX, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_LeftControl, XXX,
   XXX, XXX, Key_Slash /*Flare*/, Key_End, Key_Period, Key_Keypad0, XXX,
   ShiftToLayer(FUNCTION), Key_LeftAlt, Key_Spacebar, Key_RightControl,
   Key_RightShift),

  [GAMING_TR3] = KEYMAP_STACKED
  (Key_Escape, Key_1, Key_2, Key_3, Key_4, Key_5, M(MACRO_TOGGLE_RECENT_OR_DEFAULT),
   Key_Quote, XXX, LSHIFT(Key_LeftArrow), Key_UpArrow, LSHIFT(Key_RightArrow), XXX, Key_Escape,
   Key_Slash /*Sprint*/, Key_LeftControl, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_Period /*Duck*/,
   TOPSY(Backtick), Key_Keypad0, Key_Slash, Key_End, Key_Comma /*Flare*/, XXX, Key_LeftGui,
   Key_LeftControl, Key_Spacebar, Key_LeftAlt, ShiftToLayer(FUNCTION),
   Key_LeftShift,

   XXX,  Key_6, Key_7, Key_8, Key_9, Key_0, Key_Minus,
   Key_Enter, XXX, LSHIFT(Key_LeftArrow), Key_UpArrow, LSHIFT(Key_RightArrow), XXX, XXX,
   Key_Period /*Duck*/, Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_LeftControl, Key_Slash /*Sprint*/,
   XXX, XXX, Key_Comma /*Flare*/, Key_End, Key_Period, Key_Keypad0, XXX,
   ShiftToLayer(FUNCTION), Key_LeftAlt, Key_Spacebar, Key_RightControl,
   Key_RightShift),

  [NUMBER] = KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, XXX,
   ___, Key_KeypadAdd, Key_7, Key_8, Key_9, Key_KeypadDivide, ___,
   ___, Key_KeypadDot, Key_3, Key_2, Key_1, Key_0,
   ___, Key_KeypadSubtract, Key_4, Key_5, Key_6, Key_KeypadDot, ___,
   ___, ___, ___, XXX,
   ShiftToLayer(FUNCTION),

   XXX,  ___, ___, ___, ___, ___, XXX,
   ___, ___, ___, ___, ___, ___, ___,
   Key_5, Key_6, Key_7, Key_8, Key_9, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ShiftToLayer(FUNCTION)),

  // ! @ # $ % ^ & * / \ | <> [] () {} _ - + = ' ` ~ " ; : , . ->
  [SYMBOL] =  KEYMAP_STACKED
  (___, XXX, XXX, XXX, XXX, XXX, XXX,
   XXX, LSHIFT(Key_5) /* % */, LSHIFT(Key_6) /* ^ */, Key_KeypadMultiply /* * */, Key_LeftBracket, Key_RightBracket, XXX,
   XXX, LSHIFT(Key_4) /* $ */, LSHIFT(Key_2) /* @ */, LSHIFT(Key_3) /* # */, Key_LeftParen, Key_RightParen,
   XXX, LSHIFT(Key_Comma) /* < */, LSHIFT(Key_Period) /* > */, LSHIFT(Key_1) /* ! */, Key_LeftCurlyBracket, Key_RightCurlyBracket, XXX,
   ___, ___, ___, ___,
   ___,

   XXX, XXX, XXX, XXX, XXX, XXX, XXX,
   XXX, XXX, XXX, LSHIFT(Key_7) /* & */, XXX, XXX, XXX,
   LSHIFT(Key_Backtick) /* ~ */, LSHIFT(Key_Minus) /* _ */, Key_Minus, Key_KeypadAdd, Key_Equals, XXX,
   XXX, Key_Backtick, LSHIFT(Key_Quote) /* " */, Key_Quote /* ' */, Key_Pipe, Key_Slash, XXX,
   ___, ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (___, Key_F1, Key_F2, Key_F3, Key_F4, Key_F5, Key_LEDEffectNext,
   Consumer_Mute, XXX, LCTRL(Key_Backspace), LCTRL(Key_Delete), LCTRL(Key_LeftBracket), LCTRL(Key_RightBracket), XXX,
   Consumer_VolumeIncrement, XXX, Key_Backspace, Key_Delete, LCTRL(Key_LeftParen), LCTRL(Key_RightParen),
   // TODO: The shortcuts may be uneccessary, I might replace them
   // with often used right-side keys for mouse based applications,
   // like the E key which is on the right with colemak. On the other
   // hand, if I keep using a mac, I might want to ge used to these
   // and change them on a mac-layer, instead of re-thinking to hold
   // CMD instead of CTRL by hand.
   Consumer_VolumeDecrement,  LCTRL(Key_Z), LCTRL(Key_X), LCTRL(Key_C), LCTRL(Key_V), LCTRL(Key_B), XXX,
   ___, Key_Space, ___, ___,
   ___,

   XXX, Key_F6, Key_F7, Key_F8, Key_F9, Key_F10, Key_F11,
   XXX, XXX, LCTRL(Key_LeftArrow), Key_Home, LCTRL(Key_RightArrow), Key_PrintScreen, Key_F12,
   Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow,  Key_End, XXX,
   XXX, XXX, Key_PageDown, Key_PageUp, XXX, Key_Backslash, Key_Pipe,
   ___, ___, Key_Backspace, ___,
   ___)
) // KEYMAPS(

// *INDENT-ON*

static void arrowMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("->"));
  }
}

static uint8_t recentGamingLayer = GAMING;

/**
 * Toggle the most recent gaming layer.
 */
static void toggleRecentOrDefaultMacro(uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }
  if (Layer.top() < GAMING || Layer.top() >= NUMBER) {
    // Current top layer is not a gaming layer.
    Layer.activate(recentGamingLayer);
  } else {
    Layer.deactivate(recentGamingLayer);
  }
}

static void leadToggleMacLayer(uint8_t seq_index) {
  if (Layer.isActive(MAC_MODIFIERS)) {
    Layer.deactivate(MAC_MODIFIERS);
  } else {
    Layer.activate(MAC_MODIFIERS);
  }
}

static void leadToggleColemakLayer(uint8_t seq_index) {
  if (Layer.isActive(COLEMAK)) {
    Layer.deactivate(COLEMAK);
  } else {
    Layer.activate(COLEMAK);
  }
}

static void leadToggleGamingXLayer(uint8_t seq_index) {
  // This assumes that the gaming layers are first in the leader
  // dict and their order matches that in the layer list. Also
  // currently this assumes that the leader can only be activated
  // when no gaming layer is active.
  uint8_t targetLayer = GAMING + seq_index;
  if (Layer.isActive(targetLayer)) {
    Layer.deactivate(targetLayer);
  } else {
    // TODO: Maybe it would be safer to deactivate all gaming
    // layers except for the target.
    Layer.activate(targetLayer);
    recentGamingLayer = targetLayer;
  }
}


// *INDENT-OFF*
static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
LEADER_DICT({LEADER_SEQ(LEAD(0), Key_G, Key_G), leadToggleGamingXLayer},
            {LEADER_SEQ(LEAD(0), Key_G, Key_T, Key_1), leadToggleGamingXLayer},
            {LEADER_SEQ(LEAD(0), Key_G, Key_T, Key_3), leadToggleGamingXLayer},
            {LEADER_SEQ(LEAD(0), Key_C), leadToggleColemakLayer},
            {LEADER_SEQ(LEAD(0), Key_M), leadToggleMacLayer});
// *INDENT-ON*


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_ARROW:
    arrowMacro(keyState);
    break;

  case MACRO_TOGGLE_RECENT_OR_DEFAULT:
    toggleRecentOrDefaultMacro(keyState);
    break;
  }
  return MACRO_NONE;
}


static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/**
 * Toggle the LEDs off when the host goes to sleep, and turn them
 * back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
}, {
  .action = enterHardwareTestMode,
  // Left Fn + Prog + LED
  .keys = { R3C6, R0C0, R0C6 }
});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  Focus,
  BootGreetingEffect,
  HardwareTestMode,

  Qukeys,
  OneShot,
  LEDControl,
  // We start with the LED effect that turns off all the LEDs.
  LEDOff,
  LEDRainbowWaveEffect,
  LEDDigitalRainEffect,
  solidYellow, solidGreen, solidViolet,

  LeaderSequenceColorEffect,
  Leader,

  TopsyTurvy,
  ActiveModColorEffect,
  Macros,
  HostPowerManagement,
  MagicCombo,
  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks
);


void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  ActiveModColorEffect.highlightNormalModifiers(false);
  Leader.dictionary = leader_dictionary;
  Qukeys.setOverlapThreshold(0);
}


void loop() {
  Kaleidoscope.loop();
}
