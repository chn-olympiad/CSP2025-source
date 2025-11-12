#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, a[5005], ans;
stack<int> st;

void dfs(int sum, int maxn, int dep) {
	if (dep > n) {
		if (sum > maxn * 2) {
			ans = (ans + 1) % mod;
		}
		return;
	} 
	st.push(a[dep]);
	dfs(sum + a[dep], a[dep], dep + 1);
	st.pop();
	dfs(sum, maxn, dep + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dfs(0, 0, 1);
	cout << ans % mod << endl;
	return 0;
}