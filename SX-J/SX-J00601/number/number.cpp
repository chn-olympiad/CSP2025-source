#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int b = a.size();
	int c[2000001];
	int num = 0;
	for (int i = 1; i <= b; i++) {
		if (a[i] >= 1 && a[i] <= 9) {
			num++;
			c[i] = a[i];
			continue;
		}
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			if (c[i] < c[j]) {
				int d = c[i];
				c[i] = c[j];
				c[j] = d;
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		cout << c[i];
	}
	return 0;
}
