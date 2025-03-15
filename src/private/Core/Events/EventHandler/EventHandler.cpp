#include "EventHandler/EventHandler.hpp"


EventHandler * EventHandler::GetInstance(){
    if(!instance)
        instance= new EventHandler;
    return instance;
}

void EventHandler::Bind(){
    
}