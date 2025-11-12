#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+10;
const int M=998244353;
int n,a[N],maxn,xxx;
long long ans;
void dfs(int d,int c,int sum,int maxn,int f){
	if(sum>2*maxn&&c>=3&&f){
//		cout<<sum<<" "<<maxn<<" "<<c<<"\n";
		ans++;
		ans%=M;
	}
	if(d>n)return ;
	dfs(d+1,c+1,sum+a[d],max(maxn,a[d]),1);
	dfs(d+1,c,sum,maxn,0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
//	if(n<=20){
		dfs(1,0,0,0,0);
		cout<<ans;
//	}else{
	//	dp[0][0]=1;
//		dp[1][a[1]][a[1]]=1;
//		for(int i=2;i<=n;i++){
//			for(int j=a[i];j<=n*maxn;j++){
//				if(j==a[i]){
//					dp[i][j][a[i]]=(dp[i-1][j][a[i]+1]);
//					continue;
//				}
//				for(int k=a[i];k>=0;k--)xxx=max(xxx,dp[i-1][j-a[i]][k]);
//				dp[i][j][a[i]]=xxx;
//				for(int k=a[i]+1;k<=maxn;k++)dp[i][j][k]=dp[i-1][j-a[i]][k];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n*maxn;j++){
//				for(int k=1;k<=maxn;k++){
//					cout<<dp[i][j][k]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n\n";
//		}
//		cout<<ans;
//	}
	return 0;
}
