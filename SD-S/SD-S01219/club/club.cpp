#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long t,n,a[N][5],l;
long long dp[N],ans,f;
void dfs(int x,int c1,int c2,int c3){
	if(x>n){
		ans=max(ans,dp[n]);
		return ;
	}
	if(c1<l){
		dp[x]=dp[x-1]+a[x][1];
		dfs(x+1,c1+1,c2,c3);
	}
	if(c2<l){
		dp[x]=dp[x-1]+a[x][2];
		dfs(x+1,c1,c2+1,c3);
	}
	if(c3<l){
		dp[x]=dp[x-1]+a[x][3];
		dfs(x+1,c1,c2,c3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		l=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=3;j++){
				if(a[i][j]!=0){
					f=1;
				}
			}
		}
		
		ans=0;
		
		dfs(1,0,0,0);
		
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
