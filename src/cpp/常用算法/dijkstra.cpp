#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
struct Edge
{
    int to;
    int w;
    int next;
};
Edge e[maxn*2];
int head[maxn];
int cnt=0;
void add(int from,int to,int w)
{
    e[cnt].to=to;
    e[cnt].w=w;
    e[cnt].next=head[from];
    head[from]=cnt++;
}

bool vis[maxn];
int dist[maxn];
void dijkstra(int u)
{
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(false));
    for(int i=head[u];~i;i=e[i].next)
    {
        dist[e[i].to]=e[i].w;
    }
    dist[u]=0;
    vis[u]=true;
    while(true)
    {
        int v=-1;
        for(int i=0;i<n;i++)
        {
            if((v==-1 || dist[i]<dist[v]) && !vis[i])
                v=i;
        }
        if(v==-1)
            break;
        vis[v]=true;
        for(int i=head[v];~i;i=e[i].next)
        {
            dist[e[i].to]=min(dist[e[i].to],dist[v]+e[i].w);
        }
    }
}

int main()
{
    int k;
    int u,v,w;
    while(~scanf("%d%d",&n,&k))
    {
        memset(head,-1,sizeof(head));
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        dijkstra(0);
        for(int i=0;i<n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// test input
// 5 5
// 0 1 2
// 0 2 1
// 1 3 5
// 0 4 8
// 2 3 2
//test output
//0 2 1 3 8