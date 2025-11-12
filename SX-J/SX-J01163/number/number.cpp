#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int s[1000];
	int sum = 0, n = s[1000];
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] % 1 == 0)
			sum = s[i];
	}
	cout << sum;
	return 0;
}
