 //排序去重是手段，通过 lower_bound 把大数值映射为小下标才是离散化的目的。
 #include <bits/stdc++.h>
using namespace std;

// 方法1：使用普通数组进行离散化
void array_discretization() {
    int a[200000 + 10]; // 原数组
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 1. 排序 (左闭右开区间)
    sort(a + 1, a + n + 1);

    // 2. 去重
    // unique返回的是去重后尾部的下一个地址，减去首地址得到有效长度
    int len = unique(a + 1, a + n + 1) - (a + 1);

    cout << "去重后的离散化数组: ";
    for (int i = 1; i <= len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 3. 查询映射 (演示如何用lower_bound查找某个值的排名)
    // 假设我们要查找值 x 的排名
    int x;
    cout << "请输入要查询的值: ";
    cin >> x;
    
    // 在有序数组中查找第一个大于等于x的位置
    int rank = lower_bound(a + 1, a + len + 1, x) - a;
    
    if (rank <= len && a[rank] == x) {
        cout << "值 " << x << " 的离散化排名是: " << rank << endl;
    } else {
        cout << "值 " << x << " 不在数组中" << endl;
    }
}

// 方法2：使用vector进行离散化 (更常用，因为原数组顺序通常需要保留)
void vector_discretization() {
    int n;
    cin >> n;
    vector<int> a(n), b(n); // a用于辅助离散化，b保存原始数据
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i]; // 备份原始数据
    }

    // 1. 排序
    sort(a.begin(), a.end());

    // 2. 去重 (erase-remove惯用法)
    a.erase(unique(a.begin(), a.end()), a.end());

    // 3. 映射：将原始数组b中的每个元素替换为它们的排名
    for (int i = 0; i < n; i++) {
        // 查找 b[i] 在离散化数组 a 中的下标
        b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    }

    cout << "离散化映射后的结果: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 为了演示方便，这里注释掉其中一个函数调用，你可以根据需要选择运行哪个
    // array_discretization();
    
    vector_discretization();

    return 0;
}

