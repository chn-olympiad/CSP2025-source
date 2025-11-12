#include <bits/stdc++.h>
#define N 1000006
using namespace std;
char c[N];
int t[20];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> (c + 1);
	int len = strlen(c + 1);
	for (int i = 1; i <= len; i ++) {
		if (c[i] >= '0' && c[i] <= '9') {
			t[c[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= t[i]; j ++) {
			cout << i;
		}
	}
	return 0;
}
