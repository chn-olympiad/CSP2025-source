#include <bits/stdc++.h>
using namespace std;
string s;
long long len, a[1000005], ss;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ss++;
			a[ss] = s[i] - '0';
		}
	}
	sort(a + 1, a + ss + 1, greater<int>());
	for (int i = 1; i <= ss; i++)
		cout << a[i];
	return 0;
}