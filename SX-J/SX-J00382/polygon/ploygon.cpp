include < bits / stdc++.h >
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a, b, c, d, e, sum = 0, u;
	cin >> n;
	cin >> a >> b >> c >> d >> e;
	for (int i = 1; i <= n; i++) {
		if (a > b > c > d > e) {
			u = a;
		}
		if (b > a > c > d > e) {
			u = b;
		}
		if (c > a > b > d > e) {
			u = c;
		}
		if (d > a > b > c > e) {
			u = d;
		}
		if (e > a > b > c > d) {
			u = e;
		}
		if (u * 2 < a + b + c + d + e || u * 2 < a + b + c || u * 2 < b + c + d || u * 2 < c + d + e || u * 2 < a + c + e
		        || u * 2 < a + b + e || u * 2 < a + d + e || u * 2 < a + b + d || u * 2 < a + c + b || u * 2 < a + c + d
		        || u * 2 < c + a + e) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}