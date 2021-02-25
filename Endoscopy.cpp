
// WITHOUT STL :p
#include<iostream>
using namespace std;
int arr[2001][2001];
int vis[2001][2001];
int N,M;
struct Node
{
    int x;
    int y;
    int count;
};
Node Q[2000000];
int front;
int rear;
void dfs(int x,int y,int L)
{
    Node temp;
    temp.x=x;
    temp.y=y;
    temp.count=L;
    Q[front--]=(temp);
}
int main()
{
    int T;
    cin  >> T;
    while(T--)
    {
        // without stl krna ha ab toh :(
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                vis[i][j]=false;
        cin >>  N >>  M;
        int    sx    , sy;
        cin >> sx  >>  sy;
        int L;   cin >> L;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin >> arr[i][j];
            }
        }
        if(arr[sx][sy]== 0)
        {
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        front = 1000000;
        rear =  1000000;
        Node temp;
        temp.x=sx;
        temp.y=sy;
        temp.count=L;
        Q [front--] = temp;
        while(front != rear )
        {
            Node temp= Q[rear];
            rear--;
            int x= temp.x;
            int y= temp.y;
            L= temp.count;
            if(vis[x][y] || L==0)
            {
                continue;
            }
            vis[x][y]=true;
            if(arr[x][y]==1)
            {
                // 4 cases ha iske
                if(( x+1 < N)   &&  (arr[x+1][y] == 7 || arr[x+1][y]==4 || arr[x+1][y]==1 || arr[x+1][y]==2 ) )
                {
                    if(vis[x+1][y]==false)
                    {
                        dfs(x+1,y,L-1);
                    }
                }
                if((x-1 >=0) &&  ( arr[x-1][y]==6 || arr[x-1][y] ==5 || arr[x-1][y] == 2 || arr[x-1][y]==1  ))
                {
                    if(vis[x-1][y]==false)
                    {
                        dfs(x-1,y,L-1);
                    }
                }
                if( (y+1 < M )  && (arr[x][y+1]==7 || arr[x][y+1] ==6 || arr[x][y+1] == 3 || arr[x][y+1]==1  ))
                {
                    if(vis[x][y+1]==false)
                    {
                        dfs(x,y+1,L-1);
                    }
                }
                if( (y-1 >= 0) && (arr[x][y-1] == 5 || arr[x][y-1] ==4 || arr[x][y-1] == 3 || arr[x][y-1]==1  ))
                {
                    if(vis[x][y-1]==false)
                    {
                        dfs(x,y-1,L-1);
                    }
                }
                 
            }
            if(arr[x][y]==2)
            {
                if(( x+1 < N)   &&  (arr[x+1][y] == 7 || arr[x+1][y]==4 || arr[x+1][y]==1 || arr[x+1][y]==2 ) )
                {
                    if(vis[x+1][y]==false)
                    {
                        dfs(x+1,y,L-1);
                    }
                }
                if((x-1 >=0) &&  ( arr[x-1][y]==6 || arr[x-1][y] ==5 || arr[x-1][y] == 2 || arr[x-1][y]==1  ))
                {
                    if(vis[x-1][y]==false)
                    {
                        dfs(x-1,y,L-1);
                    }
                }
            }
            if(arr[x][y]==3)
            {
                if( (y+1 < M )  && (arr[x][y+1]==7 || arr[x][y+1] ==6 || arr[x][y+1] == 3 || arr[x][y+1]==1  ))
                {
                    if(vis[x][y+1]==false)
                    {
                        dfs(x,y+1,L-1);
                    }
                }
                if( (y-1 >= 0) && (arr[x][y-1] == 5 || arr[x][y-1] ==4 || arr[x][y-1] == 3 || arr[x][y-1]==1  ))
                {
                    if(vis[x][y-1]==false)
                    {
                        dfs(x,y-1,L-1);
                    }
                }    
            }
            if(arr[x][y]==4)
            {
                 if( (y+1 < M )  && (arr[x][y+1]==7 || arr[x][y+1] ==6 || arr[x][y+1] == 3 || arr[x][y+1]==1  ))
                {
                    if(vis[x][y+1]==false)
                    {
                        dfs(x,y+1,L-1);
                    }
                }
                if((x-1 >=0) &&  ( arr[x-1][y]==6 || arr[x-1][y] ==5 || arr[x-1][y] == 2 || arr[x-1][y]==1  ))
                {
                    if(vis[x-1][y]==false)
                    {
                        dfs(x-1,y,L-1);
                    }
                }
                
            }
            if(arr[x][y]==5)
            {
                if(( x+1 < N)   &&  (arr[x+1][y] == 7 || arr[x+1][y]==4 || arr[x+1][y]==1 || arr[x+1][y]==2 ) )
                {
                    if(vis[x+1][y]==false)
                    {
                        dfs(x+1,y,L-1);
                    }
                }
                if( (y+1 < M )  && (arr[x][y+1]==7 || arr[x][y+1] ==6 || arr[x][y+1] == 3 || arr[x][y+1]==1  ))
                {
                    if(vis[x][y+1]==false)
                    {
                        dfs(x,y+1,L-1);
                    }
                }
                
            }
            if(arr[x][y]==6)
            {
                if( (y-1 >= 0) && (arr[x][y-1] == 5 || arr[x][y-1] ==4 || arr[x][y-1] == 3 || arr[x][y-1]==1  ))
                {
                    if(vis[x][y-1]==false)
                    {
                        dfs(x,y-1,L-1);
                    }
                } 
                if(( x+1 < N)   &&  (arr[x+1][y] == 7 || arr[x+1][y]==4 || arr[x+1][y]==1 || arr[x+1][y]==2 ) )
                {
                    if(vis[x+1][y]==false)
                    {
                        dfs(x+1,y,L-1);
                    }
                }
            }
            if(arr[x][y]==7)
            {
                if( (y-1 >= 0) && (arr[x][y-1] == 5 || arr[x][y-1] ==4 || arr[x][y-1] == 3 || arr[x][y-1]==1  ))
                {
                    if(vis[x][y-1]==false)
                    {
                        dfs(x,y-1,L-1);
                    }
                } 
                if((x-1 >=0) &&  ( arr[x-1][y]==6 || arr[x-1][y] ==5 || arr[x-1][y] == 2 || arr[x-1][y]==1  ))
                {
                    if(vis[x-1][y]==false)
                    {
                        dfs(x-1,y,L-1);
                    }
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(vis[i][j])
                    cnt++;
            }
        }
        cout<<cnt<<endl;
        
    }
}
