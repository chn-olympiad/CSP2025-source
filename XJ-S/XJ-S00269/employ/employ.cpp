#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,a[505],l,c[10005];
string s;
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for (int i=1;i<=n;i++)
    {
        cin >> c[i];
        if (c[i]==0)
        {
            l--;
        }
    }
    for (int i=m;i<=l;i++)
    {
        long long re=1;
        for (int i=m+1;i<=n;i++)
            re=(re*i)%MOD;
        ans=(ans+re)%MOD;
    }
    cout << ans;
    return 0;
}
