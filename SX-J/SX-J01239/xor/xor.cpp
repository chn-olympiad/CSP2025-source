#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int a[n + 1] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int num = 0;
	int sum = -1;
	for (int i = 1, j = 2; i <= n && j <= n; ) {
		if (a[i] == k) {
			num++;
			i++;
			j++;
		} else {
			if (sum == -1) {
				sum = a[i];
				continue;
			}
			sum = sum ^a[j];
			if (sum == k) {
				num ++;
				i = j + 1;
				j = i + 1;
			} else {
				j++;
			}
		}
	}
	cout << num;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
