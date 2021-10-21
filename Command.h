#pragma once

class ICommand
{
public:
    ICommand() = default;
    ~ICommand() = default;

    virtual void execute() = 0;
};

