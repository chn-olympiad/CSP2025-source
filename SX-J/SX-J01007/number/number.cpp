#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int m[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, x, num = 0;
	cin >> s;
	n = strlen(s);
	for (int i = 0; i <= n; i++) {
		if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
			m[i] = s[i] - '0';
			num++;
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (m[i] < m[j]) {
				x = m[j];
				m[j] = m[i];
				m[i] = x;
			}
		}
	}
	for (int i = 0; i < num; i++)
		cout << m[i];
	return 0;
}
