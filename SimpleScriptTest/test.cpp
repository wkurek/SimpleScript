#include "pch.h"
#include "../SimpleScript/primitive.h"
#include "../SimpleScript/primitive.cpp"
#include "../SimpleScript/identifier.h"
#include "../SimpleScript/identifier.cpp"
#include "../SimpleScript/object.h"
#include "../SimpleScript/object.cpp"
#include "../SimpleScript/function.h"
#include "../SimpleScript/function.cpp"
#include "../SimpleScript/variable.h"
#include "../SimpleScript/variable.cpp"
#include "../SimpleScript/exception.h"
#include "../SimpleScript/exception.cpp"
#include "../SimpleScript/operation_expression.h"
#include "../SimpleScript/operation_expression.cpp"
#include "../SimpleScript/statement.h"
#include "../SimpleScript/statement.cpp"
#include "../SimpleScript/assignment.h"
#include "../SimpleScript/assignment.cpp"
#include "../SimpleScript/property.h"
#include "../SimpleScript/property.cpp"
#include "../SimpleScript/program.h"
#include "../SimpleScript/program.cpp"
#include "../SimpleScript/SimpleScript.tab.h"
#include "../SimpleScript/SimpleScript.tab.cpp"
#include "../SimpleScript/SimpleScript.flex.cpp"

#include <iostream>
#include <string>
#include <memory>
using namespace std;

extern int yyparse();
extern Variable _PARSE_RESULT;

#define INTEGER_VALUE_A 12
#define INTEGER_VALUE_B 81
#define INTEGER_MINUS_VALUE -76

#define FLOAT_VALUE_A 4.56f
#define FLOAT_VALUE_B 95.78f
#define FLOAT_MINUS_VALUE -6.84f

#define BOOLEAN_VALUE_TRUE true
#define BOOLEAN_VALUE_FALSE false

#define PARSE_RESULT_SUCCESS 0
#define PARSE_RESULT_FAILITURE 1

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


/* OBJECT TESTS */
TEST(Object, Should_Preserve_Last_Assignment) {

	Object scope;

	Identifier id = "id1";

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Function funct = Function();
	Object obj = Object();

	scope.getFunction(id) = funct;
	scope.getObject(id) = obj;
	scope.getPrimitive(id) = primitive;

	EXPECT_TRUE(scope.hasPrimitive(id));
	EXPECT_EQ(scope.getPrimitive(id).getInteger(), INTEGER_VALUE_A);
}

TEST(Object, Should_Not_Contain_Entity_After_Removal) {

	Object scope;

	Identifier id = "id1";
	Function funct = Function();

	scope.getFunction(id) = funct;

	EXPECT_FALSE(scope.hasPrimitive(id));
}

