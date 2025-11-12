//#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
//#include <ext/vstring.h>
//#include <iostream>
#ifdef LOCALDEBUG
#define fex(a, b)
#else
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;
using namespace __gnu_cxx;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	while(isdigit(c)) res=res*10+c-'0', c=getchar();
	return res*f;
}

const long long MOD=998244353;
//__vstring v;
bitset<505> s;
long long m;
long long n;
long long ans;
long long c[505], h[505], d[505];

void search(long long x, long long g, long long a) {
//	printf("%lld %lld %lld\n", x, g, a);
	if(n-g<m)return ;
	if(x>n) {
		if(n-g>=m)ans=(ans+a)%MOD;
		return ;
	}
	for(int i = 0; i <= n; i++) {
		if(h[i]) {
			h[i]--;
			search(x+1, g+(i<=g||!s[x]), (a*h[i]+a)%MOD);
			h[i]++;
		}
	}
	return ;
}

int main(void) {
	fex("employ.in", "employ.out");
	n=read();m=read();
//	getline(cin, v);
//	long long i=1;
//	for(__vstring::iterator it=v.begin(); it!=v.end(); it++, i++) {
//		if(*it=='1')s[i]=1;
//		d[i]=d[i-1]+s[i];
//	}
	for(int i = 1; i <= n; i++) {
		char c;
		while(!isdigit(c=getchar()));
		if(c=='1')s[i]=1;
		d[i]=d[i-1]+s[i];
	}
	for(int i = 1; i <= n; i++)h[c[i]=read()]++;
//	sort(c+1, c+n+1);
//	printf("%lld", c[1]);
	search(1, 0, 1);
	printf("%lld\n", ans);
	
	return 0;
}

// Hello, if someone is looking at this page.
// ...Who am I?
// Well, I am Ayanami_404, my Luogu UID is 983943.
// Why am I telling you my UID?
// I don't know.
// So, let's turn the time back to the first day I was in XSOI Team.
// My school didn't have OI teams, so I was studying OI in XSOI.
// I love OI, but today is my last time taking part in such a OI competition.
// You might noticed that I've also taken part in the morning's Junior Group.
// Ok, ok, I've messed it up.
// So it might be my last time taking part in OI, in my life.
// So just take it easy.
// You are the OIer.
// Good luck. Farewell.
// Launch the game! Genshin Impact!
// Chtholly KAWAIIIIIIIIIIIIIII
// I love CCF, give me 1= pls
// I love Luogu, pls pls pls pls
// I love OI, so pls give me 1= 1= 1= 1= 1=
// rp+=INF;
// return 0;
