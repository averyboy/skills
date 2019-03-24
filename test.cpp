#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int a=10;
    int &p=static_cast<int&>(a);
    p=100;
    cout<<p<<" "<<a<<endl;
    return 0;
}