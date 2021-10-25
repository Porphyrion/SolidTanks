#include <any>

#include "gtest/gtest.h"
#include "../UObject.h"


TEST(UObjectTest, SetProperty)
{
    auto testObject = new UObject();
    testObject->setProperty("PropertyOne", 1);
    auto res = std::any_cast<int>(testObject->getProperty("PropertyOne"));


    EXPECT_EQ(res, 1);
}