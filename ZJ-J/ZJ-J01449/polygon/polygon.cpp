#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5007;
int num[N],pre[N];
long long dp[N][N],ans;
int dfs(int m,int k){//1-n find add<k
//	if(dp[m][k]!=-1){
//		return dp[m][k];
//	}
	if(k<=0){
		return 0;
	}else if(m==0){
	//	printf("%d\n",k);
		ans++;
		return 1ll;
	}
	dp[m][k]=(dfs(m-1,k)%mod+dfs(m-1,k-num[m])%mod)%mod;
	return dp[m][k];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	if(n==3){
		printf("%d\n",(num[1]+num[2])>num[3]);
	}else{
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+num[i];
		}
		for(int i=3;i<=n;i++){//O(n^2)
			int x=pre[i-1]-num[i];
			long long ans1=dfs(i-1,x);
		}
		printf("%d\n",ans);
	}
	return 0;
}
