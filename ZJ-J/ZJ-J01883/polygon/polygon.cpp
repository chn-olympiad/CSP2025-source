#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,M=300,inf=1e18,mod=1e9+7;
int n,a[N],ans,nd;
bool vis[N];
void dfs(int x){
	if(x==nd+1){
		int maxn=-inf,sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				//cout<<a[i]<<" ";
				maxn=max(a[i],maxn);
				sum+=a[i];
			}		
		} 
		//cout<<"\n";
		if(sum>maxn*2){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])break;
		vis[i]=true;
		dfs(x+1);
		vis[i]=false;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flg=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flg=false;
	}
	if(flg){
		int sum=0;
		for(int i=3;i<=n;i++){
			sum+=(n-(i-1));
		}
		cout<<sum;
		return 0;
	}
	for(int i=3;i<=n;i++){
		nd=i;
		dfs(1);
		//for(int i=1;i<=n;i++)vis[i]=false;
	}
	cout<<ans;
	/*
	sort(a+1,a+n+1);
	for(int op=n;op>=1;op--){
		//oiiaiooiiiai
		for(int i=1;i<op;i++){
			for(int j=1;j<=i;i++){
				dp[i][j]+=dp[i-1][j];
				dp[i][j]+=
			}
		}
	}*/
	return 0;
}
/*
5
2 2 3 8 10
*/
