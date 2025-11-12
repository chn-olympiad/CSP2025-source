#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10;

struct st {
	string a;
	string b;
} a[N], b[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q, k1, k2, sum, x, y, f1, f2;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].b;
	for (int i = 1; i <= q; i++)
		cin >> b[i].a >> b[i].b;
	for (int i = 1; i <= q; i++) {
		sum = 0, k1 = 0, k2 = 0;
		for (int j = 1; j <= n; j++) {
			f1 = 1;
			for (int k = 0; k < b[i].a.size(); k++) {
				if (f1 == 0)
					break;
				for (int l = 1; l <= b[i].a.size() - k; l++) {
					if (b[i].a.substr(k, l) == a[i].a) {
						k1 ++, x = k, y = l, f1 = 0;
						break;
					}
				}
			}
			f2 = 1;
			for (int k = 0; k < b[i].b.size(); k++) {
				if (f2 == 0)
					break;
				for (int l = 1; l <= b[i].b.size() - k; l++) {
					if (b[i].b.substr(k, l) == a[i].b && k == x && l == y) {
						k2 ++, f2 = 0;
						break;
					}
				}
			}
			if (k1 == 1 && k2 == 1)
				sum++;
		}
		cout << sum << "\n";
	}
	return 0;
}
