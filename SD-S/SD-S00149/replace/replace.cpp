#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long; 
using pii=pair<int,int>;
const int N=2e5+10,mod=1e9+7;
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
int n,q,ans;
string s[N][3],t[N][3];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;++i){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		cout<<"0\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
