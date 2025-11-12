#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[20];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (size_t i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			ans[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= ans[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
