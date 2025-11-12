#include <bits/stdc++.h>
using namespace std;
int save[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int x = 0; x < len; x++) {
		if (isdigit(s[x]))
			save[s[x] - '0']++;
	}
	for (int x = 9; x >= 0; x--) {
		while (save[x] != 0) {
			cout << x;
			save[x]--;
		}
	}
	return 0;
}
