#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,ans,s[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    s[1]=1;
    for(int i=2;i<=5002;i++)
    {
        s[i]=(s[i-1]*i)%998244353;
    }
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(long long m=3;m<=n;m++)
    {
        ans=(ans+(s[n]/s[n-m]*s[m]))%998244353;
    }
    cout << ans;
    return 0;
}
