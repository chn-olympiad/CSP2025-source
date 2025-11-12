#include <algorithm>
#include <cctype>
#include <cstdio>
#ifndef LOCALDEBUG
#define _getchar getchar
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#define dfex(a, b)
#else
#define _getchar getchar
#define fex(a, b)
#define dfex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=_getchar()))if(c=='-')f=-f;
	while(isdigit(c)) {
		res=res*10+c-'0';
		c=_getchar();
	}
	return res*f;
}

bool cmp(long long x, long long y) {
	return x>y;
}

long long n, m, nm, d, c, r, a1;
long long a[105];

int main(void) {
	fex("seat.in", "seat.out");
//	dfex("seat3.in", "seat3.out");
	n=read();m=read();nm=n*m;
	for(int i = 1; i <= nm; i++) {
		a[i]=read();
		if(i==1)a1=a[i];
	}
	sort(a+1, a+nm+1, cmp);
	for(int i = 1; i <= nm; i++) {
		if(a[i]==a1) {
			d=i;break;
		}
	}
//	printf("%lld\n", d);
	c=(d+n-1)/n;
	if(c&1) {
		r=(d-1)%n+1;
	}
	else {
		r=n-(d-1)%n;
	}
	printf("%lld %lld", c, r);
	
	return 0;
} // O(n \times m), 100 points expected.
