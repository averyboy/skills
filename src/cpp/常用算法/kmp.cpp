#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int Next[maxn];
char p[maxn],t[maxn];
void getNext(char *p)
{
    Next[0]=0;
    int k=0;
    for(int i=1;p[i];i++)
    {
        while(k && p[i]!=p[k])
            k=Next[k-1];
        if(p[i]==p[k])
            k++;
        Next[i]=k;
    }
    return ;
}
int kmp(char *p,char *t)
{
    int k=0,cnt=0;
    int len=strlen(p);
    for(int i=0;t[i];i++)
    {
        while(k && p[k]!=t[i])
            k=Next[k-1];
        if(p[k]==t[i])
            k++;
        if(k==len)
        {
            cnt++;
            k=0;//不重复
            //k=Next[k-1];//可重复
        }
    }   
    return cnt;
}
int main()
{
    //char t[]="hello world hell wo hello";
    //char p[]="hell";
    char t[]="aabaabaaba";
    char p[]="aaba";
    getNext(p);
    cout<<kmp(p,t)<<endl;
    return 0;
}