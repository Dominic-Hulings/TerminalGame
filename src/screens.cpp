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

void MainScreens::MainMenu() //*
{
  auto screen = ScreenInteractive::Fullscreen();

  bool s = false;
  bool q = false;

  auto startBtn = Button("start", [&] { screen.ExitLoopClosure()(); system("clear"); EscScreen(); }) | Hoverable(&s);
  auto quitBtn = Button("quit", [&] { system("clear"); exit(0); }) | Hoverable(&q);

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

void MainScreens::EscScreen()
{
  auto screen = ScreenInteractive::Fullscreen();

  bool r = false;
  bool e = false;

  auto resumeBtn = Button("resume", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&r);
  auto exitBtn = Button("exit", [&] { screen.ExitLoopClosure()(); system("clear"); exit(0); }) | Hoverable(&e);

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