#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=1e5+10;
int n,ans,a[N][3];
inline void dfs(int x,int A,int B,int C,int res){
    if (x==n+1) return ans=max(ans,res),void();
    if (A<n/2) dfs(x+1,A+1,B,C,res+a[x][0]);
    if (B<n/2) dfs(x+1,A,B+1,C,res+a[x][1]);
    if (C<n/2) dfs(x+1,A,B,C+1,res+a[x][2]);
}
inline void solve(){
	cin>>n,ans=0;
	rep(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
    dfs(1,0,0,0,0),cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while (t--) solve();
	return 0;
}