#include<bits/stdc++.h>
using namespace std;
void swap(string &str,int a,int b)
{
    char tmp=str[a];
    str[a]=str[b];
    str[b]=tmp;
    return ;
}
void permutation(string str,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<m;i++)
        {
            cout<<str[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=k;i<m;i++)
    {
        swap(str,i,k);
        permutation(str,k+1,m);
        swap(str,i,k);
    }
}
int main()
{
    string a="abc";
    permutation(a,0,a.length());
    return 0;
}