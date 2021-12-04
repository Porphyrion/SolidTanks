#pragma once

class IRotable
{
public:
    ~IRotable() = default;
    virtual int getDirection() = 0;
    virtual void setDirection(int direction) = 0;
    virtual int getAngularVelocity() = 0;    
};