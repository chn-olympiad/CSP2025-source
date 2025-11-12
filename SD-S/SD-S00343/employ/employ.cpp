#include <bits/stdc++.h>
#define LL long long 
using namespace std;

inline LL read(){
	LL x = 0,f = 1;
	char c = getchar();
	while(c > '9'|| c < '0'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' &&c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * f;
}

const int N = 1e5 + 10, MOD = 998244353;

LL n, m;
LL c[N];
string s;
LL ans = 1;

int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();
	cin >> s;
	LL op = n;
	for(int i = 1;i <= n;i ++ ) c[i] = read();
	for(int i = 1;i <= n;i ++ ){
		if(c[i] == 0)  op ++ ;
	}
	for(int i = 1;i <= op; i++ ) {
		ans = (ans * i) % MOD;
	}
	printf("%lld", ans);
	return 0;	
}
