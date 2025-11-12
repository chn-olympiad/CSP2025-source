#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N=505;
const int P=998244353;
int n,m,s[N],c[N];
int a[3628805][11],cnt;
bool vis[11];
int b[11];
void dfs(int x,int n){
	if(x==n+1){
		++cnt;
		for(int i=1;i<=n;i++)
			a[cnt][i]=b[i];
	}for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;b[x]=i;
		dfs(x+1,n);
		vis[i]=0;
	}
}
int d[11];
bool check(int x){
	for(int i=1;i<=n;i++)
		d[i]=c[a[x][i]];
	int now=0;
	for(int i=1;i<=n;i++)
		if(s[i]==0||d[i]<=now)
			now++;
	return n-now>=m;
}
void solve(){
	int ans=0;
	cin>>n>>m;char ch;
	dfs(1,n);
//	for(int i=1;i<=cnt;i++,cout<<'\n')
//		for(int j=1;j<=n;j++)
//			cout<<a[i][j]<<' ';
	for(int i=1;i<=n;i++)
		cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=cnt;i++)
		if(check(i))ans++;
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();return 0;
}
//yu shi zhen hao ke !!!
