#include <bits/stdc++.h>
using namespace std;
#define getc getchar
inline long long read(){
	char c = getc() , f = 1;
	while (c > '9' || c < '0'){
		if (c == '-')f = -1;
		c = getc();
	}
	long long p = 0;
	while (c >= '0' && c <= '9'){
		p = p * 10 + c - '0';
		c = getc();
	}
	return p * f;
}
const long long mod = 998244353;
inline long long qpow(long long n , int p = mod - 2){
	long long ans = 1;
	while (p){
		if (p & 1)ans = ans * n % mod;
		n = n * n % mod;
		p >>= 1;
	}
	return ans;
}
int n , m , a[505] , v[505];
char s[505];
long long fac[505] , inv[505];
signed main(){
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	n = read() , m = read();
	int ans = 0;
	scanf ("%s" , (s + 1));
	for (int i = 1;i <= n;++i){
		v[i] = read();
		a[i] = i;
	}
	do{
		int num = 0;
		for (int i = 1;i <= n;++i){
			if (s[i] == '0' || num >= v[a[i]]){
				num++;
			}
		}

		if (n - num >= m)ans++;
	}while (next_permutation(a + 1 , a + n + 1));
	printf ("%d" , ans);
	return 0;
}
