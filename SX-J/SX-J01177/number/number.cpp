#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int n = 0, ans = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n++;
			a[n] = int(s[i] - '0');
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		cout << a[i];
	return 0;
}