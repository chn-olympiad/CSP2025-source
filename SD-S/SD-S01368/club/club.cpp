#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n;
ll vis[N],ans;
ll cnt1,cnt2,cnt3;
struct node{
	ll x,y,z;
}a[N];
void dfs(ll now,ll sum){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1<n/2){
		cnt1++,vis[now]=1;
		dfs(now+1,sum+a[now].x);
		cnt1--;
	}
	if(cnt2<n/2){
		cnt2++,vis[now]=2;
		dfs(now+1,sum+a[now].y);
		cnt2--;
	}
	if(cnt3<n/2){
		cnt3++,vis[now]=3;
		dfs(now+1,sum+a[now].z);
		cnt3--;
	}
}
bool cmp(node a,node b){
	return a.x>b.x;
}
void solve1(){
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=(n>>1);i++) ans+=a[i].x;
	cout<<ans<<'\n';
}
ll f[205][205][205];
ll a1[N],a2[N];
bool viss[N];
void solve2(){
	f[0][0][0]=f[0][1][0]=f[0][0][1]=0;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				f[i][j][k]=max(f[i][j][k],max(f[i-1][j-1][k]+a[i].x,f[i-1][j][k-1]+a[i].y));
				if(j<=n/2&&k<=n/2) ans=max(ans,f[i][j][k]);
			}
		}
	}
//	cout<<f[n][n/2][n/2]<<'\n';
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;
	ans=0;
	bool flA=1,flB=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].z!=0) flB=0;
		if(a[i].z!=0||a[i].y!=0) flA=0;
	}
	if(flA){
		solve1();
		return ;
	}
	if(flB){
		solve2();
		return ;
	}
	if(n<=30){
		cnt1=cnt2=cnt3=0;
		dfs(1,0);
		cout<<ans<<'\n';
		return ;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll T;cin>>T;
	while(T--) solve();
	return 0;
}
