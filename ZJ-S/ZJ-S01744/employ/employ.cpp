#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=2e7+5;
const int maxm=500+5;
const ll INF=1e18;
const ll mod=998244353;
ll n,m,c[maxn],dp[maxm][maxm][maxm];//前i个人中，有j个0，选了k个 
void solve() {
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++) {
		cin >> c[i];
//		if(c[i]==0) cnt++;
	}
	bool flg=0;
	for(auto x:s) if(x=='0') flg=1;
	if(!flg) {
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=i;j++) {
				for(int k=0;k<=i;k++) {
					if(c[i]==0&&j!=0) {
						dp[i][j][k]+=dp[i-1][j-1][k];
						dp[i][j][k]%=mod;
					}
					if(c[i]>j) {
						dp[i][j][k]+=dp[i-1][j][k-1];
						dp[i][j][k]%=mod;
					}
					if(c[i]<j&&c[i]!=0) {
						dp[i][j][k]+=dp[i-1][j][k];
						dp[i][j][k]%=mod;
					}
				}
			}
		}
		ll res=0;
		for(int i=m;i<=n;i++){
			for(int j=0;j<=n;j++) {
//				cout << dp[i][j] << " ";
				res+=dp[n][j][i];
				res%=mod;
			}
//			cout << "\n";
		}
//		cout << dp[1][1][0] << "\n";
		cout << res << "\n";
		return ; 
	}
	cout << 0 << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cin >> T;
//	while(T--) {
		solve();
//	}
}
