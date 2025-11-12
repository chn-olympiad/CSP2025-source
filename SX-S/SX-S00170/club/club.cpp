#include <bits/stdc++.h>
using namespace std;
int sum = 0;

struct a {
	int as[100010];
} aa[5];

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int n;
		cin >> n;
		if (n == 2) {
			int a, b, c, d, e, f;
			cin >> a >> b >> c;
			cin >> d >> e >> f;
			int aa = a + e, ab = a + f, ac = d + b, ad = f + b, ae = d + c, af = e + c;
			cout << max(aa, max(ab, max(ac, max(ad, max(ae, af)))));
		}
	}
	return 0;
}
