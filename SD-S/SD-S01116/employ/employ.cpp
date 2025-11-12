#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define L(i,l,r) for(int i(l);i<=(r);++i)
#define R(i,r,l) for(int i(r);i>=(l);--i)
using namespace std;
const int N=5e2+10,inf=0x7fffffff,mod=998244353; 
int n,m,s[N],c[N],p[N],ans;
//int f[N][N][N],cnt[N],fac[N],ifac[N];
//int fpow(int x,int y){
//	int res=1;
//	while(y){
//		if(y&1)res=res*x%mod;
//		x=x*x%mod,y>>=1;
//	}
//	return res;
//}
//void add(int &x,int y){
//	x+=y;
//	if(x>=mod)x-=mod;
//}
//int C(int n,int m){
//	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
//}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	fac[0]=1;
//	L(i,1,N-1)fac[i]=fac[i-1]*i%mod;
//	ifac[N-1]=fpow(ifac[N-1],mod-2);
//	R(i,N-2,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	cin>>n>>m;
	if(n<=10){
		L(i,1,n){
			char c;
			cin>>c;
			s[i]=c-'0';
		}
		L(i,1,n)cin>>c[i];
		sort(c+1,c+1+n);
		L(i,1,n)p[i]=i;
		do{
			int tot=0;
			L(i,1,n)if(c[p[i]]<=tot||(s[i]==0))++tot; 
			if(n-tot>=m)++ans;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
	return 0;
}
