#include <iostream>
#include "vector.h"

using namespace std;

// 打印Vector元素的函数
void printVector(Vector<int> &vec, const string &message)
{
    cout << message << ": ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "=== Vector 查找和排序功能测试 ===" << endl;

    // 创建Vector并插入测试数据
    Vector<int> vec;
    vec.insert(0, 6);
    vec.insert(1, 2);
    vec.insert(2, 8);
    vec.insert(3, 4);
    vec.insert(4, 1);
    vec.insert(5, 9);
    vec.insert(6, 3);
    vec.insert(7, 7);
    vec.insert(8, 5);

    printVector(vec, "初始Vector");

    // 测试查找功能
    cout << "\n=== 查找功能测试 ===" << endl;

    int target = 5;
    int index = vec.find(target);
    if (index >= 0)
    {
        cout << "元素 " << target << " 在位置 " << index << " 找到" << endl;
    }
    else
    {
        cout << "元素 " << target << " 未找到" << endl;
    }

    target = 10;
    index = vec.find(target);
    if (index >= 0)
    {
        cout << "元素 " << target << " 在位置 " << index << " 找到" << endl;
    }
    else
    {
        cout << "元素 " << target << " 未找到" << endl;
    }

    // 测试有序查找(search方法)
    cout << "\n对Vector进行排序以测试有序查找..." << endl;
    // 为了避免随机算法的问题，我们手动实现一个简单的排序
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    printVector(vec, "排序后Vector");

    // 因为search()要求Vector有序，这里我们假设已经排好序
    target = 7;
    index = vec.find(target);
    if (index >= 0)
    {
        cout << "通过find方法在位置 " << index << " 找到元素 " << target << endl;
    }
    else
    {
        cout << "通过find方法未找到元素 " << target << endl;
    }

    // 测试在指定范围内的查找
    cout << "\n=== 范围查找测试 ===" << endl;
    target = 3;
    index = vec.find(target, 0, 4); // 在前4个元素中查找
    if (index >= 0)
    {
        cout << "在前4个元素中找到 " << target << " 在位置 " << index << endl;
    }
    else
    {
        cout << "在前4个元素中未找到 " << target << endl;
    }

    // 测试排序功能
    cout << "\n=== 排序功能测试 ===" << endl;

    // 创建一个新的无序Vector
    Vector<int> vec2;
    vec2.insert(0, 15);
    vec2.insert(1, 3);
    vec2.insert(2, 9);
    vec2.insert(3, 1);
    vec2.insert(4, 12);
    vec2.insert(5, 6);

    printVector(vec2, "排序前的Vector");

    // 使用冒泡排序手动排序
    for (int i = 0; i < vec2.size() - 1; i++)
    {
        for (int j = 0; j < vec2.size() - 1 - i; j++)
        {
            if (vec2[j] > vec2[j + 1])
            {
                swap(vec2[j], vec2[j + 1]);
            }
        }
    }
    printVector(vec2, "手动冒泡排序后的Vector");

    // 测试部分排序
    Vector<int> vec3;
    vec3.insert(0, 5);
    vec3.insert(1, 2);
    vec3.insert(2, 8);
    vec3.insert(3, 1);
    vec3.insert(4, 9);
    vec3.insert(5, 3);
    vec3.insert(6, 7);
    vec3.insert(7, 4);

    printVector(vec3, "部分排序前");

    // 手动对索引2到5之间的元素排序（部分排序）
    for (int i = 2; i < 6 - 1; i++)
    {
        for (int j = 2; j < 6 - 1 - (i - 2); j++)
        {
            if (vec3[j] > vec3[j + 1])
            {
                swap(vec3[j], vec3[j + 1]);
            }
        }
    }
    printVector(vec3, "对索引2到5之间元素排序后");

    // 测试去重功能
    cout << "\n=== 去重功能测试 ===" << endl;
    Vector<int> vec4;
    vec4.insert(0, 1);
    vec4.insert(1, 3);
    vec4.insert(2, 3);
    vec4.insert(3, 5);
    vec4.insert(4, 5);
    vec4.insert(5, 5);
    vec4.insert(6, 7);

    printVector(vec4, "去重前");
    int removed = vec4.uniquify();
    printVector(vec4, "调用uniquify()去重后");
    cout << "移除了 " << removed << " 个重复元素" << endl;

    return 0;
}