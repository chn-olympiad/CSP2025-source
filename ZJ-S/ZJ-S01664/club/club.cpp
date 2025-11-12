#include<bits/stdc++.h>
using namespace std;
int T,n;
const int MAXN=250;
struct as{
	int c1,c2,c3;
}a[MAXN+5];
int dp[MAXN+5][MAXN/2+5][MAXN/2+5];
bool cmp(as a,as b){
	return a.c1>b.c1;
}
int ans;
void solve(){
	scanf("%d",&n);
	ans=0;
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
		ans+=a[i].c3;
		a[i].c1-=a[i].c3;
		a[i].c2-=a[i].c3;
		a[i].c3=0;
	}
	bool flagA=false;
	for(int i=0;i<n;++i){
		if(a[i].c2!=0){
			flagA=true;
			break;
		}
	}
	if(flagA==false){
		sort(a,a+n,cmp);
		long long sum=0;
		for(int i=0;i<=n/2;++i)sum+=a[i].c1;
		printf("%d\n",sum);
		return;
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=i+1&&j<=n/2;++j){
			for(int k=0;k<=i-j+1&&k<=n/2;++k){
				dp[i][j][k]=0;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<=i+1&&j<=n/2;++j){
			for(int k=0;k<=i-j+1&&k<=n/2;++k){
				if(j>0){
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]+a[i].c1);
				}
				if(k>0){
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k-1]+a[i].c2);
				}
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
			}
		}
	}
//	for(int i=0;i<n;++i){
//		for(int j=0;j<=i+1&&j<=n/2;++j){
//			for(int k=0;k<=i-j+1&&k<=n/2;++k){
//				printf("%d %d %d:%d\n",i+1,j,k,dp[i+1][j][k]);
//			}
//		}
//	}
	int maxn=0;
	for(int j=0;j<=n/2;++j){
		for(int k=n/2-j;k<=n/2;++k){
			maxn=max(maxn,dp[n][j][k]);
		}
	}
	printf("%d\n",maxn+ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
1 4
3 1 0
-1 -2 0
1 -1 0
2 4 0*/

