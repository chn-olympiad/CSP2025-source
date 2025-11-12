#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5100;
const LL mod=998244353;
LL n,a[N],ans,Maxs;
void dfs(LL k,LL sum,LL maxs){
	if(k==n+1){
		if(sum>2*maxs) ans=(ans+1)%mod;
	}else{
		dfs(k+1,sum,maxs);
		dfs(k+1,sum+a[k],max(maxs,a[k]));
	} 
}
LL Pow(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],Maxs=max(Maxs,a[i]);
	if(Maxs==1){
		ans=(Pow(2,n)-n+mod)%mod;
		ans=(ans-n*(n-1)%mod*Pow(2,mod-2)%mod+mod)%mod;
		ans=(ans-1+mod)%mod;
		cout<<ans;
	}else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}