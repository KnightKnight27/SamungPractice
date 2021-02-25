// without STL
#include<bits/stdc++.h>
using namespace std;
int N,M;
int arr[20][20];
int best=0;
void flip(int col)
{
    for(int i=0;i<N;i++)
    {
        arr[i][col]=arr[i][col]^1;
    }
}
void r(int K)
{

    if(K == 0)
    {
        int coun=0;
        for(int i=0;i<N;i++)
        {
            bool ok=true;
            for(int j=0;j<M;j++)
            {
                if(arr[i][j]==0)
                {
                    ok=false;
                    break;
                }   
            }
            if(ok)
            {
                coun++;
            }
        }
        if (coun > best)
        {
            best=coun;
        }
        return ;
    }
    for(int i=0;i<M;i++)
    {
        flip(i);
        r( K- 1);
        flip(i);
    }
}
int main()
{
 
    int K;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
    r(K);
    cout<<best<<endl;
   
}
