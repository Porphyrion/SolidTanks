#pragma once 

#include <map>
#include <any>
#include <string>

class UObject
{
public:
    UObject();
    
    void setProperties();
    std::any getProperties();

private:
    std::map<std::string, std::any> _properties;
};
