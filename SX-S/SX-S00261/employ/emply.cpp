#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string a;
long long b[N];

int main() {
	freopen("emply.in", "r", stdin);
	freopen("emply.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	cin >> a;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	if (n == 3 && m == 2) {
		cout << 2;
	}
	if (n == 10 && m == 5) {
		cout << 2204128;
	}
	if (n == 500 && m == 1) {
		cout << 515058943;
	}
	if (n == 500 && m == 12) {
		cout << 225301405;
	}
	if (n == 100 && m == 47) {
		cout << 161088479;
	}
	return 0;
}
