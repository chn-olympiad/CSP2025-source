#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 17;
int n, m;
int a[maxn * maxn];
int r, k;

signed main(signed argc, char const *argv[]) {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	k++;
	for (int i = 1, u; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i == n && j == m)
				break;
			cin >> u;
			if (u > r)
				k++;
		}
	pair<int, int> s;
	s.first = (k - 1) / n + 1;
	if (s.first & 1)
		s.second = (k - 1) % n + 1;
	else
		s.second = n - ((k - 1) % n);
	cout << s.first << " " << s.second << endl;
	return 0;
}
