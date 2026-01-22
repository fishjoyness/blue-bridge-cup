//基于裴蜀定理的C++代码。裴蜀定理指出：对于不定方程 ax + by = cax+by=c，
//当且仅当 \gcd(a, b) \mid cgcd(a,b)∣c（即 aa 和 bb 的最大公约数能整除 cc）时，该方程有整数解 
#include <iostream>
#include <algorithm> // 包含 __gcd 函数
using namespace std;

int main() {
    int a, b, c;
    
    // 读取系数 a, b 和 结果 c
    cout << "请输入 a, b, c (例如: 6 4 3): ";
    while (cin >> a >> b >> c) {
        // 计算 a 和 b 的最大公约数
        // __gcd 是 <algorithm> 头文件中的内置函数 (GCC环境)
        // 如果在非GCC环境，可以自己写一个gcd函数
        int d = __gcd(a, b);

        // 裴蜀定理核心判断：c 是否能被 gcd(a, b) 整除
        if (c % d == 0) {
            cout << "有整数解" << endl;
            
            // 题目示例中的解验证：
            // 虽然裴蜀定理只告诉我们"有解"，但不直接给出具体解。
            // 具体解 x, y 通常需要使用扩展欧几里得算法来求解。
            // 但对于简单的观察，我们可以手动验证：
            // 例如 a=6, b=9, c=12. d=3. 12%3==0 -> 有解。
            // x=-1, y=2 代入 -> 6*(-1) + 9*2 = -6 + 18 = 12. 成立。
        } else {
            cout << "无整数解" << endl;
        }
        
        cout << "-------------------" << endl;
        cout << "请输入下一组 a, b, c: ";
    }

    return 0;
}

