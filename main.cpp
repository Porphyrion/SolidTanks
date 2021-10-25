#include <iostream>
#include <memory>

#include "UObject.h"
#include "MovebleAdapter.h"
#include "MoveCommand.h"

#include <Eigen/Dense>


std::shared_ptr<UObject> createTank()
{
    auto moveble  = std::make_shared<UObject>();
    auto coord =  Eigen::VectorXf(2); 
    coord(0,0) = 1.0;
    coord(1,0) = -1.0;
    moveble->setProperty("coordinates", coord);

    auto velocity =  Eigen::VectorXf(2); 
    velocity(0,0) = -1.0;
    velocity(1,0) = 1.0;
    moveble->setProperty("velocity", coord);

    return moveble;
}


int main(int argc,  char const *argv[])
{
   
    auto mAdapter = std::make_shared<MovebleAdapter>(createTank());
    MoveCommand command(mAdapter);

    command.execute();

    try{
        // auto res = std::any_cast<std::string>(testObject->getProperty("test"));

        // std::cout << res;
    }
    catch(const std::bad_any_cast& e)
    {
        std::cout<<e.what();
    }
    

    return 0;
}