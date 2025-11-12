#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 5e3 + 10;
const int M = 1e4 + 10;
const int mod = 998244353;

int n,v;
int a[N],dp[2][M][5];

void add (int &x,int y){
	x += y;
	if (x >= mod) x -= mod;
}
void solve(){
	cin >> n; v = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i],v = max(v,a[i]);
	sort(a + 1,a + n + 1);
	v = v * 2 + 1;
	dp[0][0][0] = 1;
	int cur = 0,ans = 0;
	for (int i = 0 ; i < n ; i++){
		int nxt = (cur ^ 1);
		for (int k = 0 ; k <= min(i,3) ; k++){
			for (int j = 0 ; j <= v ; j++){
				if (!dp[cur][j][k]) continue;
				int jj = min(v,j + a[i + 1]),kk = min(3,k + 1);
				add(dp[nxt][jj][kk],dp[cur][j][k]);
				if (kk == 3 && jj > 2 * a[i + 1]) add(ans,dp[cur][j][k]);
				add(dp[nxt][j][k],dp[cur][j][k]);
				dp[cur][j][k] = 0;
			}
		}
		//for (int j = 0 ; j <= v ; j++)
		//	for (int k = 0 ; k <= 3 ; k++)
		//		cout << "i = " << i + 1 << " j = " << j << " k = " << k << ' ' << dp[nxt][j][k] << endl;
		cur ^= 1;
	}
	for (int j = 0 ; j <= v ; j++)
		for (int k = 0 ; k <= 3 ; k++)
			dp[0][j][k] = dp[1][j][k] = 0;
	cout << ans << endl;
}
signed main(){
	//freopen("polygon4.in","r",stdin);
	//freopen("my.txt","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
