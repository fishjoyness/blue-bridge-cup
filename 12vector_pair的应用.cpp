#include <bits/stdc++.h> 
using namespace std;
struct Person {
   	string name;
    int age;
};
int main() {
    vector<Person> people;
    people.push_back({"Alice", 25});
    people.push_back({"Bob", 30});
    people.push_back({"Charlie", 20});
    vector<pair<Person, int>> scores;
    scores.push_back({people[0], 90}); 
//people[0] 会获取到 people 数组的第一个元素，也就是 {"Alice", 25} 这个 pair 对象
//程序创建了一个新的 pair，它的第一个元素是 {"Alice", 25}，第二个元素是 90
//scores[0] -> { {"Alice", 25}, 90 }
    scores.push_back({people[1], 85});
    scores.push_back({people[2], 95});
    // 遍历 pair 向量，并输出每个人的姓名、年龄和评分
    for (const auto& p : scores) {
        // p.first 是 Person 对象, p.second 是评分
        cout << "Name: " << p.first.name << endl;
        cout << "Age: " << p.first.age << endl;
        cout << "Score: " << p.second <<endl;
        cout << "---------" << endl;
    }
    return 0;
}
