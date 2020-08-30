#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
1. vector扩容为两倍
2. 

*/

int main(int argc, char const *argv[])
{
    vector<int> v1; // 初始值为0
    vector<string> v2; //string默认构造
    vector<int> v3(10); // 10个默认数
    vector<int> v4(10, 5); // 10个5
    
    v4.push_back(11);
    size_t size = v4.size(); // 容器中的元素数
    cout << "v4.size = " << size << endl;
    //容器是否为空
    cout << "v4.empty = " << (!v4.empty() ? "true":"false") << endl;
    cout<< "v4.max_size = " << v4.max_size() << endl;
    v4.insert(v4.end(), 5,7);//往容器的某一位置插入元素
    v4.pop_back(); //pop最后的元素
    v4.erase(v4.begin(), v4.begin()+4); //删除指定范围元素
    for(auto it = v4.begin() ; it != v4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    const auto const_it = v4.begin(); //const 迭代器
    //const_it++;

    auto it = v4.begin();
    it++;

    v4.clear(); //清空容器

    return 0;
}
