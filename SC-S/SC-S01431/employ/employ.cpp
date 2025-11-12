
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int n, m, a, cnt = 0;
int solve(int x, int y) {
	int s1 = 1;
	for (int i = x; i <= y; i++)	s1 = s1*i % p;
	return s1;
}

signed main() {
	cin.tie(0), cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a == 0)	cnt++;
	}
	if (n - cnt < m) {
		cout << 0;
		return 0;
	}


	cout << (solve(1, n - 1)*cnt + solve(1, n)) % p;


	return 0;
}
/*
5 3
12345

*/