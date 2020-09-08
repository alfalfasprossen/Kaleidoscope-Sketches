set arduino_dir=%USERPROFILE%\Documents\Arduino
rmdir %arduino_dir%\hardware\keyboardio
mklink /D %arduino_dir%\hardware\keyboardio %~dp0..\Kaleidoscope-Bundle-Keyboardio

set libname=Kaleidoscope-LED-LeaderSequenceColor
rmdir %arduino_dir%\libraries\%libname%
mklink /D %arduino_dir%\libraries\%libname% %~dp0..\%libname%

set libname=Kaleidoscope-Repeater
rmdir %arduino_dir%\libraries\%libname%
mklink /D %arduino_dir%\libraries\%libname% %~dp0\..\%libname%
