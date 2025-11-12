#include <bits/stdc++.h>
using namespace std;
int a[1000010], cnt;
bool flag;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		if (a[i] != 0)
			flag = 1;
	}
	if (flag) {
		for (int i = cnt; i >= 1; i--) {
			cout << a[i];
		}
	} else
		cout << 0;
	return 0;
}
