//WAP to declare a friend function in two classes to calculate the sum of integers of both the classes.
#include<iostream>
using namespace std;
class B;
class A
{
    int x;
    public:
    void input(int p)
    {
        x=p;
        cout<<"1st number ="<<x<<endl;
    }
    friend void add(A& ,B&);
};
class B
{
    int y;
    public:
    void input(int q)
    {
        y=q;
        cout<<"2nd number ="<<y<<endl;
    }
    friend void add(A& ,B&);
};
void add(A&m,B&n)
{
    cout<<"Sum of the two numbers="<<m.x+n.y<<endl;
}
int main()
{
    A ob1;
    B ob2;
    ob1.input(24);
    ob2.input(126);
    add(ob1,ob2);
    return 0;
}