#include <bits/stdc++.h>
using namespace std;
int n, m, cnts[15];
string s;
bool flag = true;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			cnts[s[i] - '0']++;
	}
	for (int i = 9; i >= 1; i--) {
		for (int j = 0; j < cnts[i]; j++) {
			cout << i;
			flag = false;
		}
	}
	if (flag)
		cout << 0;
	else {
		for (int i = 0; i < cnts[0]; i++)
			cout << 0;
	}
	return 0;
}
