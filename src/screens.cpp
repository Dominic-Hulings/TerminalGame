#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "ftxui/component/screen_interactive.hpp" 

#include "screens.h"

using namespace ftxui;

using std::string, std::ifstream, std::vector, std::filesystem::exists, std::filesystem::current_path;


//!
//! MAINSCREENS CLASS DEFINITIONS
//!

void MainScreens::MainMenu() //*
{
  auto screen = ScreenInteractive::Fullscreen();

  auto startBtn = Button("start", [&] { screen.ExitLoopClosure()(); system("clear");});
  auto quitBtn = Button("quit", [&] { system("clear"); exit(0);});
  
  auto mainMenu = Container::Horizontal({startBtn, quitBtn}, 0);

  auto renderer = Renderer(mainMenu, [&] {
    return vbox ({
      filler(),
      DisplaySprite("logoSPR") | center,
      filler(),
      hbox ({
        filler(),
        filler(),
        startBtn->Render() | flex,
        filler(),
        quitBtn->Render() | flex,
        filler(),
        filler()
      }),
      filler(),
      filler()
    });
  });

  screen.Loop(renderer);
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