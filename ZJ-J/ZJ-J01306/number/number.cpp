// T1 number
#include <bits/stdc++.h>
using namespace std;
string s; int cnt, a[1000010];
bool cmp(int p, int q) {
	return p > q;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0, len = s.size(); i < len; i++)
		if (s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) cout << a[i];
	return 0;
}