#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
string s;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long slen = s.size(), k = 0;
	for (int i = 0; i < slen; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++k] = s[i] - '0';
	}
	sort(a + 1, a + k + 1, cmp);
	for (int i = 1; i <= k; i++)
		cout << a[i];
	return 0;
}
