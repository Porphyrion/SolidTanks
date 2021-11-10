#pragma once 

#include <memory>

#include "IMovable.h"
#include "UObject.h"

class MovebleAdapter : public IMovable
{
    public:
        using Ptr = std::shared_ptr<MovebleAdapter>;

        MovebleAdapter(std::shared_ptr<UObject> movableObject);
        ~MovebleAdapter() = default;

        void setCoordinates(const Eigen::RowVector2i& newCoordinates) override;
        Eigen::RowVector2i getCoordinates() override;
        Eigen::RowVector2i getVelocity() override;  
        
    private:
        std::shared_ptr<UObject> _movableObject;
};