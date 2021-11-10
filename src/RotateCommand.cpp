#include "RotateCommand.h"
#include <iostream>

RotateCommand::RotateCommand(std::shared_ptr<IRotable> rotable) : _rotableObject(rotable)
{}


void RotateCommand::execute()
{
    try{
        auto direction = _rotableObject->getDirection();
        auto angularVelocity = _rotableObject->getAngularVelocity();
        _rotableObject->setDirection( (direction +  angularVelocity) % _maxDirection);
    }
    catch(std::exception& e)
    {
         std::cerr << e.what() << '\n';
    }
}
