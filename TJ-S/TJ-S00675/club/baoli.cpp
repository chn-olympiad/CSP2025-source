#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n,a[200][3],ans;
void dfs(int now,int sum,int k1,int k2,int k3){
	if (k1 > n / 2 || k2 > n / 2 || k3 > n / 2) return;
	if (now > n){
		ans = max(ans,sum);
		return;
	}
	dfs(now + 1,a[now][0] + sum,k1 + 1,k2,k3);
	dfs(now + 1,a[now][1] + sum,k1,k2 + 1,k3);
	dfs(now + 1,a[now][2] + sum,k1,k2,k3 + 1);
}
void solve(){
	ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		for (int j = 0;j <= 2;j++){
			cin >> a[i][j];
		}
	}
	dfs(1,0,0,0,0);
	cout << ans << '\n';
}
signed main(){
	int T;
	cin >> T;
	while (T--) solve();
return 0;
}
