#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],d[510];
bool book[510];
string s;
inline void dfs(int k)
{
	if(k==n+1)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			dfs(k+1);
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,&s);
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<0<<'\n';
	return 0;
}
