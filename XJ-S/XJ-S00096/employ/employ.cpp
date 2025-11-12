#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int n,m;
ll ans=1;
string str;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
    }
    ans=n;
    for(int i=1;i<n;i++)
    {
        ans=ans*(n-i);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
