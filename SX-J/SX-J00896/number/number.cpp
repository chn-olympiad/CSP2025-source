#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
int a[N];
long long x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long l = s.length();
	for (long long i = 0; i < l; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[x] = s[i] - '0';
			x++;
		}
	}
	sort(a, a + x);
	for (long long i = x - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}