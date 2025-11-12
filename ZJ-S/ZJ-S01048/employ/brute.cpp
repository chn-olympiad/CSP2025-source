#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read(){ ll x; scanf("%lld",&x); return x; }

const int mod = 998244353;

int n,m,c[505],qz[505],seq[505]; char s[505];

int f[505][505][505], C[505][505], fac[505];
inline void addmod(int &x){ (x>=mod) && (x-=mod); }

void procedure(){
	n=read(),m=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read(),seq[i]=i;

	int ans = 0;
	do{
		int fl=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') fl++;
			else if(fl>=c[seq[i]]) fl++;
		}
		if(fl <= n-m){
			ans ++;
			// cout<<"fl = "<<fl<<endl;
			for(int i=1;i<=n;i++) cout<<c[seq[i]]<<" "; cout<<endl;
		}
	}while(next_permutation(seq+1,seq+n+1));

	printf("%d\n", ans);
}
int main(){
	assert(freopen("employ.in","r",stdin));
	assert(freopen("employ.ans","w",stdout));
	ll T=1;
	while(T--) procedure();
}