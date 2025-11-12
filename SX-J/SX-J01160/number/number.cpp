#include <bits/stdc++.h>
using namespace std;
int cnt[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size() - 1;
	for (int i = 0; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			cnt[x]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++)
			printf("%d", i);
	}
	return 0;
}