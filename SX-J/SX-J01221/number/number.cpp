#include <bits/stdc++.h>
using namespace std;
int arr[1000005], l, mmax = -1e9, mmin = 1e9;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			arr[++l] = s[i] - '0';
		}
	}
	sort(arr + 1, arr + 1 + l);
	for (int i = l; i >= 1; i--) {
		if (arr[i] >= mmax)
			mmax = arr[i];
		if (arr[i] <= mmin)
			mmin = arr[i];
	}
	if (mmax == 0 && mmin == 0) {
		cout << 0;
		return 0;
	}
	for (int i = l; i >= 1; i--) {
		cout << arr[i];
	}
	return 0;
}