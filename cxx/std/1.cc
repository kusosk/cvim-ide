#include	<iostream>
#include	<climits>
#include	<bitset>
#include	<exception>
#include	<stdexcept>
#include    <string>
#include    <cstring>

using namespace std;

void func1()
{
    std::string orbits ("68.7a365.24AAA");
    std::string::size_type sz;     // alias of size_t

    float mars = std::stof (orbits,&sz);
    cout << mars << " =" << orbits.substr(sz) << endl;
    float earth = 0;
    try {
        earth = std::stof (orbits.substr(sz), &sz);
        cout << earth << " =" << orbits.substr(sz) << endl;
        std::cout <<"One martian year takes " << (mars/earth) << " Earth years.\n";
    } catch (std::invalid_argument& ) {
        cout << "sz=" << sz << endl;
        throw;
    } catch (...) {
        cout << "clenup done" << endl;
    }


    string s2 = string("123.45 345");

    size_t n;
    cout << (double)stod(s2, &n) << " N=" << s2.substr(n) << "|" << stoi(s2.substr(n), &n)<< " N=" << s2.substr(n) << endl;
}

void func2()
{
    try {
        // bitset constructor throws an invalid_argument if initialized
        // with a string containing characters other than 0 and 1
        std::bitset<5> mybitset (std::string("01234"));
    }
    catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }

}
int main()
{
    try {
        func1();
    } catch (invalid_argument&) {
        cout << "caught in main" << endl;
    }
    func2();
    return 0;
}
