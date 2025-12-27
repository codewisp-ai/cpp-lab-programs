#include <iostream>
using namespace std;

class shape{
public:
    int r; //radius
     virtual void volume()=0;
     virtual void area()=0;
     virtual void perimeter()=0;
     virtual void display(){
        cout<<"inside abstract class";
     }
     virtual ~shape() {}

};
class circle:public shape{
    public:
    circle(int r){
        this->r=r;
    }
    void perimeter () override {
        cout<< 2*3.14*r<<endl;
    }
    void area() override{
        cout<<3.14*r*r<<endl;
    }
    void volume(){
        cout<<"not applicable fior circle";
    }

};

class sphere:public shape{
    public:
        sphere(int r){
            this->r=r;
        }
        void area() override{
            cout<<4*3.14*r*r<<endl;
        }
        void volume() override{
            cout<<4.0/3.0*3.14*r*r*r<<endl;
        }
        void perimeter() override{
            cout<<"not applicable for sphere";
        }

};
int main(){
    shape* s1;
    shape* s2;
    circle c1(1);
    sphere s(1);
    s1=&c1;
    s2=&s;
    s1->area();
    s2->volume();
    s2->perimeter();
    

}