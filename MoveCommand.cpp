#include "MoveCommand.h"
#include <iostream>

MoveCommand::MoveCommand(std::shared_ptr<IMovable> movebleObject) : _movebleObject(movebleObject)
{}


void MoveCommand::execute()
{
    _movebleObject->setCoordinates(_movebleObject->getCoordinates() + _movebleObject->getVelocity());
    auto newCoord = _movebleObject->getCoordinates();
    std::cout<< "New coordinates"<< newCoord(0,0) << " " << newCoord(1,0) <<std::endl;
}