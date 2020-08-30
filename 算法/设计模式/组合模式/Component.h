#ifndef __COMPONENT__
#define __COMPONENT__
#include <string>
#include <vector>
using namespace std;
class Component{
    private:
        string name;
    public:
        Component(string name):name(name){}
        virtual void add(Component*)=0;
        virtual void remove(Component*)=0;
        virtual Component* getChild(int i)=0;
        virtual void operation()=0;
        string getName(){
            return name;
        }
};

class Leaf: public Component{
    void add(Component*){cout<<"No Support."<<endl;}
    void remove(Component*){cout<<"No Support."<<endl;}
    Component* getChild(int i){cout<<"No Support."<<endl;return nullptr;}
    void operation(){
        cout<< getName()<<endl;
    }
    public:
        Leaf(string name):Component(name){}
};

class SubComponent: public Component{
    vector<Component*> v;

    void add(Component*c){v.push_back(c);}
    void remove(Component*){v.clear();}
    Component* getChild(int i){return v[i];}
    void operation(){
        cout<<"-----"<< getName()<<"-----" <<endl;
        for (auto item:v){
            item->operation();
        }
    }
    public:
        SubComponent(string name):Component(name){}
};
#endif