#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t=0,n,p=0;
    cin>>n>>m;
    int s[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>s[i];
    }
    n=s[0];
    for(int i=0;i<n*m;i++)
    {
        if(s[i+1]>s[i])
        {
            t=s[i];
            s[i]=s[i+1];
            s[i+1]=t;
        }
    }
    for(int i=0;i<n*m;i++)
    {
        if(n==s[i])
        {
            p=i+1;
            break;
        }
    }
    cout<<p/m+1<<" "<<p&m;
    return 0;
}
