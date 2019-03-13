#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
struct Edge
{
    int to,w,next;
};
Edge e[maxn*2];
int head[maxn];
int cnt=0;
void add(int from ,int to,int w)
{
    e[cnt].to=to;
    e[cnt].w=w;
    e[cnt].w=head[from];
    head[from]=cnt++;
    return ;
}
int vis[maxn];
int dist[maxn];
void prim()
{
    return ;
}