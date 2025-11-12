#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int n,m,a[N],b[N],ans;
int d[N];
char c[N];
void dfs(int x,int anss)
{
	if(x>n)
	{
		if(n-anss>=m)
			ans++;
		return ;
	}
	else if(n-anss<m)
		return ;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
			continue;
		b[i]=x;
		if(c[x]=='0'||anss>=a[i])
			dfs(x+1,anss+1);
		else
			dfs(x+1,anss);
		b[i]=0;
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
