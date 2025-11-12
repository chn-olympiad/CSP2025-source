#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	long long cnt = 0;
	string s;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
