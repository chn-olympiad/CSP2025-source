#include <bits/stdc++.h>
using namespace std;

int zhuanhuan(int q) {
	if (q == 1) {
		return 1;
	}
	int ans = 0, i = 0;
	while (q > 0) {
		if (q % 2 == 1) {
			ans += i * 10;
		}
		q = q / 2;
		i++;
	}
	return ans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int dong = 0;
	k = zhuanhuan(k);
	for (int i = 0; i < n ; i++) {
		a[i] = zhuanhuan(a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = 0, sum = 0;
			for (int h = i; h <= j; h++) {
				if (a[h] > num) {
					num = a[h];
				}
			}
			while (num > 0) {
				int w = 0, d = 0;
				for (int h = i; h <= j; h++) {
					w += a[h] % 10;
					a[h] /= 10;
				}
				if (w % 2 == 1) {
					sum += pow(10, d);
				}
				d++;
			}
			if (sum == k) {
				dong++;
			}
		}
	}
	cout << dong << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
