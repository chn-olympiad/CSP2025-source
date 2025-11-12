#include <bits/stdc++.h>
using namespace std;
int s[105];

bool cmp(int b, int c) {
	return b > c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	int a = s[0];
	int t;
	sort(s, s + n *m, cmp);
	for (int i = 0; i < n * m; i++) {
		if (s[i] == a) {
			t = i;
			break;
		}
	}
	int l = t / n + 1, h = 0;
	int tt = t % n;
	if (l % 2 == 0) {
		h = n - tt;
	} else {
		h = tt + 1;
	}
	cout << l << " " << h;
	return 0;
}
