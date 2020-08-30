#ifndef __HOUSE__
#define __HOUSE__
#include <string>
#include <iostream>
using std::string;
class House{
    string floor;
    string wall;
    string roof;
    public:
        void setFloor(string floor){
            this->floor = floor;
        }
        void setWall(string wall){
            this->wall = wall;
        }
        void setRoof(string roof){
            this->roof = roof;
        }
        void print(){
            std::cout<<floor<<" "<< wall<<" "<<roof<<std::endl;
        }
};
#endif