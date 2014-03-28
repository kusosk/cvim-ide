#include <iostream>
#include <exception>

namespace test1 {
	class C1 {
		public:
		C1() { std::cout << "C1 up" << std::endl;}
		void func1 (int arg) {std::cout<<"C1:func"<<std::endl;}
	};	
};

class exception1 : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "exception1 throws this...";
    } 
};

std::exception_ptr exptr = NULL;

    void
test_exception1 (  )
{
    try {
        throw exception1();
    } catch (std::exception& exc) {
        //exptr = std::current_exception();
        using namespace std;
        cerr << exc.what() << endl;
    } catch (...) {
        using namespace std;
        cerr<< "................" << endl;
    }
    return ;
}		/* -----  end of function test_exception1  ----- */

int main()
{
	using std::cout;
	cout << "test1" << std::endl;	
	using std::endl;
	cout << "test2" << endl;

    test_exception1();
	return 0;
}
