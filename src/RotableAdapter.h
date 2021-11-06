#pragma once 

#include <memory>
#include <any>

#include "UObject.h"
#include "IRotable.h"

class RotableAdapter : public IRotable
{
    public: 
        RotableAdapter(std::shared_ptr<UObject> movableObject);
        ~RotableAdapter() = default;

        void setDirection(int derection) override;
        int  getDirection() override;
        int  getAngularVelocity() override; 
    
    private:
        std::shared_ptr<UObject> _rotableObject;
};
