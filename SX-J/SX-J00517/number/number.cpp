#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005], sum, b, m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			a[sum] = s[i] - 48;
		}
	}

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i]) {
				m = a[i];
				a[i] = a[j];
				a[j] = m;
			}
		}
	}
	for (int i = 1; i <= sum; i++) {
		cout << a[i];
	}
	return 0;
}
