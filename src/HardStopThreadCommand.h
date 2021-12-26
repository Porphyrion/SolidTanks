#include "ICommand.h"

#include <boost/lockfree/stack.hpp>

class HardStopThreadCommand : public ICommand
{
    public:
        HardStopThreadCommand();
        ~HardStopThreadCommand();

        virtual void execute() override;

        boost::lockfree::stack<int> stack;
};
