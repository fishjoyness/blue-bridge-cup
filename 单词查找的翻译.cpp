#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; // m: 内存容量, n: 文章长度
    cin >> m >> n;
    queue<int> memory_queue;       // 用队列记录单词进入内存的顺序，用于FIFO淘汰
    unordered_set<int> memory_set; // 用集合快速判断单词是否在内存中
    int lookup_count = 0; // 需要查词典的次数
    for (int i = 0; i < n; ++i) {
        int word;
        cin >> word;
        // 1. 检查单词是否在内存中
        // unordered_set的find函数平均时间复杂度是O(1)，非常快
        //哈希函数 
        if (memory_set.find(word) != memory_set.end()) {
            // 在内存中，直接跳过，不需要查词典
            continue;
        }
//如果找到了 word，它会返回一个指向这个 word 的“指针”（迭代器）
//如果没找到 word，它就会返回这个特殊的“哨兵”——memory_set.end() 

        // 2. 如果不在内存中，需要查词典
        lookup_count++;

        // 3. 将单词加入内存
        // 检查内存是否已满
        if (memory_queue.size() == m) {
            // 内存已满，需要淘汰最早进入的单词
            int word_to_remove = memory_queue.front();
            memory_queue.pop();          // 从队头移除
            memory_set.erase(word_to_remove); // 从哈希表中也同步移除
        }
        // 将新单词加入内存
        memory_queue.push(word);      // 加入队尾
        memory_set.insert(word);      // 加入集合
    }

    cout << lookup_count << '\n';

    return 0;
}
