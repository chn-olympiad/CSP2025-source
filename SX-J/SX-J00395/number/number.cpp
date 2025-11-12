#include <bits/stdc++.h>
using namespace std;
int t[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			t[int(s[i] - '0') + 1]++;
	}
	for (int i = 10; i >= 1; i--) {
		if (t[i] != 0) {
			for (int j = 1; j <= t[i]; j++)
				cout << i - 1;
		}
	}
	return 0;
}
