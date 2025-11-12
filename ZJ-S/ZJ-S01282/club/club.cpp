#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn][3]={0},group_people[3]={0},dp[maxn],zj[3];
bool p[maxn];
int t,n,zjtj;
void dfs(int i){
	dp[0]=0;

	if(i==0){
		return ;
	}
	dfs(i-1);
	for(int j=1;j<=3;j++){
		if(group_people[j]<n/2){
			if(a[i][j]+dp[i-1]>dp[i]){
				zjtj=j;
			}
			dp[i]=max(dp[i-1]+a[i][j],dp[i]);
		}
		else if(group_people[j]==n/2){
			for(int x=1;x<=3;x++){
				zj[x]=a[i-1][x];
				sort(zj,zj+3);
			}
			dp[i]=max(dp[i],dp[i-1]-a[i-1][j]+a[i][j]+zj[2]);
		}
		else{
			dp[i]=dp[i-1];
		}
		
	}
	group_people[zjtj]++;
	
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int x=1;x<=3;x++){
				cin>>a[j][x];
			}
		}
	
		dfs(n);
		cout<<dp[n]<<endl;
		for(int j=1;j<=3;j++){
			group_people[j]=0;
		}
	
	}
	return 0;
}