#include <bits/stdc++.h>
using namespace std;
int k[1010], m[1010], g[1010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n = 1;
	string s;
	cin >> s;
	for (int i = 1; i <= s.size() - 1 ; i++) {

		if (s[i] >= 48 && s[i] <= 57) {
			k[i] = s[i];
			n++;
		}
		k[i] = k[i] - 48;
		m[i] = k[i];
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {


		}
	}
	for (int j = 1; j <= n; j++) {
		cout << k[j];
	}
	return 0;
}