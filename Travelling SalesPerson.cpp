
// WITHOUT STL :p :p
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100][100];
int N;
int best;
bool vis[100];
void TSP(int vertex,int count,int cost)
{
    if(count==N)
    {
        cost=cost + arr[vertex][0];
        if(cost  <  best)
        {
            best=cost;
        }
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(i !=vertex and vis[i]==false)
        {
            vis[i]=true;
            TSP(i, count+1, cost + arr[vertex][i]  );
            vis[i]=false;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        best=100000;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin >> arr[i][j];
            }
        }
        
        for(int i=0;i<N;i++)
        {
            vis[i]=false;
        }
        vis[0]=true;
        TSP(0,1,0);
        cout<<best<<endl;
    }
}
