#include<bits/stdc++.h>
#define int long long
#define lb(x) (x&-x)
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,dp[N][N],c[N],ans,sum[N];
string a;
bool vis[N];
void dfs(int noww,int x) {
	vis[x]=1;
	sum[noww]=x;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs(noww+1,i);
			vis[i]=0;
		}
	}
	if(noww==n) {
		int cnt=0,num=0;
		for(int i=1; i<=n; i++) {
			if(cnt>=c[sum[i]]||a[i]=='0') cnt++;
			else num++;
		}
		ans+=(num>=m);
		return;
	}
}
void dfs2(int noww,int x,int k) {
	vis[x]=1;
	sum[noww]=x;
	if(c[x]<=k||a[noww]=='0') k++;
	if(k!=noww) return;
//	cout<<1;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs2(noww+1,i,k);
			vis[i]=0;
		}
	}
	if(noww==n) {
		ans--;
		return;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	a=" "+a;
	for(int i=1; i<=n; i++) cin>>c[i];
	if(n<=10) {
		for(int i=1; i<=n; i++) {
			dfs(1,i);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	if(m==n) {
		cout<<0;
		return 0;
	}
	if(m==1) {
		ans=1;
		for(int i=1; i<=n; i++) {
			ans=(ans*i)%mod;
		}
		for(int i=1; i<=n; i++) {
			dfs2(1,i,0);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1; i<=n; i++) {
		if(a[i]=='0') flag=0;
	}
	if(flag) {
		ans=1;
		for(int i=1; i<=n; i++) {
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}

	return 0;
}
/*
3 1
0 0 0
1 1 1
*/