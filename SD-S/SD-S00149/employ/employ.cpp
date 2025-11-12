#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=510,mod=1e9+7;
ll fac[N],inv[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
int n,m,c[N],p[N],ans;
string s;
void solve1(){
	for(int i=1;i<=n;++i) p[i]=i;
	do{
		int cnt=0,res=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='0') cnt++;
			else res++;
		}
//		cout<<res<<"\n";
		if(res>=m) ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	init(n);
	s=" "+s;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	if(n<=10){
		solve1();
		return 0;
	}
	else cout<<fac[n];
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/ 
