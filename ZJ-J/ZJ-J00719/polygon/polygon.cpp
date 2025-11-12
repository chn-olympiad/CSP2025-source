#include<bits/stdc++.h>
#define lb(x) (x&(-x))
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=5e3+10,mod=998244353;
ll ans,f[N],cnt[N],maxn;
int n,a[N];
set<int>s;
void add(ll x,ll d){while(x<=5000)f[x]=(f[x]+d)%mod,x+=lb(x);}
ll sum(ll x){ll res=0;while(x)res=(res+f[x])%mod,x-=lb(x);return res;}
inline ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%mod;
		b>>=1,a=(a*a)%mod;
	}
	return res%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();	
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++)ans=((ans+qpow(2,i-1)-i)%mod+mod)%mod;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i>=3)ans=(((ans+sum(5000)+maxn-sum(a[i]))%mod)+mod)%mod;
		maxn=(maxn*2)%mod;
		for(auto j=s.end();j!=s.begin();){
			j--;
			if(*j+a[i]<=5000)add(*j+a[i],cnt[*j]),cnt[*j+a[i]]=(cnt[*j+a[i]]+cnt[*j])%mod;
			else maxn=(maxn+cnt[*j])%mod;
		}
		for(auto j=s.end();j!=s.begin();){
			j--;
			if(a[i]+*j<=5000)s.insert(a[i]+*j);
		}
		for(int j=1;j<i;j++){
			if(a[i]+a[j]<=5000)add(a[j]+a[i],1),cnt[a[i]+a[j]]=(cnt[a[i]+a[j]]+1)%mod,s.insert(a[j]+a[i]);	
			else maxn=(maxn+1)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
luogu uid:1113349
name I_Love_Furina
Genshin Impact uid :275713829 
*/

//100pts+100pts+100pts+80pts=380pts