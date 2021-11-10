#pragma once 

#include <memory>

#include "UObject.h"
#include "IRotable.h"

class RotableAdapter : public IRotable
{
    public: 
        using Ptr = std::shared_ptr<RotableAdapter>;

        RotableAdapter(std::shared_ptr<UObject> rotableObject);
        ~RotableAdapter() = default;

        void setDirection(int derection) override;
        int  getDirection() override;
        int  getAngularVelocity() override; 
    
    private:
        std::shared_ptr<UObject> _rotableObject;
};
