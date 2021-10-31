#include <any>

#include "gtest/gtest.h"
#include "../src/UObject.h"

#include <Eigen/Dense>


std::shared_ptr<UObject> createMovable()
{
    auto moveble  = std::make_shared<UObject>();

    auto coord =  Eigen::RowVector2i(); 
    coord(0) = 4;
    coord(1) = 4;
    moveble->setProperty("coordinates", coord);

    auto velocity =  Eigen::RowVector2i(2); 
    velocity(0) = 3;
    velocity(1) = -7;
    moveble->setProperty("velocity", velocity);

    return moveble;
}

TEST(UObjectTest, SetProperty)
{
    auto testObject = new UObject();
    testObject->setProperty("PropertyOne", 1);
    auto res = std::any_cast<int>(testObject->getProperty("PropertyOne"));


    EXPECT_EQ(res, 1);
}