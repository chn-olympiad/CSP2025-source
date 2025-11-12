#include<bits/stdc++.h>

using namespace std;

const int N=5e3+5,mod=998244353;

int a[N],ans;

long long c[N][N];

int n;

void dfs(int i,int cnt,int ma,int sum){
	if(i>n){
		if(cnt>=3){
			if(sum>2*ma){
				ans++;
				if(ans>=mod) ans-=mod;
			}
		}
		return ;
	}
	dfs(i+1,cnt+1,max(ma,a[i]),sum+a[i]);
	dfs(i+1,cnt,ma,sum);
}

int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	scanf("%d",&n);
	if(n>20){
		c[0][0]=1;
		for(int i=1;i<N;i++){
			for(int j=0;j<=i;j++){
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=(ans+c[n][i])%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,-1,0);
	printf("%d",ans);
	return 0;
}
/*
ccf is really good,so please to give me 1=.
I love ccf!!!!!!!!!!!!
感觉预期324，可能会高一点
*/
