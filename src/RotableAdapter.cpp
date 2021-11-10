#include "RotableAdapter.h"

RotableAdapter::RotableAdapter(std::shared_ptr<UObject> rotable) : _rotableObject(rotable)
{}


void RotableAdapter::setDirection(int direction)
{
    _rotableObject->setProperty("direction", direction);
}


int RotableAdapter::getDirection()
{
    try
    {
        auto direction = std::any_cast<int>(_rotableObject->getProperty("direction"));
        return direction;
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}


int RotableAdapter::getAngularVelocity()
{
    try
    {
        auto angularVelocity = std::any_cast<int>(_rotableObject->getProperty("angular_velocity"));
        return angularVelocity;
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}