#include <bits/stdc++.h>
using namespace std;
int a[1000007];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int m = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[m] = s[i] - '0';
			m++;
		}
	}
	m--;
	sort( a + 1, a + m + 1);
	for (int i = m; i >= 1; i--) {
		cout << a[i] ;
	}
}
