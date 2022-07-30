#include <iostream>
#include <string>

int main()
{
	uint8_t someVal = 0x01;
	uint8_t result = uint32_t(someVal);
	std::cout << "Result" + result;
}
