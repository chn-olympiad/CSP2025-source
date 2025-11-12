#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 5;
int b[MAXN];
int cnt;
int main(void) {
	ios :: sync_with_stdio(false);
	cin . tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0;s[i]; ++i)
		if (s[i] >= '0' && s[i] <= '9')
			b[++cnt] = s[i] - '0';
	sort(b + 1, b + 1 + cnt, greater<int>());
	for (int i = 1;i <= cnt; ++i)
		cout << b[i];
	return 0;
}
