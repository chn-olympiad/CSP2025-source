#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s[i] += s[i];
		}
	}
	string m;
	cin >> m;
	for (int i = 0; i <= m.size(); i++) {
		for (int j = 0; j <= m.size(); j++) {
			if (m[j] > m[j + 1]) {
				int num = m[j]++;
			}
			cout << num;
		}

	}

	return 0;
}
