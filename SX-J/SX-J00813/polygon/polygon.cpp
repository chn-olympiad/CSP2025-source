#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long t[10086], yu[10086], hz[10086];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ma = -1;
	long long as = 0;
	cin >> n;
	int f[5005], d[5005];
	long long num = 0;
	for (int i = n; i >= 3; i--) {
		f[i] = (i - 1) * (i - 2) / 2;
		as += f[i] * (n - i + 1);
		as %= M;
	}

	cout << as << endl;
}
