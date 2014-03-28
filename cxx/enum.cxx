#include <iostream>

enum class Title : char {ms, mr, none};

int main()
{
	Title t1 = Title::ms;
	std::cout << t1 << std::endl;
	return 0;
}
