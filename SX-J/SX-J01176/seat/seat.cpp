#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s, c, r;
	cin >> n >> m;
	for (int i = 0; i <= n * m; i++) {
		cin >> s;
	}
	sort(s, s + n + 1);
	for (int i = 1; i <= n * m; i++) {
		cout << s;
	}
	return 0;
}
