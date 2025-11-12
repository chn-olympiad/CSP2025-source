#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],maxn=0,c[5005][5005],ans=0,qz[5005],lg[5005],st[5005][20];
int MOD=998244353;
void init(){
	for(int i=0;i<=n;i++){
		c[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
		}
	}
}
void dfs(int x,int last,int sum,int cnt){
	if(x==n+1){
		if(cnt>=3&&sum>2*a[last]){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	dfs(x+1,x,sum+a[x],cnt+1);
	dfs(x+1,last,sum,cnt);
}
signed main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);maxn=max(maxn,a[i]);
	}
	init();
	if(n<3){
		printf("0\n");
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[n]<a[n-1]+a[n-2])printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	printf("%lld\n",ans/2);
    return 0;
}
