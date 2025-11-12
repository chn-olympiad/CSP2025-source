#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch;
	int sz=0,f=1;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		sz=sz*10+int(ch-'0');
		ch=getchar();
	}
	return sz*f;
}
struct bian{
	int u,v,c;
}b[1500001];
int n,m,k,fa[1000001],js=0,a[11][100001],c[11];
long long s=0;
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[fa[y]]=fa[x];
	return;
}
bool cmp(bian x,bian y)
{
	return x.c<=y.c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	js=n-1;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		b[i].u=read();
		b[i].v=read();
		b[i].c=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j>=n;j++)
		{
			a[i][j]=read();
			for(int l=1;l<j;l++)
			{
				b[++m].u=l;
				b[m].v=j;
				b[m].c=c[i]+a[i][l]+a[i][j];
			}
		}
	}
	sort(b+1,b+1+m,cmp);
	for(int i=1;js&&i<=m;i++)
	{
		if(find(b[i].u)==find(b[i].v))continue;
		merge(b[i].u,b[i].v);
		s+=b[i].c;
		js--;
	}
	cout<<s;
	return 0;
}
//wrong answer,don't learn me.
