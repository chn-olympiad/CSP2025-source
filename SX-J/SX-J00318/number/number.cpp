#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (a[i] != 0) {
			for (int j = 9; j >= 0; j--) {
				for (int k = 0; k < a[j]; k++) {
					cout << j;
				}
			}
			return 0;
		}
	}
	cout << 0;
	return 0;
}
