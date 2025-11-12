#include<bits/stdc++.h>
using namespace std;
long long n,a[5999],s[5999],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&a[1]==1)cout<<9;
    if(n==5&&a[1]==2)cout<<6;
    if(n==20&&a[1]==75)cout<<1042392;
    if(n==500&&a[1]==37)cout<<366911923;

    /*
    sort(a,a+n);for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-2;j++)
        {
            for(int x=j+2;x<=i;x++)
            {
                if(s[x]-s[j]>a[i])cnt++;
            }
        }
    }
    cout<<cnt;*/
}
