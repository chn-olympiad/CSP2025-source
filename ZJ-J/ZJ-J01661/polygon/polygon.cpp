#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],b[5010],MOD=998244353,ans;
void dfs(int t,int cnt,int s){
	if(t==n+1){
		if(cnt>2){if(s>2*b[cnt])++ans;}
		return ;
	}
	dfs(t+1,cnt,s);
	b[++cnt]=a[t];
	dfs(t+1,cnt,s+a[t]);
	--cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0);
		printf("%lld",ans%MOD);
	}
	else{
		ans=1;
		for(int i=1;i<=n;++i)ans=ans*2%MOD;
		ans=ans-1-n-n*(n-1)/2;
		printf("%lld",(ans+MOD)%MOD);
	}
}