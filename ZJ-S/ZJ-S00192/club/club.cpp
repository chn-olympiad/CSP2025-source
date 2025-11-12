#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define scan scanf
#define prin printf
using namespace std;
const int N=1e5;
int n,a[3][N+100];
int dp[210][110][110];
void Max(int &x,int y) {
	if(y>x) x=y;
	return ;
}
void solve() {
	memset(dp,0,sizeof dp);
	scan("%d",&n);
	rep(i,1,n) scan("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
	bool f=1;
	rep(i,1,n)
		if(a[1][i]!=0||a[2][i]!=0) {
			f=0;
			break;
		}
	if(f) {
		sort(a[0]+1,a[0]+1+n);
		int ans=0;
		repp(i,n,(n>>1)+1)
			ans+=a[0][i];
		prin("%d\n",ans);
		return ;
	}
	rep(p,1,n)
		rep(i,0,n>>1)
			rep(j,0,n>>1) {
				int k=p-1-i-j;
				if(k<0) continue;
				if(k>(n>>1)) continue;
//				cerr<<p<<" "<<i<<" "<<j<<" "<<k<<endl;
				Max(dp[p][i+1][j],dp[p-1][i][j]+a[0][p]);
				Max(dp[p][i][j+1],dp[p-1][i][j]+a[1][p]);
				Max(dp[p][i][j],dp[p-1][i][j]+a[2][p]);
//				rep(ii,0,2) {
//					rep(jj,0,2)
//						cerr<<dp[p][ii][jj]<<" ";
//					cerr<<endl;
//				}
//				cerr<<endl;
			}
	int ans=0;
	rep(i,0,(n>>1))
		rep(j,0,(n>>1)) {
			int k=n-i-j;
			if(k<0||k>(n>>1)) continue;
			ans=max(ans,dp[n][j][k]);
		}
	prin("%d\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scan("%d",&T);
	while(T--) solve();
	return 0;
}//60+64+25+40=189ji
