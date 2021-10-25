#pragma once 

#include <memory>

#include "IMovable.h"
#include "UObject.h"

class MovebleAdapter : public IMovable
{
    public:
        MovebleAdapter(std::shared_ptr<UObject> movableObject);
        ~MovebleAdapter() = default;

        void setCoordinates(const Eigen::VectorXf& newCoordinates) override;
        Eigen::VectorXf getCoordinates() override;
        Eigen::VectorXf getVelocity() override;  
        
    private:
        std::shared_ptr<UObject> _movableObject;
};