TEST(Object, Should_Be_Able_To_Nest_Objects) {

	Object scope;

	Identifier id1 = "function";
	Identifier id2 = "object";
	Identifier id3 = Identifier(id2, "primitive");
	Identifier id4 = Identifier(id2, "object2");
	Identifier id5 = Identifier(id4, "primitive2");
	Identifier id6 = Identifier(id4, "object3");
	Identifier id7 = Identifier(id6, "function2");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(BOOLEAN_VALUE_FALSE);
	Function funct = Function();
	Function funct2 = Function();
	Object obj = Object();
	Object obj2 = Object();
	Object obj3 = Object();

	scope.getFunction(id1) = funct;
	scope.getObject(id2) = obj;
	scope.getPrimitive(id3) = primitive;
	scope.getObject(id4) = obj2;
	scope.getPrimitive(id5) = primitive2;
	scope.getObject(id6) = obj3;
	scope.getFunction(id7) = funct2;

	EXPECT_TRUE(scope.hasFunction(id1));
	EXPECT_TRUE(scope.hasObject(id2));
	EXPECT_TRUE(scope.hasPrimitive(id3));
	EXPECT_TRUE(scope.hasObject(id4));
	EXPECT_TRUE(scope.hasPrimitive(id5));
	EXPECT_TRUE(scope.hasObject(id6));
	EXPECT_TRUE(scope.hasFunction(id7));

	EXPECT_EQ(scope.getPrimitive(id3).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(scope.getPrimitive(id5).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Object, Should_Throw_Exception_When_Identifier_Nested_Not_To_Object_Identifier_Assignment) {

	Object scope;

	Identifier id1 = "function";
	Identifier id2 = Identifier(id1, "primitive");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Function funct = Function();

	scope.getFunction(id1) = funct;

	EXPECT_ANY_THROW(scope.getPrimitive(id2) = primitive);
}

TEST(Object, Should_Remove_Function_Correctly) {

	Object scope;

	Identifier id1 = "function";
	Function funct = Function();

	scope.getFunction(id1) = funct;
	scope.removeFunction(id1);

	EXPECT_FALSE(scope.hasFunction(id1));
}
TEST(Object, Should_Remove_Nested_Primitive) {

	Object scope;

	Identifier id1 = "object1";
	Identifier id2 = Identifier(id1, "object2");
	Identifier id3 = Identifier(id2, "primitive");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Object obj1 = Object();
	Object obj2 = Object();

	scope.getObject(id1) = obj1;
	scope.getObject(id2) = obj2;
	scope.getPrimitive(id3) = primitive;

	scope.removePrimitive(id3);

	EXPECT_TRUE(scope.hasObject(id1));
	EXPECT_TRUE(scope.hasObject(id2));
	EXPECT_FALSE(scope.hasPrimitive(id3));
}

TEST(Object, Should_Not_Throw_Exception_When_Removing_Not_Existing_Entity) {

	Object scope;

	Identifier id1 = "function";
	Identifier id2 = "primitive";

	Function funct = Function();

	scope.getFunction(id1) = funct;

	EXPECT_NO_THROW(scope.removePrimitive(id2));
}

/* IDENTIFIER TESTS */

TEST(Identifier, Should_Be_Able_To_Nest) {

	std::string id1 = "id1";
	std::string id2 = "id2";

	Identifier identifier1 = Identifier(id1);
	Identifier identifier2 = Identifier(id1, id2);

	EXPECT_FALSE(identifier1.hasTail());
	EXPECT_TRUE(identifier2.hasTail());

	EXPECT_EQ(identifier1.getHead(), id1);
	EXPECT_EQ(identifier2.getHead(), id1);
}

TEST(Identifier, Should_Generate_Tail_Properly) {

	std::string id1 = "id1";
	std::string id2 = "id2";
	std::string id3 = "id3";

	Identifier identifier1 = Identifier(id1);
	Identifier identifier2 = Identifier(identifier1, id2);
	Identifier identifier3 = Identifier(identifier2, id3);

	Identifier tail = identifier3.getTail();

	EXPECT_FALSE(identifier1.hasTail());
	EXPECT_TRUE(identifier2.hasTail());
	EXPECT_TRUE(identifier3.hasTail());

	EXPECT_EQ(identifier3.getHead(), id1);
	EXPECT_EQ(tail.getHead(), id2);
	EXPECT_EQ(tail.getTail().getHead(), id3);
}

/* OPERATION EXPRESSION */

TEST(OperationExpression, Should_Assign_Constant_To_Variable_Properly) {
	/*
		a = 12
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression = 
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable result = aExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);
}


TEST(OperationExpression, Should_Assign_Addition_Constant_To_Variable_Properly) {
	/*
		a = 12
		b = a + 8
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression = 
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	std::shared_ptr<Identifier> bIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("b"));
	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable sumVariable = Variable(bPrimitive);
	ConstantExpression sumConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(sumVariable)));

	IdentifierExpression aIdExpression = IdentifierExpression(aIdentifier);


	OperationExpressionAssignment bExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(bIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new ConstantExpression(sumConstantExpression)), 
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)))));

	Variable result = bExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*bIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*bIdentifier).isInteger());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(*bIdentifier).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
}

TEST(OperationExpression, Should_Assign_Subtraction_From_Self) {
	/*
		a = 12 * 13
		a = a - 12
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Variable variable1 = Variable(primitive1);
	ConstantExpression constantExpression1 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable1)));

	Primitive primitive2 = Primitive(INTEGER_VALUE_B);
	Variable variable2 = Variable(primitive2);
	ConstantExpression constantExpression2 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable2)));


	OperationExpressionAssignment expressionAssignment1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Multiplication(
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression1)),
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression2)))));

	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);


	OperationExpressionAssignment expressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Subtraction(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression1)))));

	Variable result = expressionAssignment2.evaluate(globalScope);



	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());


	EXPECT_EQ(firstAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), 
		(INTEGER_VALUE_A * INTEGER_VALUE_B) - INTEGER_VALUE_A);

}

TEST(OperationExpression, Should_Assign_Constants_Multiplication) {
	/*
		a = 12 * 13
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Variable variable1 = Variable(primitive1);
	ConstantExpression constantExpression1 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable1)));

	Primitive primitive2 = Primitive(INTEGER_VALUE_B);
	Variable variable2 = Variable(primitive2);
	ConstantExpression constantExpression2 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable2)));


	OperationExpressionAssignment expressionAssignment1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Multiplication(
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression1)),
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression2)))));

	Variable result = expressionAssignment1.evaluate(globalScope);

	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());


	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);

}

TEST(OperationExpression, Should_Assign_Variables_Subtraction_Properly) {
	/*
		a = 12
		b = a + 8
		c = b - a
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);
	 
	std::shared_ptr<Identifier> bIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("b"));

	Primitive sumPrimitive = Primitive(INTEGER_VALUE_B);
	Variable sumVariable = Variable(sumPrimitive);
	ConstantExpression sumConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(sumVariable)));

	IdentifierExpression aIdExpression = IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier));


	OperationExpressionAssignment bExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(bIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new ConstantExpression(sumConstantExpression)),
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)))));

	Variable bAssignmentResult = bExpressionAssignment.evaluate(globalScope);

	std::shared_ptr<Identifier> cIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("c"));

	OperationExpressionAssignment cExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(cIdentifier),
			std::shared_ptr<OperationExpression>(new Multiplication(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)),
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(bIdentifier))))));

	Variable result = cExpressionAssignment.evaluate(globalScope);



	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_TRUE(bAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*bIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*bIdentifier).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*cIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*cIdentifier).isInteger());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(bAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
	
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*bIdentifier).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A * (INTEGER_VALUE_A + INTEGER_VALUE_B));
	EXPECT_EQ(globalScope.getPrimitive(*cIdentifier).getInteger(), INTEGER_VALUE_A * (INTEGER_VALUE_A + INTEGER_VALUE_B));
}

TEST(OperationExpression, Should_Increment_Variable_Properly) {
	/*
		a = 12
		++a
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment expressionAssignment1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable assignmentResult = expressionAssignment1.evaluate(globalScope);

	Primitive onePrimitive = Primitive(1);
	Variable one = Variable(onePrimitive);
	ConstantExpression oneConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

	OperationExpressionAssignment expressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)))));

	Variable result = expressionAssignment2.evaluate(globalScope);

	EXPECT_TRUE(assignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_EQ(assignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A + 1);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A + 1);
}

TEST(OperationExpression, Should_Negate_Variable_Properly) {
	/*
		a = 12 * 13
		a = -a
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Variable variable1 = Variable(primitive1);
	ConstantExpression constantExpression1 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable1)));

	Primitive primitive2 = Primitive(INTEGER_VALUE_B);
	Variable variable2 = Variable(primitive2);
	ConstantExpression constantExpression2 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable2)));


	OperationExpressionAssignment expressionAssignment1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Multiplication(
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression1)),
				std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression2)))));

	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);


	OperationExpressionAssignment expressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Negation(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))))));

	Variable result = expressionAssignment2.evaluate(globalScope);


	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());


	EXPECT_EQ(firstAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(),
		-(INTEGER_VALUE_A * INTEGER_VALUE_B));
}

TEST(OperationExpression, Should_Logically_Negate_Boolean_Variable_Properly) {
	/*
		a = true
		a = !a
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Variable variable1 = Variable(BOOLEAN_VALUE_TRUE);
	ConstantExpression constantExpression1 =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(variable1)));


	OperationExpressionAssignment expressionAssignment1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(constantExpression1)));

	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);


	OperationExpressionAssignment expressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new LogicalNot(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))))));

	Variable result = expressionAssignment2.evaluate(globalScope);


	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isBoolean());


	EXPECT_EQ(firstAssignmentResult.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(OperationExpression, Should_Compare_Variables_Properly) {
	/*
		a = 12
		b = a + 8
		c = a >= b
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	std::shared_ptr<Identifier> bIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("b"));

	Primitive sumPrimitive = Primitive(INTEGER_VALUE_B);
	Variable sumVariable = Variable(sumPrimitive);
	ConstantExpression sumConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(sumVariable)));

	IdentifierExpression aIdExpression = IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier));


	OperationExpressionAssignment bExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(bIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new ConstantExpression(sumConstantExpression)),
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)))));

	Variable bAssignmentResult = bExpressionAssignment.evaluate(globalScope);

	Identifier* cIdentifier = new Identifier("c");

	OperationExpressionAssignment cExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(cIdentifier),
			std::shared_ptr<OperationExpression>(new GreaterThanOrEqualTo(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)),
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(bIdentifier))))));

	Variable result = cExpressionAssignment.evaluate(globalScope);



	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_TRUE(bAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*bIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*bIdentifier).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*cIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*cIdentifier).isBoolean());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(bAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*bIdentifier).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(result.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
	EXPECT_EQ(globalScope.getPrimitive(*cIdentifier).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(OperationExpression, Should_Compare_Variable_And_Constant_Properly) {
	/*
		a = 12
		b = a == 12
	*/

	Object globalScope = Object();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(std::shared_ptr<Identifier>(aIdentifier)),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));


	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	std::shared_ptr<Identifier> bIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("b"));
	IdentifierExpression aIdExpression = IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier));

	OperationExpressionAssignment bExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(bIdentifier),
			std::shared_ptr<OperationExpression>(new Equals(
				std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)),
				std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdExpression)))));

	Variable result = bExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());


	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*bIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*bIdentifier).isBoolean());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);

	EXPECT_EQ(result.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
	EXPECT_EQ(globalScope.getPrimitive(*bIdentifier).getBoolean(), BOOLEAN_VALUE_TRUE);
}

