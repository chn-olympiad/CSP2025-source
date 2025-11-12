#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N =1e5+5;
ll dp[N][3],T,a[N][3],n,ans;
ll dfs(ll len,ll a1,ll a2,ll a3){
	if(len-1>n) return 0;
	cout<<len<<' '<<a1<<' '<<a2<<' '<<a3<<'\n';
	//if(len==1) return max(a[1][1],max(a[1][2],a[1][3]));
	if(a1*2<=n)dp[len][1]=max(dp[len][1],dfs(len+1,a1+1,a2,a3)+a[len][1]);
	if(a2*2<=n)dp[len][1]=max(dp[len][1],dfs(len+1,a1+1,a2,a3)+a[len][1]);
	if(a3*2<=n)dp[len][1]=max(dp[len][1],dfs(len+1,a1+1,a2,a3)+a[len][1]);
//	for(int i=1;i<=3;i++){
//		dp[len][i]=max(dp[ien][i],dp[ien-1][i]+a[len][i]);
//	}
	return max(dp[len][1],max(dp[len][2],dp[len][3]));
//}
}
int main(){
	//freopen ("club.in","r",stdin);
	//freopen ("club.out","w"stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){a[i][1]=a[i][2]=a[i][3]=0;dp[i][1]=dp[i][2]=dp[i][3]=0x3f3f3f3f3f;}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		cout<<dfs(1,0,0,0)<<'\n';
	}
	return 0;
}
