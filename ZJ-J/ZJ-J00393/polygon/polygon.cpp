//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,ans,a[N],fac[N],inv[N];
void dfs(int x,int cnt,int sum,int mx){
	if(cnt>2&&sum>mx*2)ans=(ans+1)%mod;
	if(x==n)return;
	for(int i=x+1;i<=n;i++)dfs(i,cnt+1,sum+a[i],a[i]);
}
bool flag;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=(res*x)%mod;
		k>>=1;
		x=(x*x)%mod;
	}
	return res;
}
int C(int x,int y){return fac[y]*inv[x]%mod*inv[y-x]%mod;}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=1;	
	}
	if(!flag){
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
		inv[0]=qpow(1,mod-2);
		for(int i=3;i<=n;i++)ans=(ans+C(i,n))%mod;
		cout<<ans;
	}
	else{
		ans=0;
		sort(a+1,a+n+1);
		dfs(0,0,0,0);
		cout<<ans;
	}
	return 0;
}
