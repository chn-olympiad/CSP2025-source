#include <bits/stdc++.h>
using namespace std;

string s, ans;
int a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	sort(a + 1, a + cnt + 1, greater<int> ());
	for (int i = 1; i <= cnt; i++)
		ans += (a[i] + '0');
	cout << ans;
	return 0;
}