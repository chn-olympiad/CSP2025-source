#include <bits/stdc++.h>
using namespace std;
string s;
map<int, int> m;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			m[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (m[i] != 0) {
			for (int j = 1; j <= m[i]; j++)
				cout << i;
		}
	}

	return 0;
}
