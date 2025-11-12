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
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 0, r = 0, a[10010], num = 0, a1, q = 0, p = 1;
	n = read();m = read();
	for (int i = 1; i <= n * m; i++){
		num++;
		a[i] = read(); 
		if (i == 1) a1 = a[i];
	}
	sort(a, a + num);
	p = n * m;
	for (int i = n; i > 0; i--){
		q++;
		c++;
		for (int j = m; j > 0; j--){
			p--;
			if (r == m) r++;
			if (isp(q)) {
				r++;
			} else {
				r--;
			}
			if (a1 == a[p]) {
				cout << c << " " << r ;
				break;
			}
		} 
	}
}











