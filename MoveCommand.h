#pragma once 

#include <memory>

#include "Command.h"
#include "IMovable.h"


class MoveCommand : public ICommand
{
public:
    MoveCommand(std::shared_ptr<IMovable> movableObject);

    void execute() override final;
    
private:
    std::shared_ptr<IMovable> _movableObject;
} 