#include <bits/stdc++.h>
using namespace std;
int n, m, d;
string s;

long long jc(int x) {
	long long sum = 1;
	for (int i = 2; i <= x; i ++) {
		sum *= i;
		sum %= 998244353;
	}
	return sum;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int c;
		cin >> c;
		if (c != 0) {
			d ++;
		}
	}
	printf("%lld", jc(d));
	return 0;
}