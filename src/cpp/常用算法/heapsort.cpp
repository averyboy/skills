#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
struct Heap
{
    int ele[maxn];
    int sz;
    Heap()
    {
        sz=0;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz==0?true:false;
    }
    void push(int v)
    {
        ele[++sz]=v;
        int x=sz;
        while(x>1 && ele[x]<ele[x>>1])
        {
            swap(ele[x],ele[x>>1]);
            x>>=1;
        }
        return ;
    }
    int top()
    {
        return ele[1];
    }
    void pop()
    {
        if(sz==0)
            return ;
        ele[1]=ele[sz--];
        int x=1;
        while(x<sz)
        {   
            int son=x*2;
            if(son>sz)
                break;
            if(son+1<=sz && ele[son]>ele[son+1])
                son+=1;
            if(ele[x]>ele[son])
            {
                swap(ele[x],ele[son]);
                x=son;
            }
            else
            {
                break;
            }
        }
        return ;
    }
};
void heapsort(int *a,int l,int r)
{
    Heap heap;
    for(int i=l;i<r;i++)
    {
        heap.push(a[i]);
    }
    for(int i=l;i<r;i++)
    {
        a[i]=heap.top();
        heap.pop();
    }
    return ;
}
int main()
{
    for(int i=0;i<10;i++)
    {
        a[i]=10-i;
    }
    heapsort(a,0,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}