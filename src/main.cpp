#include <iostream>
#include <memory>

#include "UObject.h"
#include "MovebleAdapter.h"
#include "MoveCommand.h"




int main(int argc,  char const *argv[])
{
   
    // auto mAdapter = std::make_shared<MovebleAdapter>(createTank());
    // MoveCommand command(mAdapter);

    // command.execute();

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