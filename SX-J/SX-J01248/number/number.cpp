#include <bits/stdc++.h>
using namespace std;
long long tong[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int a = s[i] - '0';
			tong[a] += 1;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (tong[i]--)
			cout << i;
	}
	return 0;
}
