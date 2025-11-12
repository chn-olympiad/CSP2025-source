#include <bits/stdc++.h>
using namespace std;
string s;
int p[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			p[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (p[i] != 0) {
			printf("%d", i);
			p[i]--;
		}
	}
	return 0;
}
