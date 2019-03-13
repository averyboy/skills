#include<iostream>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
void quickSort(int *a,int l,int r)
{
    if(l>=r)
        return ;
    int i=l,j=r;
    int x=a[l];
    while(i<j)
    {
        while(i<j && a[j]>=x)
            j--;
        a[i]=a[j];
        while(i<j && a[i]<x)
            i++;
        a[j]=a[i];
    }
    a[i]=x;
    quickSort(a,l,i-1);
    quickSort(a,i+1,r);
}
int main()
{
    for(int i=0;i<10;i++)
    {
        a[i]=10-i;
    }
    quickSort(a,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}