#include <bits/stdc++.h>
using namespace std;
int b[1010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int a = s.size();
	long long ans = 0;
	cin >> s;
	for (int i = 0; i <= a; i++) {
		b[i + 1] = s[i];
		ans++;
	}
	for (int i = ans; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (b[j] <= b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 1; i <= ans; i++) {
		cout << b[i];
	}
	return 0;
}