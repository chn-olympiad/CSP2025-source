#include <bits/stdc++.h>
using namespace std;

struct ss {
	string s1;
	string s2;
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	ss a[n + 2], b[q + 2];
	for (int i = 1; i <= n; i++)
		cin >> a[i].s1 >> a[i].s2;
	for (int i = 1; i <= q; i++)
		cin >> b[i].s1 >> b[i].s2;
	for (int i = i; i <= q; i++)
		cout << 0 << endl;

	return 0;
}