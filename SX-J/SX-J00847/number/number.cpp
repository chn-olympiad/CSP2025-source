#include <bits/stdc++.h>
using namespace std;
int a[1000005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int len = s.size(), k = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			a[k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k + 1, cmp);
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= k; i++)
		cout << a[i];
	return 0;
}