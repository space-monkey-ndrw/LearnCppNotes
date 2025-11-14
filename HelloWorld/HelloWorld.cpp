#include <iostream> // for cin, cout...
#include "add2.h"
#include "square.h"
#include <climits>
#include <cstdint>
#include <iomanip>

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
#if 0
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
	std::cout << "printValue(getValueFromUser()): ";
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
	std::cout << std::endl;

	// 2.8 - programming with multiple code files
	std::cout << "divide() is forward declared here in main, defined in separate divide.cpp file\n";
	int divide(int, int);
	std::cout << "10 / 2 = " << divide(10, 2);
	std::cout << std::endl;
	std::cout << std::endl;

	// 2.9 - naming collisions & namespaces

	// 2.10 - preprocessor
#define MY_NAME "Ndrw";
	std::cout << "#defined MY_NAME \"Ndrw\", printing My name is: << MY_NAME\n";
	std::cout << "My name is: " << MY_NAME;
	std::cout << std::endl;

#define PRINT_JOE
#ifdef PRINT_JOE
	std::cout << "#define PRINT_JOE, so this code executes\n";
#endif
#ifndef PRINT_BOB
	std::cout << "did not #define PRINT_BOB, so this code executes\n";
#endif

#if 1
	std::cout << "#if 1, so this code compiles & executes";
#endif

#if 0
	/* this code will not execute
	unless we
	change #if 0 to #if 1 */
	std::cout << "#if 0, so this code does not compile";
#endif
	// mostly, macro substitution doesn't happen when the macro identifier is used within another preprocessor command
	// counter example, most forms of #if and #elif DO macro substitution within the preprocessor command
#define FOO 9
#ifdef FOO
	std::cout << FOO << '\n';
#endif

#if FOO
	std::cout << "#if FOO, but #define FOO 9, so becomes #if 9, which will compile since 9 != 0?\n";
	std::cout << "#define's can be anywhere, like inside of functions, but best to have at top of code\n";
#endif

#define BAR 0
#if BAR
	std::cout << "#if BAR, but #define BAR 0 before this code, so becomes #if 0, so this shouldn't compile";
#endif
	// directives are resolved before compilation, from top to bottom, on a file-by-file basis
	void doStuff();
