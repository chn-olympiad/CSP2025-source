#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int cnt[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s + 1;
	int len = strlen(s + 1);
	int n;
	for (int i = 1; i <= len; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			n = s[i] - '0';
			cnt[n]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i;
		}
	}
	return 0;
}