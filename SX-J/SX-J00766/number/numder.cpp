#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int sum = 0;
	string s[1000000 + 3];
	for (int i = 0; i <= 1000000; i++) {
		cin >> s[i];
		sum *= 10;
	}
	for (int j = 1; j <= sum; sum /= 10) {
		for (int n = 1; n <= sum; j++) {
			int m = sum * j++;
			int c = m += m;
			cout << c;
		}
	}
	return 0;
}
