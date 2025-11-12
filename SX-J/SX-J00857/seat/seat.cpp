#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int cmp(int x, int y) {
	if (x > y) {
		return x > y;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n * m];
	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= m; j++) {
			cin >> a[i];
		}
	}
	sorf(a + 1, a + n + 1, cmp);

	return 0;
}
