//╤тедр╩об 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005, mod = 998244353;

int n;
int a[N], maxn;
ll dp[N * 2], pre[N * 2];
/*4 11 12 13 14*/
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); maxn = a[n] * 2;
	dp[0] = 1;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = maxn; j >= 0; j--) pre[j] = (pre[j + 1] + dp[j]) % mod;
		ans = (ans + pre[a[i] + 1]) % mod;
		for(int j = maxn; j >= 0; j--) dp[min(maxn, j + a[i])] = (dp[min(maxn, j + a[i])] + dp[j]) % mod;
	}
	cout << ans;
	return 0;
}
