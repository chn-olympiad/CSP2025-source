#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1 || n == 2) {
		cout << 0;
		return 0;
	} else if (n == 3) {
		for (int i = 1; i <= n; i++) {
			if (a[i] + a[i + 1] > a[i + 2]) {
				cout << 1;
				return 0;
			} else {
				cout << 0;
				return 0;
			}
		}
	}
	return 0;
}