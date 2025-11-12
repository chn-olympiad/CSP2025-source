#include <bits/stdc++.h>
using namespace std;
long long n, a[5000], s, maxs, maxz, z, z1, book[5000];

void dfs(int x) {
//	if (z >= 3 && x > n) {
//		if (s > maxs * 2) {
//			z1++;
//			z1 %= 998244353;
//		}
//		return;
//	}
	if (x > n) {
		if (z >= 3) {
			for (int i = 1; i <= n; i++) {
				if (book[i] == 1)
					maxs = a[i];
			}
			if (s > maxs * 2) {
				z1++;
//				cout << s << " " << maxs << endl;
			}
		}
		return ;
	}
	z++;
	book[x] = 1;
	s += a[x];
	dfs(x + 1);
	z--;
	book[x] = 0;
	s -= a[x];
	dfs(x + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		a[i] = i;
	}
	sort(a + 1, a + n + 1);
	dfs(1);
	cout << z1;
	return 0;
}