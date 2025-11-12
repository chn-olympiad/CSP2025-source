#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			a[cnt] = s[i];
		}
	}
	for (int i = 1; i <= cnt; i++)
		cout << cnt;
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i--) {
		cout << i;
	}
	return 0;
}
