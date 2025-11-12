#include <bits/stdc++.h>
using namespace std;
int a[1000006], m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int sth = s.size();
	for (int i = 0; i < sth; i++) {
		if (s[i] <= '9' && s[i] >= '0')
			a[m++] = s[i] - '0';
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; i--)
		cout << a[i];
	return 0;
}
