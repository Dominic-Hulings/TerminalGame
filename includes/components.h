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
    bool OnEvent(ftxui::Event event) override;
  private:
    ftxui::Components children_;
};

class CustomButton : public ftxui::ComponentBase
{
  public:
    CustomButton();
  private:

};

#endif