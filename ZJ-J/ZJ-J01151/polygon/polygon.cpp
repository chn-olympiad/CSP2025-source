#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, MOD = 998244353, M = 25000000;
int n, m, mid, x, y, cnt, idx, a[N], vis[M + 10], tr[M + 10], v[M + 10];
long long ans, num, maxx, lin;
long long lowbit(long long x){
	return -x & x;
}
void upd(long long x, long long k){
	for (x; x <= N * N; x += lowbit(x)){
		lin = (tr[x] + k) % MOD;
		tr[x] = lin;
	}
}
long long find(long long x){
	num = 0;
	for (x; x; x -= lowbit(x)){
		num = (num + tr[x]) % MOD;
	}
	return num;
}
void DFS(int x, int t, int y, int sum, int maxx){
	if (x == n + 1){
		if (sum > maxx * 2 && y >= 3) ans += 1;
		return ;
	}
	DFS(x + 1, 1, y + 1, sum + a[x], max(maxx, a[x]));
	DFS(x + 1, 0, y, sum, maxx);
	return ;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 10){
		DFS(1, 0, 0, 0, 0);
		cout << ans;
	}
	else {
		for (int i = 1; i <= n; i ++){
			if (i > 2) ans = (ans + find(maxx) - find(a[i])) % MOD;
			//cout << find(maxx) - find(a[i]) << " ";
			idx = cnt;
			for (int j = idx; j >= 1; j --){
				if (vis[v[j] + a[i]] == 0) v[++ cnt] = a[i] + v[j];
				vis[v[j] + a[i]] += vis[v[j]];
				upd(v[j] + a[i], vis[v[j]]);
				maxx = max(maxx, (long long)(v[j] + a[i]));
			}
			if (vis[a[i]] == 0) v[++ cnt] = a[i];
			vis[a[i]] += 1;
			//cout << ans << " ";
		}
		cout << ans;
	}
	return 0;
}
