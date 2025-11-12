#include<bits/stdc++.h>
using namespace std;
const int N=100004;
struct Node{
	int c[4],Max;
}dp[N][4];
int n,p[N][4];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i][1]>>p[i][2]>>p[i][3];
	if(n==2){
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i==j) ans=max(ans,max(p[1][i],p[2][j]));
				else ans=max(ans,p[1][i]+p[2][j]);
			}
		}
		cout<<ans;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(dp[i-1][j].c[j]+1>n/2) continue;
			dp[i][j].c[j]=dp[i-1][j].c[j]+1;
			for(int k=1;k<=3;k++){
				dp[i][j].Max=max(dp[i-1][j].Max,dp[i-1][k].Max)+p[i][j];
			}
		}
	}
	int Max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) Max=max(Max,dp[i][j].Max);
	}
	cout<<Max<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) Solve();
	return 0;
}