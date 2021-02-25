#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int x,y;
};
int N;
bool vis[1000];
Node arr[1000];
int dist(Node A,Node B)
{
    int x1=A.x-B.x;
    if(x1<0)
    {
        x1= -x1;
    }
    int y1=A.y-B.y;
    if(y1< 0)
    {
        y1 = -y1;
    }
    return x1+y1;
}
int r(Node src,Node dest)
{
    if( src.x == dest.x and src.y == dest.y)
    {
        return 0;
    }
    int ans=10000000;
    bool ok=false;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==false)
        {
            ok=true;
            vis[i]=true;
            ans=min(ans , dist(src,arr[i]) +r(arr[i],dest));
            vis[i]=false;
        }
    }
    if(!ok)
    {
        ans= dist(src,dest);
    }
    return ans;
}
int main()
{
    for(int i=1;i<=10;i++)
    {
        cin >> N;
        for(int j=1;j<=N;j++)
        {
            vis[i]=false;
        }
        int x,y;
        cin >> x >> y;
        Node src;
        src.x=x;
        src.y=y;
        cin >> x >> y;
        Node dest;
        dest.x=x;
        dest.y=y;
        for(int j=1;j<=N;j++)
        {
            cin >> x >> y;   
            Node temp;
            temp.x=x;
            temp.y=y;
            arr[j]=temp;
        }
        // destination source aa gye bhai
        cout<<"# "<<i<<" "<<r(src,dest) << endl;
    }
}
