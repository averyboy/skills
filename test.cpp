#include<bits/stdc++.h>
using namespace std;
class Test
{
public:
    Test()
    {
        cout<<"constructor"<<endl;
    }
    ~Test()
    {
        cout<<"decontructor"<<endl;
    }
};
int main()
{
    {
        Test a=Test();
    }
    cout<<"Hello world"<<endl;
    return 0;
}