#include <bits/stdc++.h>

const int N = 5e2 + 10;

using namespace std;

int n, m;
string s;
long long sum = 1;
int a[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= 998244353;
	}
	cout << sum;
	return 0;
}

