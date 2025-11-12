#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],sum,cnt,ans,vis[505];
string s;
bool flag;
void dfs(int x)
{
	flag=0;
	if(m-cnt+x>n)
		return;
	if(x==n&&cnt>=m)
	{
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(s[x]=='1'&&c[i]>sum)
				cnt++;
			else
				sum++;
			vis[i]=1;
			dfs(x+1);
			if(s[x]=='1'&&c[i]>sum)
				cnt--;
			else
				sum--;
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(0);
	cout<<ans;
	return 0;
}
