#pragma once 

#include <boost/lockfree/queue.hpp>

class CommandProcessor
{
public:
    CommandProcessor();
    ~CommandProcessor();
private:
    boost::lockfree::queue<int> q{100};
};
