#include <bits/stdc++.h>
using namespace std;
string s;
const long long N = 1e7;
long long f[N], l;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (long long i = 0; i < (long long)(s.size()); i++) {
		if (s[i] <= '9' && s[i] >= '0' ) {
			f[l++] = (long long)(s[i] - '0');
		}
	}
	sort(f, f + l, cmp);
	for (long long i = 0; i < l; i++) {
		cout << f[i];
	}
	return 0;
}
