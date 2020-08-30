#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> lst1; //创建空list

    list<int> lst2(3); //创建含有三个元素的list

    list<int> lst3(3, 2); //创建含有三个元素的值为2的list

    list<int> lst4(lst2); //使用lst2初始化lst4

    list<int> lst5(lst2.begin(), lst2.end()); //同lst4

    lst1.assign(lst2.begin(), lst2.end()); //分配值
    lst1.push_back(10);                    //添加值
    lst1.pop_back();                       //删除末尾值
    lst1.begin();                          //返回首值的迭代器
    lst1.end();                            //返回尾值的迭代器
    lst1.clear();                          //清空值
    bool isEmpty1 = lst1.empty();         //判断为空
    lst1.erase(lst1.begin(), lst1.end());  //删除元素
    lst1.front();                          //返回第一个元素的引用
    lst1.back();                           //返回最后一个元素的引用
    lst1.insert(lst1.begin(), 3, 2);       //从指定位置插入3个值为2的元素
    lst1.rbegin();                         //返回第一个元素的前向指针
    lst1.remove(2);                        //相同的元素全部删除
    lst1.reverse();                        //反转
    lst1.size();                           //含有元素个数
    lst1.sort();                           //排序
    lst1.unique();                         //删除相邻重复元素
    lst1.insert(lst1.end(), 10, 5);
    for (list<int>::const_iterator iter = lst1.begin(); iter != lst1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    const list<int> lst55;
    // list<int>::iterator it1 = lst55.begin();
    list<int>::const_iterator it1 = lst55.begin(); // const容器只能用const_iterator
    it1++; //并且it1可以++
    //*it1 = 10; *it1 为const引用不能修改
    
    const list<int>::iterator it2 = lst1.begin();
    //it2++; 错误，不能修改
    *it2 = 10;

    const list<int>::const_iterator it3 = lst55.begin();
    //it3++; error
    //*it3 = 10; error
    return 0;
}
