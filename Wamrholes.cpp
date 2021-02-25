// without stl using floyd warshal maybe you can optimize with djikstra

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define LL long long int
struct Node
{
    LL x,y;
};
Node arr[100];
LL distance(Node A,Node B)
{
    LL x= A.x-B.x;
    LL y= A.y-B.y;
    if(x<0)
        x = -x;
    if(y<0)
        y= -y;
    return  x+y;
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL T;
    cin>> T;
    while(T--)
    {
        LL N;
        cin >> N;
        LL dist[101][101];
        for(LL i=0;i<=100;i++)
        {
            for(LL j=0;j<=100;j++)
            {
                dist[i][j]=1000000000;
            }
        }
        LL sx,sy;
        cin >> sx >> sy;
        LL dx,dy;
        cin >> dx >> dy;
        Node temp;
        temp.x=sx;
        temp.y=sy;
        arr[0]=temp;
        temp.x=dx;
        temp.y=dy;
        // temp jayega abb last mei
        LL count=1;
        for(LL i=1;i<=N;i++)
        {
            LL x1,y1,x2,y2;
            cin >> x1 >> y1 >>  x2 >> y2;
            LL w;
            cin >> w;
            Node first;
            first.x=x1;
            first.y=y1;
            Node second;
            second.x=x2;
            second.y=y2;
            arr[count]=first;
            arr[count+1]=second;
            dist[count][count+1]=w;
            dist[count+1][count]=w;
            count+=2;
        }
        arr[count]=temp;
        N=count;
        for(LL i=0;i<=N;i++)
        {
            for(LL j=0;j<=N;j++)
            {
                LL x=distance(arr[i],arr[j]);
                if(x < dist[i][j])
                {
                    dist[i][j]=x;

                }
            }
        }
        // floyd warshall now
        for(LL i=0;i<=N;i++)
        {
            for(LL j=0;j<=N;j++)
            {
                for(LL k=0;k<=N;k++)
                {
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        cout<<dist[0][N]<<endl;
    }
    
}
