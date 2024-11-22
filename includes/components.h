#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>

class CustomContainerH : public ftxui::ComponentBase
{
  public:
    CustomContainerH(ftxui::Components children) : children_(std::move(children)) {};
    ftxui::Element Render() override;
  private:
    ftxui::Components children_;
};

/*
class CustomContainerH : public ftxui::ComponentBase
{
  public:
    CustomContainerH(ftxui::Components children) : children_(std::move(children)) {};
    ftxui::Element Render() override;
  private:
    ftxui::Components children_;
};
*/
#endif