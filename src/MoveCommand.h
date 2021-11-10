#pragma once 

#include <memory>

#include "ICommand.h"
#include "IMovable.h"


class MoveCommand : public ICommand
{
public:
    MoveCommand(std::shared_ptr<IMovable> movebleObject);

    void execute() override final;
    
private:
    std::shared_ptr<IMovable> _movebleObject;
};
