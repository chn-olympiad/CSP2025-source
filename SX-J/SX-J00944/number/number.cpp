#include <bits/stdc++.h>
using namespace std;
char s[1000000];
long long cnt = 0;
long long num[15];
long long sum = 0, ans = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = strlen(s);
	if (n == 1) {
		cout << s[0] - '0';
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (num[i] != 0) {
			for (int j = 0; j < num[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
