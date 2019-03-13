#include<bits/stdc++.h>
using namespace std;
void add(int &a)
{
    a+=10;
    return ;
}
int main()
{
    vector<int> vec;
    for(int i=0;i<10;i++)
    {
        vec.push_back(i);
    }
    for(auto &i:vec)
    {
        cout<<i<<endl;
    }
    for_each(vec.begin(),vec.end(),add);
    for(auto &i:vec)
    {
        cout<<i<<endl;
    }
    return 0;
}