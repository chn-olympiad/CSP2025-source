#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnt] = int(s[i] - '0');
			cnt++;
		}
	}
	int n0um = 0;
	cnt--;
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i--) {
		if (a[i] == 0) {
			n0um++;
		}
	}
	if (n0um == cnt) {
		cout << "0";
		return 0;
	}
	for (int i = cnt; i >= 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
