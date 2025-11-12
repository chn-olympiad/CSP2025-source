#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans, n, a[100005][5];
void dfs(int x, int r1, int r2, int r3, int sum){
	if(r1 > n / 2 || r2 > n / 2 || r3 > n / 2){
		return;
	}
	if(x > n){
		ans = max(ans, sum);
		return;
	}
	dfs(x + 1, r1 + 1, r2, r3, sum + a[x][1]);
	dfs(x + 1, r1, r2 + 1, r3, sum + a[x][2]);
	dfs(x + 1, r1, r2, r3 + 1, sum + a[x][3]);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		ans = 0;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= 3; k++){
				a[j][k] = 0;
			}
		}
		cin >> n;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= 3; k++){
				cin >> a[j][k];
			}
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
