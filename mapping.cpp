#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, int>marks;

    marks["Soumyo"]=98;
    marks["Deep"]=100;
    marks["rohan"]=2;
    marks["Urmi"]=91;

    map<string,int> :: iterator it;
    for(it=marks.begin();it!=marks.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    
   return 0;
}