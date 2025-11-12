#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
string s, t = "", a;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {

		if (s[i] >= 'a' && s[i] <= 'z') {
			cout << "0";
		} else {

			cout << s[i] - 48;
		}
	}


	return 0;
}
