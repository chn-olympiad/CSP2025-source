#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	long long sum = 0;
	long long max = 0;
	cin >> s;
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] >= max) {
			max = s[i];

		}
		sum += max * (s.size() - i);
	}

	cout << sum;
	return 0;
}
