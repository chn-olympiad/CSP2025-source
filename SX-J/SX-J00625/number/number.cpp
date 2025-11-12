#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100000005], sum = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int u = s.size();
	for (int i = 0; i <= u - 1; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[sum] = s[i] - '0';
			sum++;
		}
	}
	sort(a + 1, a + 1 + sum);
	for (int i = sum; i > 1; i--) {
		cout << a[i];
	}
	return 0;
}
