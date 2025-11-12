#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int sum = 0;
	int b[a.size()] = {0};
	int t = 0;
	for (int i = 0; i < a.size(); i++) {
		if (int(a[i]) >= 48 && int(a[i]) <= 57) {
			sum++;
			t++;
			b[t] = a[i] - '0';

		}
	}
	sort(b + 1, b + 1 + t);
	for (int i = sum; i >= 1; i--) {
		cout << b[i];
	}

	return 0;
}
