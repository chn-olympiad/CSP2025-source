#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],dp[N][4],cnt[4];
int ans=INT_MIN;
void dfs(int id,int ct){
	if(id==n+1){
		ans=max(ans,ct);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2)continue;
		cnt[i]++;
		dfs(id+1,ct+a[id][i]);
		cnt[i]--;
	}
}
void solve(){
	memset(a,0,sizeof a);
	memset(cnt,0,sizeof cnt);
	ans=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	dfs(0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
}
