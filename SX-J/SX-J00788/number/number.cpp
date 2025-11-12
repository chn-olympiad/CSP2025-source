#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int ans;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}

	return 0;
}//   =>     :)