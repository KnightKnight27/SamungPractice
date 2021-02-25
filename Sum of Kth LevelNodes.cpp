#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int K;
    cin >> K;
    string S;
    cin >> S;
    int ans=0;
    int count=0;
    int i=0;
    int z=S.size();
    while( i < z )
    {
        char it=S[i];
        if(it== '(')
        {   
            count++;
            i++;
        }
        else if(it==')')
        {
          count--;  
          i++;
        }
        else
        {
              if(count == K+1)
              {
                  string temp="";
                  while(i<z && S[i]!='(' && S[i]!=')')
                  {
                      temp+=S[i];
                      i++;
                  }
                  int N= temp.size();
                  int x=1;
                  for(int j=N-1;j>=0;j--)
                  {
                      ans=ans +  x * (temp[j]-'0');
                      x=x*10;
                  }
              }
              else
              {
                    i++;
              }
            
        }
    }
    cout<<ans;
}
