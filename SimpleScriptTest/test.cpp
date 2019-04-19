#include "pch.h"
#include "../SimpleScript/primitive.h"
#include "../SimpleScript/primitive.cpp"

#include <iostream>

TEST(TestCaseName, TestName) {
	Primitive primitive1 = Primitive(5);
	Primitive primitive2 = Primitive(4);

	std::cout << primitive1 << std::endl;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}