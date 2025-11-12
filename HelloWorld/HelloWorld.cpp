#include <iostream> // for cin, cout...

bool isPrime(int x)
{
	if (x == 2)
		return true;
	else if (x == 3)
		return true;
	else if (x == 5)
		return true;
	else if (x == 7)
		return true;

	return false;
}

int getValueFromUser()
{
	std::cout << "Enter an int: ";
	int input{};
	std::cin >> input;
	return input;
}

void printValue(int x)
{
	std::cout << x << '\n';
}

int add(int x, int y)
{
	return x + y;
}

// 2.7 - forward declaration
int multiply(int, int);

int main()
{
	// chapter 1.5 - iostream
	/*
	int x{ 5 };
	std::cout << "x is equal to: " << x << '\n';
	std::cout << "printing /n instead of \\n gives: " << '/n' << '\n';

	int y{};
	std::cout << "enter an int: ";
	std::cin >> y;
	std::cout << "you entered: " << y << '\n';

	std::cout << "enter two ints separated by a space: " << '\n';
	std::cin >> x >> y;
	std::cout << "you entered " << x << " and " << y << '\n';
	std::cout << std::endl;

	// chapter 1.6 - uninitialized vars and undefined behavior
	std::cout << "trying to print an uninitialized variable gives build error C4700: uninitialized local variable 'z' used" << '\n';
	int z;
	std::cout << "we can trick compiler to ignore unused variable warning with sizeof(z): " << sizeof(z);
	std::cout << std::endl;

	// chapter 1.8 - whitespace and formatting
	std::cout << "when whitespace is required, amount doesn't matter.\n";
	std::cout << "int x; is the same as int         x; \n";
	std::cout << "whitespace            in quotes is taken literally.\n";
	std::cout << "quoted text separated by whitespace"  " is concatenated\n";
	std::cout << std::endl;

	// chapter 1.9 - literals and operators
	std::cout << "can chain operations like x = y = 5.\n";
	int x, y;
	x = y = 5;
	std::cout << "x = " << x << " and y = " << y << '\n';
	std::cout << "std::cout << \"Hello \" prints to console then returns std::cout so << \"world\"; is also printed to console\n";
	std::cout << "Hello " << "world\n";
	std::cout << std::endl;

	// chapter 1.10 - expressions
	std::cout << "x = 5 is an expression.  x=5; is an expression statement\n";
	std::cout << "2*3; is a useless expression.  It compiles but has no effect.\n";
	std::cout << std::endl;
	*/

	// chapter 1.11 - develop first program
	std::cout << "enter an int: ";
	int num{};
	std::cin >> num;
	std::cout << "Double " << num << " is " << num * 2 << '\n';
	std::cout << "Triple " << num << " is " << num * 3 << '\n';
	std::cout << std::endl;

	// chapter 2.1 - functions
	int num2{ getValueFromUser() };
	std::cout << num2 << " doubled is " << num2 * 2 << '\n';
	std::cout << std::endl;

	// 2.4 - function parameters & arguments
	std::cout << "calling printValue(6): ";
	printValue(6);
	printValue(getValueFromUser());
	std::cout << std::endl;

	// 2.5 - local scope
	int x{ 5 };
	int y{ 6 };
	std::cout << "add(x, y), local scope x = 5 and y = 6: " << add(x, y) << '\n';
	std::cout << std::endl;

	// 2.7 - forward declarations
	std::cout << "multiply is forward declared - multiply(9, 9) = " << multiply(9, 9);
	std::cout << std::endl;

	// 2.8 - programming with multiple code files
	std::cout << "divide() is forward declared here in main, defined in separate divide.cpp file\n";
	int divide(int, int);
	std::cout << "10 / 2 = " << divide(10, 2);
	std::cout << std::endl;

	/*
	int s { -1 };
	std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

	unsigned int u { 4294967295 }; // largest 32-bit unsigned int
	std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;

	std::cout << "You entered: \'" << c << "\', which has ASCII code " << static_cast<int>(c) << '\n';

	std::cout << "Enter a single character: ";
	std::cin >> c;
	int ascii{ c };
	std::cout << "You entered: \'" << c << "\', which has ASCII code " << ascii << ".\n";
	*/

	return 0;
}

int multiply(int x, int y)
{
	return x * y;
}