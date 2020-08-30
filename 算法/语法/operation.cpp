#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
        char *s;
    public:
        String():s(new char[100]){}
        String(const char*s){
            this->s = new char[strlen(s)+1];
            strcpy(this->s, s);
        }
        String(const String& str){
            if (s != str.s){
                s = new char[str.getLength()+1];
                strcpy(s, str.s);
            }
        }
        String& operator = (const String& str){
            if (s == str.s)
                return *this;
            if (getLength()< str.getLength()){
                delete[] s;
                s = new char[str.getLength()+1];
            }
            strcpy(s, str.s);
            return *this;
        }
        ~String(){
            delete[] s;// 简单类型 delete s; 都对
        }
        const char* get_c_str(){
            return s;
        }
        String& operator+(const String& str){
            size_t length1 = strlen(s);
            size_t length2 = strlen(str.s);
            char *tmp = new char[length1 + length2+1];
            strcpy(tmp, s);
            free(s);
            strcpy(tmp+length1, str.s);
            s = tmp;
            return *this;
        }
        const size_t getLength() const{
            return strlen(s);
        }
        char operator[](const int i){
            if(i<getLength())
                return s[i];
            return '\0';
        }
        friend ostream& operator << (ostream& out,String& s);
        friend istream& operator >> (istream& in ,String& s);
};
ostream& operator << (ostream& out,String& str){
    out << str.s;
    return out;
}
istream& operator >> (istream& in ,String& str){
    in >> str.s;
    return in;
}

int main(int argc, char const *argv[])
{
    String ss = "DSADA";
    cout << ss << endl;
    String copy = ss;
    cout << copy << endl;
    String s1 = "World ";
    copy = s1;
    cout << copy << endl;
    return 0;
}
