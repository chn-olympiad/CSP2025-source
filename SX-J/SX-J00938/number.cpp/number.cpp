#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	long long s, sum = 0;
	cin >> s;
	while (s) {
		sum = s % 10;
	}
	for (int i = 0; i < sum; i++) {
		if (sum >= 0 && sum <= 9) {
			cout << sum;
		}
	}



	return 0;
}
