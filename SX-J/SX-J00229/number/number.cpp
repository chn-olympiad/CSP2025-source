#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
//	cout << l;
	for (int i = 0; i < l; i++) {
		if (int(s[i]) < 97) {
			a[cnt] = int(s[i]) - 48;
			cnt += 1;
		}
	}
	sort(a, a + cnt);
	for (int i = cnt - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
