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


class MovebleObjectTest : public  ::testing::Test
{
    protected:
        void SetUp() override
        {
            auto uobjectOne = std::make_shared<UObject>();
            auto uobjectTwo = std::make_shared<UObject>();
            auto uobjectThree = std::make_shared<UObject>();

            _setCoordintates(uobjectOne, 12, 5 );
            _setVelocity(uobjectOne, -7, 3);

            _setCoordintates(uobjectTwo, 12, 5);

            _setVelocity(uobjectThree, -7, 3);

            tankOne = std::make_shared<MovebleAdapter>(uobjectOne);
            tankTwo = std::make_shared<MovebleAdapter>(uobjectTwo);
            tankThree = std::make_shared<MovebleAdapter>(uobjectThree);
        }

        // tankOne - tank with coordinates and velocity
        MovebleAdapter::Ptr tankOne;
        // tankOne - tank with coordinates and without velocity
        MovebleAdapter::Ptr tankTwo;
        // tankOne - tank with velocity and without coordinates  
        MovebleAdapter::Ptr tankThree;
    
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


class RotableObjectTest : public ::testing::Test
{
    protected:
        void SetUp() override{
            auto uobjectFour = std::make_shared<UObject>();
            auto uobjectFive = std::make_shared<UObject>();
            auto uobjectSix  = std::make_shared<UObject>();

            uobjectFour->setProperty("direction", 1);
            uobjectFour->setProperty("angular_velocity", 4);

            uobjectFive->setProperty("direction", 1);
            
            uobjectSix->setProperty("angular_velocity", 4);

            tankFour = std::make_shared<RotableAdapter>(uobjectFour);
            tankFive = std::make_shared<RotableAdapter>(uobjectFive);
            tankSix  = std::make_shared<RotableAdapter>(uobjectSix);
        }

        // tankFour - tank with direction and angular velocity
        RotableAdapter::Ptr tankFour;
        // tankFive -tank with direction and without angular velocity
        RotableAdapter::Ptr tankFive;
        // tankSix - tank  with velocity and without coordinates 
        RotableAdapter::Ptr tankSix;

};



TEST_F(MovebleObjectTest, Move)
{
    auto testCoordinates = Eigen::RowVector2i(); 
    testCoordinates(0) = 5;
    testCoordinates(1) = 8;


    auto commandMoveOne = std::make_shared<MoveCommand>(tankOne);
    auto commandMoveTwo = std::make_shared<MoveCommand>(tankTwo);
    auto commandMoveThree = std::make_shared<MoveCommand>(tankThree);

    commandMoveOne->execute();
    commandMoveTwo->execute();
    commandMoveThree->execute();

    auto newCoordinatesOne = tankOne->getCoordinates();
    auto newCoordinatesTwo = tankTwo->getCoordinates();

   
    EXPECT_ANY_THROW(tankThree->getCoordinates());
   
    EXPECT_EQ(newCoordinatesOne, testCoordinates);
    EXPECT_NE(newCoordinatesTwo, testCoordinates);
}


TEST_F(RotableObjectTest, Rotate)
{
    auto testDirection = 5;

    auto commandRotateOne   = std::make_shared<RotateCommand>(tankFour);
    auto commandRotateTwo   = std::make_shared<RotateCommand>(tankFive);
    auto commandRotateThree = std::make_shared<RotateCommand>(tankSix); 

    commandRotateOne->execute();
    commandRotateTwo->execute();
    commandRotateThree->execute();

    auto newDirectionFour = tankFour->getDirection();
    auto newDirectionFive = tankFive->getDirection();

    EXPECT_ANY_THROW(tankSix->getDirection());
   
    EXPECT_EQ(newDirectionFour, testDirection);
    EXPECT_NE( newDirectionFive, testDirection);
}