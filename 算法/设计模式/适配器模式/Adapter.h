#ifndef __ADAPTER__
#define __ADAPTER__

class PowerTarget{
    public:
        virtual int out5v()=0;
};

class Adaptee{
    private:
        int output;
    public:
        Adaptee():output(220){}
        int output220v(){
            return output;
        }
};

class Adapter: Adaptee,public PowerTarget{
    int out5v(){
        return output220v()/44;
    }
};

#endif