#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, ans;
int a[5005];

void dfs(int id, int b, int l, int mx){
	if(b >= 3 && l > mx * 2) ans = (ans + 1) % mod;//, cout << l << "\n";
	if(id > n) return;

	dfs(id + 1, b, l, mx);
	dfs(id + 1, b + 1, l + a[id], max(mx, a[id]));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 3){
		if(a[1] + a[2] + a[3] > max(max(a[1], a[2]), a[3])) cout << 1;
		else cout << 0;
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}