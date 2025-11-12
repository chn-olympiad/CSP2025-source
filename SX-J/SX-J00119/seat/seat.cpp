#include <bits/stdc++.h>
using namespace std;
int n, m, s[100005], a;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1, cmp);
	m = n = 1;
	for (int i = 1; i <= n; i++) {
		if (i > m)	{
			n++;
			i = 1;
		} else {
			m++;
		}
	}
	cout << n << " " << m;
	return 0;
}
