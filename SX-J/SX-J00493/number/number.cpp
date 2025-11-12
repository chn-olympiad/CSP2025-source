#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int cnt, num[1000005];
bool vis[1000005];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= sizeof(s); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[i] = (s[i] - '0');
			cnt++;
		}
	}
	sort(num, num + 1000000, cmp);
	for (int i = 0; i < cnt; i++) {
		cout << num[i];
	}
	return 0;
}
