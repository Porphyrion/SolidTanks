#include <any>

#include "gtest/gtest.h"

#include "../src/UObject.h"
#include "../src/MovebleAdapter.h"
#include "../src/RotableAdapter.h"
#include "../src/MoveCommand.h"
#include "../src/RotateCommand.h"

#include <Eigen/Dense>

class IMoveble;
class IRotable;


class CommandTests : public  ::testing::Test
{
    protected:
        void SetUp() override
        {
            tankOne = std::make_shared<UObject>();
            tankTwo = std::make_shared<UObject>();
            tankThree = std::make_shared<UObject>();

            _setCoordintates(tankOne, 12, 5 );
            _setVelocity(tankOne, -7, 3);
            tankOne->setProperty("direction", 1);
            tankOne->setProperty("angular_velocity", 4); 

            _setCoordintates(tankTwo, 12, 5);
            tankTwo->setProperty("direction", 1);

            _setVelocity(tankThree, -7, 3);
            tankThree->setProperty("angular_velocity", 4);
        }

        // tankOne - tank always has coordinates(or direction) and velocity
        UObject::Ptr tankOne;
        // tankOne - tank always has coordinates(or direction), but doesn`t have some velocity property
        UObject::Ptr tankTwo;
        // tankOne - tank always has some velocity. , but doesn`t have  coordinates(or direction)  
        UObject::Ptr tankThree;
    
    private:
        void _setVelocity(UObject::Ptr obj, int xV, int yV){
            auto velocity =  Eigen::RowVector2i(); 
            velocity(0) = xV;
            velocity(1) = yV;
            obj->setProperty("velocity", velocity);
        }

        void _setCoordintates(UObject::Ptr obj, int xCoord, int yCoord){
            auto coord =  Eigen::RowVector2i(); 
            coord(0) = xCoord;
            coord(1) = yCoord;
            obj->setProperty("coordinates", coord);
        }
};



TEST_F(CommandTests, Move)
{
    auto testCoordinates = Eigen::RowVector2i(); 
    testCoordinates(0) = 5;
    testCoordinates(1) = 8;

    auto movebleTankOne = std::make_shared<MovebleAdapter>(tankOne);
    auto movebleTankTwo = std::make_shared<MovebleAdapter>(tankTwo);
    auto movebleTankThree = std::make_shared<MovebleAdapter>(tankThree);

    auto commandMoveOne = std::make_shared<MoveCommand>(movebleTankOne);
    auto commandMoveTwo = std::make_shared<MoveCommand>(movebleTankTwo);
    auto commandMoveThree = std::make_shared<MoveCommand>(movebleTankThree);


    commandMoveOne->execute();
    commandMoveTwo->execute();
    commandMoveThree->execute();

    auto newCoordinatesOne = movebleTankOne->getCoordinates();
    auto newCoordinatesTwo = movebleTankTwo->getCoordinates();
  
    EXPECT_ANY_THROW(movebleTankThree->getCoordinates());
   
    EXPECT_EQ(newCoordinatesOne, testCoordinates);
    EXPECT_NE(newCoordinatesTwo, testCoordinates);
}


TEST_F(CommandTests, Rotate)
{
    auto testDirection = 5;

    auto rotableTankOne = std::make_shared<RotableAdapter>(tankOne);
    auto rotableTankTwo = std::make_shared<RotableAdapter>(tankTwo);
    auto rotableTankThree = std::make_shared<RotableAdapter>(tankThree);

    auto commandRotateOne   = std::make_shared<RotateCommand>(rotableTankOne);
    auto commandRotateTwo   = std::make_shared<RotateCommand>(rotableTankTwo);
    auto commandRotateThree = std::make_shared<RotateCommand>(rotableTankThree); 

    commandRotateOne->execute();
    commandRotateTwo->execute();
    commandRotateThree->execute();

    auto newDirectionFour = rotableTankOne->getDirection();
    auto newDirectionFive = rotableTankTwo->getDirection();

    EXPECT_ANY_THROW(rotableTankThree->getDirection());
   
    EXPECT_EQ(newDirectionFour, testDirection);
    EXPECT_NE(newDirectionFive, testDirection);
}