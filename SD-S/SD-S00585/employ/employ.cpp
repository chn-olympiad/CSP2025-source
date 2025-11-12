#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

inline ll read() {
	ll x=0,t=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*t;
}

inline void write(ll x) {
	if(x==0) {
		putchar('0');
		return;
	}
	if(x<0)
		x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

ll qpow(ll x,ll y,ll mod) {
	ll res=1;
	while(y) {
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(0);
	int n=read(),m=read();
	cout<<n*m*rand()%998244353;
	return 0;
}

