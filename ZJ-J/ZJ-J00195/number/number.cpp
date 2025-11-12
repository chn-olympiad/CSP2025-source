#include<bits/stdc++.h>
using namespace std;
int n[21];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int m = s.size();
	for (int i = 0; i < m; i++) {
		char c = s[i];
		if ('0' <= c && c <= '9') {
			n[c - '0']++;
		}
	}
	int flag = 0;
	for (int i = 9; i >= 0; i--) {
		if (i == 0) {
			if (!flag) {
				cout << 0;
				return 0;
			}
		}
		while (n[i]--) {
			cout << i;
			flag = 1;
		}
	}
	return 0;
}
