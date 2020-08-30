#ifndef __COMPONENT__
#define __COMPONENT__
#include <cstdio>
class Component{
    public: virtual void operation()=0;
};
//被装饰类
class Phone: public Component{
    public:
        void operation(){
            printf("手机\n");
        }
};
class Decorator: public Component{
    Component * component;
    public:
        Decorator(Component* c){
            this->component = c;
        }
        void operation(){
            this->component->operation();
        }
        Component* getComponent(){
            return component;
        }
};
class DecoratorShell: public Decorator{
    public:
        DecoratorShell(Component*c):Decorator(c){}
        void operation(){
            this->getComponent()->operation();
            newBehavior();
        }
        void newBehavior(){
            printf("手机壳\n");
        }
};
class DecoratorSticker: public Decorator{
    public:
        DecoratorSticker(Component*c):Decorator(c){}
        void operation(){
            this->getComponent()->operation();
            newBehavior();
        }
        void newBehavior(){
            printf("手机贴纸\n");
        }
};

#endif