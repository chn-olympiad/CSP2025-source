#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char a[200005];
char b[200005];
char c[200005];
char d[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= q; i++) {
		int cnt = 0;
		if (b[i] == a[i]) {
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
