#include <bits/stdc++.h>
using namespace std;
long long n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	long long f = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			f = 1;
		}
	}
	if (f == 0)
		cout << n % 998244353;
	else
		cout << 0;
	return 0;
}
