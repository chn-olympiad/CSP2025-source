#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[505];
int ch[505];
bool vis[505];
int ans=0;
void dfs(int k)
{
	if(k==n+1)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<s[i]<<' '<<i<<' '<<c[ch[i]]<<endl;;
			if(s[i]=='1'&&(i-tot)<=c[ch[i]])
			{
				tot++;
			}
		}
		if(tot==m)
			ans++;
//		cout<<tot<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			ch[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	printf("%lld",ans);
}
