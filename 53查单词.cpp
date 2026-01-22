//建立字典：先把单词表存进 map 里，比如存入 {"abc": "a"}。
//扫描：从头开始读句子。
//积累：如果是字母（a-z），就把它暂时存起来（相当于正在读一个单词）。
//翻译：一旦读到了标点符号，说明上一个单词结束了。去 map 里查刚才存的那个单词：
//查到了？把翻译结果写进答案。
//没查到？把 “UNK” 写进答案。
//最后别忘了把标点符号也原样写进答案。
#include <bits/stdc++.h>
using namespace std;

map<string, string> m;
string a, b, t, ans, s;

int main() {
    int n;
    cin >> n;
    
    // 读取字典
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        m[a] = b;
    }
    
    // 读取需要翻译的文章
    cin >> s;
    
    // 遍历文章，逐个字符处理
    for (int i = 0; i <= s.size(); i++) {
        // 如果是字母，加入临时单词
        if (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
            t += s[i];
        } 
        // 如果不是字母（或到达字符串末尾），处理当前单词
        else {
            if (!t.empty()) {
                // 查找单词是否在字典中
                if (m.find(t) != m.end()) {
                    ans += m[t];  // 在字典中，添加翻译
                } else {
                    ans += "UNK";  // 不在字典中，添加UNK
                }
                t.clear();  // 清空临时单词
            }
            // 添加标点符号（如果不是字符串末尾）
            if (i < s.size()) {
                ans += s[i];
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}

