#include<bits/stdc++.h>
using namespace std;
#define int long long
#define const constexpr
#define endl '\n'
const int MOD=998244353;
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,ans=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int maxa=0;
            maxa=max(maxa,a[j]);
            sum+=a[j];
            //cout << maxa << " " << sum << endl;
            if(sum>maxa*2)
            {
                ans++;
            }
        }
        sum=0;
    }
    ans*=3;
    cout << ans%MOD << endl;
    return 0;
}