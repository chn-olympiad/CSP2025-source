#include <bits/stdc++.h>
using namespace std;
int n, m;

int s[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c, w = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	c = s[1];
	int l = 0;
	int r = n * m;
	sort(s, s + n, cmp);
	for (int i = 1; i <= n; i++) {
		int mid = (l + r) / 2;
		if (s[mid] = c) {
			w = mid;
			break;
		} else if (mid < c)
			l = mid + 1;
		else
			r = mid - 1;
	}
	int d = w / m;
	int f = w / n;
	if (w%m==0) {
		if (w % m != 0)
			d = w / m + 1;
		if (w % n != 0)
			f = w / m + 1;
		cout << d << " " << f - m + 1;
	} else {
		if (w % m != 0)
			d = w / m + 1;
		if (w % n != 0)
			f = w / n + 1;
		cout << d << " " << f + 1;
	}
	return 0;
}
