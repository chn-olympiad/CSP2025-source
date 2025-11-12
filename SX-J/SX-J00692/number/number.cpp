#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long n, v = 0;
	string s, x;
	cin >> s;
	int len = s.size();
	if (len == 1) {
		cout << s;
		return 0;
	}
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			v++;
			x[v] = s[i];
		}
	}
	for (int i = 2; i <= v; i++) {
		if (x[i] - '0' > x[i - 1] - '0') {
			n = x[i - 1];
			x[i - 1] = x[i];
			x[i] = n;
		}
	}
	for (int i = 1; i <= v; i++) {
		cout << x[i];
	}
	return 0;
}