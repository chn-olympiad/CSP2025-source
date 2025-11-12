#include <bits/stdc++.h>
using namespace std;

bool jh(int c, int d) {
	return c > d;
}
long long a[100005], num, n, n1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	while (s[num] != 0)

	{
		num++;

	}
	for (int i = 0; i < num; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			n1++;
		}

	}
	sort(a, a + num, jh);
	while (n != n1) {
		cout << a[n];
		n++;
	}
	return 0;
}