/* STATEMENTS */

TEST(ConditionalStatement, Should_Execute_Positive_Block_When_True_Condition) {
	/*
		if (true) { a = 12 }
	*/

	Object globalScope = Object();

	StatementsList* trueStatementsList = new StatementsList();

		std::shared_ptr<Identifier> aIdentifier = 
			std::shared_ptr<Identifier>(new Identifier("a"));

		Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
		Variable aVariable = Variable(aPrimitive);
		ConstantExpression aConstantExpression =
			ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

		OperationExpressionAssignment aExpressionAssignment =
			OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
				std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

		ExpressionStatement expressionStatement = ExpressionStatement(
			std::shared_ptr<OperationExpression>(
				new OperationExpressionAssignment(aExpressionAssignment))
		);

	trueStatementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));

	ConstantExpression condition = ConstantExpression(
		std::shared_ptr<Variable>(new Variable(true))
	);

	ConditionalStatement conditionalStatement = ConditionalStatement(
		std::shared_ptr<OperationExpression>(
			new ConstantExpression(condition)),
		std::shared_ptr<StatementsList>(trueStatementsList)
	);

	conditionalStatement.evaluate(globalScope);

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);
}

TEST(ConditionalStatement, Should_Not_Execute_Positive_Block_When_Condition_Evaluates_To_False) {
	/*
		a = 12
		if ( a > 13 ) { a = a + 13 }
	*/

	Object globalScope = Object();

	StatementsList* trueStatementsList = new StatementsList();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable bVariable = Variable(bPrimitive);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	GreaterThan condition = GreaterThan(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	Variable conditionResult = condition.evaluate(globalScope);

	OperationExpressionAssignment aExpressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
			)));



	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(aExpressionAssignment2))
	);

	trueStatementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));


	ConditionalStatement conditionalStatement = ConditionalStatement(
		std::shared_ptr<OperationExpression>(
			new GreaterThan(condition)),
		std::shared_ptr<StatementsList>(trueStatementsList)
	);

	conditionalStatement.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());
	EXPECT_TRUE(conditionResult.getPrimitive().isBoolean());

	EXPECT_EQ(conditionResult.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A);
}


