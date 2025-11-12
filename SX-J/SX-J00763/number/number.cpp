#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const ll MAXN = 1e8+10;
str s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	sort(s.begin(), s.end());
	for (ll i = s.size() - 1; i >= 0; i--) {
		if (s[i] <= '9' && s[i] >= '0') {
			cout << s[i];
		}
	}
	return 0;
}
