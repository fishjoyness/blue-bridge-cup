#include <iostream>
using namespace std;
const int N = 100010; 
char stk[N]; // 用字符数组模拟栈
int top = 0; // 栈顶指针，0表示栈为空
char s[N];   // 用来存储输入的括号字符串
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        // 如果遇到右括号
        if (s[i] == ')') {
            // 如果栈不为空，并且栈顶是左括号，说明匹配成功
            if (top != 0 && stk[top] == '(') {
                top--; // 弹出栈顶的左括号
                continue; // 跳过后续代码，处理下一个字符
            }
        }
        // 其他所有情况（遇到左括号，或遇到无法匹配的右括号）都入栈
        stk[++top] = s[i];//把字符 s[i] 存入到 top 指向的新位置上 
    }
    // 遍历结束后，如果栈为空(top==0)，说明所有括号都成功匹配
    if (top == 0) {
        cout << "Yes" << '\n';
    } else { // 如果栈不为空，说明有未匹配的括号
        cout << "No" << '\n';
    }

    return 0;
}
