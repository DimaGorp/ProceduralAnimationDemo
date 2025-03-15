#pragma once
#include <SFML/Graphics.hpp>
#include <Events/Event/Event.hpp>
#include <queue>
class EventHandler{
private:
    static EventHandler * instance;
    std::vector<Event*> events;
public:
    EventHandler(const EventHandler&) = delete;
    ~EventHandler(){instance = nullptr;}
    static EventHandler * GetInstance();
private:
    EventHandler() = default;
public:
    void Bind();
};
EventHandler* EventHandler::instance = nullptr;
