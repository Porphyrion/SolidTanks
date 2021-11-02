#include "MovebleAdapter.h"


MovebleAdapter::MovebleAdapter() : _movableObject(std::make_shared<UObject>())
{}


MovebleAdapter::MovebleAdapter(std::shared_ptr<UObject> movableObject) : _movableObject(movableObject)
{}


void MovebleAdapter::setCoordinates(const Eigen::RowVector2i& newCoordinates)
{
    _movableObject->setProperty("coordinates", newCoordinates);
}


Eigen::RowVector2i MovebleAdapter::getCoordinates()
{
    auto result = std::any_cast<Eigen::RowVector2i>(_movableObject->getProperty("coordinates"));
    return result;
}


Eigen::RowVector2i MovebleAdapter::getVelocity()
{
    auto result = std::any_cast<Eigen::RowVector2i>(_movableObject->getProperty("velocity"));
    return result;
}