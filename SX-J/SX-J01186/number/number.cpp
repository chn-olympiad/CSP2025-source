#include <bits/stdc++.h>
using namespace std;
string s;
long long a[9], t;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			a[s[i] - '0' ]++;

	}

	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < a[i]; j++) {
			cout << i ;
		}
	}

	return 0;
}