#pragma once 

#include <map>
#include <memory>
#include <any>
#include <string>

class UObject
{
public:
    using Ptr = std::shared_ptr<UObject>;

    UObject();
    ~UObject() = default;
    
    void setProperty(std::string propertyName, std::any propertyValue);
    std::any getProperty(std::string propertyName);

private:
    std::map<std::string, std::any> _properties;
};
 