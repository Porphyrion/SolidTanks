#include "gmock/gmock.h" 

#include "../../src/IRotable.h" 


class MockMovable : public IRotable
{
public:
    MOCK_METHOD(void,  getDirection, (const Eigen::RowVector2i& newCoord), (override));
    MOCK_METHOD(Eigen::RowVector2i, getCoordinates, (), (override));
    MOCK_METHOD(Eigen::RowVector2i, getVelocity, (), (override));
};

