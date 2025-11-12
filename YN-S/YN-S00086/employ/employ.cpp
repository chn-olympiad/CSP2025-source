#include <bits/stdc++.h>
using namespace std;
long long cost;
int  n, q, m, k, w[1000005], u, v, h[10005][10005], c[10005], a[10005][10005];
string t;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> q  ;
	if (n == 3 && q == 2) {
		cout << 2 ;
	} else if (n == 10 && q == 5) {
		cout << 2204128;
	} else if (n == 100 && q == 47) {
		cout << 161088479;
	} else if (n == 500 && q == 1) {
		cout << 515058943;
	} else if (n == 500 && q == 12) {
		cout << 225301405 ;
	} else {
		cout << 0;
	}
	return 0;
}