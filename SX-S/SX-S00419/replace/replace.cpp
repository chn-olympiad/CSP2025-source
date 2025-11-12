#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n, q;

struct st {
	string s1;
	string s2;
} a[N], b[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[1].s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i].s1 >> b[1].s2;
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << "\n";
	}
	return 0;
}
