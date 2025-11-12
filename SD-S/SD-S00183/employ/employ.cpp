#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
string s;
int n,m,c[510],p[510],ans;
bool vis[510];
void dfs(int idx)
{
	if(idx==n)
	{
		int ot=0;
		for(int i=0;i<n;i++)
			ot+=(ot>=c[p[i]]||s[i]=='0');
		(ans+=(n-ot>=m))%=M;
		return;
	}
	for(int i=0;i<n;i++)
	if(!vis[i])
		{
			p[idx]=i,vis[i]=1;
			dfs(idx+1);
			vis[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	dfs(0);
	cout<<ans;
	return 0;
}
