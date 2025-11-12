#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205,NN=1e5+5;
int dp[2][N][N],ddp[2][NN],t,n,a[NN][4],xl[NN],ans;
int checka,checkb;
int check(){
	int res=0;
	for(int i=1;i<=n;i++)
		res+=a[i][xl[i]];
	return res;
}
void dfs(int now,int sum1,int sum2,int sum3){
	if(now==n+1){
		ans=max(ans,check());
		return ;
	}
	if(sum1<n/2){
		xl[now]=1;
		dfs(now+1,sum1+1,sum2,sum3);
	}
	if(sum2<n/2){
		xl[now]=2;
		dfs(now+1,sum1,sum2+1,sum3);
	}
	if(sum3<n/2){
		xl[now]=3;
		dfs(now+1,sum1,sum2,sum3+1);
	}
//	xl[now]=0;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			checka+=a[i][1]+a[i][3];
			checkb+=a[i][3];
		}
		if(!checka){
			for(int i=1;i<=n;i++)
				xl[i]=a[i][2];
			sort(xl+1,xl+n+1);
			int res=0;
			for(int i=n;i>n/2;i--)
				res+=xl[i];
			cout<<res<<'\n';
			continue;
		}
//		if(!checkb){
//			memset(ddp,0,sizeof ddp);
//			ddp[1][0]=a[1][2];
//			ddp[1][1]=a[1][1];
//			ans=max(ddp[1][0],ddp[1][1]);
//			for(int i=2;i<=n;i++){
//				for(int j=0;j<=min(n/2,i);j++){
//					if(j<i)ddp[i%2][j]=ddp[(i+1)%2][j]+a[i][2];
//					if(j>0&&j<=n/2)ddp[i%2][j]=max(ddp[i%2][j],ddp[(i+1)%2][j-1]+a[i][1]);
//					ans=max(ans,ddp[i%2][j]);
//				}
//			}
//			cout<<ans<<'\n';
//			continue;
//		}
		if(n<=10){
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		memset(dp,0,sizeof dp);
		dp[1][1][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		dp[1][0][0]=a[1][3];
		ans=max(max(dp[1][1][0],dp[1][0][1]),dp[1][0][0]);
		for(int i=2;i<=n;i++){
			for(int j=0;j<=min(n/2,i);j++){
				for(int k=0;k<=min(n/2,i-j);k++){
					if(j+k<i&&(i-(j+k))<=n/2)dp[i%2][j][k]=dp[(i+1)%2][j][k]+a[i][3];
					if(j>0&&j<=n/2)dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i+1)%2][j-1][k]+a[i][1]);
					if(k>0&&k<=n/2)dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i+1)%2][j][k-1]+a[i][2]);
					ans=max(ans,dp[i%2][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
