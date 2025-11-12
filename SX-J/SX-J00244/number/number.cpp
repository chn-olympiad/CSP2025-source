#include <bits/stdc++.h>
using namespace std;

int a[1000001];


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0')
			a[x++] = s[i] - '0';
	}
	sort(a, a + x);
	for (int i = x - 1; i >= 0; i--)
		cout << a[i];
	return 0;
}