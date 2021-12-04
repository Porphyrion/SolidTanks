#pragma once

#include <Eigen/Dense>

class IMovable
{
public:
    virtual ~IMovable() = default;
    virtual void setCoordinates(const Eigen::RowVector2i& newCoordinates) = 0;
    virtual Eigen::RowVector2i getCoordinates() = 0;
    virtual Eigen::RowVector2i getVelocity() = 0; 
};
