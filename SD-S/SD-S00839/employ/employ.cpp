//See You, My OIer Life 

#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 2e5 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

ll n, m;
std::string s;
int a[MAXN], p[MAXN];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	std::cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++)
		a[i] = read(), p[i] = i;
	ll ans = 0;
	do {
		ll res = 0, cur = 0;
		for (int i = 1; i <= n; i++) {
			if(res >= a[p[i]] || s[i] == '0') ++res;
			else ++cur;
		}
		if(cur >= m) ++ans;
	}while(std::next_permutation(p + 1, p + n + 1));
	std::cout << ans << '\n';
	return 0;
}

