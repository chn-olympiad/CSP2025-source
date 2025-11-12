#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;

const int N=5e5+10;

int a[N][3];
int c[3], v[3][N], n, ans;

void solve() {
    cin>>n;
    rep(i, 1, n) cin>>a[i][0]>>a[i][1]>>a[i][2];
    rep(i, 1, n) {
        if(a[i][0]>=max(a[i][1], a[i][2])) v[0][++c[0]]=a[i][0]-max(a[i][1], a[i][2]);
        else if(a[i][1]>=max(a[i][0], a[i][2])) v[1][++c[1]]=a[i][1]-max(a[i][0], a[i][2]);
        else if(a[i][2]>=max(a[i][0], a[i][1])) v[2][++c[2]]=a[i][2]-max(a[i][0], a[i][1]);
        ans+=max(a[i][0], max(a[i][1], a[i][2]));
    }
    rep(k, 0, 2) {
        if(c[k]<=(n>>1)) continue;
        sort(v[k]+1, v[k]+c[k]+1);
        int m=c[k]-(n>>1);
        rep(i, 1, m) ans-=v[k][i];
    } cout<<ans<<'\n'; ans=c[0]=c[1]=c[2]=0;
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}