#include<bits/stdc++.h>
using namespace std;
#define ll long long
int _;
const int N=507,mod=998244353;
int s[N],n,m;
int c[N],ans;
vector<int> v;
bool vis[N];
void dfs(int dep,int sum,int xxx)
{
//	for(auto i:v)
//	{
//		cout<<i<<' ';
//	}cout<<'\n';
	if(dep>n)
	{
		if(sum>=m)ans++;
		return ;
	}
	if(m-sum<n-dep) return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&xxx<c[i])
		{
			vis[i]=1;
			v.push_back(i);
			dfs(dep+1,sum+(s[dep]-s[dep-1]),xxx+(s[dep]-s[dep-1]==1?0:1));
			vis[i]=0;
			v.pop_back();
		}
	}
}
void solve()
{
	cin>>n>>m;
	string ch;
	cin>>ch;
	for(int i=1;i<=n;i++)
	{
		s[i]=ch[i-1]-'0';
		s[i]+=s[i-1];
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(s[n]<m)
	{
		cout<0<<'\n';
		return ;
	}
	dfs(1,0,0);
	cout<<ans%mod<<'\n';
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cin>>_;
//	for(int i=1; i<=_; i++) {
//		printf("---test---%d---\n",i);
		solve();
//	}
	return 0;
}

