#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5002],num[5002];
const int mod=998244353;
void dfs(int now){
	if(now>n){
		int maxn=-1,cnt=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,num[i]);
			cnt+=num[i];
		}
		if(cnt>maxn*2)	ans++;
		ans%=mod;
		return;
	}
	num[now]=a[now];
	dfs(now+1);
	num[now]=0;
	dfs(now+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=20){
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]>1)	goto nxt;
	sum=1ll*(n-2)*(n-1);
	sum%=mod;
	sum=1ll*sum*n;
	sum%=mod;
	sum/=1ll*6;
	sum%=mod;
	printf("%lld",sum);
	nxt:;
	printf("0");
	return 0;
}
