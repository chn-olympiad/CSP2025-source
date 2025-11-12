#include <iostream>
#define int long long
#define F(i, m, n) for(int i = m; i <= n; i++)
using namespace std;
int const N = 505, P = 998244353;
int n, m, c[N], q;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	string s;
	cin >> n >> m >> s;
	q = n;
	F(i, 1, n) {
		cin >> c[i];
		if(c[i] == 0)q--;
	}q = min(++q, n);
	int s1 = 1, s2 = 1;
	F(i, m+1, q)s1=i*s1;
	F(i, 1, q-m)s2=i*s2;
	cout << s1/s2%P;
	return 0;
}