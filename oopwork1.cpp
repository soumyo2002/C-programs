#include<iostream>
#include<string>
using namespace std;
class S
{
    string *str,*str1;
    public:
    S()
    {
        str=new string();
        *str="20051110";
        str1=new string();
        *str1="Soumyo";
    }
    void join()
    {
        str=str+str1;
        cout<<"New string:"<<str;
    }
};
int main()
{
    S ob;
    ob.join();
    return 0;
}