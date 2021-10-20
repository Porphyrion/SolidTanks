#include <map>
#include <any>
#include <string>

class UObject
{
public:
    UObject();

private:
    std::map<std::string, std::any> _properties;
}