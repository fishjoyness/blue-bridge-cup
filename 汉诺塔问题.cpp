//汉诺塔问题
#include <iostream>
using namespace std; 
void hanoi(int n, char source, char auxiliary, char destination);

int main() {
    int n; 
    cout << "请输入汉诺塔的盘子数量: ";
    cin >> n; 
    // 'A'是起始柱，'B'是辅助柱，'C'是目标柱
    hanoi(n, 'A', 'B', 'C'); 
    return 0; 
}
void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "将盘子 " << n << " 从 " << source << " 移动到 " << destination << endl;
        return; 
    }
    // 第一步：将上面的 n-1 个盘子，从起始柱借助目标柱(destination)移动到辅助柱(auxiliary)
    // 注意这里destination和auxiliary的角色互换了
    hanoi(n - 1, source, destination, auxiliary);
    // 第二步：将最底下的第 n 个盘子，从起始柱(source)移动到目标柱(destination)
    cout << "将盘子 " << n << " 从 " << source << " 移动到 " << destination << endl;    
    // 第三步：将刚才移动到辅助柱上的 n-1 个盘子，借助起始柱(source)移动到目标柱(destination)
    // 注意这里source和auxiliary的角色互换了
    hanoi(n - 1, auxiliary, source, destination);
}
//次数：f(1)=1
//f(n)=f(n-1)+1+f(n-1)= 2f(n-1)+1 
