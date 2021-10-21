#include <iostream>
#include "UObject.h"


int main(int argc,  char const *argv[])
{
    auto testObject = new UObject();
    std::any test = std::string {"testest"}; 
    testObject->setProperty("test", test);

    try{
        auto res = std::any_cast<std::string>(testObject->getProperty("test"));

        std::cout << res;
    }
    catch(const std::bad_any_cast& e)
    {
        std::cout<<e.what();
    }
    

    return 0;
}