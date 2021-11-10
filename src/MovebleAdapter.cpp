#include "MovebleAdapter.h" 


MovebleAdapter::MovebleAdapter(std::shared_ptr<UObject> movableObject) : _movableObject(movableObject)
{}


void MovebleAdapter::setCoordinates(const Eigen::RowVector2i& newCoordinates)
{
    _movableObject->setProperty("coordinates", newCoordinates);
}


Eigen::RowVector2i MovebleAdapter::getCoordinates()
{
    try{
        auto result = std::any_cast<Eigen::RowVector2i>(_movableObject->getProperty("coordinates"));
        return result;
    }
    catch(const std::exception& e){
        throw e;
    }
    
}


Eigen::RowVector2i MovebleAdapter::getVelocity()
{
    try{
        auto result = std::any_cast<Eigen::RowVector2i>(_movableObject->getProperty("velocity"));
        return result;
    }
    catch(const std::exception& e){
        throw e;
    }
}