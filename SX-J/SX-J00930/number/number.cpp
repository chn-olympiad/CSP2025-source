#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
char a[1000005];

bool cmp(char x, char y) {
	return x > y;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int j = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && '9' >= s[i]) {
			a[j] += s[i];
			j++;
		}
	}
	sort(a + 1, a + j, cmp);
	for (int i = 1; i < j; i++) {
		cout << a[i];
	}
	return 0;
}