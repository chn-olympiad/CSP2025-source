#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,a[11],c[11],b[11],ans;
char s[11];
bool flag[11];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool check(int x[])
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if ()
	}
}
int dfs(int x)
{
	if (x==n)
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f=1;
	n=read();
	m=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		a[i]=s[i]-'0';
		if (!a[i]) f=0;
	}
	for (int i=1;i<=n;i++) c[i]=read();
	sort(c+1,c+n+1);
	dfs(1);
	return 0;
}
