#include "UObject.h"

#include <iostream>

UObject::UObject(){}


void UObject::setProperty(std::string propertyName, std::any propertyValue)
{
    _properties[propertyName] =  propertyValue;
};


std::any UObject::getProperty(std::string propertyName)
{
    try
    {
        auto property =  _properties.at(propertyName);
        return property; 
    }
    catch(const std::exception& e)
    {
        throw e;
    }

};

