#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], sum, x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			sum++;
			a[sum] = s[i] - '0';
		}
	}
	sort(a + 1, a + sum + 1);
	for (int i = sum; i >= 1; i--) {
		x = x * 10 + a[i];
	}
	cout << x;
	return 0;
}