TEST(ConditionalStatement, Should_Execute_Positive_Block_When_Condition_Evaluates_To_True) {
	/*
		a = 12
		if ( a <= 13 ) { a = a + 13 }
		else {  }
	*/

	Object globalScope = Object();

	StatementsList* trueStatementsList = new StatementsList();
	StatementsList* falseStatementsList = new StatementsList();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable bVariable = Variable(bPrimitive);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	LessThanOrEqualTo condition = LessThanOrEqualTo(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	Variable conditionResult = condition.evaluate(globalScope);

	OperationExpressionAssignment aExpressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
			)));



	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(aExpressionAssignment2))
	);

	trueStatementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));


	ConditionalStatement conditionalStatement = ConditionalStatement(
		std::shared_ptr<OperationExpression>(
			new LessThanOrEqualTo(condition)),
		std::shared_ptr<StatementsList>(trueStatementsList)
	);

	conditionalStatement.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());
	EXPECT_TRUE(conditionResult.getPrimitive().isBoolean());

	EXPECT_EQ(conditionResult.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
}

TEST(ConditionalStatement, Should_Execute_False_Block_When_Condition_Evaluates_To_False) {
	/*
		a = 12
		if ( a > 13 ) {}
		else { a = a * 13 }
	*/

	Object globalScope = Object();

	StatementsList* trueStatementsList = new StatementsList();
	StatementsList* falseStatementsList = new StatementsList();

	std::shared_ptr<Identifier> aIdentifier = std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable bVariable = Variable(bPrimitive);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	GreaterThan condition = GreaterThan(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	Variable conditionResult = condition.evaluate(globalScope);

	OperationExpressionAssignment aExpressionAssignment2 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Multiplication(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
			)));



	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(aExpressionAssignment2))
	);

	falseStatementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));


	ConditionalStatement conditionalStatement = ConditionalStatement(
		std::shared_ptr<OperationExpression>(
			new GreaterThan(condition)),
		std::shared_ptr<StatementsList>(trueStatementsList),
		std::shared_ptr<StatementsList>(falseStatementsList)
	);

	conditionalStatement.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());
	EXPECT_TRUE(conditionResult.getPrimitive().isBoolean());

	EXPECT_EQ(conditionResult.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
}


