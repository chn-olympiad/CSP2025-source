#include <bits/stdc++.h>
using namespace std;
string s, sum;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			cout << s[i];
			while (s[i]--) {
				s[i] = s[i] / 10;
				sum[i] += s[i];
				sum[i] = sum[i] % 10;
			}
		}
	}
	return 0;
}
