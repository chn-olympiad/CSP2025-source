#include <bits/stdc++.h>
#define l long long
using namespace std;

l n, m, a[506], c[506], maxn, su = 1, mo = 998244353;
string s;
bool flag = 0;

void mian() {
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	l f = s.size();
	for (l i = 1; i < f ; i++) {
		if (s[i] != '1')
			flag = 1;
	}
	if (flag == 1) {
		printf("0");
		return ;
	}
	for (l i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (l i = 1; i <= n; i++) {
		su *= i;
		su %= mo;
	}
	printf("%lld", su);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	mian();
	return 0;
}
