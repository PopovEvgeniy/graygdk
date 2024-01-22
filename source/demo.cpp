#include "graygdk.h"

int main()
{
 char perfomance[8];
 GRAYGDK::Common::Timer timer;
 GRAYGDK::Input::Keyboard keyboard;
 GRAYGDK::Input::Gamepad gamepad;
 GRAYGDK::Input::Mouse mouse;
 GRAYGDK::Misc::Audio media;
 GRAYGDK::Graphics::Screen screen;
 GRAYGDK::Graphics::Scene space;
 GRAYGDK::Graphics::Sprite ship;
 GRAYGDK::Graphics::Text text;
 GRAYGDK::Tools::enable_logging("log.txt");
 keyboard.initialize();
 screen.initialize();
 space.load("space.tga");
 space.prepare(screen);
 ship.load("ship.tga",GRAYGDK::HORIZONTAL_ANIMATED,2);
 ship.set_start(screen.get_width()/2,screen.get_height()/2);
 ship.go_start();
 text.load_font("font.tga");
 text.set_position(text.get_font_width(),text.get_font_height());
 mouse.hide();
 timer.set_timer(1);
 media.initialize();
 media.load("space.mp3");
 memset(perfomance,0,8);
 while(screen.sync())
 {
  gamepad.update();
  media.play_loop();
  if (mouse.check_press(GRAYGDK::MOUSE_LEFT)==true)
  {
   break;
  }
  if (keyboard.check_hold(57)==true)
  {
   break;
  }
  if (keyboard.check_hold(59)==true)
  {
   space.disable_mirror();
  }
  if (keyboard.check_hold(60)==true)
  {
   space.horizontal_mirror();
  }
  if (keyboard.check_hold(61)==true)
  {
   space.vertical_mirror();
  }
  if (keyboard.check_hold(62)==true)
  {
   space.complex_mirror();
  }
  if (keyboard.check_hold(72)==true)
  {
   ship.decrease_y(2);
  }
  if (keyboard.check_hold(80)==true)
  {
   ship.increase_y(2);
  }
  if (keyboard.check_hold(75)==true)
  {
   ship.decrease_x(2);
  }
  if (keyboard.check_hold(77)==true)
  {
   ship.increase_x(2);
  }
  if (gamepad.check_hold(GRAYGDK::GAMEPAD_BUTTON2)==true)
  {
   break;
  }
  switch (gamepad.get_dpad())
  {
   case GRAYGDK::GAMEPAD_UP:
   ship.decrease_y();
   break;
   case GRAYGDK::GAMEPAD_DOWN:
   ship.increase_y();
   break;
   case GRAYGDK::GAMEPAD_UPLEFT:
   ship.decrease_y();
   ship.decrease_x();
   break;
   case GRAYGDK::GAMEPAD_UPRIGHT:
   ship.decrease_y();
   ship.increase_x();
   break;
   case GRAYGDK::GAMEPAD_DOWNLEFT:
   ship.increase_y();
   ship.decrease_x();
   break;
   case GRAYGDK::GAMEPAD_DOWNRIGHT:
   ship.increase_y();
   ship.increase_x();
   break;
   case GRAYGDK::GAMEPAD_LEFT:
   ship.decrease_x();
   break;
   case GRAYGDK::GAMEPAD_RIGHT:
   ship.increase_x();
   break;
   default:
   ;
   break;
  }
  if (gamepad.get_stick_x(GRAYGDK::GAMEPAD_LEFT_STICK)==GRAYGDK::GAMEPAD_NEGATIVE_DIRECTION)
  {
   ship.decrease_x();
  }
  if (gamepad.get_stick_x(GRAYGDK::GAMEPAD_LEFT_STICK)==GRAYGDK::GAMEPAD_POSITIVE_DIRECTION)
  {
   ship.increase_x();
  }
  if (gamepad.get_stick_y(GRAYGDK::GAMEPAD_LEFT_STICK)==GRAYGDK::GAMEPAD_NEGATIVE_DIRECTION)
  {
   ship.decrease_y();
  }
  if (gamepad.get_stick_y(GRAYGDK::GAMEPAD_LEFT_STICK)==GRAYGDK::GAMEPAD_POSITIVE_DIRECTION)
  {
   ship.increase_y();
  }
  if (screen.check_x(ship.get_x())==false)
  {
   ship.go_start_x();
  }
  if (screen.check_y(ship.get_y())==false)
  {
   ship.go_start_y();
  }
  itoa(screen.get_fps(),perfomance,10);
  space.draw();
  text.print(perfomance);
  ship.draw();
  if (timer.check_timer()==true)
  {
   ship.step();
  }

 }
 return 0;
}