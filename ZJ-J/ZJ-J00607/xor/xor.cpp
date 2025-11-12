#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 5e5 + 10;
const int M = 2e6 + 10;
const int mx = (1ll << 20);

int n,k;
int a[N],s[N],dp[N],pre[N],lxt[M];

void solve(){
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= n ; i++) s[i] = (s[i - 1] ^ a[i]);
	lxt[0] = dp[0] = pre[0] = 0;
	for (int i = 1 ; i < mx ; i++) lxt[i] = -1;
	for (int i = 1 ; i <= n ; i++){
		int x = (k ^ s[i]);
		//cout << "!!! " << x << endl;
		if (lxt[x] == -1) dp[i] = 0;
		else dp[i] = pre[lxt[x]] + 1;
		pre[i] = max(pre[i - 1],dp[i]);
		lxt[s[i]] = i;
	}
	//for (int i = 1 ; i <= n ; i++) cout << dp[i] << ' ';
	//cout << endl;
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
		ans = max(ans,dp[i]);
	cout << ans << endl;
}
signed main(){
	//freopen("xor6.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
