#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
int n;
int a[50010];
int qzh[50010];
int flag=1;
ll dp[5010][5010];
ll ans;
void dfs(int k,int mx,int s,int sum){
	if(k>n){
//		cout<<mx<<"  "<<s<<"  "<<sum<<endl;
		if(mx!=INT_MIN&&s>=3&&sum>2*mx)
		ans++;
		ans%=mod;
		return;
	}
	if(qzh[n]-qzh[k-1]+sum<=mx){
		return;
	}
	if(s+n-k+1<3){
		return;
	}
	dfs(k+1,max(mx,a[k]),s+1,sum+a[k]);
	dfs(k+1,mx,s,sum);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(int i=0;i<=n;i++) dp[0][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
				dp[i][j]%=mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans+=dp[i][n];
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,INT_MIN,0,0);
	cout<<ans;
	return 0;
}