#define PRINT
	std::cout << "calling doStuff()\n";
	doStuff();
	std::cout << std::endl;
	
	// 2.11 - Header Files
	std::cout << "add2.h and add2.cpp files exist\n";
	std::cout << "add2(999, 998) is " << add2(999, 998) << '\n';
	std::cout << std::endl;

	// 2.12 - header guards
	std::cout << "square.h file exists with header guards\n";
	std::cout << "square(3) = " << square(3);
	std::cout << std::endl;

	// chapter 3 - debugging
	std::cout << "Debugging, steps, strategy, tactics\n";
	std::cout << "3.6 - integrated debugger: stepping (into, over, out)\n";
	std::cout << "3.7 - running & breakpoints.  run to cursor, continue, start.  Set next statement\n";
	std::cout << "3.8 - watching variables\n";
	std::cout << "3.9 - the call stack\n";
	std::cout << "3.10 - preventing problems.  Constraints with assert & static_assert\n";
	std::cout << "       (visual studio 19+ includes a linter for static code analysis.)\n";
	std::cout << std::endl;

	// chapter 4 - fundamental data types
	std::cout << std::endl << "Chapter 4:" << '\n' << "A byte is: " << CHAR_BIT << " bits\n";
	std::cout << "+==============================================================================+\n";
	std::cout << "+                            FUNDAMENTAL DATA TYPES                            +\n";
	std::cout << "+==============================================================================+\n";
	std::cout << "|     category     |      type      |     min.  size     |     usual  size     |\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Boolean          | bool           | 1 Byte             | 1 Byte              | sizeof(bool): " << sizeof(bool) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Character        | char           | 1 Byte (exactly)   | 1 Byte (exactly)    | sizeof(char): " << sizeof(char) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Character        | wchar_t        | 1 Byte             | 2 or 4 Bytes        | sizeof(wchar_t): " << sizeof(wchar_t) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Character        | char8_t        | 1 Byte             | 1 Byte              | char8_t unavailable, added in C++20\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Character        | char16_t       | 2 Bytes            | 2 Bytes             | sizeof(char16_t): " << sizeof(char16_t) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Character        | char32_t       | 4 Bytes            | 4 Bytes             | sizeof(char32_t): " << sizeof(char32_t) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Integral         | short          | 2 Bytes            | 2 Bytes             | sizeof(short): " << sizeof(short) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Integral         | int            | 2 Bytes            | 4 Bytes             | sizeof(int): " << sizeof(int) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Integral         | long           | 4 Bytes            | 4 or 8 Bytes        | sizeof(long): " << sizeof(long) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Integral         | long long      | 8 Bytes            | 8 Bytes             | sizeof(long long): " << sizeof(long long) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Floating point   | float          | 4 Bytes            | 4 Bytes             | sizeof(float): " << sizeof(float) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Floating point   | double         | 8 Bytes            | 8 Bytes             | sizeof(double): " << sizeof(double) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Floating point   | long double    | 8 Bytes            | 8 or 12 or 16 Bytes | sizeof(long double): " << sizeof(long double) << " Byte(s)\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "| Pointer          | std::nullptr_t | 4 Bytes            | 4 or 8 Bytes        | sizeof(std::nullptr_t): " << sizeof(std::nullptr_t) << " Byte(s)\n";
	std::cout << "+==============================================================================+\n";
	std::cout << std::endl;

	// 4.4 Signed Integers
	int x{ 2147483647 };
	std::cout << "x is at max value: " << x << '\n';
	x = x + 1;
	std::cout << "x = x + 1, x is now: " << x << '\n';
	std::cout << "\ninteger division: 8 / 5 = " << 8 / 5 << '\n';
	std::cout << '\n';

	// 4.5 - Unsigned integers
	unsigned int y{ 4294967295 };
	std::cout << "unsigned in y is at max value: " << y << '\n';
	y = y + 1;
	std::cout << "y = y + 1, y is now: " << y << "\n\n";
	int s{ -1 };
	unsigned int u{ 1 };
	std::cout << "int s = -1, unsigned int u = 1, so should have s < u, but: " << '\n';
	if (s < u)
		std::cout << "s{ -1 } is less than u{ 1 }" << '\n';
	else
		std::cout << "u{ 1 } is less than s{ -1 }" << '\n';
	std::cout << "because s{ -1 } is implicitly converted to an unsigned int and becomes 4,294,967,295" << '\n';
	std::cout << "avoid unsigned ints unless needed ie. random number generation, encryption, embedded systems, etc.\n\n";

	// 4.6 - fixed-width integers & size_t
	std::cout << "+================================================================================================+\n";
	std::cout << "+                                      FIXED WIDTH INTEGERS                                      +\n";
	std::cout << "+================================================================================================+\n";
	std::cout << "|     name              |     size     |     range                                               |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::int8_t           | 1 Byte       | -128 to 127                                             |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::uint8_t          | 1 Byte       | 0 to 255                                                |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::int16_t          | 2 Bytes      | -32,768 to 32,767                                       |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::uint16_t         | 2 Bytes      | 0 to 65,535                                             |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::int32_t          | 4 Bytes      | -2,147,483,648 to 2,147,483,647                         |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::uint32_t         | 4 Bytes      | 0 to 4,294,967,295                                      |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::int64_t          | 8 Bytes      | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";
	std::cout << "| std::uint64_t         | 8 Bytes      | 0 to 18,446,744,073,709,551,615                         |\n";
	std::cout << "+------------------------------------------------------------------------------------------------+\n";

	std::cout << "\nstd::int16_t x{ 32767 }\n";
	std::int16_t stdint16t{ 32767 };
	std::cout << "stdint16t is: " << stdint16t << '\n';
	stdint16t = stdint16t + 1;
	std::cout << "stdint16t = stdint16t + 1, stdint16t is now: " << stdint16t << '\n';

	std::cout << "\nmodern compilers treat std::int8_t and std::uint8_t (and corresponding fast / least fixed-width types) as a signed / unsigned char\n";
	std::int8_t i8t{ 65 };
	std::cout << "int8_t i8t{ 65 } will likely print 'A', not 65: " << i8t << '\n';
	std::int_fast8_t if8t{ 65 };
	std::cout << "int_fast8_t if8t{ 65 } will likely print 'A', not 65: " << if8t << '\n';
	std::int_least8_t il8t{ 65 };
	std::cout << "int_least8_t il8t{ 65 } will likely print 'A', not 65: " << il8t << '\n';

	std::cout << "\nleast 8:  " << sizeof(std::int_least8_t) << " Byte(s)\n";
	std::cout << "fast 8:   " << sizeof(std::int_fast8_t) << " Byte(s)\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) << " Byte(s)\n";
	std::cout << "fast 16:  " << sizeof(std::int_fast16_t) << " Byte(s)\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) << " Byte(s)\n";
	std::cout << "fast 32:  " << sizeof(std::int_fast32_t) << " Byte(s)\n";
	std::cout << "least 64: " << sizeof(std::int_least64_t) << " Byte(s)\n";
	std::cout << "fast 64:  " << sizeof(std::int_fast64_t) << " Byte(s)\n";
	std::cout << '\n';

	// 4.8 - floating point numbers
	std::cout << "double dbl{ 5.0 } - 5.0 means floating point, literals default to type double\n";
	double dbl{ 5.0 };
	std::cout << "cout default will omit fractional 0's, so dbl prints as: " << dbl << '\n';
	std::cout << "float flt{ 5.0f } - f suffix means float\n";
	float flt{ 5.0f };
	std::cout << "flt = " << flt << '\n';
	long double ldbl{ 5.7 };
	std::cout << "long double ldbl{ 5.7 } prints as: " << ldbl << '\n';
	std::cout << "precision: float has 6-9 sig.dig's.  Will exactly represent any number with up to 6 sigdig's.\n";
	std::cout << "  A number w/ 7-9 sigdig's MAY be represented exactly, depending on the specific value\n";
	std::cout << "  A number with 10 or more sigdig's will NOT be represented exactly.\n\n";

	std::cout << "+===========================================================================================================+\n";
	std::cout << "+                                FLOATING POINT PRECISION & RANGE                                           +\n";
	std::cout << "+===========================================================================================================+\n";
	std::cout << "|     format                          |     precision               |     range                             |\n";
	std::cout << "+-----------------------------------------------------------------------------------------------------------+\n";
	std::cout << "| single precision (4B) (float)       | 6-9 (usually 7) sigdig's    | 0.0 and +/-1.18e-38 to +/-3.4e38      |\n";
	std::cout << "+-----------------------------------------------------------------------------------------------------------+\n";
	std::cout << "| double precision (8B) (double)      | 15-18 (usually 16) sigdig's | 0.0 and +/-2.23e-308 to +/-1.80e308   |\n";
	std::cout << "+-----------------------------------------------------------------------------------------------------------+\n";
	std::cout << "| quad precision (16B) (long double)  | 33-36 sigdig's              | 0.0 and +/-3.36e-4932 to +/-1.18e4932 |\n";
	std::cout << "+-----------------------------------------------------------------------------------------------------------+\n\n";

	std::cout << "cout has default precision of 6 sigdig's, truncates anything after.\n";
	std::cout << "std::cout << 1.23456789f prints as: " << 1.23456789f << '\n';
	std::cout << "std::cout << 12.3456789f prints as: " << 12.3456789f << '\n';
	std::cout << "std::cout << 123.456789f prints as: " << 123.456789f << '\n';
	std::cout << "std::cout << 1234.56789f prints as: " << 1234.56789f << '\n';
	std::cout << "std::cout << 12345.6789f prints as: " << 12345.6789f << '\n';
	std::cout << "std::cout << 0.0000123456789f prints as: " << 0.0000123456789f << '\n';
	std::cout << "\nstd::setprecision() allows us to change default precision.\n";
	std::cout << "I/O manipulators are sticky - once set, they remain (except setw - some I/O ops will reset std::setw)\n";
	std::cout << "doing std::setprecision(17) (needs to #include <iomanip>)\n" << std::setprecision(17);
	float threesfloat{ 3.33333333333333333333333333333333f };
	std::cout << "float 3.33333333333333333333333333333333f prints as: " << threesfloat << '\n';
	double threesdouble{ 3.33333333333333333333333333333333 };
	std::cout << "double 3.33333333333333333333333333333333 prints as: " << threesdouble << '\n';

	std::cout << "\nPrecision issues also impact big numbers:\n";
	std::cout << "float bigNumber{ 123456789.0f } will print as:";
	float bigNumber{ 123456789.0f };
	std::cout << bigNumber << '\n';

	std::cout << "\nRounding errors are the norm.  Never assume floating point numbers are exact.\n";
	double d01{ 0.1 };
	std::cout << "double d01{ 0.1 } prints as: " << d01 << '\n';
	std::cout << "d01 * 10 = " << d01 * 10 << '\n';
	std::cout << "does d01 * 10 = 1.0? ";
	if (d01 * 10 == 1)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	double tenTenths{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
	std::cout << "double tenTenths{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }\n";
	std::cout << "tenTenths prints as: " << tenTenths << '\n';
	std::cout << "does tenTenths = 1.0? ";
	if (tenTenths == 1.0)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	std::cout << "with setPrecision(16), tenTenths prints as: " << std::setprecision(16) << tenTenths << '\n';
	std::cout << "now does tenTenths = 1.0? ";
	if (tenTenths == 1.0)
		std::cout << "still yes\n";
	else
		std::cout << "still no\n";
	std::cout << "This is why comparing floating point numbers is problematic.\n\n";

	// 4.9 - Boolean
	bool b1{};
	std::cout << "bool b1{} defaults to 0 (false), prints as: " << b1 << '\n';
	std::cout << "use std::boolalpha to print as 'true' or 'false' (use std::noboolalpha to deactivate)\n";
	std::cout << std::boolalpha << "now b1 prints as: " << b1 << '\n';
	std::cout << "can use cin for boolean, but only accepts 0 or 1.\n";
	std::cout << "Enter a bool(0 / 1) : ";
	std::cin >> b1;
	std::cout << "b1 is now: " << b1 << '\n';
	std::cout << "can use boolalpha to accept true / false (case sensitive).  Enter a bool (true/false): ";
	std::cin >> std::boolalpha >> b1;
	std::cout << "b1 is now: " << b1 << '\n';
	std::cout << "any incorrect input with boolean cin will evaluate to false, and put cin in failure mode.\n\n";


	// 4.10 - if statements
	std::cout << "if statements, conditionals.\n";
	std::cout << "non-boolean conditionals are converted to boolean.\n0 is false, anything != 0 is true\n";
	int nonBool{ 4 };
	if (nonBool)
		std::cout << "int nonBool{ 4 } != 0, so if (nonBool) eval to true & this will print\n";
	else
		std::cout << "this will not print unless nonBool = 0.\n";
	std::cout << "may use early returns with conditionals, as in: \n";
	std::cout << "int absolute(int x) { if (x<0) return -x; else return x; }\n\n";

	// 4.11 - chars
	std::cout << "chars, prefer def's like char ch{ 'a' } instead of char ch{ 97 }\n";
	std::cout << "can use cin to extract chars, extra chars stay in buffer\n";
	std::cout << "extracting ignores leading whitespace.  std::cin.get() does not\n";
	std::cout << "demo: try inputting \"a b\": ";
	char char1{}, char2{}, char3{}, char4{}, char5{};
	std::cin >> char1 >> char2;
	std::cout << "char1 is now: " << char1 << " and char2 is now: " << char2 << '\n';

	std::cin.clear(); // clear any errors from input stream

	// Discard characters from the input buffer until a newline or EOF is encountered
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "cleared input buffer.  Try again, using get().  Input \"a b\": ";
	std::cin.get(char3);
	std::cin.get(char4);
	std::cin.get(char5);
	std::cout << "char3 is now: " << char3 << " and char4 is now: " << char4 << " and char5 is: " << char5 << '\n';
	std::cout << '\n';
#endif

	// 4.12 - Type conversion & static_cast
	std::cout << "void printDouble( double x ) { std::cout << x << '\\n'; }\n";
	void printDouble(double);
	std::cout << "calling printDouble(5): ";
	printDouble(5);
	std::cout << "  5 is an int, printDouble expects a double - implicit conversion from int 5 to double 5.0\n";
	std::cout << "  type conversions don't modify underlying object, returns temp object\n";
	int thisInt{ 7 };
	std::cout << "calling printDouble(thisInt): ";
	printDouble(thisInt);
	std::cout << "  but thisInt is still of type: " << typeid(thisInt).name() << '\n';
	std::cout << "can implicitly convert int to double, no loss of data\n";
	std::cout << "  but converting double to int will give warning on loss of data\n\n";
	std::cout << "can do explicit type conversion with static_cast\n";
	void printInt(int);
	std::cout << "explicit type conversion from double 5.5 to int 5:\n  printInt(static_cast<int>(5.5)) is: ";
	printInt(static_cast<int>(5.5));
	std::cout << "\ncan use static_cast to print char number instead of ASCII char: \n";
	char castChar{ 'a' };
	std::cout << "castChar " << castChar << " has value: " << static_cast<int>(castChar) << '\n';
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered: \'" << c << "\', which has ASCII code " << static_cast<int>(c) << '\n';
	std::cout << "Enter a single character: ";
	std::cin >> c;
	int ascii{ c };
	std::cout << "You entered: \'" << c << "\', which has ASCII code " << ascii << ".\n";

	std::cout << '\n';

	std::cout << "signed integral values can be converted to unsigned (and vice versa)\n";
	std::cout << "  converted value unchanged if destination type can hold the value\n";
	unsigned int u1{ 5 };
	int s1{ static_cast<int>(u1) };
	int s2{ 5 };
	unsigned int u2{ static_cast<unsigned int>(s2) };
	std::cout << "s1 is u1{5} static cast to int: " << s1 << '\n';
	std::cout << "u2 is s2{5} static cast to unsigned int: " << u2 << '\n';
	std::cout << "\nif value being converted doesn't fit in destination type, likely modulo wrapped\n";
	int s{ -1 };
	std::cout << "  static casting int s{ -1 } to unsigned int gives: " << static_cast<unsigned int>(s) << '\n';
	unsigned int u{ 4294967295 }; // largest 32-bit unsigned int
	std::cout << "  static casting unsigned int { 4294967295 } to signed int gives: " << static_cast<int>(u) << '\n';

	std::cout << "\nMost compilers treat std::int8_t and std::uint8_t like (un)signed chars\n";
	std::int8_t i{ 65 };
	std::cout << "  int8_t i{ 65 } prints as: " << i << '\n';
	std::cout << "can convert with static_cast, i would be: " << static_cast<int>(i) << '\n';

	std::cout << "Enter an ASCII code like 35: ";
	std::cin >> i;
	std::cout << "  you entered: " << static_cast<int>(i) << '\n';
	std::cout << "  because when int8_t is treated as char, cin interprets input as sequence of chars\n";
	std::cout << "  so the '3' in \"35\" is extracted, and '3' in ASCII has code 51\n";
	std::cout << "if you enterd 35, the 5 is still in the buffer.\n";
	std::cin >> i;
	std::cout << "  from the buffer: " << i << '\n';
	std::cout << "However, the other fixed-width types always print & input as integral values\n";
	

	return 0;
}

int multiply(int x, int y)
{
	return x * y;
}

void printDouble(double x)
{
	std::cout << x << '\n';
	std::cout << "in printDouble, type of x is: " << typeid(x).name() << '\n';
}

void printInt(int x)
{
	std::cout << x << '\n';
	std::cout << "in printInt, type of x is: " << typeid(x).name() << '\n';
}