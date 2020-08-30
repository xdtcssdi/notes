#include <deque>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int> deq;
    deq.push_front(10);
    deq.push_back(100);

    deq.insert(deq.end(),111);
    deq.insert(deq.end(), 10, 5);
    deq.max_size();
    deq.empty();
    deq.resize(100);//少的删除，多的扩容
    deq.resize(100,34);//扩容的默认值34
    deq.front(); //第一个元素
    deq.back(); //最后一个元素
    deq[10]; //下标
    deq.at(10); //
    deq.erase(deq.begin());
    deq.erase(deq.begin(),deq.end());
    deq.clear();
    deq.pop_front();
    deq.pop_back();
    

    return 0;
}
