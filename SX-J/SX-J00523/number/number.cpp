#include <bits/stdc++.h>
#define qwq return
using namespace std;
string s;
int ans[1000005];
int sum;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	s = ' ' + s;
	int q123 = 0;
	for (int i = 1; i <= l; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			ans[++q123] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + 1 + q123, cmp);
	bool bo = 0;
	for (int i = 1; i <= q123; i++) {
		if (ans[i] != 0) {
			cout << ans[i];
			bo = 1;
		} else {
			if (bo == 1) {
				cout << ans[i];
			}
		}
	}
	if (bo == 0)
		cout << 0;

	qwq 0;
}
