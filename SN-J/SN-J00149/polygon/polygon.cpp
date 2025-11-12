#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 998244353;
int n, a[5005], ans;

void dfs(int start, int num, int los, int maxx, int sum) {
	
	if (num == los) {
		if (sum > 2 * maxx) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	for (int i = start;i + los - num - 1 <= n;i++) {
		dfs(i + 1, num + 1, los, max(maxx, a[i]), sum + a[i]);
	}
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}
	for (int lo = 3;lo <= n;lo++) {
		dfs(1, 0, lo, -1, 0);
	}
	cout << ans;
	return 0;
}
