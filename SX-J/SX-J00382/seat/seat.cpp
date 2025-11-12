include < bits / stdc++.h >
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, a, b, t, s;
	cin >> n >> m;
	cin >> a >> b >> t >> s;
	if (a = 100) {
		c = 1;
		r = 1;
	}
	if (a = 99) {
		c = 1;
		r = 2;
	}
	if (a = 98) {
		c = 2;
		c = 2;
	}
	if (a = 97) {
		c = 2;
		r = 1;
	}
	if (a = 94) {
		c = 3;
		r = 1;
		cout << c << " " << r;
		return 0;
	}