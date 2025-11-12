#include <bits/stdc++.h>
using namespace std;
long long a, f = 0;
int v[20];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	a = s.size();
	for (int i = 0; i < a; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v[s[i] - '0']++;
			if (s[i] - '0' != 0)
				f = 1;
		}
	}
	if (v[0] > 1 && f == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		if (v[i] > 0) {

			for (int j = 1; j <= v[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
