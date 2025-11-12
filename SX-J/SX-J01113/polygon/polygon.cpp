#include <bits/stdc++.h>
using namespace std;
int a[5050];
int qz[5050];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int m, cnt = 0;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		qz[i] = qz[i - 1] + a[i];
	}
	for (int i = 2; i < m; i++) {
		for (int j = 1; j <= m; j + i) {
			if (qz[j] - qz[j - 1] > a[j] && qz[j] / a[j] > 2) {
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout << cnt;
	return 0;
}