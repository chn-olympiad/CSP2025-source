#include <bits/stdc++.h>
using namespace std;
int a[1000005], tot = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++tot] = int(s[i] - '0');
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; i++)
		cout << a[i];
	return 0;
}
