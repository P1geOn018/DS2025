#include <iostream>
#include "../MySLQ/stack.h"

using namespace std;

int main()
{
    char S[] = "((1+2)*3+3)-4/5";
    cout << "����Ϊ: " << S << " ��ȷ��Ϊ: 11.2 "<<endl;
    char *RPN = new char[strlen(S) * 2 + 1];
    RPN[0] = '\0';
    cout << "���Ϊ: ";
    cout << evaluate(S, RPN) << endl;
    cout << "�沨�����ʽΪ: " << endl;
    cout << RPN << endl;
    delete[] RPN;
    return 0;
}
