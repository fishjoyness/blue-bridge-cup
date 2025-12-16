#include <bits/stdc++.h>
using namespace std; 

int main() {
    stack<int> mystack;

    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);

    // 获取并打印栈顶元素
    cout << "初始栈顶元素: " << mystack.top() << endl;//top查看栈顶元素 

    // 弹出栈顶元素 (出栈)
    mystack.pop();

    // 再次获取并打印栈顶元素
    cout << "弹出一个元素后的栈顶元素: " << mystack.top() << endl;

    // 检查栈是否为空
    if (mystack.empty()) {
        cout << "栈为空" << endl;
    } else {
        cout << "栈不为空" << endl;
        // 获取栈的大小
        cout << "栈的大小: " << mystack.size() << endl;
    }

    return 0;
}

