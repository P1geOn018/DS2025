#include <iostream>
#include "../MySLQ/stack.h"

using namespace std;

int main()
{
    char S[] = "((1+2)*3+3)-4/5";
    cout << "举例为: " << S << " 正确答案为: 11.2 "<<endl;
    char *RPN = new char[strlen(S) * 2 + 1];
    RPN[0] = '\0';
    cout << "结果为: ";
    cout << evaluate(S, RPN) << endl;
    cout << "逆波兰表达式为: " << endl;
    cout << RPN << endl;
    delete[] RPN;
    return 0;
}
