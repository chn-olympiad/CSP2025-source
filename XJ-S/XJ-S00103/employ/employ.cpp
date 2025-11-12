#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define const constexpr
const int mod=998244353;
int32_t main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0,ans=1;
    cin >> n >> m;
    string s;
    cin >> s;
    bool t=true;
    vector<int> c(n);
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!='0')
        {
            t=false;
        }
    }
    if(t)
    {
        cout << m << endl;
        return 0;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                n--;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans*=i;
        }
        cout << ans%mod << endl;
        return 0;
    }
    return 0;
}
