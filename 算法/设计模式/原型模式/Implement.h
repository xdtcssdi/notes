#ifndef __IMPLEMENT__
#define __IMPLEMENT__
#include "proto.h"
#include <cstdio>
#include <cstring>
class Concrete: public ProtoType{
    char* work;
    int id;
    char* name;
    
    public:
        Concrete(){
            name = new char[30];
            work = new char[100];
        }
        void setName(const char* s){
            strcpy(name, s);
        }
        void setId(const int id){
            this->id = id;
        }
        void setWork(const char*s){
            strcpy(work, s);
        }
        void print(){
            printf("%d %s %s\n", id, name, work);
        }
        Concrete * clone(){
            Concrete* type = new Concrete();
            type->setName(name);
            type->setWork(work);
            type->setId(id);
            return type;
        }
};

#endif