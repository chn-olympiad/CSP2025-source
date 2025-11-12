#include <bits/stdc++.h>
using namespace std;
long long b[100];

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;

	cin >> s;
	long long	len = s.size();
	for (long long i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int a = s[i] - '0';
			b[a]++;
		}
	}

	for (int i = 9; i >= 0; i--) {
		for (long long j = 0; j < b[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
