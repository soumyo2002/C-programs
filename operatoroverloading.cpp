#include <iostream>
using namespace std;
class Num
{
public:
    int x, y;
    Num()
    {
        x = 0;
        y = 0;
    }
    Num(int j, int k)
    {
        x = j;
        y = k;
    }
    Num operator +(Num ob)
    {
        Num result;
        result.x=x+ob.x;
        result.y=y+ob.y;
        return result;
    }
    void show()
    {
        cout<<x<<" "<<y;
    }
};
main()
{
    Num ob1(2,3);
    Num ob2(4,5);
    Num ob3;
    ob3=ob1+ob2;
    ob3.show();
}