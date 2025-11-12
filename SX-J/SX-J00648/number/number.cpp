#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], cnt;

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (long long i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = (long long)(s[i] - '0');
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (long long i = 1; i <= cnt; i++) {
		cout << a[i];
	}

	return 0;
}
