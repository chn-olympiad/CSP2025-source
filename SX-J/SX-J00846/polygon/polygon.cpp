#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int j;
	int shu = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == k) {
			shu++;
		}
	}
	if (k != 0) {

		for (int i = 0; i < n - 1; i++) {
			j = b[i] ^ b[i + 1];
			if (j == k)
				shu++;
		}
	}
	cout << shu;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
