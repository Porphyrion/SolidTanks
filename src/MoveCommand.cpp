#include "MoveCommand.h"
#include <iostream>

MoveCommand::MoveCommand(std::shared_ptr<IMovable> movebleObject) : _movebleObject(movebleObject)
{}


void MoveCommand::execute()
{
    _movebleObject->setCoordinates(_movebleObject->getCoordinates() + _movebleObject->getVelocity());
}
   