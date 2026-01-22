#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // map<string, int> - 字符串到整数的映射
    map<string, int> scoreMap;
    scoreMap["Alice"] = 95;
    scoreMap["Bob"] = 88;
    scoreMap["Charlie"] = 92;
    
    // 访问map中的值
    cout << "Alice的分数: " << scoreMap["Alice"] << endl;
    cout << "Bob的分数: " << scoreMap["Bob"] << endl;
    
    // map<string, string> - 字符串到字符串的映射
    map<string, string> personalityMap;
    personalityMap["Alice"] = "INTJ";
    personalityMap["Bob"] = "ENFP";
    personalityMap["Charlie"] = "ISFP";
    
    // 遍历map
    cout << "\n性格类型:" << endl;
    for (auto it = personalityMap.begin(); it != personalityMap.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    // 检查键是否存在
    if (personalityMap.find("David") == personalityMap.end()) {
        cout << "\nDavid不在map中" << endl;
    }
    
    return 0;
}

