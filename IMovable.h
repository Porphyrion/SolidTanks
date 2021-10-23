#pragma once

#include <Eigen/Dense>

class IMovable
{
public:
    virtual void setCoordinates(const Eigen::VectorXf& newCoordinates) = 0;
    virtual Eigen::VectorXf getCoordinates() = 0;
    virtual Eigen::VectorXf getVelocity() = 0; 
};
