#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
int T;
int n,a[N][3],b[N],dp[205][105];
int ans;
bool A,B,C;
bool cmp(int a,int b){return a>b;}
void dfs(int dep,int sum,int x,int y,int z){
	if(dep>n){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2) dfs(dep+1,sum+a[dep][0],x+1,y,z);
	if(y<n/2) dfs(dep+1,sum+a[dep][1],x,y+1,z);
	if(z<n/2) dfs(dep+1,sum+a[dep][2],x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		A=B=C=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]) A=0;
			if(a[i][2]) B=0;
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}else if(A){
			for(int i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<'\n';
		}else if(B){
			memset(dp,128,sizeof dp);
			dp[0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][1]);
					if(j) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][0]);
				}
			}
			cout<<dp[n][n/2]<<'\n';
		}
	}
	return 0;
}
