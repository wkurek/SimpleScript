#include "pch.h"
#include "../SimpleScript/primitive.h"
#include "../SimpleScript/primitive.cpp"

#include <string>

#define INTEGER_VALUE_A 12
#define INTEGER_VALUE_B 81
#define INTEGER_MINUS_VALUE -76

#define FLOAT_VALUE_A 4.56f
#define FLOAT_VALUE_B 95.78f
#define FLOAT_MINUS_VALUE -6.84f

#define BOOLEAN_VALUE_TRUE true
#define BOOLEAN_VALUE_FALSE false

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

TEST(Primitive, Should_Be_Added_Correctly_When_Integers) {

	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(INTEGER_VALUE_B);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isInteger());
	EXPECT_EQ(resultPrimitive.getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
}

TEST(Primitive, Should_Be_Added_Correctly_When_Integer_And_Float) {

	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(FLOAT_VALUE_A);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isFloat());
	EXPECT_EQ(resultPrimitive.getFloat(), INTEGER_VALUE_A + FLOAT_VALUE_A);
}
TEST(Primitive, Should_Be_Added_Correctly_When_Floats) {

	Primitive primitive1 = Primitive(FLOAT_VALUE_A);
	Primitive primitive2 = Primitive(FLOAT_VALUE_B);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isFloat());
	EXPECT_FLOAT_EQ(resultPrimitive.getFloat(), FLOAT_VALUE_A + FLOAT_VALUE_B);
}

TEST(Primitive, Should_Be_Concatenated_Correctly_When_Strings) {

	std::string str1 = "Winter";
	std::string str2 = "fell";

	Primitive primitive1 = Primitive(str1);
	Primitive primitive2 = Primitive(str2);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isString());
	EXPECT_EQ(resultPrimitive.getString(), str1 + str2);
}

TEST(Primitive, Should_Cast_To_True_When_Integer_Greater_Than_0) {
	
	Primitive primitive = Primitive(INTEGER_VALUE_A);

	EXPECT_TRUE(primitive.operator bool());
}
TEST(Primitive, Should_Cast_To_False_When_Integer_Less_Than_0) {
	
	Primitive primitive = Primitive(INTEGER_MINUS_VALUE);

	EXPECT_FALSE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_True_When_Float_Greater_Than_0) {

	Primitive primitive = Primitive(FLOAT_VALUE_A);

	EXPECT_TRUE(primitive.operator bool());
}
TEST(Primitive, Should_Cast_To_False_When_Float_Less_Than_0) {

	Primitive primitive = Primitive(FLOAT_MINUS_VALUE);

	EXPECT_FALSE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_False_When_String) {

	std::string str = "example";
	Primitive primitive = Primitive(str);

	EXPECT_FALSE(primitive.operator bool());
}
TEST(Primitive, Should_Cast_To_Value_When_Bool) {

	Primitive primitive1 = Primitive(BOOLEAN_VALUE_TRUE);
	Primitive primitive2 = Primitive(BOOLEAN_VALUE_FALSE);

	EXPECT_TRUE(primitive1.operator bool());
	EXPECT_FALSE(primitive2.operator bool());
}
