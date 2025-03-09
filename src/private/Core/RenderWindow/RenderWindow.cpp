#include "RenderWindow.hpp"

Frame::Frame(const sf::VideoMode& videomeode, const std::string& title){
    this->title;
    this->videomode = videomeode;
    window = std::make_unique<sf::RenderWindow>(videomeode, title);
}
Frame* Frame::MakeRenderWindow(const sf::VideoMode& videomeode, const std::string& title){
    return new Frame(videomeode, title);
}
void Frame::display(const sf::Drawable& drawable) {
    window->clear();
    window->draw(drawable);
    window->display();
}

bool Frame::isOpen() {
    return window->isOpen();
}
void Frame::close() {
    window->close();
}