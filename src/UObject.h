#pragma once 

#include <map>
#include <any>
#include <string>

class UObject
{
public:
    UObject();
    
    void setProperty(std::string propertyName, std::any propertyValue);
    std::any getProperty(std::string propertyName);

private:
    std::map<std::string, std::any> _properties;
};
 