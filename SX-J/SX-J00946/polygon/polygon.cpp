#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, way, chu, chuy, chuyy;
	cin >> n;
	int a[n];
	cin >> a[n];
	int s[n];
	for (int i = 1; i <= n; i++) {
		chu = i + 1;
		s[i] = chu;
	}
	for (int j = 1; j <= n; j++) {
		chuy = s[j - 1] * s[j];
	}
	chuyy = chuy - n - n / 2;
	for (int k = 0; k <= n; k++) {
		for (int x = 0; x <= n; x++) {
			for (int y = 0; y <= n; y++) {
				if (a[k] + a[x] > a[y] && a[y] + a[x] > a[k] && a[k] + a[y] > a[x])
					chuyy = chuyy - 1;
			}
		}
	}
	way = chuyy;
	cout << way;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
