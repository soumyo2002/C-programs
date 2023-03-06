/*
//1)
#include<iostream>
using namespace std;

template<class T>

class vector{
    T* arr;
    int size;
    public:
    vector(T m)
    {
        size=m;
        arr=new T[size];
    }
    void input()
    {
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
    }
    T dotproduct(vector &v)
    {
        T dot=0;
        for(int i=0;i<3;i++)
        {
        dot+=this->arr[i]*v.arr[i];
        }
        return(dot);
    }
};
int main(){
    vector <int> v1(3);
    cout<<"Enter 1st vector:"<<endl;
    v1.input();
    vector <int> v2(3);
    cout<<"Enter 2nd vector:"<<endl;
    v2.input();
    int r=v1.dotproduct(v2);
    cout<<"Dot product="<<r;

    vector <float> v3(3);
    cout<<"Enter 1st vector:"<<endl;
    v3.input();
    vector <float> v4(3);
    cout<<"Enter 2nd vector:"<<endl;
    v4.input();
    float r1=v3.dotproduct(v4);
    cout<<"Dot product="<<r1;
   return 0;
}
*/

/*
//2)
#include <iostream>
using namespace std;
template<class T1,class T2>//T1 will be substitue for first datatype
class print
{
    T1 a;
    T2 b;

public:
    print(T1 x, T2 y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << a << " " << b << endl;
    }
};
int main()
{
    print<int,float> ob(7, 7.123456789);
    ob.display();
    print<int,double> ob1(7, 7.123456789);
    ob1.display();
    print<int,char> ob2(7, 'c');
    ob2.display();
    return 0;
}
*/

/*
//3)
#include<iostream>
using namespace std;
template<class T1=int,class T2=float,class T3=char>
class print
{
    T1 a;
    T2 b;
    T3 c;

public:
    print(T1 x=12, T2 y=7.8,T3 z='t')
    {
        a = x;
        b = y;
        c=z;
    }
    void display()
    {
        cout << a << " " << b << " " <<c<<endl;
    }
};
int main()
{
    print<> ob(7, 7.1,'d');
    ob.display();
    cout<<endl;

    print<float,int,float> ob1(9.1,4,5.4);
    ob1.display();
    cout<<endl;

    print<>ob2;
    ob2.display();
    cout<<endl;

    return 0;
}
*/

/*
//4)
#include<iostream>
using namespace std;
template<class T1=int,class T2=float,class T3=char>
class print
{
    T1 a;
    T2 b;
    T3 c;

public:
    print(T1 x=12, T2 y=7.8,T3 z='t')
    {
        a = x;
        b = y;
        c=z;
    }
    void display()
    {
        cout << a << " " << b << " " <<c<<endl;
    }
};
int main()
{
    print<> ob(7, 7.1,'d');
    ob.display();
    cout<<endl;

    print<float,int,float> ob1(9.1,4,5.4);
    ob1.display();
    cout<<endl;

    print<>ob2;
    ob2.display();
    cout<<endl;

    return 0;
}
*/

// 5)
// Vector

#include <iostream>
#include<vector>
using namespace std;

template <class T>

void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    char ch;
    int ele;
    vector<int> v;
    while (ch != 'N')
    {
        cout << "Enter Y to enter vector elements,D to display and press N to terminate:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 'Y':
            cout << "Enter data:" << endl;
            cin >> ele;
            v.push_back(ele);
            break;

        case 'D':
            display(v);
            break;

        case 'N':
            exit(1);

        default:
            cout << "Wrong choice!Try again!" << endl;
        }
    }
    return 0;
}