#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000], k;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int lens = s.length();
	for (int i = 0; i < lens; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[k] = s[i] - '0';
			k++;
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cout << a[i];
	}
	return 0;
}
