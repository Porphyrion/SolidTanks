#pragma once

class IRotable
{
public:
    virtual int getDirection() = 0;
    virtual void setDirection(int direction) = 0;
    virtual int getAngularVelocity() = 0;    
};