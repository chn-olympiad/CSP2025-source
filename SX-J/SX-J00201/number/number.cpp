#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.length();
	int e = 1;
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[e] = s[i] - '0';
			e++;
		}
	}
	sort(a + 1, a + e + 1);
	for (int i = e; i > 1; i--)
		cout << a[i];
	return 0;
}
