#include "MovableAdapter.h"


MovableAdapter::MovableAdapter(std::shared_ptr<UObject> movableObject) : _movableObject(movableObject)
{}


void MovableAdapter::setCoordinates(const Eigen::VectorXf& newCoordinates)
{
    _movableObject->setProperty("coordinates", newCoordinates);
}


Eigen::VectorXf MovableAdapter::getCoordinates()
{
    return std::any_cast<Eigen::VectorXf>(_movableObject->getProperty("coordinates"));
}


Eigen::VectorXf MovableAdapter::getVelocity()
{
    return std::any_cast<Eigen::VectorXf>(_movableObject->getProperty("velocity"));
}