#include<bits/stdc++.h>
using namespace std;
int input()
{
	int x=0;
	while(1)
	{
		char ch=getchar();
		if(ch==' '||ch=='\n') return x;
		x=x*10+ch-'0';
	}
}
void print(int x)
{
	int a[15],l=0;
	while(x!=0)
	{
		a[l++]=x%10;
		x/=10;
	}
	for(int i=l-1;i>=0;i--) putchar(a[i]+'0');
	putchar('\n');
}
int n,m,k,p;
int u,v,w;
pair<int,pair<int,int> > d[1000001];
int c[11],a[11][10001];
int fa[10030];
int s,ans=0;
int findfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=input(),m=input(),k=input();
	for(int i=1;i<=m;i++)
	{
		u=input(),v=input(),w=input();
		d[i]=make_pair(w,make_pair(u,v));
	}
	sort(d+1,d+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		if(findfa(d[i].second.first)!=findfa(d[i].second.second))
			fa[findfa(d[i].second.first)]=findfa(d[i].second.second),ans+=d[i].first;
	print(ans);
	return 0;
}
