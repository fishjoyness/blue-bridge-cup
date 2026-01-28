#include <iostream>
using namespace std;
const int N = 2e5 + 9;  // 定义最大学生数量
int pre[N];             // pre[i] 表示节点i的父节点（祖先）

// 查找函数：查找x的根节点（祖先）
// 路径压缩：在查找过程中将沿途节点的父节点直接指向根节点
int root(int x)
{
    // 如果x的父节点是自己，说明x就是根节点，返回x
    // 否则，递归查找pre[x]的根节点，并将pre[x]更新为根节点（路径压缩）
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

int main()
{	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    // 初始化：一开始每个学生都是独立的集合，自己的父节点是自己
    for(int i = 1; i <= n; ++ i)
        pre[i] = i;
    
    // 处理m条操作指令
    while(m --)
    {
        int op, x, y;
        cin >> op >> x >> y;
        
        if(op == 1)
        {
            // 操作1：合并集合
            // 将x的根节点作为y的根节点的子节点
            pre[root(x)] = root(y);
        }
        else
        {
            // 操作2：查询是否在同一集合
            // 比较x和y的根节点是否相同
            // 注意：题目通常要求输出 YES 或 NO，这里修正了大小写
            if(root(x) == root(y))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}

