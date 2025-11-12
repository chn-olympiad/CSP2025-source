#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=5e5+5;
int n,a[INF][5];
void solve() {
    cin>>n; vector < pii > A[3];
    for (int i=1;i<=n;i++) 
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    int ans=0;
    for (int i=1;i<=n;i++) {
        int Max=max({a[i][0],a[i][1],a[i][2]});
        if (a[i][0]==Max) A[0].pb({max(a[i][1],a[i][2])-Max,i});
        if (a[i][1]==Max) A[1].pb({max(a[i][0],a[i][2])-Max,i});
        if (a[i][2]==Max) A[2].pb({max(a[i][0],a[i][1])-Max,i});
        ans+=Max;
    }
    for (int t=0;t<3;t++)
        sort(A[t].begin(),A[t].end(),greater<pii>());
    int Max=max({A[0].size(),A[1].size(),A[2].size()});
    if (Max>n/2) {
        int t=2;
        if (Max==A[0].size()) t=0;
        if (Max==A[1].size()) t=1;
        int op=0;
        while (Max>n/2) 
            ans+=A[t][op++].fi,Max--;
        cout<<ans<<"\n";
    } else cout<<ans<<"\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    int t=0;cin>>t;
    while (t--) solve();
    return 0;
}