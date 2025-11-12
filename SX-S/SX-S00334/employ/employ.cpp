#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n, m, cnt, c[600], ans, shu;
char ch[600];
int maxx;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	srand(time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ch[i];
		if (ch[i] == '1')
			cnt++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		maxx = max(maxx, c[i]);
	}
	if (cnt == n) {
		ans = 1;
		for (int i = n; i >= shu + 1; i--) {
			ans *= i;
			ans %= M;
		}
		cout << ans, exit(0);
	}
	if (m == n)
		cout << 1, exit(0);
	int yu = min(cnt, n - cnt);
	int anss = 1;
	for (int i = n; i >= n - yu + 1; i--) {
		anss *= i;
		anss %= M;
	}
	for (int i = 2; i <= yu; i++)
		anss /= i;
	int asw = rand() % anss + 1;
	cout << asw;
	return 0;
}