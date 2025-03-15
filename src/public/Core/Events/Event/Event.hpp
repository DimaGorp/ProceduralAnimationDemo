#pragma once
#include <functional>

enum ShapeEvents{
    MouseHover,
    MouseUnHover,
    DragOn,
    DragOver
};

enum WindowEvents{
    Resized,
    Closed,
    Opened
};


class Event{
private:
    std::function<void()> EventFunc;
    void * Object;
public:
    Event(std::function<void()> method){
    }
public:
    static void Bind(std::function<void()> method){
        Event::Event(method);
    }

};