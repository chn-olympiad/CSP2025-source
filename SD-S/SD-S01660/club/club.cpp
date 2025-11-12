//LUOGU UID 1208546

#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct Node {
	int x,y,z;
}a[N]; 
int n,T,cnt1,cnt2,cnt3,ans,res;
int dp[110][110][110];
bool flg;
inline bool cmp(Node x,Node y) {
	return x.x>y.x;
}
inline void dfs(int x) {
	if(x==n+1) {
		ans=max(ans,res);
		return;
	}
	if(cnt1+1<=n/2) {
		cnt1++;
		res+=a[x].x;
		dfs(x+1);
		res-=a[x].x;
		cnt1--;
	}
	if(cnt2+1<=n/2) {
		cnt2++;
		res+=a[x].y;
		dfs(x+1);
		res-=a[x].y;
		cnt2--;
	}
	if(cnt3+1<=n/2) {
		cnt3++;
		res+=a[x].z;
		dfs(x+1);
		res-=a[x].z;
		cnt3--;
	}
}
inline void solve() {
	cin>>n;
	flg=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].y!=0||a[i].z!=0) flg=0;
	} 
	if(flg) {
		sort(a+1,a+1+n,cmp);
		int res=0;
		for(int i=1;i<=n/2;i++) ans+=a[i].x;
		cout<<ans<<'\n';
		return;
	}
	ans=-1;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) {
		for(int x=0;x<=n;x++) {
			for(int y=0;y<=n;y++) {
				if(x>i||y>i||x>n/2||y>n/2) continue;
				int z=i-x-y;
				if(z<0||z>n/2) continue;
				int mx=-1;
				if(x!=0) {
					mx=max(mx,dp[x-1][y][z]+a[i].x);
				}
				if(y!=0) {
					mx=max(mx,dp[x][y-1][z]+a[i].y);
				}
				if(z!=0) {
					mx=max(mx,dp[x][y][z-1]+a[i].z);
				}
				dp[x][y][z]=mx;
				ans=max(ans,mx);
			}
		}
	}
	//dfs(1);
	cout<<ans<<'\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}

