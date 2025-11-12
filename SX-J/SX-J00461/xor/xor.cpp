#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], sum, num, b[20][20];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0 ; i < l ; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum += s[i];
		}
	}
	for (int i = 0 ; i < sum.size() ; i++) {
		for (int j = 0 ; j < n.size() ; j++) {
			if (n[j] < n[j] + 1) {
				n[j]++;
			}
		}
	}
	cout << n[j];
	return 0;
}