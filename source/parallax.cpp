#include "graygdk.h"

int main()
{
 bool limit;
 char perfomance[8];
 GRAYGDK::Common::Timer timer;
 GRAYGDK::Input::Keyboard keyboard;
 GRAYGDK::Input::Gamepad gamepad;
 GRAYGDK::Input::Mouse mouse;
 GRAYGDK::Misc::Audio media;
 GRAYGDK::Graphics::Screen screen;
 GRAYGDK::Graphics::Parallax sky;
 GRAYGDK::Graphics::Sprite ship;
 GRAYGDK::Graphics::Text text;
 GRAYGDK::Tools::enable_logging("log.txt");
 keyboard.initialize();
 screen.initialize();
 sky.load("sky.tga");
 sky.prepare(screen);
 sky.set_speed(0.0f,0.001f);
 ship.load("ship.tga",GRAYGDK::HORIZONTAL_ANIMATED,2);
 ship.set_position(screen.get_width()/2,screen.get_height()/2);
 text.load_font("font.tga");
 text.set_position(text.get_font_width(),text.get_font_height());
 mouse.hide();
 timer.set_timer(1);
 media.initialize();
 media.load("space.mp3");
 memset(perfomance,0,8);
 limit=true;
 while(screen.sync(limit))
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
   sky.disable_mirror();
  }
  if (keyboard.check_hold(60)==true)
  {
   sky.horizontal_mirror();
  }
  if (keyboard.check_hold(61)==true)
  {
   sky.vertical_mirror();
  }
  if (keyboard.check_hold(62)==true)
  {
   sky.complex_mirror();
  }
  if (keyboard.check_hold(63)==true)
  {
   limit=true;
  }
  if (keyboard.check_hold(64)==true)
  {
   limit=false;
  }
  if (keyboard.check_hold(72)==true)
  {
   ship.decrease_y();
  }
  if (keyboard.check_hold(80)==true)
  {
   ship.increase_y();
  }
  if (keyboard.check_hold(75)==true)
  {
   ship.decrease_x();
  }
  if (keyboard.check_hold(77)==true)
  {
   ship.increase_x();
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
  if (gamepad.get_stick_x(GRAYGDK::GAMEPAD_RIGHT_STICK)==GRAYGDK::GAMEPAD_NEGATIVE_DIRECTION)
  {
   ship.decrease_x();
  }
  if (gamepad.get_stick_x(GRAYGDK::GAMEPAD_RIGHT_STICK)==GRAYGDK::GAMEPAD_POSITIVE_DIRECTION)
  {
   ship.increase_x();
  }
  if (gamepad.get_stick_y(GRAYGDK::GAMEPAD_RIGHT_STICK)==GRAYGDK::GAMEPAD_NEGATIVE_DIRECTION)
  {
   ship.decrease_y();
  }
  if (gamepad.get_stick_y(GRAYGDK::GAMEPAD_RIGHT_STICK)==GRAYGDK::GAMEPAD_POSITIVE_DIRECTION)
  {
   ship.increase_y();
  }
  if (screen.check_horizontal_border(ship.get_box())==true)
  {
   ship.decrease_x();
  }
  if (screen.check_vertical_border(ship.get_box())==true)
  {
   ship.decrease_y();
  }
  itoa(screen.get_fps(),perfomance,10);
  sky.draw();
  text.print(perfomance);
  ship.draw();
  if (timer.check_timer()==true)
  {
   ship.step();
  }

 }
 return 0;
}