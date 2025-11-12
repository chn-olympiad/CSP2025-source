#include<iostream>
#include<cstring>
#include<algorithm>
const int p= 998244353; int n, m, a[1000]; std::string s;
void sv1(){
	int b[15]; for(int i = 1; i <= n; i++) b[i] = i;
	int rs = 0, ct, sm; do{
		ct = sm = 0; for(int i = 1; i <= n; i++){
			if(ct >= a[b[i]]) ct++;
			else if(s[i] == '0') ct++;
			else sm++;
		} if(sm >= m) rs++;
	} while(std::next_permutation(b + 1, b + n + 1));
	std::cout << rs << '\n';
}
void sv2(){
	int fl = 1; for(int i = 1; i <= n; i++) if(s[i] == '0') fl = 0;
	for(int i = 1; i <= n; i++) if(a[i] == 0) fl = 0;
	if(fl == 0) return std::cout << 0 << '\n', void();
	for(int i = 1; i <= n; i++) fl = 1ll * fl * i % p;
	std::cout << fl << '\n';
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	if(n <= 10) return sv1(), 0;
	if(m == n) return sv2(), 0;
}
