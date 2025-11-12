#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,t,a[100005][4],tot[4],vis[100005];
ll ans,dp[100005][4],tmp;
int read(){
	int x=0,f=1;char aa=getchar();
	while(aa<'0'||aa>'9'){
		if(aa=='-')f=-1;
		aa=getchar();
	}
	while('0'<=aa&&aa<='9'){
		x=x*10+aa-'0';
		aa=getchar();
	}
	return x*f;
}
void dfs(int part,int peo,ll cnt,int total){
	if(vis[peo]||tot[part]>=n/2)return;
	if(total==n){
		if(cnt>ans)ans=cnt;
		return;
	}
	vis[peo]=1;
	tot[part]++;
	for(int i=1;i<=3;i++){
		dfs(i,peo+1,cnt+a[peo][part],total+1);
	}
	vis[peo]=0;
	tot[part]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		n=read();
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(vis));
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		if(n<30){
			for(int i=1;i<=3;i++){
				dfs(i,1,0,0);
			}	
		}
		else{	
			for(int k=1;k<=n;k++){
				for(int i=1;i<=3;i++){
					for(int j=n/2;j>=1;j--){
						dp[j][i]=max(dp[j][i],dp[j-1][i]+a[k][i]);
					}
				}
			}
			for(int i=1;i<=2;i++){
				tmp=0;
				for(int j=0;j<=n/2;j++)tmp=max(tmp,dp[j][i]);
				ans+=tmp;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//Expected:AC on #1~4,WA on #5~~20. I can get 20 points!!!
