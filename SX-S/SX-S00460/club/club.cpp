#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
int t;
int n;
int s[100005];

bool cmp(int z, int x) {
	return z > x;
}

int  main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int q, w, e;
			cin >> q >> w >> e;
			s[i] = q;
		}
		sort(s + 1, s + n + 1, cmp);
		for (int j = 1; j <= n / 2; j++) {
			sum += s[j];
		}
		cout << sum << endl;
		memset(s, 0, sizeof(s));
	}
	return 0;
}
