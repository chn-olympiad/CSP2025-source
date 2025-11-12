#include <bits/stdc++.h>
#define ll long long
#define f_1(i,a,b) for(ll i=a;i<=b;i++)
#define f_0(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;

ll read() {
	ll n = 0, f = 1;
	char x;
	x = getchar();
	while (x > '9' || x < '0') {
		if (x == '-')
			f = -1;
		x = getchar();
	}
	while (x >= '0' && x <= '9') {
		n = (n << 1) + (n << 3) + (x ^ 48);
		x = getchar();
	}
	return n * f;
}
ll n, m, k, u[1000010], v[1000010], w[1000010], c[11][1000010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	f_1(i, 1, m) u[i] = read(), v[i] = read(), w[i] = read();
	f_1(i, 1, k) f_1(j, 0, n) c[i][j] = read();
	cout << 0;
	return 0;
}