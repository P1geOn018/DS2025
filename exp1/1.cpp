#include <iostream>
#include "../MySLQ/vector.h"
#include <ctime>
#include <chrono>

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
            if( (I *I+ R * R > p.getI() *p.getI()+ p.getR() * p.getR()))
                return true;
            else if (I *I+ R * R == p.getI() *p.getI()+ p.getR() * p.getR()){
                        if(R > p.getR())
                            return true;
                        else
                            return false;   
                        }
            return false;
        }
        bool operator<(Plural p) const
        {
            if( (I *I+ R * R < p.getI() *p.getI()+ p.getR() * p.getR()))
                return true;
            else if (I *I+ R * R == p.getI() *p.getI()+ p.getR() * p.getR()){
                        if(R < p.getR())
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
        ~Plural(){}
};

Vector<Plural> zonesearch(Plural p1, Plural p2,Vector<Plural> &V)
{
    Rank lo = V.search(p1);
    Rank hi = V.search(p2);
    int size = hi - lo + 1;
    Vector<Plural> V2(size);
    for (Rank i = lo; i < hi;i++)
    {
        V2.insert(V[i]);
    }
    return V2;
}
int main()
{
    Vector<Plural> V(100);
    for (Rank i = 0; i < 100;i++)
    {
        V.insert(Plural());
    }
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout<<"��������"<<endl;
    V.unsort();
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout<<"�����������"<<endl;
    Plural p = V[10];
    cout << "������Ҷ���Ϊ:" << "("<< p.getI() << "," << p.getR() << ")" << endl;
    cout << "������ҽ��Ϊ:" << V.find(p) << endl;
    cout << "����ɾ��"  << endl;
    V.remove(10);
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout << "���Բ���" << endl;
    V.insert(10, p);
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout<<"����Ψһ��"<<endl;
    for(Rank i = 0; i < 5;i++)
    {
        V[i] = p;
    }
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    V.deduplicate();
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout<<"������������"<<endl;
    Vector<Plural> V2(V);
    auto start = chrono::high_resolution_clock::now();
    V.sort(0, V.size(), 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V.size();i++)
    {
        cout<< "("<< V[i].getI() << "," << V[i].getR() << ") ";
    }
    cout << endl;
    cout<<"��ʱ:" << duration.count() << "΢��" << endl;
    cout<<"���Թ鲢����"<<endl;
    start = chrono::high_resolution_clock::now();
    V2.sort(0, V2.size(), 3);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "��ǰ����˳��:" << endl;
    for (Rank i = 0; i < V2.size();i++)
    {
        cout<< "("<< V2[i].getI() << "," << V2[i].getR() << ") ";
    }
    cout << endl;
    cout<<"��ʱ:" << duration.count() << "΢��" << endl;
    cout << endl;
    cout<<"�����������"<<endl;
    Plural p1 = V[10];
    Plural p2 = V[20];
    Vector<Plural> V3 = zonesearch(p1, p2, V);
    cout << "������Ҷ���Ϊ:" << "("<< p1.getI() << "," << p1.getR() << ") " << "("<< p2.getI() << "," << p2.getR() << ")" << endl;
    cout << "������ҽ��Ϊ:" << endl;
    for (Rank i = 0; i < V3.size();i++)
    {
        cout<< "("<< V3[i].getI() << "," << V3[i].getR() << ") ";
    }
    cout << endl;


    return 0;
}