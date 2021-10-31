#include "UObject.h"


UObject::UObject(){}


void UObject::setProperty(std::string propertyName, std::any propertyValue)
{
    _properties[propertyName] =  propertyValue;
};


std::any UObject::getProperty(std::string propertyName)
{
    return _properties.at(propertyName);
};



