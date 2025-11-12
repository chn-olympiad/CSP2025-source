#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, d, e, f, g, h, i, j, k, l, m, mmax = 0, mmax5 = 0, mmax6 = 0, cnt = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == 3) {
		cin >> a >> b >> c;
		if (a + b > c && a + c > b && a < b + c)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (n == 4) {
		cin >> a >> b >> c >> d;
		mmax = max(a, max(b, max(c, d)));
		if (a + b > c && a + c > b && a < b + c)
			cnt++;
		if (a + b > d && a + d > b && a < b + d)
			cnt++;
		if (a + c > d && a + d > c && a < c + d)
			cnt++;
		if (c + b > d && c + d > b && c < b + d)
			cnt++;
		if (a + b + c + d > mmax)
			cnt += 1;
	}
	if (n == 5) {
		cin >> a >> b >> c >> d >> e;
		mmax = max(a, max(b, max(c, d)));
		if (a + b > c && a + c > b && a < b + c)
			cnt++;
		if (a + b > d && a + d > b && a < b + d)
			cnt++;
		if (a + c > d && a + d > c && a < c + d)
			cnt++;
		if (c + b > d && c + d > b && c < b + d)
			cnt++;
		if (a + b > e && a + e > b && a < b + e)
			cnt++;
		if (a + e > c && a + c > e && a < e + c)
			cnt++;
		if (a + e > d && a + d > e && a < e + d)
			cnt++;
		if (e + b > d && e + d > b && e < b + d)
			cnt++;
		if (c + e > d && c + d > e && c < e + d)
			cnt++;
		if (a + b + c + d > mmax)
			cnt += 1;
		if (a + b + c + e > mmax)
			cnt += 1;
		if (a + b + e + d > mmax)
			cnt += 1;
		if (a + e + c + d > mmax)
			cnt += 1;
		if (e + b + c + d > mmax)
			cnt += 1;
		mmax5 = max(a, max(b, max(c, max(d, e))));
		if (a + b + c + d + e > mmax5)
			cnt++;
	}
	if (n == 6) {
		cin >> a >> b >> c >> d >> e >> f;
		mmax = max(a, max(b, max(c, max(d, e))));
		if (a + b > c && a + c > b && a < b + c)
			cnt++;
		if (a + b > d && a + d > b && a < b + d)
			cnt++;
		if (a + c > d && a + d > c && a < c + d)
			cnt++;
		if (c + b > d && c + d > b && c < b + d)
			cnt++;
		if (a + b > e && a + e > b && a < b + e)
			cnt++;
		if (a + e > c && a + c > e && a < e + c)
			cnt++;
		if (a + e > d && a + d > e && a < e + d)
			cnt++;
		if (e + b > d && e + d > b && e < b + d)
			cnt++;
		if (c + e > d && c + d > e && c < e + d)
			cnt++;
		if (a + b > f && a + f > b && a < b + f)
			cnt++;
		if (a + f > c && a + c > f && a < b + f)
			cnt++;
		if (a + f > d && a + f > b && a < f + d)
			cnt++;
		if (a + e > f && a + f > e && a < e + f)
			cnt++;
		if (f + b > c && f + c > b && f < b + c)
			cnt++;
		if (f + b > d && f + d > b && f < b + d)
			cnt++;
		if (f + b > e && f + c > e && f < b + e)
			cnt++;
		if (d + f > c && d + c > f && c < d + f)
			cnt++;
		if (e + f > c && e + c > f && c < e + f)
			cnt++;
		if (f + e > d && f + d > e && f < e + d)
			cnt++;
		if (a + b + c + d > mmax)
			cnt += 1;
		if (a + b + c + e > mmax)
			cnt += 1;
		if (a + b + e + d > mmax)
			cnt += 1;
		if (a + e + c + d > mmax)
			cnt += 1;
		if (e + b + c + d > mmax)
			cnt += 1;
		if (a + b + c + f > mmax)
			cnt += 1;
		if (a + b + d + f > mmax)
			cnt += 1;
		if (a + b + e + f > mmax)
			cnt += 1;
		if (a + d + c + f > mmax)
			cnt += 1;
		if (a + e + c + f > mmax)
			cnt += 1;
		if (a + d + e + f > mmax)
			cnt += 1;
		mmax5 = max(a, max(b, max(c, max(d, e))));
		if (a + b + c + d + e > mmax5)
			cnt++;
		if (a + b + c + d + f > mmax5)
			cnt++;
		if (a + b + c + f + e > mmax5)
			cnt++;
		if (d + b + c + f + e > mmax5)
			cnt++;
		if (a + b + d + f + e > mmax5)
			cnt++;
		mmax6 = max(a, max(b, max(c, max(d, max(e, f)))));
		if (a + b + c + d + e > mmax6)
			cnt++;
	}
	cout << cnt;
	return 0;
}
