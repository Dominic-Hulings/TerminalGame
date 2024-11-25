#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <memory>

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp" 

#include "screens.h"
#include "components.h"

using namespace ftxui;

using std::string, std::ifstream, std::vector, std::make_shared, std::filesystem::exists, std::filesystem::current_path;

//!
//! STYLE DEFINITIONS
//!

//!
//! END STYLE DEFINITIONS
//!

//!
//! MAINSCREENS CLASS DEFINITIONS
//!

void MainScreens::MainMenu() //* MAIN MENU -----
{
  auto screen = ScreenInteractive::Fullscreen();

  bool s, q = false;

  auto startBtn = Button("Start", [&] { screen.ExitLoopClosure()(); system("clear"); NightSelect(); }) | Hoverable(&s);
  auto quitBtn = Button("Quit", [&] { system("clear"); exit(0); }) | Hoverable(&q);

  Components components = {startBtn, quitBtn};

  auto buttons = make_shared<CustomContainerH>(components);

  auto mainMenu = Renderer(buttons, [&] {
    auto sBackColor = (s) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto qBackColor = (q) ? color(Color::GrayLight) : color(Color::GrayDark);
    return vbox ({
      filler(),
      DisplaySprite("logoSPR") | center,
      filler(),
      hbox ({
        filler(),
        filler(),
        startBtn->Render() | flex | sBackColor,
        filler(),
        quitBtn->Render() | flex | qBackColor,
        filler(),
        filler()
      }),
      filler(),
      filler()
    });
  });

  screen.Loop(mainMenu);
}

void MainScreens::EscScreen() //* ESC SCREEN -----
{
  auto screen = ScreenInteractive::Fullscreen();

  bool r, e = false;

  auto resumeBtn = Button("Resume", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&r);
  auto exitBtn = Button("Exit", [&] { screen.ExitLoopClosure()(); system("clear"); exit(0); }) | Hoverable(&e);

  auto components = {resumeBtn, exitBtn};

  auto buttons = make_shared<CustomContainerH>(components);

  auto escMenu = Renderer(buttons, [&] {
    auto rBackColor = (r) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto eBackColor = (e) ? color(Color::GrayLight) : color(Color::GrayDark);
    return vbox ({
      filler(),
      hbox ({
        filler(),
        vbox ({
          filler(),
          filler(),
          resumeBtn->Render() | flex | rBackColor,
          filler(),
          exitBtn->Render() | flex | eBackColor,
          filler(),
          filler(),
          filler()
        }),
        filler(),
        filler(),
        filler()
      }),
      filler()
    });
  });

  screen.Loop(escMenu);
}

void MainScreens::NightSelect() //* NIGHT SELECT -----
{
  auto screen = ScreenInteractive::Fullscreen();

  bool one, two, three, four, five = false; //* Bools to hold if a button is hoverable

  auto nOneBtn = Button("Night 1", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&one);
  auto nTwoBtn = Button("Night 2", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&two);
  auto nThreeBtn = Button("Night 3", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&three);
  auto nFourBtn = Button("Night 4", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&four);
  auto nFiveBtn = Button("Night 5", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&five);

  auto components = {nOneBtn, nTwoBtn, nThreeBtn, nFourBtn, nFiveBtn};

  auto buttons = make_shared<CustomContainerH>(components);

  auto nightSelectMenu = Renderer(buttons, [&] {
    auto oneBackColor = (one) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto twoBackColor = (two) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto threeBackColor = (three) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto fourBackColor = (four) ? color(Color::GrayLight) : color(Color::GrayDark);
    auto fiveBackColor = (five) ? color(Color::GrayLight) : color(Color::GrayDark);

    return vbox({
      filler(),
      hbox({
        filler(),
        filler(),
        nOneBtn->Render() | flex | oneBackColor,
        filler(),
        nTwoBtn->Render() | flex | twoBackColor,
        filler(),
        nThreeBtn->Render() | flex | threeBackColor,
        filler(),
        nFourBtn->Render() | flex | fourBackColor,
        filler(),
        nFiveBtn->Render() | flex | fiveBackColor,
        filler(),
        filler()
      }),
      filler()
    });
  });

  screen.Loop(nightSelectMenu);
}

//!
//! END MAINSCREENS CLASS DEFINITIONS
//!

//!
//! DISPLAYMETHODS CLASS DEFINITIONS
//!

Element DisplayMethods::DisplaySprite(string sprNameToDisplay)
{
  string spriteFilePath = string(current_path().parent_path()) + "/sprites/" + sprNameToDisplay + ".txt";

  if (!exists(spriteFilePath))
  {
    return text("Sprite not found!");
  }

  else
  {
    ifstream spriteFile(spriteFilePath);
    string lineRead;
    vector<Element> documentElements;

    while (getline(spriteFile, lineRead))
    {
      documentElements.push_back(hbox(text(lineRead)));
    }

    return vbox(documentElements);
  }
}

//!
//! END DISPLAYMETHODS CLASS DEFINITIONS
//!