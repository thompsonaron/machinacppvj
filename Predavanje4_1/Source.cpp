#include <iostream>
#include <string>
int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	std::string* stringptr;
	std::string someWord = "nesto";
	stringptr = &someWord;

	int** doubleptr = &ptr;

	number = 20;
	tracker = 4;






	std::cout << "Hello world" << std::endl;
	std::cout << number << std::endl;
	std::cout << tracker << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	std::cout << "stringptr:" << stringptr << std::endl;
	std::cout << "dereference stringptr:" << (*stringptr) << std::endl;
	*stringptr = "nesto drugo";
	std::cout << "dereference doradjen stringptr:" << (*stringptr) << std::endl;
	std::cout << "double ptr adress: " << (**doubleptr) << std::endl;
	std::cout << "double referenced int je: " << (**doubleptr) << std::endl;
	std::cin.get();

}