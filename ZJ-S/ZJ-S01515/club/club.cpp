#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
struct node{
	ll _a,_b,_c;
}fi[N][3];
ll dp[N][3],T,a[N][3],n,ans,d[N];
ll dfs(ll len,ll a1,ll a2,ll a3){
	if(len>n) return 0;
	//cout<<len<<' '<<a1<<' '<<a2<<' '<<a3<<'\n';
	if(a1*2<n&&(dp[len][1]==-0x3f3f3f3f||fi[len][1]._a!=a1)){dp[len][1]=max(dp[len][1],dfs(len+1,a1+1,a2,a3)+a[len][1]);fi[len][1]={a1,a2,a3};}
	if(a2*2<n&&(dp[len][2]==-0x3f3f3f3f||fi[len][2]._a!=a1)){dp[len][2]=max(dp[len][2],dfs(len+1,a1,a2+1,a3)+a[len][2]);fi[len][2]={a1,a2,a3};}
	if(a3*2<n&&(dp[len][3]==-0x3f3f3f3f||fi[len][3]._a!=a1)){dp[len][3]=max(dp[len][3],dfs(len+1,a1,a2,a3+1)+a[len][3]);fi[len][3]={a1,a2,a3};}
	//cout<<dp[len][1]<<' '<<dp[len][2]<<dp[len][3]<<'\n';
	return max(dp[len][1],max(dp[len][2],dp[len][3]));
}
ll dfs2(ll len,ll a1,ll a2,ll a3){
	ll ans1=-0x3f3f3f3f;
	if(len>n) return 0;
	//cout<<len<<' '<<a1<<' '<<a2<<' '<<a3<<'\n';
	if(a1*2<n)ans1=max(ans,dfs(len+1,a1+1,a2,a3)+a[len][1]);
	if(a2*2<n)ans1=max(ans,dfs(len+1,a1,a2+1,a3)+a[len][2]);
	if(a3*2<n)ans1=max(ans,dfs(len+1,a1,a2,a3+1)+a[len][3]);
	//cout<<dp[len][1]<<' '<<dp[len][2]<<dp[len][3]<<'\n';
	return ans1;
}
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>T;
	while(T--){
		bool flaga=1,flagb=1;
		cin>>n;
		for(int i=1;i<=n;i++){a[i][1]=a[i][2]=a[i][3]=0;dp[i][1]=dp[i][2]=dp[i][3]=-0x3f3f3f3f;}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll cnt=0;
			if((a[i][1]==0)) cnt++;
			if((a[i][2]==0)) cnt++;
			if((a[i][3]==0)) cnt++;
			if(cnt!=2) flaga=0;
			else{
				if(a[i][1]){d[i]=a[i][1];continue;}
				if(a[i][2]){d[i]=a[i][2];continue;}
				if(a[i][3]){d[i]=a[i][3];continue;}
			}
		}
		if(flaga){
			sort(d+1,d+1+n,cmp);
			ll ans=0;
			for(int i=1;i<=n/2;i++) ans+=d[i];
			cout<<ans<<'\n';
			continue;
		}
		cout<<dfs(1,0,0,0)<<'\n';
	}
	return 0;
}
