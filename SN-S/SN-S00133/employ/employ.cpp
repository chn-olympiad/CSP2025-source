#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,t;
const int maxn=1e3+5;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=0x3f3f3f3f3f3f3f3fll;
int a[maxn];
int c[maxn];
bool b[maxn];
int d[maxn];
int ans;
//XTBT
//15:01
//把T4暴力打了 
//15:28 
//T4暴力打红了 
void dfs(int p,int u,int tot){
//	cout<<p<<" "<<u<<" "<<tot<<" "<<y<<endl;
	if(p>n){
		if(tot>=m)ans++;
		if(ans>mod)ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		dfs(p+1,u+(a[p]==0||u>=c[i]),tot+(c[i]>u&&a[p]==1));
		b[i]=0;
	}
}
void dfs2(int p,int u,int tot){
	if(tot<p-1)return ;
	if(p>n){
		if(tot>=m)ans++;
		if(ans>mod)ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		dfs2(p+1,u+(a[p]==0||u>=c[i]),tot+(c[i]>u&&a[p]==1));
		b[i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	//freopen("jmcakioi.txt","w",stdout);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool pp=0;
	for(int i=1;i<=n;i++){
		char o;
		cin>>o;
		if(o=='1')a[i]=1;
		else a[i]=0,pp=1;	
	}
	for(int i=1;i<=n;i++)cin>>c[i];
if(n==m){
	for(int i=1;i<=n;i++){
		if(a[i]==0||c[i]==0){
			cout<<0<<endl;
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<endl;
	return 0;
}
if(!pp){
	int cnt=0;
	for(int i=1;i<=n;i++)if(c[i]!=0)cnt++;
	if(cnt<m){
		cout<<0<<endl;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<endl;
	return 0;
}
	dfs(1,0,0);
	cout<<ans<<endl;
	
	
	return 0;
}

