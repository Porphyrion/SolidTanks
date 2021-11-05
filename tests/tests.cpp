#include <any>

#include "gtest/gtest.h"
#include "../src/UObject.h"
#include "../src/MovebleAdapter.h"
#include "../src/MoveCommand.h"

#include <Eigen/Dense>

class IMoveble;

std::shared_ptr<UObject> createMovable(int xCoord, int yCoord, int xV, int yV)
{
    auto moveble  = std::make_shared<UObject>();

    auto coord =  Eigen::RowVector2i(); 
    coord(0) = xCoord;
    coord(1) = yCoord;
    moveble->setProperty("coordinates", coord);

    auto velocity =  Eigen::RowVector2i(); 
    velocity(0) = xV;
    velocity(1) = yV;
    moveble->setProperty("velocity", velocity);

    return moveble;
}


std::shared_ptr<UObject> createMovable(int xV, int yV)
{
    auto moveble  = std::make_shared<UObject>();

    // auto coord =  Eigen::RowVector2i(); 
    // coord(0) = xCoord;
    // coord(1) = yCoord;
    // moveble->setProperty("coordinates", coord);

    auto velocity =  Eigen::RowVector2i(); 
    velocity(0) = xV;
    velocity(1) = yV;
    moveble->setProperty("velocity", velocity);

    return moveble;
}



std::shared_ptr<IMovable> createAdapter()
{
   return std::make_shared<MovebleAdapter>(createMovable(12, 5, -7, 3));
}


std::shared_ptr<IMovable> createBadAdapter()
{
   return std::make_shared<MovebleAdapter>(createMovable(-7, 3));
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


TEST(UObjectTest, BadProperty)
{
    auto testObject = createBadAdapter();
    auto command = new MoveCommand(testObject);

    command->execute();

    auto res = testObject->getCoordinates();

    auto test = Eigen::RowVector2i(); 
    test(0) = 5;
    test(1) = 8;
    
    EXPECT_EQ(res, test);

    delete command;
}