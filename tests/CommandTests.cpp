#include "mocks.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../src/MoveCommand.h"

using ::testing::AtLeast;   
using ::testing::Throw;         
using ::testing::Return;              


TEST(Movable, Test){

    using ::testing::Mock;

    auto  movable = std::make_shared<MockMovable>(); 
    Eigen::RowVector2i x{1, 1};

    EXPECT_CALL(*movable, getCoordinates())
            .WillOnce(Return(x));

    EXPECT_CALL(*movable, getVelocity())
            .WillOnce(Throw(new std::exception{}));

    MoveCommand cmd(movable);
 
    EXPECT_ANY_THROW(cmd.execute());   
}


TEST(Rotable, Test){

    using ::testing::Mock;

    auto  movable = std::make_shared<MockMovable>(); 
    Eigen::RowVector2i x{1, 1};

    EXPECT_CALL(*movable, getCoordinates())
            .WillOnce(Return(x));

    EXPECT_CALL(*movable, getVelocity())
            .WillOnce(Throw(new std::exception{}));

    MoveCommand cmd(movable);
 
    EXPECT_ANY_THROW(cmd.execute());   
}