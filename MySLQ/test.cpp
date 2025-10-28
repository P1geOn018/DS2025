#include <iostream>
#include "queue.h" // 包含队列相关头文件
#include "stack.h" // 包含栈相关头文件

using namespace std;

int main()
{
    cout << "测试 Vector 功能:" << endl;
    // 测试 Vector (类似于动态数组)
    Vector<int> vec(10); // 创建初始容量为10的向量
    vec.insert(0, 10);
    vec.insert(1, 20);
    vec.insert(2, 30);
    cout << "初始化 Vector 完成" << endl;
    cout << "Vector第0个元素: " << vec[0] << endl;
    cout << "Vector第1个元素: " << vec[1] << endl;
    cout << "Vector第2个元素: " << vec[2] << endl;
    cout << "当前Vector大小: " << vec.size() << endl;

    // 测试Vector查找功能
    cout << "\n测试 Vector 查找功能:" << endl;
    int index = vec.find(20);
    cout << "查找元素20的位置: " << index << endl;

    // 测试Vector插入功能
    cout << "\n测试 Vector 插入功能:" << endl;
    vec.insert(3, 5);
    vec.insert(4, 25);
    cout << "插入元素后Vector内容: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // vec.sort(); // 排序
    // cout << "排序后Vector内容: ";
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }
    // cout << endl;

    // 测试栈
    cout << "\n测试 Stack 功能:" << endl;
    Stack<char> stack;
    stack.push('A');
    stack.push('B');
    stack.push('C');

    cout << "栈顶元素: " << stack.top() << endl;
    cout << "弹出元素: " << stack.pop() << endl;
    cout << "弹出元素: " << stack.pop() << endl;
    cout << "栈是否为空: " << (stack.empty() ? "是" : "否") << endl;
    stack.pop(); // 弹出最后一个元素
    cout << "弹出所有元素后栈是否为空: " << (stack.empty() ? "是" : "否") << endl;

    // 测试链表
    cout << "\n测试 List 功能:" << endl;
    List<int> list;
    list.insertAsFirst(1);
    list.insertAsLast(2);
    list.insertAsLast(3);
    cout << "初始化 List 完成" << endl;
    cout << "List大小: " << list.size() << endl;
    cout << "List第一个元素: " << list.first()->data << endl;
    cout << "List最后一个元素: " << list.last()->data << endl;

    // 测试List查找功能
    cout << "\n测试 List 查找功能:" << endl;
    ListNode<int> *node = list.find(2);
    if (node)
    {
        cout << "找到元素2" << endl;
    }
    else
    {
        cout << "未找到元素2" << endl;
    }

    // 测试队列
    cout << "\n测试 Queue 功能:" << endl;
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "初始化 Queue 完成" << endl;
    cout << "队首元素: " << queue.front() << endl;
    cout << "出队元素: " << queue.dequeue() << endl;
    cout << "出队元素: " << queue.dequeue() << endl;
    cout << "队列是否为空: " << (queue.empty() ? "是" : "否") << endl;

    // 测试斐波那契数列
    cout << "\n测试 Fibonacci 功能:" << endl;
    Fib fib(100);
    cout << "不超过100的最大斐波那契数: " << fib.get() << endl;
    cout << "下一个斐波那契数: " << fib.next() << endl;
    cout << "再下一个斐波那契数: " << fib.next() << endl;

    cout << "\n所有测试完成!" << endl;

    return 0;
}