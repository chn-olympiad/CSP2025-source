#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read() { //快读
	ll ans = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = (ans << 3) + (ans << 1) + ch - '0';
		ch = getchar();
	}
	return f * ans;
}

bool isp (ll n) { //六倍定理-指数判断
	if (n < 2) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 6 != 1 && n % 6 != 5) return 0;
	ll x = sqrt(n);
	for (int i = 5; i <= x; i += 6) if (n % i == 0 || n % (i + 1) == 0) return 0;
	return 1;
}

int main(){

}

