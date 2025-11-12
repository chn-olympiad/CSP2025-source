#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
bool p[5005];
long long ans;

bool f() {
	int maxx = INT_MIN;
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			maxx = max(maxx, a[i]);
			s += a[i];
		}
	}
	return s > (maxx * 2);
}

void fps(int cnt, int now) {
	if (cnt >= 3) {
		if (f()) {
			ans++;
		}
	}
	if (now == n)
		return;
	for (int i = now + 1; i <= n; i++) {
		p[i] = 1;
		fps(cnt + 1, i);
		p[i] = 0;
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fps(0, 0);
	cout << ans;
}
