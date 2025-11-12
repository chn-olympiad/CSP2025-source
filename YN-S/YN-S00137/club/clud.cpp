#include <bits/stdc++.h>
using namespace std;

struct f {
	int a, b, c, zd;
} r[100005];


bool mat(f x, f y) {
	if ((x.a < y.a  && x.a == 0) || (x.b < y.b  && x.b == 0) || (x.c < y.c  && x.c == 0))
		return x.zd < y.zd;
	return x.zd >= y.zd;
}

int main() {
	freopen("clud.in", "r", stdin);
	freopen("clud.out", "w", stdout);`
	int t;
	cin >> t;

	while (t--) {
		long long n, num = 0;
		cin >> n;
		int rs[3] = {0};

		for (int i = 0; i < n; i++) {

			cin >> r[i].a >> r[i].b >> r[i].c;
			r[i].zd = max(r[i].a, max(r[i].b, r[i].c));

		}

		sort(r, r + n, mat);

		for (int i = 0; i < n; i++) {

			if (r[i].a > r[i].b && r[i].a > r[i].c && rs[0] < n / 2) {
				num += r[i].a;
				rs[0]++;
			} else if (r[i].b > r[i].c && rs[1] < n / 2) {
				num += r[i].b;
				rs[1]++;
			} else {
				num += r[i].c;
				rs[2]++;
			}
		}

		cout << num;
	}

	return 0;
}