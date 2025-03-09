#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class sf::RenderWindow;
class sf::Drawable;
class Frame {
private:
    Frame(const sf::VideoMode& videomeode, const std::string& title);
public:
    static Frame* MakeRenderWindow(const sf::VideoMode& videomeode, const std::string& title = "NO TITLE");
    void display(const sf::Drawable& drawable);
    bool isOpen();
    void close();
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::VideoMode videomode;
    const char* title;
};
