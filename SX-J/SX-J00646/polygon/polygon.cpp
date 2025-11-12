#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
long long n, a[N], b[N], cnt = 0;
bool st[N];

void dfs(int u) {
	if (u >= 3 ) {
		long long sum = 0;
		bool gg = 0;
		//	cout << " u= " << u << "// ";
		for (int i = 0; i < u; i++) {
			if (b[i] < b[i - 1]) {
				gg = 1;
			}
			sum += b[i];
			//cout << b[i] << " ";
		}
		//cout << " 最大值=" << b[u - 1]  << " 最大值2倍=" << b[u - 1] * 2 << "  sum=" << sum << endl;;
		if (b[u - 1] * 2 < sum && gg == 0) {
			cnt++;
			cnt %= 998;
			cnt %= 244;
			cnt %= 353;
			//cout << "  ++  " << endl;
		}
		if (u == n) {
			return ;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (st[i] == false) {
			b[u] = a[i];
			st[i] = true;
			dfs(u + 1);
			b[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	memset(b, 0, sizeof(b));
	memset(st, false, sizeof(st));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	dfs(0);
	cnt %= 998;
	cnt %= 244;
	cnt %= 353;
	cout << cnt;
	return 0;
}
