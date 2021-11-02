#include <any>

#include "gtest/gtest.h"
#include "../src/UObject.h"
#include "../src/MovebleAdapter.h"
#include "../src/MoveCommand.h"

#include <Eigen/Dense>

class IMoveble;

std::shared_ptr<UObject> createMovable()
{
    auto moveble  = std::make_shared<UObject>();

    auto coord =  Eigen::RowVector2i(); 
    coord(0) = 12;
    coord(1) = 5;
    moveble->setProperty("coordinates", coord);

    auto velocity =  Eigen::RowVector2i(); 
    velocity(0) = -7;
    velocity(1) = 3;
    moveble->setProperty("velocity", velocity);

    return moveble;
}


std::shared_ptr<IMovable> createAdapter()
{
   return std::make_shared<MovebleAdapter>(createMovable());
}


TEST(UObjectTest, SetProperty)
{
    auto testObject = createAdapter();
    auto command = new MoveCommand(testObject);

    command->execute();

    auto res = testObject->getCoordinates();

    auto test = Eigen::RowVector2i(); 
    test(0) = 5;
    test(1) = 8;


    EXPECT_EQ(res, test);

    delete command;
}