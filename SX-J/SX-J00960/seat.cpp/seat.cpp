#include <bits/stdc++.h>
using namespace std;
int a[105], tong[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, i, gj, dzyx, dzyy, s = 0;
	cin >> n >> m;
	gj = n * m;
	for (i = 1; i <= gj; i++)
		cin >> a[i];
	int r = a[1];
	for (int i = 1; i <= gj; i++) {
		for (int t = 100; t >= 1; t--) {
			if (a[i] == t)
				tong[t]++;
		}
	}
	for (int t = 100; t >= 1; t--) {
		if (tong[t] == 1)
			s++;
		if (t == r)
			break;
	}
	cout << s << endl;
	if (s % m == 0)
		dzyy = s / m;
	else
		dzyy = s / m + 1;
	if (dzyy % 2 == 0)
		dzyx = n - s % m + 1;
	if (dzyy % 2 == 1)
		dzyx = s % (n + 1);
	cout << dzyy << " " << dzyx;
}
