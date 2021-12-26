#include <iostream>
#include <memory>

#include "UObject.h"
#include "MovebleAdapter.h"
#include "MoveCommand.h"

#include <boost/lockfree/stack.hpp>

boost::lockfree::stack<long> stack(128);


int main(int argc,  char const *argv[])
{
    
    return 0;
}