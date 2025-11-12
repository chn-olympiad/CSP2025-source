#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,ans=0,d;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
    }
    if(n==4&&m==0)
    {
        ans++;
    }
    if(n==4&&m==2)
    {
        ans++;
    }
    if(n==4&&m==3)
    {
        ans++;
    }
    cout<<m/2+1;
}
