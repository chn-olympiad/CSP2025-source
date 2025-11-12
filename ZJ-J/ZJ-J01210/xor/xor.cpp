#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define pii pair<ll,ll>
#define pb push_back
ll _t_;
ll n,m;
ll sum,ans;
map<ll,ll>mp;
void solve()
{
    cin>>n>>m;
    mp[0]=1;
    forl(i,1,n)
    {
        ll x;
        cin>>x;
        sum^=x;
        if(mp.count(sum^m))
        {
            // cerr<<i<<',',
            sum=0;
            ans++;
            mp.clear();
            mp[0]=1;
            continue;
        }
        mp[sum]++;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}