#include "MovebleAdapter.h"


MovebleAdapter::MovebleAdapter(std::shared_ptr<UObject> movableObject) : _movableObject(movableObject)
{}


void MovebleAdapter::setCoordinates(const Eigen::VectorXf& newCoordinates)
{
    _movableObject->setProperty("coordinates", newCoordinates);
}


Eigen::VectorXf MovebleAdapter::getCoordinates()
{
    return std::any_cast<Eigen::VectorXf>(_movableObject->getProperty("coordinates"));
}


Eigen::VectorXf MovebleAdapter::getVelocity()
{
    return std::any_cast<Eigen::VectorXf>(_movableObject->getProperty("velocity"));
}