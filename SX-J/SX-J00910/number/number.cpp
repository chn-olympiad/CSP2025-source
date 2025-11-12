#include <bits/stdc++.h>
using namespace std;
int a[1000005], n;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n++;
			a[n] = s[i] - '0';
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		cout << a[i];
	return 0;
}
