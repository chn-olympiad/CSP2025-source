#include <bits/stdc++.h>
using namespace std;
long long h[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	long long n = 0;
	cin >> s;
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h[n] = s[i] - 48;
			n++;
		}
	}
	sort(h, h + n + 1);
	for (long long i = n; i >= 1; i--) {
		cout << h[i];
	}
}
