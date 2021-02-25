
// too lazy to write merge sort on own try doing it on your own rest is without STL :P
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node 
{
    Node* next;
    int   data;
};
Node* adj[10000];
void insert ( int i,int y)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=y;
    temp->next=adj[i];
    adj[i]=temp;
}
// void merge(int start,int mid,int end)
// {
    
// }
// void mergeSort(int start,int end)
// {
//     if(start<end)
//     {
//         mergeSort(start,mid);
//         mergeSort(mid+1,end);
//         merge(start,mid,end);
//     }
// }
int f=0;
bool vis[10000];
bool has[10000];
int  tmp[100000];
int index=0;
int finalans[10000];
int best=1000000000;
bool dfs(int src)
{
    if(vis[src]==false)
    {
        tmp[index++]=src;
        vis[src]=true;
        has[src]=true;
        Node *temp=adj[src];
        while(temp)
        {
            int it=temp->data;
            if(has[it]==true)
            {
                int s=it;
                for(int i=index-1;i>=0;i--)
                {
                    if(tmp[i]!= it )
                    {
                         s= s + tmp[i];
                    }
                    else
                        break;
                }
                if(s   <  best)
                {
                    best =  s;
                }
                return true;
            }
            if(vis[it]==false)
            {
                return dfs(it);
            }
            temp=temp->next;
        }
        has[src]=false;
        return false;
    }
    return false;
}
bool dfs2(int src)
{
    if(vis[src]==false)
    {
        tmp[index++]=src;
        vis[src]=true;
        has[src]=true;
        Node *temp=adj[src];
        while(temp)
        {
            int it=temp->data;
            if(has[it]==true)
            {
                int s=it;
                for(int i=index-1;i>=0;i--)
                {
                    if(tmp[i]!= it )
                    {
                         s= s + tmp[i];
                    }
                    else
                        break;
                }
                if(s  == best)
                {
                    for(int i=index-1;i>=0;i--)
                    {
    
                        if(it!= tmp [i])
                        {
                            finalans[f++]=tmp[i];
                        }
                        else
                        {
                            finalans[f++]=it;
                            break;
                        }
                    }
                    // ans me bharle bhai
                }
                return true;
            }
            if(vis[it]==false)
            {
                return dfs2(it);
            }
            temp=temp->next;
        }
        has[src]=false;
        return false;
    }
    return false;
}
int main() 
{
    
    int   N,M;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        vis[i]=false;
        has[i]=false; 
    }
    for(int i=1;i<=N;i++)
    {
        adj[i]=NULL;
    }
    for(int i=0;i<M;i++)
    {
        int  x  , y;
        cin >> x >> y;
        insert (x , y);
    }
    bool ok=false;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==false)
        {
           ok= ok | dfs(i);
        }
    }
    for(int i=1;i<=N;i++)
    {
        vis[i]=false;
        has[i]=false; 
    }
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==false)
        {
           ok= ok | dfs2(i);
        }
    }
    sort(finalans,finalans+f);
    // final ans and size f
    for(int i=0;i<f;i++)
        cout<<finalans[i]<<" ";
    cout<<endl;
    
}
