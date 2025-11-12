#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int s[10001];
	for (int i = 0; i <= n + m - 1; i++) {
		int l = i;
		cin >> s[l];
	}
	int cnt = 0;
	for (int j = 0; j <= n + m - 1; j++) {
		if (s[1] < s[l]) {
			cnt++;
		}
	}
	int a = cnt / m;
	int b = cnt % m;
	int c;
	if (a % 2 == 0)
		c = m - b + 1;
	else
		c = b;
	cout << a << " " << c;
	return 0;
}