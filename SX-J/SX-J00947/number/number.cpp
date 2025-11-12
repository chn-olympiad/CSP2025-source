#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int b[a.size()];
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[sum] = a[i] - '0';
			sum++;
		}
	}
	sort(b, b + sum);
	for (int i = sum - 1; i >= 0; i--) {
		cout << b[i];
	}
	return 0;
}
