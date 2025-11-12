#include <bits/stdc++.h>
using namespace std;
int a[10], n[1000005], sum = 0, c = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		n[i] = -1;
		if (s[i] >= '0' && s[i] <= '9') {
			n[sum] = s[i] - '0' ;
			sum++;
		}
	}
	sort(n, n + s.size());
	for (int i = s.size() - 1; i >= s.size() - sum; i--) {
		if (n[i] >= 0) {
			cout << n[i];
		}
	}
	return 0;
}
