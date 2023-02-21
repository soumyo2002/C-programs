#include<iostream>
#include<list>
using namespace std;

void display(list<int> &l)
{
    list<int> :: iterator it;
    for(it=l.begin();it!=l.end();it++)
    {
        cout<<*(it)<<endl;
    }
    cout<<endl;
}

int main(){
    list<int>list1;
    list<int>list2;
    int a,c,b=0;
    cout<<"Enter two values,first enter 0(to enter value) and -1(to discontinue insertion) and second value enter the data to be inserted:"<<endl;
    while(b!=-1)
    {
    cout<<"Enter the first value:"<<endl;
    cin>>b;
    if(b==(-1))
    {
        break;
    }
    cout<<"Enter second values:"<<endl;
    cin>>a>>c;
    list1.push_back(a);
    list2.push_back(c);
    }
    display(list1);
    display(list2);
    list1.pop_back();
    list1.pop_front();
    list1.remove(1);
    display(list1);
    list1.merge(list2);
    display(list1);
   return 0;
}