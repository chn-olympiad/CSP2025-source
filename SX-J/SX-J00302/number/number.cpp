#include <bits/stdc++.h>
using namespace std;
int a[1000005];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l;
	int cnt = 0;
	l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			{
				a[cnt] = s[i] - '0';
				cnt++;
			}
		}
	}
	sort(a, a + cnt + 1);
	for (int i = cnt; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
