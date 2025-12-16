#include <bits/stdc++.h>
using namespace std;
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // 同样，a > b 实现最小堆
    }
};

int main(){
	//栈和队列 
	//push()将元素插入队列中 
	//pop()弹出顶部元素 
	//top()返回顶部元素 
	//empty()检查是否为空 
	//size() 返回元素个数
	//队列 front返回队首元素
	//     back返回队尾 
	 
	//push_back  在vector,双向队列，双向链表，字符 
	//优先队列priority_queue中的元素是按照一定的优先级进行排序的 
	priority_queue<int, vector<int>, Compare> pq;
	//compare决定了队列中元素的优先级顺序
    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(20);

    cout << "最小堆输出: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
    
    //双端队列
	//push_back(x)在尾部插入元素
	//push_front(x)在头部插入元素
	//pop_back()弹出尾部元素
	//pop_front()
	//front()返回头部元素
	//back()
	//empty()
	//size()
	//clear() 
    
} 


