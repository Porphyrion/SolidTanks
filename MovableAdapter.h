#pragma once 

#include <memory>

#include "IMovable.h"
#include "UObject.h"

class MovableAdapter : public IMovable
{
    public:
        MovableAdapter(std::shared_ptr<UObject> movableObject);
        ~MovableAdapter() = default;

        void setCoordinates(const Eigen::VectorXf& newCoordinates) override;
        Eigen::VectorXf getCoordinates() override;
        Eigen::VectorXf getVelocity() override;  
        
    private:
        std::shared_ptr<UObject> _movableObject;
};