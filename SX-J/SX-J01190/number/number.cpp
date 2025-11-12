#include <bits/stdc++.h>
using namespace std;

long long a[100000000] = {0};
long long  c = 0;
long long  a1 = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = int (s[i] - '0') ;
			c++;
		}
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < c; i++) {
		a1 = a1 * 10 + a[i];

	}
	cout << a1;
	return 0;
}
