#include <bits/stdc++.h>
using namespace std;
long long a[1000005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	long long n, m, max = -1, i;
	cin >> n >> m;
	for (i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	while (max) {
		if (i >= max) {
			max = i;
		}
	}


	return 0;
}
