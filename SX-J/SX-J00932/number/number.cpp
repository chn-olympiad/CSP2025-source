#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000022];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int sum = 0;
	int c = s.length();
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[sum] = s[i] - '0';
			sum++;
		}
	}
	sort(a, a + sum );
	for (int i = sum - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
