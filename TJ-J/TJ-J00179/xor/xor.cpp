#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N+100],s[N+100],n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]^s[i-1];
    }
    int now=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=now;j<i;j++)
        {
            if((s[j]^s[i])==k)
            {
                ans++;
                now=i;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
