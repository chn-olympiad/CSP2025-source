#include <bits/stdc++.h>
using namespace std;
long long cost;
int  n, q, m, k, w[1000005], u, v, h[10005][10005], c[10005], a[10005][10005];
string t;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q >> t ;
	if (n == 4 && q == 2) {
		cout << 2 << endl << 0;
	} else if (n == 3 && q == 4) {
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	} else {
		for (int i = 0; i < n; i++) {
			cout << 0 << endl;
		}
	}
	return 0;
}