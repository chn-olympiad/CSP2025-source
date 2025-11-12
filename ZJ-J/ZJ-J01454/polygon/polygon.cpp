#include <bitset>
#include <cctype>
#include <cstdio>
#ifndef LOCALDEBUG
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#define _getchar getchar
#else
#define fex(a, b)
#define _getchar getchar
#endif
using namespace std;

unsigned long long read() {
	unsigned long long res=0;
	char c;
	while(!isdigit(c=_getchar()));
	while(isdigit(c)) {
		res=res*10+c-'0';
		c=_getchar();
	}
	return res;
}

const unsigned long long MOD = 998244353;
unsigned long long n, ans, mxa;
unsigned long long a[5005];
bitset<5005> vis;

void search(unsigned long long l, unsigned long long m, unsigned long long s, unsigned long long x) {
//	printf("%lld %lld %lld %lld\n", l, m, s, x);
	if(m>2&&s>2*x)ans=(ans+1)%MOD;
	for(unsigned int i = l+1; i <= n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			search(i, m+1, s+a[i], max(x, a[i]));
			vis[i]=0;
		}
	}
	return ;
}

unsigned long long smul(unsigned long long x, unsigned long long y) {
	unsigned long long res=1;
	for(unsigned int i = x; i <= y; i++)res=(res*i);
	return res;
}

unsigned long long C(unsigned long long n, unsigned long long m) {
	// Choose m things in n things
	printf("C(%lld, %lld)=%lld\n", n, m, smul(n-m+1, n)/smul(1, m));
	return smul(n-m+1, n)/smul(1, m);
}

int main(void) {
	fex("polygon.in", "polygon.out");
	n=read();
	for(unsigned int i = 1; i <= n; i++)a[i]=read(), mxa=max(mxa, a[i]);
	if(mxa==1) {
		for(unsigned int i = 3; i <= n; i++)ans=(ans+C(n, i))%MOD;
		printf("%llu", ans);
		return 0;
	}
	search(0, 0, 0, 0);
	printf("%llu", ans);
	
	return 0;
} // O(n^n) or O(n^2) when max{a_i}=1, 24 points expected, **at most** more 12 to 24 points expected.

// Help me kkksc03!!!!!
// Ayanami_404(983943) here.
// I love CCF, I love Luogu
// So let me get 29 points ok?