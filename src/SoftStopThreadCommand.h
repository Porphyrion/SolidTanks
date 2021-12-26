#include "ICommand.h"

class SoftStopThreadCommand : public ICommand
{
    public:
        SoftStopThreadCommand();
        ~SoftStopThreadCommand();

        virtual void execute() override;
};
