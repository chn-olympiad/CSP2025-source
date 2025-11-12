#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long a;
	cin >> a;
	long long b[100005];
	long long num = 0;
	while (a > 0) {
		b[num] = a % 10;
		num++;
		a = a / 10;

	}
	sort(b, b + num);
	for (int i = num - 1; i >= 0; i--) {
		cout << b[i];
	}
	return 0;
}
