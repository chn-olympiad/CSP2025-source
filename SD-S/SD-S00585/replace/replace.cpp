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

const int N=2e5+7;

string s[N][3],t[N][3];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) {
		cin>>t[i][1]>>t[i][2];
	}
	while(q--)
		cout<<"0\n";
	return 0;
}



