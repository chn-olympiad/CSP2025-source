#include <bits/stdc++.h>
using namespace std;
string s;
int n, num;
string ans;
int a[1000005];

bool cmp(int x, int y) {
	if (x < y)
		return x > y;
}

int main() {
	freopen("number.in", "w", stdin);
	freopen("number.out", "r", stdout);
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] < 'a' || s[i] > 'z') {
			a[i] = (int)s[i];
			num++;
		}
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < num; i++) {
		ans += (char)a[i];
	}
	cout << ans;
	return 0;
}
