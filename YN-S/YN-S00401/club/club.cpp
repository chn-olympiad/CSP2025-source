//zhongyc10 2025.11.01.CSP/S
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n;
int a[N], b[N], c[N];

bool cmp(int x, int y) {
	return x > y;
}

bool cmp1(int x, int y) {
	return x > y;
}

bool cmp2(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int ans = 0;
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp1);
		sort(c + 1, c + n + 1, cmp2);
		for (int i = 1; i <= n; i++) {
			ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/