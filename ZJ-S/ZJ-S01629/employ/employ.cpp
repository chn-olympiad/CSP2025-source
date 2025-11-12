#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
const int N=501;
int n,m,ans;
int p[N],c[N];
string s;
bool vis[N];
void print()
{
	for(int i=1;i<=n;++i) cout<<p[i]<<" ";
	cout<<"\n";
}
bool ck()
{
	int res=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='1'&&c[p[i]]>i-res-1) res++;
	return res>=m;
}
void dfs(int k)
{
	if(k>n)
	{
		if(ck()) ++ans,ans%=P;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			p[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
			p[k]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
}
