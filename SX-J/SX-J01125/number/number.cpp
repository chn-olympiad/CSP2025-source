#include <bits/stdc++.h>
using namespace std;

long long a, n;
int q[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	n = a = s.length();
	for (int i = 0; i < a; i++) {
		q[i] = s[i] - '0';
	}
	sort(q, q + n);
	for (int i = n - 1; i >= 0; i--) {
		if (q[i] <= 9 && q[i] >= 0) {
			cout << q[i];
		}
	}
	return 0;
}
