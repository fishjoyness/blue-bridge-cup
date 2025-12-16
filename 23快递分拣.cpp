#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

// map (内部是红黑树）的键是城市名(string)，
//值是该城市所有快递单号的列表(vector<string>)
//map 的强大之处：快速查找和自动分组
    map<string, vector<string>> mp;
    // vector 用来按输入顺序记录所有出现过的城市名
    vector<string> citys;
//map 本身不保留插入顺序，citys 完美地记录了城市首次出现的顺序 

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string id, city;
        cin >> id >> city; // 读取快递单号和城市

        // 如果这个城市是第一次出现
        if (mp.count(city) == 0) {
// 如果找到了，说明这个城市已经出现过了，函数返回 1。
//如果没找到，说明这是第一次出现，函数返回 0

            citys.push_back(city); 
// 把城市名加入 citys 列表，push_back 的意思是“添加到末尾”
        }
        mp[city].push_back(id); // 把快递单号存入对应城市的列表中
    }

    // 遍历所有出现过的城市
    for (const auto& city_name : citys) {
        // 输出城市名和该城市的快递总数
        
// citys：这是我们熟悉的那个 vector<string>，
//里面按顺序存着所有城市名，比如 ["北京", "上海", "广州"]
        cout << city_name << " " << mp[city_name].size() << '\n';

        // 输出该城市所有的快递单号
        for (const auto& package_id : mp[city_name]) {
// 嵌套在第一个循环里的第二个循环
//在外层循环的第一次迭代时，mp[city_name] 就变成了 mp["北京"]，
//里面存着所有北京的快递单号
            cout << package_id << '\n';

        }
    }

    return 0;
}

