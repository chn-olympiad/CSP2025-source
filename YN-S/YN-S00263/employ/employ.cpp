#include <bits/stdc++.h>
using namespace std;
long long n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool p = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			p = 0;
	}
	if (n == m && p)
		cout << 1;
	else if (n == m)
		cout << 0;
	else if (p && m == 1)
		cout << n;
	else
		cout << 0;
	return 0;
}