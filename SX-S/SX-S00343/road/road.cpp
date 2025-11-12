#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum, a[3000001], b[101];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			int s = i * j;
			cin >> a[s];
			if (j == 3)
				sum += a[s];
		}
	}
	for (int i = 1; i <= m + 1; i++)
		cin >> a[i];
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}