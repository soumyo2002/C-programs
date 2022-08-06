#include <iostream>
using namespace std;
struct Name
{
    char name[6];

public:
    void input(char ptr[])
    {
        for (int i = 0; i < 6; i++)
        {
            name[i] = ptr[i];
        }
    }
    void output()
    {
        for (int i = 0; i < 6; i++)
        {
            cout << name[i];
        }
    }
};
int main()
{
    char name[6];
    cout << "Enter \n";
    cin >> name;
    Name ob;
    ob.input(name);
    ob.output();
    return 0;
}