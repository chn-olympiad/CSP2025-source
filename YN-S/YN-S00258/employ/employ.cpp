#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[505];

long long digui(int n) {
	int cnt = 0;
	if (n == 1) {
		return 1;
	}
	return digui(n - 1) * digui(n - 1) + c[cnt++];
}
long long sum;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >>  c[i];
	}
	sum = digui(n) % 998244353;
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}