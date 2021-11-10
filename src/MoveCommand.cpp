#include "MoveCommand.h"

#include <iostream>
#include <exception>

MoveCommand::MoveCommand(std::shared_ptr<IMovable> movebleObject) : _movebleObject(movebleObject)
{}


void MoveCommand::execute()
{
    try{
        auto coordinates = _movebleObject->getCoordinates();
        auto velocity =  _movebleObject->getVelocity();
        _movebleObject->setCoordinates(coordinates + velocity);
    }
    catch(std::exception& e){
        std::cerr <<e.what() << '\n';
    }
}   
   