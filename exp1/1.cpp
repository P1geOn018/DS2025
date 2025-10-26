#include <iostream>
#include "../MySLQ/vector.h"
#include <ctime>

using namespace std;

class Plural
{
private:
    double I;
    double R;

public:
    Plural()
    {
        I = (double)rand() / RAND_MAX * 200 - 100;
        R = (double)rand() / RAND_MAX * 200 - 100;
    }
    Plural(int c)
    {
        I = (double)rand() / RAND_MAX * 200 - 100;
        R = (double)rand() / RAND_MAX * 200 - 100;
    }
    double getI() const
    {
        return I;
    }
    double getR() const
    {
        return R;
    }
    bool operator!=(Plural p) const
    {
        return I != p.getI() || R != p.getR();
    }
    bool operator>(Plural p) const
    {
        if ((I * I + R * R > p.getI() * p.getI() + p.getR() * p.getR()))
            return true;
        else if (I * I + R * R == p.getI() * p.getI() + p.getR() * p.getR())
        {
            if (R > p.getR())
                return true;
            else
                return false;
        }
        return false;
    }
    bool operator<(Plural p) const
    {
        if ((I * I + R * R < p.getI() * p.getI() + p.getR() * p.getR()))
            return true;
        else if (I * I + R * R == p.getI() * p.getI() + p.getR() * p.getR())
        {
            if (R < p.getR())
                return true;
            else
                return false;
        }
        return false;
    }
    bool operator==(Plural p) const
    {
        return I == p.getI() && R == p.getR();
    }
    bool operator>=(Plural p) const
    {
        return *this > p || *this == p;
    }
    bool operator<=(Plural p) const
    {
        return *this < p || *this == p;
    }
    ~Plural() {}
};

Vector<Plural> zonesearch(Plural p1, Plural p2, Vector<Plural> &V)
{
    Rank lo = V.search(p1);
    Rank hi = V.search(p2);
    int size = hi - lo + 1;
    Vector<Plural> V2(size);
    for (Rank i = lo; i < hi; i++)
    {
        V2.insert(V[i]);
    }
    return V2;
}
int main()
{
    Vector<Plural> V(30);
    for (Rank i = 0; i < 30; i++)
    {
        V.insert(Plural());
    }
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "测试置乱" << endl;
    V.unsort();
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "测试无序查找" << endl;
    Plural p = V[10];
    cout << "无序查找对象为:" << "(" << p.getI() << "," << p.getR() << ")" << endl;
    cout << "无序查找结果为:" << V.find(p) << endl;
    cout << "测试删除" << endl;
    V.remove(10);
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "测试插入" << endl;
    V.insert(10, p);
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "测试唯一化" << endl;
    for (Rank i = 0; i < 5; i++)
    {
        V[i] = p;
    }
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    V.deduplicate();
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "乱序测试气泡排序" << endl;

    Vector<Plural> V2(V);
    clock_t start = clock();
    V.sort(0, V.size(), 1);
    clock_t end = clock();
    double cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;
    for (Rank i = 0; i < V.size(); i++)
    {
        cout << "(" << V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;
    V.unsort();
    V2.unsort();

    cout << "乱序测试归并排序" << endl;
    start = clock();
    V2.sort(0, V2.size(), 3);
    end = clock();
    cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;
    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;
    cout << endl;

    cout << "顺序测试气泡排序" << endl;
    start = clock();
    V.sort(0, V.size(), 1);
    end = clock();
    cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;
    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;

    cout << "顺序测试归并排序" << endl;
    start = clock();
    V2.sort(0, V2.size(), 3);
    end = clock();
    cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;

    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;
    cout << endl;

    cout << "倒序测试气泡排序" << endl;
    V.reverse();
    start = clock();
    V.sort(0, V.size(), 1);
    end = clock();
    cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;
    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;

    cout << "倒序测试归并排序" << endl;
    V2.reverse();
    start = clock();
    V2.sort(0, V2.size(), 3);
    end = clock();
    cpu_time_used_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    cout << "当前向量顺序:" << endl;
    cout << endl;
    cout << "耗时:" << cpu_time_used_ms << "毫秒" << endl;
    cout << endl;

    cout << "测试区间查找" << endl;
    Plural p1 = V[10];
    Plural p2 = V[20];
    Vector<Plural> V3 = zonesearch(p1, p2, V);
    cout << "区间查找对象为:" << "(" << p1.getI() << "," << p1.getR() << ") " << "(" << p2.getI() << "," << p2.getR() << ")" << endl;
    cout << "区间查找结果为:" << endl;
    for (Rank i = 0; i < V3.size(); i++)
    {
        cout << "(" << V3[i].getI() << "," << V3[i].getR() << ") ";
    }
    cout << endl;

    return 0;
}