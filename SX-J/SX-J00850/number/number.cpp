#include <bits/stdc++.h>
using namespace std;
long long sum[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (long long i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			sum[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		while (sum[i]--)
			cout << i;
	}
	return 0;
}
