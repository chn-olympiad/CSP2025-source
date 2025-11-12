#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
int a[500005];
bool b[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		int n11 = 0, n0 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0 && b[i] == 0) {
				n0++;
				b[i] = 1;
			}
		}
		for (int i = 2; i <= n; i++) {
			if ((a[i] == 1 && a[i - 1] == 1)
			        && (b[i] == 0 && b[i - 1] == 0 ) ) {
				n11++;
				b[i] = 1;
				b[i - 1] = 1;
			}
		}
		cout << n11 + n0 ;
	} else if (k == 1) {
		int n1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && b[i] == 0) {
				n1++;
			}
		}
		cout << n1;
	}
	return 0;
}
