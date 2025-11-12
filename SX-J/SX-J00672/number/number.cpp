#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int c = s.size();
	int a[c];
	int ans = 0;
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
		} else {
			a[i] = 0;
			ans++;
		}
	}
	for (int i = 0; i < c - ans; i++) {
		int r, num = 0;
		for (int j = 0; j < c; j++) {
			if (a[j] > num && a[j] != 0) {
				num = a[j];
				r = j;
			}
		}
		cout << num;
		a[r] = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}