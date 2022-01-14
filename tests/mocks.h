#include "gmock/gmock.h" 

#include "../src/IMovable.h" 


class MockMovable : public IMovable
{
public:
    MOCK_METHOD(void, setCoordinates, (const Eigen::RowVector2i& newCoord), (override));
    MOCK_METHOD(Eigen::RowVector2i, getCoordinates, (), (override));
    MOCK_METHOD(Eigen::RowVector2i, getVelocity, (), (override));
};

