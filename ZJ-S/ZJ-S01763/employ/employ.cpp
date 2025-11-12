#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,maxn=505;
ll n,m,c[maxn],i,f,res,ans1=1,ans2=1;
string s;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]!='0') res=(res+1)%mod;
		}
		cout<<res;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) res=res*i%mod;
		cout<<res;
		return 0;
	}
	sort(c+1,c+n+1);
	while(!c[++i]);
	for(;i<=n;i++){
		if(f<c[i]) res=(res+1)%mod;
		else f++;
	}
	for(int i=res+1;i<=n-res+1;i++) ans1=ans1*i%mod;
	for(int i=1;i<=res;i++) ans2=ans2*i%mod;
	cout<<ans1*qpow(ans2,mod-2)%mod;
	return 0;
}
/*
By ZJ-S01763.
Luogu UID:1086453.
*/