TEST(ReturnStatement, Should_Throw_ReturnVariable_Exception) {

	Object globalScope = Object();

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	ReturnStatement returnStatement = ReturnStatement(
		std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression))
	);

	EXPECT_THROW({ try {
		returnStatement.evaluate(globalScope);
	}
	catch (const ReturnVariable &returnVar) {
		throw;
		} }, ReturnVariable);
}
TEST(ReturnStatement, Should_Throw_Filled_ReturnVariable_Exception) {

	Object globalScope = Object();

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	ReturnStatement returnStatement = ReturnStatement(
		std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression))
	);

	EXPECT_THROW({ try {
		returnStatement.evaluate(globalScope);
	}
	catch (const ReturnVariable &returnVar) {

		Variable result = returnVar.getVariable();

		EXPECT_TRUE(result.isPrimitive());
		EXPECT_TRUE(result.getPrimitive().isInteger());
		EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A);

		throw;
		} }, ReturnVariable);
}

TEST(IterationStatement, Should_Iterate_While_Condition_Is_True) {

	Object globalScope = Object();

	StatementsList* statementsList = new StatementsList();

	std::shared_ptr<Identifier> aIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable bVariable = Variable(bPrimitive);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	LessThan condition = LessThan(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	Primitive onePrimitive = Primitive(1);
	Variable one = Variable(onePrimitive);
	ConstantExpression oneConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

	OperationExpressionAssignment loopExpression =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)))));

	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(loopExpression))
	);

	statementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));


	IterationStatement iterationStatement = IterationStatement(
		std::shared_ptr<OperationExpression>(new LessThan(condition)),
		std::shared_ptr<StatementsList>(statementsList)
	);

	iterationStatement.evaluate(globalScope);

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_B);
}

