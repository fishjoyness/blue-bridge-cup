#include <iostream>
//数组模拟链表 - 写起来复杂，但跑起来飞快 
const int N = 100010;
// e[i] 存储节点i的下一个节点的索引 (next指针)
// p[i] 存储节点i的上一个节点的索引 (prev指针)
// head 和 tail 分别记录链表头和尾的节点索引
int e[N], p[N], head, tail;

// 在节点y的后面插入节点x 
void insert_back(int y, int x) {
    // 如果y是链表的尾部
    if (e[y] == -1) {
        e[y] = x;
        p[x] = y;
        e[x] = -1;
        tail = x;//全局的尾指针更新 
    } else {
        //在y和y的下一个节点之间插入x
        e[x] = e[y];//y 原来的下一个节点(A)存起来，作为 x 的下一个节点 
        p[x] = y;// 让 x 的上一个节点指向 y
        //使x的位置正确，x 的后继指向 A， x 的前驱指向 y
        
        p[e[y]] = x;// A 的上一个节点必须变成 x
        e[y] = x;//y 的下一个节点不再是 A 了，而是新插入的 x
        //原来的 y 和 A 的指针被更新 
    }
}

// 新增函数：在节点y的前面插入节点x
void insert_front(int y, int x) {
    // 如果y是链表的头部
    if (p[y] == -1) {
        p[y] = x;
        e[x] = y;
        p[x] = -1;
        head = x;
    } else {
        // 正常情况：在y和y的上一个节点之间插入x
        p[x] = p[y];
        e[x] = y;
        e[p[y]] = x;
        p[y] = x;
    }
}

// 删除节点x 
void del(int x) {
    // 如果x不是头节点，就让x的前驱指向x的后继
    if (p[x] != -1) {
        e[p[x]] = e[x];
    } else {
        // 否则，x是头节点，更新头节点
        head = e[x];
    }

    // 如果x不是尾节点，就让x的后继指向x的前驱
    if (e[x] != -1) {
        p[e[x]] = p[x];
    } else {
        // 否则，x是尾节点，更新尾节点
        tail = p[x];
    }
}

int main() {
    // 初始化所有节点为未使用状态
    for (int i = 0; i < N; ++i) {
        e[i] = -1;
        p[i] = -1;
    }
    head = -1;
    tail = -1;

    int n, m;
    std::cin >> n >> m;

    // 读取初始的n个节点，并依次插入到链表中
    if (n > 0) {
        head = tail = 1; // 第一个节点1成为头和尾
        for (int i = 2; i <= n; ++i) {
            insert_back(tail, i); // 每次都在当前尾部插入新节点
        }//把新数字 i 插入到当前链表的最后一个节点（tail）的后面 
    }

    // 处理m条指令--------------移动=先删除，再插入 
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z; 

        // 如果x和y是同一个节点，移动无意义，直接跳过本次操作
        if (x == y) continue;

        // 第一步：将节点x从它原来的位置删除
        del(x);// 节点 x 成了一个独立的、自由的节点

        // 第二步：根据z的值，将x插入到y的相应位置
        if (z == 0) {
            // z=0，将x移动到y之后
            insert_back(y, x);
        } else { // z == 1
            // z=1，将x移动到y之前
            insert_front(y, x);
        }
    }

    // 从头到尾遍历链表并打印结果
    int current = head;
    while (current != -1) {
        std::cout << current << " ";
        current = e[current]; // 移动到下一个节点
    }
    std::cout << std::endl;

    return 0;
}

