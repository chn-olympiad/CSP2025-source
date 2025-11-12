#include<bits/stdc++.h>
using namespace std;

int n, ans, a[5010];
const int P = 998244353;

inline void dfs(int p, int sum, int ma){
	if(p == n + 1){
		if(sum > ma * 2){
			ans++;
			if(ans >= P){
				ans -= P;
			}
		}
		return;
	}
	dfs(p + 1, sum, ma);
	dfs(p + 1, sum + a[p], max(ma, a[p]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans << "\n";
	return 0;
}
