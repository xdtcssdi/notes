#ifndef __SINGLETON__
#define __SINGLETON__
#include <iostream>

class Singleton{
    private:
        Singleton(){}
        static Singleton * obj;
    public:
        static Singleton* getInstance(){
            if(obj == nullptr){
                printf("创建单例\n");
                obj = new Singleton();
            }
            return obj;
        }
};
Singleton* Singleton::obj = nullptr;
#endif