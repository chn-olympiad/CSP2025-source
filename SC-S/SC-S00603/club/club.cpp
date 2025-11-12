#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
ll T, n, a[N][5];
ll cnt[5], ans;
void dfs (int k, ll sum){
	if (k > n){
		ans = max (ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i ++){
		if (cnt[i] < n / 2){
			cnt[i] ++;
			dfs (k + 1, sum + a[k][i]);
			cnt[i] --;
		}
	}
	return;
}
int main (){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> T;
	while (T --){
		ans = -1;
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs (1, 0);
		cout << ans << "\n";
	}
	return 0;
} 