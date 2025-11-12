#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
string s;
long long n,m,a[505],ans[505],t,vis[505];
bool is;
inline void dfs(int x)
{
	if(x>n)
	{
		int t1=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||t1>=ans[i])t1++;
		}
		if(n-t1>=m)t++;
		t%=md;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans[x]=a[i];
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<t%md;
	return 0;
}