#include <iostream>
#include "../MySLQ/vector.h"
#include <random>

using namespace std;

int cul(Vector<int> &v)
{
    Vector<int> S, v2 = v;
    v2.sort(0, v2.size(), 1);
    for (int i = 1; i <= v2[v2.size() - 1]; i++)
    {
        Vector<int> t;
        int s = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] >= i)
                s += i;
            else
            {
                t.insert(s);
                s = 0;
            }
        }
        t.insert(s);
        t.sort(0, t.size(), 1);
        S.insert(t[t.size() - 1]);
    }
    S.sort(0, S.size(), 1);
    return S[S.size() - 1];
}
int main()
{
    // v.insert(2);
    // v.insert(1);
    // v.insert(5);
    // v.insert(6);
    // v.insert(2);
    // v.insert(3);
    // cout << cul(v) << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 105);
    uniform_int_distribution<> dis2(1, 104);

    for (int i = 0; i < 10; i++)
    {
        Vector<int> v;
        int num = dis(gen);
        for (int j = 0; j < num; j++)
        {
            v.insert(dis2(gen));
        }
        cout << "当前测试向量：" << endl;
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
        cout << "计算结果为：";
        cout << cul(v) << endl;
    }
    return 0;
}