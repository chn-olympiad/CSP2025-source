#include <bits/stdc++.h>
using namespace std;
long long n, k, cnt;
int a[500005], mmax;
queue<int> que;

int xo(int l, int r) {
	int xos = 0;
	for (int i = l; i < r; i++) {
		xos = xos ^a[i];
	}
	return xos;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			int t = xo(l, r);
			que.push(t);
			if (t > mmax) {
				mmax = t;
			}
		}
	}
	while (!que.empty()) {
		if (que.front() == mmax) {
			cnt++;
		}
		que.pop();
	}
	cout << cnt;
	return 0;
}
