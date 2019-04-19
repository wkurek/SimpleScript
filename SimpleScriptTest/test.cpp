#include "pch.h"
#include "../SimpleScript/primitive.h"
#include "../SimpleScript/primitive.cpp"

#include <string>

#define INTEGER_VALUE_A 12

#define FLOAT_VALUE_A 4.56f

#define BOOLEAN_VALUE_TRUE true

TEST(Primitive, Should_Contstruct_When_Passed_Int) {

	Primitive primitive = Primitive(INTEGER_VALUE_A);

	EXPECT_TRUE(primitive.isInteger());
	EXPECT_EQ(primitive.getInteger(), INTEGER_VALUE_A);
}
TEST(Primitive, Should_Contstruct_When_Passed_Float) {

	Primitive primitive = Primitive(FLOAT_VALUE_A);

	EXPECT_TRUE(primitive.isFloat());
	EXPECT_FLOAT_EQ(primitive.getFloat(), FLOAT_VALUE_A);
}

TEST(Primitive, Should_Contstruct_When_Passed_Bool) {

	Primitive primitive = Primitive(BOOLEAN_VALUE_TRUE);

	EXPECT_TRUE(primitive.isBoolean());
	EXPECT_EQ(primitive.getBoolean(), BOOLEAN_VALUE_TRUE);
}
TEST(Primitive, Should_Contstruct_When_Passed_String) {

	std::string str = "example";
	Primitive primitive = Primitive(str);

	EXPECT_TRUE(primitive.isString());
	EXPECT_EQ(primitive.getString(), str);
}