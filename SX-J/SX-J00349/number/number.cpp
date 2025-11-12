#include <bits/stdc++.h>
using namespace std;
string a;
int n1um[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			n1um[a[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (n1um[i] > 0) {
			for (int j = 0; j < n1um[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
