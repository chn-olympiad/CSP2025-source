#include <bits/stdc++.h>
using namespace std;
string s;
int k = 0, w = 0;
int a[1000009];

bool px(int c, int b) {
	return c > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	w = s.size();
	for (int i = 0; i < w; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[k] = s[i] - 48;
			k++;
		}
	}
	sort(a, a + k, px);
	for (int i = 0; i < k; i++) {
		cout << a[i];
	}

	return 0;
}