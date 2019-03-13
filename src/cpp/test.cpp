#include<bits/stdc++.h>
#include<typeinfo>
#include<memory>
using namespace std;
void test(int a)
{
    cout<<"INT "<<a<<endl;
    return ;
}
void test(double a)
{
    cout<<"DOUBLE "<<a<<endl;
}

int main()
{
    auto a=10;
    auto b=11.4;
    auto c=string("Hello World!");
    cout<<a<<" "<<b<<" "<<c<<endl;
    shared_ptr<int> p=make_shared<int>(42);
    cout<<"智能指针p："<<*p<<endl;
    test(0);
    test(1.344);
    return 0;
}