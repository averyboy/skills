#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int tree[maxn<<2];
int lazy[maxn<<2];
void pushdown(int root,int l,int r)
{
    return ;
}
void pushup(int root)
{
    tree[root]=tree[root<<1]+tree[root<<1|1];
    return ;
}
void build(int root,int l,int r)
{
    if(l==r)
    {
        scanf("%d",tree+root);
        return ;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    pushup(root);
}
void update(int root,int l,int r,int pos,int v)
{
    if(l==r)
    {
        tree[root]=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(root<<1,l,mid,pos,v);
    else
        update(root<<1|1,mid+1,r,pos,v);
    pushup(root);
}
int query(int root,int l,int r,int L,int R)
{
    if(L<=l && R>=r)
    {
        return tree[root];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(L<=mid)
        ans+=query(root<<1,l,mid,L,R);
    if(R>mid)
        ans+=query(root<<1|1,mid+1,r,L,R);
    return ans;
}
int main()
{

}