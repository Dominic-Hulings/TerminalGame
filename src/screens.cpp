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

  auto startBtn = Button("start", [&] { screen.ExitLoopClosure()(); system("clear"); }) | Hoverable(&s);
  auto quitBtn = Button("quit", [&] { system("clear"); exit(0); }) | Hoverable(&q);

  Components y = {startBtn, quitBtn};

  auto buttons = make_shared<CustomContainerH>(y);

  auto mainMenu = Renderer(buttons, [&] {
    auto sBackColor = (s) ? color(Color::Red) : color(Color::Blue);
    auto qBackColor = (q) ? color(Color::Red) : color(Color::Blue);
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