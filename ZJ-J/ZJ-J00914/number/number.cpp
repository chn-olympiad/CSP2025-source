#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int num[N], cnt;
char c[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	int len = strlen(c);
	for (int i = 0; i < len; i++ ) {
		if (c[i] >= '0' && c[i] <= '9') {
			num[++cnt] = c[i] - '0';
		}
	}
	sort(num + 1, num + cnt + 1, cmp);
	if (num[1] == 0) cout << 0;
	else {
		for (int i = 1; i <= cnt; i++)
			cout << num[i];
	}
	return 0;
}

