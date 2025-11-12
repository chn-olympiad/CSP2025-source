#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t = 1;

inline int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0 ; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[t] = s[i] - 48;
			t++;
		}
	}
	stable_sort(a + 1, a + t, cmp);
	for (int i = 1 ; i <= t - 1 ; i++) {
		cout << a[i];
	}
	return 0;
}
