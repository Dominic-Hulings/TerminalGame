#ifndef SCREENS_H
#define SCREENS_H

#include <ftxui/dom/elements.hpp>
#include <string>

class DisplayMethods
{
  protected:
    ftxui::Element DisplaySprite(std::string sprNameToDisplay);
};

class MainScreens : DisplayMethods
{
  protected:
    void EscScreen();
    void MainMenu();
    void NightSelect();
};

#endif