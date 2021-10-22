#pragma once 

#include <memory>

#include "IMovable.h"
#include "UObject.h"

class MovableAdapter : public IMovable
{
    public:
        MovableAdapter(std::shared_ptr<UObject> movableObject);
    private:
};