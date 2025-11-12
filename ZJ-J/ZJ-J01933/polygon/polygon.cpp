#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010];
long long ans;
void dfs(int now, int sum, int mx, int cnt){
	if (cnt >= 1e8 - 10) return ;
	if (now == n + 1){
		if (sum > mx * 2){
			ans++;
			ans %= 998224353;
		}
		return ;
	}
	dfs(now+1, sum + a[now], max(mx, a[now]), cnt + 1);
	dfs(now+1, sum, mx, cnt + 1);
}
int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	// cout << n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0);
	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int sum = 0, mx = 0;
			for (int k = j; k <= j + i-1; k++){
				sum += a[k];
				mx = max(mx, a[k]);
			}
			if (mx * 2 < sum){
				cout << mx << ' ' << sum << "\n";
				ans++;
			}
		}
	}*/
	cout << ans;
	return 0;
}