#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

const int N = 1e5 + 9;
ll cnt[3], n, ans, T;
struct node {
	ll val, id;
	bool friend operator < (node a, node b) {
		return a.val > b.val;
	}
} a[N][3];
priority_queue<ll, vector<ll>, greater<ll>> s[10][3];

bool cmp(node x, node y) {
	return x.val > y.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (T = read(); T--; ans = 0) {
		n = read();
		for (int i = 0; i < 3; i++)
			cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j].val = read();
				a[i][j].id = j;
			}
			sort(a[i], a[i] + 3, cmp);
			for (int j = 0; j < 3; j++) {
				if (cnt[a[i][j].id] == n / 2) {
					ll tv = s[T][a[i][j].id].top();
					if (a[i][j].val - a[i][j + 1].val - tv > 0) {
						s[T][a[i][j].id].pop();
						s[T][a[i][j].id].push(a[i][j].val - a[i][j + 1].val);
						ans += a[i][j].val - tv;
						break;
					}
				} else {
					cnt[a[i][j].id]++;
					s[T][a[i][j].id].push(a[i][j].val - a[i][j + 1].val);
					ans += a[i][j].val;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}