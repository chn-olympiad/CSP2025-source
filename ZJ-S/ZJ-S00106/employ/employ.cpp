#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[510],c[510],flag[510];
char s[510];
void dfs(int now,int pre)
{
	if(pre>n-m)return;
	if(now==n+1)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)if(!flag[i])
	{
		flag[i]=1;
		if(pre>=c[i])
		{
			dfs(now+1,pre+1);
		}
		else
		{
			dfs(now+1,pre+(1-a[now]));
		}
		flag[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
