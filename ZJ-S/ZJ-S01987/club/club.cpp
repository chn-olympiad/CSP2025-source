#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,a[5][N],ans,f1,f2,dp[1000][1000];
void dfs(int d,int s1,int s2,int s3,int sum){
	if(s1>n/2||s2>n/2||s3>n/2)return ;
	if(d>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(d+1,s1+1,s2,s3,sum+a[1][d]);
	dfs(d+1,s1,s2+1,s3,sum+a[2][d]);
	dfs(d+1,s1,s2,s3+1,sum+a[3][d]);
	
}
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0,f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[3][i])f1=0;
			if(a[2][1])f2=0;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}else if(f1&&f2){
			sort(a[1]+1,a[1]+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[1][i];
			cout<<ans<<"\n";
			continue;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=min(i,n/2);j++){
					dp[j][i-j]=max(dp[j-1][i-j]+a[1][i],dp[j][i-j-1]+a[2][i]);
					
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<dp[i][n-i]<<"\n";
//			}
			cout<<dp[n/2][n/2]<<"\n";
		}
	}
	
	return 0;
}
