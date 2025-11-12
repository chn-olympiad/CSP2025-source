#include <bits/stdc++.h>
using namespace std;

int a[10005];
string s;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	for (int i = 1; ; i++) {
		cin >> s;
		a[i] = s;
		int cnt = 0;
		if (a[i] >= 1 && a[i] <= 9) {
			if (a[i].first < a[i].second) {
				a[i].second = a[i].first;
			}
			if (a[i] < cnt) {
				cnt = a[i];
			}
		}
		if (s == " ") {
			break;
		}
	}

	cout << cnt;

	return 0;
}