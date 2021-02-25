#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int r(int *arr,int N)
{
    if(N==0)
    {
        return arr[0];
    }
    int final=0;
    for(int i=0;i<=N;i++)
    {
        int ans;
        int temp[N];
        if(i==0)
        {
            ans =  arr[i+1];
            int count=0;
            for(int j=0;j<=N;j++)
            {
                if(j!=i)
                {
                    temp[count++]=arr[j];   
                }
            }
        }
        else if(i==N)
        {
            ans=arr[i-1];
            int count=0;
            for(int j=0;j<=N;j++)
            {
                if(j!=i)
                {
                    temp[count++]=arr[j];   
                }
            }
        }
        else
        {
            ans=arr[i-1]*arr[i+1]; 
            int count=0;
            for(int j=0;j<=N;j++)
            {
                if(j!=i)
                {
                    temp[count++]=arr[j];   
                }
            }
        }
        final=max(final,ans+r(temp,N-1));
    }
    return final;
}
int main() 
{
    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    cout<<r(arr , N-1 ) << endl ;
    // using recursion ha ye toh
}
