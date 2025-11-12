#include<bits/stdc++.h>
using namespace std;
int n,ans=0,mod=998244353,a[5005],s[5005];
void dfs(int d,int maxn,int tot,int cnt){
	if(maxn*2>s[n]-s[d-1]+tot)return ;
	if(d>n){
		if(cnt<3)return ;
		if(tot>maxn*2)ans++;
		ans%=mod;
		return ;
	}
	dfs(d+1,max(maxn,a[d]),tot+a[d],cnt+1);
	dfs(d+1,maxn,tot,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		if(i>=2&&a[i]!=a[i-1])flag=1;
	}
	if(flag==0){
		ans=-1-n-(n-1)*n/2;
		int p=1;
		for(int i=1;i<n;i++)ans+=p,p*=2,p%=mod,ans%=mod;
		printf("%d",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
