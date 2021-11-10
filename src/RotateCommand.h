#pragma once 

#include <memory>

#include "ICommand.h"
#include "IRotable.h"

class RotateCommand : public ICommand
{
    public: 
        RotateCommand(std::shared_ptr<IRotable> rotable);

        void execute() override;

    private:
        std::shared_ptr<IRotable> _rotableObject;

        const uint _maxDirection = 8;
};
