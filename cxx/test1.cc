#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

//section nullptr
void f_nullptr(int v)
{
	cout << "1" << endl;
}

void f_nullptr(void *p)
{
	cout << "2" << endl;
}

void test_nullptr()
{
	std::nullptr_t nullValue = nullptr;
	f_nullptr(100);
	f_nullptr(nullValue);
	f_nullptr(0);
}
// end of nullptr

// auto parameter
class Person {
public:
	Person(string n) : name(n) {};
	//operator <<
protected:
	string name;
};

class Man {
public:
	Man(string n, int p) : name(n), power(p) {};
private:
    string name;
	int power;
};

void test_auto()
{
	auto intv = 100*3;
	cout << "type1 : " << typeid(intv).name() << endl;	
	auto funcv = [] (int v) -> bool { return (v==1)?false:true;};
	cout << "type2 : " << typeid(funcv).name() << endl;	
	cout << "	type2 result: " << funcv(10) << " " << funcv(1) << endl;
}

void test_lamba()
{
	//auto f1 = [] (
}

void test_initlization()
{
	int v[] = { 1, 2, 4};
	vector<string> vs1 {"A1", "A2", "A3"};
}
int main()
{
	// test nullptr
	test_nullptr();
	
	test_auto();
	test_initlization();
	test_lamba();
	cout << "test1..." << endl;
	return 0;
}
