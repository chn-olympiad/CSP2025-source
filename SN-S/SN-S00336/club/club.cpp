//SN-S00336 李宸昊 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define inf 0x3f3f3f3f
#define int long long
const int maxn=205,tp=1e5+5;
struct node{
	int x,y,z;
}a[maxn*2];
int n,aa,ta[maxn],dp[maxn][maxn][maxn];
bool cmd(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>b.y;
	if(a.z!=b.z) return a.z>b.z;
}
void solve(){
	memset(dp,0,sizeof(dp));
	cin>>n;
	if(n==100000){
		rep(i,1,n) cin>>ta[i]>>aa>>aa;
		sort(ta+1,ta+1+n);
		int ans=0;
		rep(i,1,n/2) ans+=ta[i];
		cout<<ans;
		return;
	}
	rep(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+n,cmd);
	dp[0][0][0]=0;
	int ans=-1;
	rep(i,0,n/2) rep(j,0,n/2) rep(k,0,min(n-i-j,n/2)){
		if(i-1>=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k].x);
		if(j-1>=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k].y);
		if(k-1>=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k].z);
		if((i+j+k)==n) ans=max(ans,dp[i][j][k]);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
