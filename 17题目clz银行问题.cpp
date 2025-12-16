#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    int m; cin >> m;	
    // 定义两个队列，分别用于VIP和普通用户
    queue<string> V, N;

    while (m--) {
        string op;
        cin >> op;

        if (op == "IN") {
            string name, q;
//name 用来存用户名，q 用来存窗口类型（"V" 或 "N"）
            cin >> name >> q;
            if (q == "V") {
                V.push(name); // VIP用户进入VIP队列
            } else {
                N.push(name); // 普通用户进入普通队列
            }
        } else { // op == "OUT"
            string q;
            cin >> q;
            if (q == "V") {
                // 重要：弹出前应检查队列是否为空，防止程序崩溃
                if (!V.empty()) {
                    V.pop(); // VIP队头用户离开
                }
            } else {
                if (!N.empty()) {
                    N.pop(); // 普通队头用户离开
                }
            }
        }
    }

    // 按顺序输出VIP队列中的所有姓名
    while (!V.empty()) {
        cout << V.front() << '\n';
        V.pop();
    }

    // 按顺序输出普通队列中的所有姓名
    while (!N.empty()) {
        cout << N.front() << '\n';
        N.pop();
    }

    return 0;
}

