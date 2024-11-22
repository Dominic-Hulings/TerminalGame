#include <vector>
#include <string>
#include <ftxui/component/event.hpp>

#include "components.h"

using std::string;

using namespace ftxui;

Element CustomContainerH::Render()
{
  Elements allElements;

  for (Component t : children_)
  {
    allElements.push_back(hbox(t));
  }

  return vbox(allElements);
}