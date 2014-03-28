/*
 * =====================================================================================
 *
 *       Filename:  smallptr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2013 02:31:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include	<cstdio>

using namespace std;
int main()
{
    shared_ptr< string > t1 = make_shared<string>("test1");
    std::shared_ptr < string > ptr1;
    cout << ptr1.use_count() << endl;
    ptr1.reset(new string("aaa"));
    cout << ptr1.use_count() << endl;

    cout << (*t1)[4] << endl;
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << " ";
    }
    cout << endl;
    // overwrite a name again
    *pNico = "Nicolai";
    // print all elements again
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << " ";
    }
    cout << endl;
    // print some internal data
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
    cout << "Nico ref:" << pNico.use_count() << endl;
    whoMadeCoffee.resize(2);
    cout << "Nico ref:" << pNico.use_count() << endl;


    const char* filename = "./tmp";
    std::remove(filename);

/*
    string t("aaaaa");
    shared_ptr<string> sv1(&t);
    shared_ptr<string> sv2(&t);

    cout << sv1.use_count() << endl;
    sv1.reset();
    cout << sv1.use_count() << endl;
*/
    int i0 = 10 << 3;
    cout << i0 << endl;
    return 0;
}				/* ----------  end of function main  ---------- */