TEST(IterationStatement, Should_Iterate_Certain_number_Of_Times) {
	/*
		a = 12
		while( a < 13) {
			++a
			--b
		}
	*/

	Object globalScope = Object();

	StatementsList* statementsList = new StatementsList();

	std::shared_ptr<Identifier> aIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	Primitive bPrimitive = Primitive(INTEGER_VALUE_B);
	Variable bVariable = Variable(bPrimitive);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	LessThan condition = LessThan(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	Primitive onePrimitive = Primitive(1);
	Variable one = Variable(onePrimitive);
	ConstantExpression oneConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

	OperationExpressionAssignment loopExpression =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new Addition(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)))));

	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(loopExpression))
	);

	std::shared_ptr<Identifier> bIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("b"));

	OperationExpressionAssignment loopExpression1 =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(bIdentifier),
			std::shared_ptr<OperationExpression>(new Subtraction(
				std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>(bIdentifier))),
				std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)))));

	ExpressionStatement expressionStatement1 = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(loopExpression1))
	);

	statementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement)));
	
	statementsList->add(
		std::shared_ptr<Statement>(new ExpressionStatement(expressionStatement1)));


	IterationStatement iterationStatement = IterationStatement(
		std::shared_ptr<OperationExpression>(new LessThan(condition)),
		std::shared_ptr<StatementsList>(statementsList)
	);

	iterationStatement.evaluate(globalScope);

	EXPECT_TRUE(globalScope.hasPrimitive(*aIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*aIdentifier).isInteger());

	EXPECT_TRUE(globalScope.hasPrimitive(*bIdentifier));
	EXPECT_TRUE(globalScope.getPrimitive(*bIdentifier).isInteger());

	EXPECT_EQ(globalScope.getPrimitive(*aIdentifier).getInteger(), INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(*bIdentifier).getInteger(), -(INTEGER_VALUE_B - INTEGER_VALUE_A));
}

/* FUNCTION */
TEST(Function, Should_Be_SuccessFully_Constructed_With_No_Parameters) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Identifier* functionIdentifier = new Identifier("doSomething");

	FunctionAssignment functionAssignemnt = FunctionAssignment(
		std::shared_ptr<Identifier>(functionIdentifier), function);

	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new FunctionAssignment(functionAssignemnt))
	);

	expressionStatement.evaluate(globalScope);

	EXPECT_TRUE(globalScope.hasFunction(*functionIdentifier));
}

TEST(Function, Should_Be_Called_Successfully_When_Passed_Proper_Number_Of_Arguments) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	ArgumentsList argumentsList = ArgumentsList();

	std::string a = "a";
	std::string b = "b";

	parametersList.add(a);
	parametersList.add(b);

	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	Variable bVariable = Variable(FLOAT_MINUS_VALUE);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	argumentsList.add(
		std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression))
	);	
	argumentsList.add(
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	
	EXPECT_NO_THROW({
			Variable functionResult = function.call(globalScope, argumentsList);
		});
}
TEST(Function, Should_Be_Called_Successfully_When_Passed_Greater_Number_Of_Arguments) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	ArgumentsList argumentsList = ArgumentsList();

	std::string a = "a";

	parametersList.add(a);

	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	Variable bVariable = Variable(FLOAT_MINUS_VALUE);
	ConstantExpression bConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(bVariable)));

	argumentsList.add(
		std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression))
	);	
	argumentsList.add(
		std::shared_ptr<OperationExpression>(new ConstantExpression(bConstantExpression))
	);

	
	EXPECT_NO_THROW({
			Variable functionResult = function.call(globalScope, argumentsList);
		});
}

TEST(Function, Should_Throw_Exception_When_Passed_Not_Enough_Arguments) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	ArgumentsList argumentsList = ArgumentsList();

	std::string a = "a";
	std::string b = "b";

	parametersList.add(a);
	parametersList.add(b);

	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	argumentsList.add(
		std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression))
	);

	EXPECT_ANY_THROW({
			Variable functionResult = function.call(globalScope, argumentsList);
		});
}

