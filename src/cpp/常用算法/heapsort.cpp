#include<iostream>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
template<class T>
class Heap
{
private:
    vector<T> ele;
    int sz;
public:
    Heap(int _num)
    {
        sz=0;
    }
    void push(T x)
    {
        if(sz+1==ele.size())
        {
            ele.resize(sz*2);
        }
        ele[++sz]=x;
        int x=sz;
        while(x>1)
        {
            if(ele[x]<ele[x>>1])
            {
                swap(ele[x],ele[x>>1]);
                x>>=1;
            }
            else
            {
                break;
            }
        }
        return ;
    }
    void pop()
    {
        if(sz==0)
            return ;
        ele[1]=ele[sz];
        sz--;
        int x=1;
        while(x<sz)
        {
            if(ele[x]>ele[x<<1])
            
        }
    }
    T top()
    {
        return ele[1];
    }
    ~Heap()
    {
        delete[] ele;
    }
};
int main()
{

}