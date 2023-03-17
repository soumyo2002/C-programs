//Welcome to a complete Tutorial of Vectors.

#include<iostream>
//Header file to include Vector
#include<vector>
using namespace std;

//template<class T>//Using Template for generic programming

int main(){
    cout<<"Welcome to a complete Tutorial of Vectors:"<<endl<<"First lets learn ways to create vector:"<<endl<<endl<<"First lets create an Empty vector"<<endl;

    //First lets learn ways to create vector:
    //First lets create an Empty vector
    vector<int>a;
    cout<<"Size of the empty vector found using .size() function is "<<a.size()<<endl<<endl;


    //Next lets create an Empty vector of size 3
    cout<<"Next lets create an Empty vector of size 3"<<endl;
    vector<float>b(3);
    cout<<"Size of the empty vector found using .size() function is "<<b.size()<<endl;
    cout<<"Contents of vector using [] operator:"<<b[0]<<b[1]<<b[2]<<endl<<endl;


    //Next lets create a vector of size 3 all containing value 6
    cout<<"Next lets create a vector of size 3 all containing value 6"<<endl;
    vector<int>c(3,6);
    cout<<"Size of the vector found using .size() function is "<<c.size()<<endl;
    cout<<"Contents of vector using [] operator:"<<c[0]<<c[1]<<c[2]<<endl<<endl;


    //lets copy the previous vector in a new vector
    cout<<"lets copy the previous vector in a new vector using vector<int>vec(vec1):"<<endl;
    vector<int>d(c);
    cout<<"Size of the copied vector found using .size() function is "<<d.size()<<endl;
    cout<<"Contents of vector using [] operator:"<<d[0]<<d[1]<<d[2]<<endl<<endl;


    //lets create first vector of integer type,alloted size of 5
    vector<int>v(5);
    int ele;
    //Another type of float type.Thanks to Template
    vector<float>v1;
    cout<<"lets create first vector of integer type,alloted size of 5 and Another type of float type.Thanks to Template"<<endl;
    cout<<"Enter values into the first vector:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>v[i];
    }
    cout<<"Displaying the values using []:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"Enter 3 values into the second vector:Note that we will use .push_back() to accept values here"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>ele;
        v1.push_back(ele);
    }
    cout<<"Displaying the values using .size() to terminate and [] to print:"<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<endl;
    }


    //Next lesson is to find current size,maximum size and storage space alloted to a vector using size,max_size and capacity functions
    cout<<"Next lesson is to find current size,maximum size and storage space alloted to a vector using size,max_size and capacity functions"<<endl;
    cout<<"Size of the previous vector:"<<v1.size()<<endl;
    cout<<"Maximum Size of a vector:"<<v1.max_size()<<endl;
    cout<<"storage alloted to the vector:"<<v1.capacity()<<endl<<endl;


    //Next we will learn how to find value at a particular place using .at
    cout<<"Next we will learn how to find value at a particular place using .at() function"<<endl;
    cout<<"Lets find 2nd element in previous vector"<<endl;
    cout<<"ELement at 2nd position:"<<v1.at(2)<<endl<<endl;


    //Next lesson is to find the first and last value of a vector using .front and .back()
    cout<<"Next lesson is to find the first and last value of a vector using .front and .back()"<<endl;
    cout<<"Value at front="<<v1.front()<<endl;
    cout<<"Value at back="<<v1.back()<<endl<<endl;

    //Now lets resize the last vector to size 4
    cout<<"Now lets resize the last vector to size 4"<<endl;
    v1.resize(4);
    cout<<"Entering the 4th value as 100"<<endl;
    v1.at(3)=100;
    cout<<"Update vector:"<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<endl;
    }
    cout<<endl;

    //Now lets delete last element
    cout<<"Now lets delete last element from previous array"<<endl;
    v1.pop_back();
    cout<<"Updated vector after using pop_back()"<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<endl;
    }
    cout<<"Notice how last element is deleted using pop_back()"<<endl<<endl;

    //Next lets clear the prev vector and use it again using .clear() function
    cout<<"Next lets clear the prev vector and use it again using .clear() function"<<endl;
    v1.clear();
    //lets check if the prev vector is empty or not using .empty() function
    if(!v1.empty())
    cout<<"Vector is not empty"<<endl;
    else
    cout<<"Vector is empty"<<endl;
    cout<<"Enter new values:"<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>v1[i];
    }
    cout<<"Updated vector"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<v1[i];
    }
    cout<<endl<<endl;


    //Next lesson is to swap 2 vectors using vec1.swap(vec2)
    cout<<"Next lesson is to swap 2 vectors using vec1.swap(vec2)"<<endl;
    vector<int> foo (3,100);   // three ints with a value of 100
    cout<<"Vector foo before swap"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<foo[i];
    }
    cout<<endl<<"Vector bar before swap"<<endl;
    vector<int> bar (5,200);   // five ints with a value of 200
    for(int i=0;i<5;i++)
    {
        cout<<bar[i];
    }

    foo.swap(bar);
    cout<<endl<<"Vector foo after swap"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<foo[i];
    }
    cout<<endl<<"Vector bar after swap"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<bar[i];
    }
    cout<<endl<<endl;

   return 0;
}