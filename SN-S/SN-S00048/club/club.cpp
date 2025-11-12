#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mem(i,o) memset(i,o,sizeof i)
#define rep(i,o,n) for(int i=o;i<=n;i++)
#define dep(i,o,n) for(int i=o;i>=n;i--)

const int N = 100010;
const int nN = 210;
int n;
int a[3][N];
int dp[nN][nN][nN];

int t;
void solve() {
	cin>>n;
	int f[3];
	mem(f,0);
	rep(i,1,n) {
		rep(j,0,2) {
			cin>>a[j][i];
			f[j]=max(f[j],a[j][i]);
		}
	}
	if(n>200){
			int ans = 0;
		if(f[2]==0&&f[1]==0){
			sort(a[0]+1,a[0]+1+n,greater<int>());
			rep(i,1,n/2){
				ans+=a[0][i];
			}
		}
		else if(f[2]==0){
			rep(i,1,n) ans+=a[1][i],a[0][i]-=a[1][i];
			sort(a[0]+1,a[0]+1+n,greater<int>());
			rep(i,1,n/2) ans+=a[0][i];
		}
		else{
			rep(i,1,n) ans+=max({a[0][i],a[1][i],a[2][i]});
		}
		cout<<ans<<endl;
		return;
	}
	mem(dp,0xc0);
	dp[0][0][0] = 0;
	rep(i,1,n) {
		rep(a1,0,n/2) {
			rep(a2,0,n/2) {
				int& x = dp[i][a1][a2];
				x = dp[i-1][a1][a2]+a[2][i];
				if(a1) x = max(x,dp[i-1][a1-1][a2]+a[0][i]);
				if(a2) x = max(x,dp[i-1][a1][a2-1]+a[1][i]);
//				cout<<x<<" ";
			}
//			cout<<endl;
		}
//		cout<<endl;
	}
	int ans = 0;
	rep(a1,1,n/2) {
		rep(a2,1,n/2) {
			if(a1+a2>=n/2) {
				ans=max(ans,dp[n][a1][a2]);
			}
		}
	}
	cout<<ans<<endl;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--) {
		solve();
	}
}

