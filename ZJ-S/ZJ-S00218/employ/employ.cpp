#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[509] = {0};
int p[509] = {0};
char a[509] = {0};
int b[509] = {0};
int s = 0;
int n,m;
void dfs(int x)
{
	if(x==n+1)
	{
		int s1 = 0,s2 = 0;
		for(int i = 1; i<=n; ++i)
		{
			if(s2<b[p[i]]&&a[i]=='1') s1++;
			else s2++;
		}
		if(s1>=m) s++;
	}
	for(int i = 1; i<=n; ++i)
	{
		if(!f[i])
		{
			p[x]=i;
			f[i]=1;
			dfs(x+1);
			f[i]=0;
			p[x]=0;
		}
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s", a+1);
	for(int i = 1; i<=n; ++i) cin>>b[i];
	dfs(1);
	printf("%d\n", s);
	return 0;
}
