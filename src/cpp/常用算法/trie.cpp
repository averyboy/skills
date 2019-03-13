#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie* next[26];
    int cnt;
    Trie()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        cnt=0;
    }
};
Trie* root;
void insert(Trie* root,char *str)
{
    Trie* p=root;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        if(p->next[num]==NULL)
        {
            p->next[num]=new Trie();
        }
        p=p->next[num];
        p->cnt++;
    }
    return ;
}
int query(Trie* root,char* str)
{
    Trie *p=root;
    for(int i=0;str[i];i++)
    {
        int num=str[i]-'a';
        if(p->next[num]==NULL)
        {
            return 0;
        }
        else
        {
            p=p->next[num];
        }
    }
    return p->cnt;
}

int main()
{
    root=new Trie();
    insert(root,(char*)"abcdef");
    insert(root,(char*)"helloworld");
    insert(root,(char*)"helloworl");
    insert(root,(char*)"whatfuck");
    insert(root,(char*)"averyboy");
    insert(root,(char*)"averyboy");
    cout<<query(root,(char*)"helloworl")<<endl;
    cout<<query(root,(char*)"averyboy")<<endl;
    cout<<query(root,(char*)"whatfuck")<<endl;
    cout<<query(root,(char*)"b")<<endl;
    return 0;
}