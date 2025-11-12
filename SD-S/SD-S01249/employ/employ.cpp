#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
ll perm[1000010];
bool c[1000010];
ll arr[1000010],a[1000010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n=read(),m=read(),ans=0;
	bool cmp=1;
	ll cnttt=0,zero=0;
	for(ll i=1;i<=n;i++){
		perm[i]=i;
		char cc=getchar();
		while(cc!='0'&&cc!='1') cc=getchar();
		c[i]=(cc=='1'),cmp&=c[i],cnttt+=c[i];
	} 
	putchar('\n\n\n');
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==0) zero++;
	}
	if(cmp||(m==n&&cnttt==n)){
		ll ans=1;
		for(ll i=1;i<=n-zero;i++) (ans*=i)%=mod;
		cout<<ans;
		return 0;
	}
	do{
		for(ll i=1;i<=n;i++) arr[i]=a[perm[i]];
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			ll pre=i-cnt-1;
			if(pre>=arr[i]) continue;
			cnt+=c[i];
		}
		if(cnt>=m) ans++;
	}while(next_permutation(perm+1,perm+n+1));
	cout<<ans;
	return 0;
}
