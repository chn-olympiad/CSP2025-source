#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N], cnt;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i]))
			a[++cnt] = int(s[i] - '0');
	}
	sort(a + 1, a + 1 + cnt);
	for (int i = cnt; i >= 1; i--) {
		cout << a[i];
	}


	return 0;
}
