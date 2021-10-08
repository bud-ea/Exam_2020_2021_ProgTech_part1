#include "DBClass.h"
#include <iostream>

using namespace std;

#define dp(var) (std::cout << #var ": " << (var) << std::endl)

int main()
{
    DBClass c;
   // dp(c.load("ttt.txt", 0));
    dp(c.load("t.txt", 0));
    c.printAll();
    cout << endl;

    dp(c.find("Smith"));
    dp(c.find("Scott"));
    cout << endl;

    dp(c.add("abac", "qwe", "1234 223344"));
    dp(c.add("ab?c", "qwe", "1234 223344"));
    dp(c.add("abcc", "q e", "1234 223344"));
    dp(c.add("abac", "qwe", "1234-223344"));
    dp(c.add("abac", "qwe", "12F4 223344"));
    cout << endl;

    dp(c.remove(-14));
    dp(c.remove(2));

    c.save("t2.txt", 0);
}
