
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define LL long long int
LL N;
LL arr[100][5];
LL best;
void flip(LL row)
{
    // now how to flip bro :P 
    LL till=row-5;
    if(till<0)
    {
        till=0;
    }
    for(LL i=till ;i<row;i++)
    {
        for(LL j=0;j<5;j++)
        {
            if(arr[i][j]==2)
            {
                arr[i][j]=9;
            }
        }
    }
}
void unflip(LL row)
{
    LL till=row-5;
    if(till<0)
    {
        till=0;
    }
    for(LL i=till ;i<row;i++)
    {
        for(LL j=0;j<5;j++)
        {
            if(arr[i][j]==9)
            {
                arr[i][j]=2;
            }
        }
    }
}
void r( bool bomb ,LL row ,LL col, LL cost)
{
    if(row < 0)
    {
        if(best <  cost)
        {
            best  =  cost;
        }
        return;
    }
    if(col>=5 or col<0)
    {
        return ;
    }
    if( arr [row] [col] == 2)
    {
        if (best < cost)
        {
            best  =  cost;
        }
        return;
    }
    if(arr[row][col] == 1)
    {
        cost+=1;
    }
    if(bomb == false)
    {
        // bomb use kro 
        flip(row);
        r(true,row-1,col,cost);
        r(true,row-1,col+1,cost);
        r(true,row-1,col-1,cost); 
        // bomb use mt kro
        unflip(row);
        r(false,row-1,col,cost);
        r(false,row-1,col+1,cost);
        r(false,row-1,col-1,cost); 
    }
    else
    {
        r(true,row-1,col,cost);
        r(true,row-1,col+1,cost);
        r(true,row-1,col-1,cost); 
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL T;
    cin>> T;
    for(LL k=1;k<=T;k++)
    {
        best=0;
        cin >> N;
        for(LL i=0;i<N;i++)
        {
            for(LL j=0;j<5;j++)
            {
                cin >> arr[i][j];
            }
        }
        flip(N);
        r(true,N-1,2,0);
        r(true,N-1,3,0);
        r(true,N-1,1,0);
        unflip(N);
        r(false,N-1,2,0);
        r(false,N-1,1,0);
        r(false,N-1,3,0);
        cout<<"#"<<k<<" "<<best<<endl;
    }
    
}
