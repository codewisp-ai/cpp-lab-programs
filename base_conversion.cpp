#include <iostream>
using namespace std;
class a{
    public:
        int x;
        a(int x){
            this->x=x;
        }
};
class b:public a{
    public:
        int y;
        b(int x,int y){
            this->x=x;
            this->y=y;
        }
};
int main(){

}