TEST(Function, Should_Create_Isolated_Scope) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	std::shared_ptr<Identifier> aIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	ExpressionStatement expressionAssignmentStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(aExpressionAssignment))
	);

	statementsList.add(
		std::shared_ptr<Statement>(
			new ExpressionStatement(expressionAssignmentStatement))
	);

	ArgumentsList argumentsList = ArgumentsList();


	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Identifier* functIdentifier = new Identifier("funct");

	globalScope.getFunction(*functIdentifier) = function;

	FunctionCallExpression functionCallExpression = FunctionCallExpression(
		std::shared_ptr<Identifier>(functIdentifier),
		std::shared_ptr<ArgumentsList>(new ArgumentsList(argumentsList))
	);

	ExpressionStatement expressionStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new FunctionCallExpression(functionCallExpression))
	);

	expressionStatement.evaluate(globalScope);

	EXPECT_FALSE(globalScope.hasPrimitive(*aIdentifier));
}

TEST(Function, Should_Return_Variables_Properly) {

	Object globalScope = Object();

	StatementsList statementsList = StatementsList();
	ParametersList parametersList = ParametersList();

	std::shared_ptr<Identifier> aIdentifier = 
		std::shared_ptr<Identifier>(new Identifier("a"));

	Primitive aPrimitive = Primitive(INTEGER_VALUE_A);
	Variable aVariable = Variable(aPrimitive);
	ConstantExpression aConstantExpression =
		ConstantExpression(std::shared_ptr<Variable>(new Variable(aVariable)));

	OperationExpressionAssignment aExpressionAssignment =
		OperationExpressionAssignment(std::shared_ptr<Identifier>(aIdentifier),
			std::shared_ptr<OperationExpression>(new ConstantExpression(aConstantExpression)));

	ExpressionStatement expressionAssignmentStatement = ExpressionStatement(
		std::shared_ptr<OperationExpression>(
			new OperationExpressionAssignment(aExpressionAssignment))
	);

	statementsList.add(
		std::shared_ptr<Statement>(
			new ExpressionStatement(expressionAssignmentStatement))
	);

	IdentifierExpression aIdentifierExpression = IdentifierExpression(std::shared_ptr<Identifier>(aIdentifier));

	ReturnStatement returnStatement = ReturnStatement(
		std::shared_ptr<OperationExpression>(new IdentifierExpression(aIdentifierExpression))
	);

	statementsList.add(
		std::shared_ptr<Statement>(
			new ReturnStatement(returnStatement))
	);

	ArgumentsList argumentsList = ArgumentsList();


	Function function = Function(
		std::shared_ptr<ParametersList>(new ParametersList(parametersList)),
		std::shared_ptr<StatementsList>(new StatementsList(statementsList)));

	Identifier* functIdentifier = new Identifier("funct");

	globalScope.getFunction(*functIdentifier) = function;


	FunctionCallExpression functionCallExpression = FunctionCallExpression(
		std::shared_ptr<Identifier>(functIdentifier),
		std::shared_ptr<ArgumentsList>(new ArgumentsList(argumentsList))
	);

	Variable result = functionCallExpression.evaluate(globalScope);

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(result.getPrimitive().isInteger());
	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, YYPARSE_BASIC_TEST) {
	ostringstream inputStream;
	inputStream << "var a = " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}
TEST(Parser, Should_Fail_When_Wrongly_Placed_Semicolon) {
	ostringstream inputStream;
	inputStream << "var a =; " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Two_Semicolons) {
	ostringstream inputStream;
	inputStream << "var a = " << INTEGER_VALUE_A << ";; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}
TEST(Parser, Should_Fail_When_Variable_Name_Starts_With_Number) {
	ostringstream inputStream;
	inputStream << "var 1a = " << INTEGER_VALUE_A << "; return 1a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Variable_Name_Starts_With_Symbol) {
	ostringstream inputStream;
	inputStream << "var @a = " << INTEGER_VALUE_A << "; return @a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Assign_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Assign_Boolean_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = true; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}
TEST(Parser, Should_Assign_Float_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = " << FLOAT_MINUS_VALUE << "; return a;";

	string input = inputStream.str();

	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_MINUS_VALUE);
}