#include <bits/stdc++.h>
using namespace std;
int a[1000007], m;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++m] = s[i] - '0';
		}
	}
	sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
	for (int i = 1; i <= m; ++i) {
		cout << a[i];
	}
} 

