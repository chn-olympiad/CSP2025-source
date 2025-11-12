#include<bits/stdc++.h>
using namespace std;
const int N=1000010,M=100010,K=11;
int n,m,k,u,v,w,c[K],tot,cnt,x,sp;
int fa[M];
struct node{
	int fr,to,lo;
}rd[N];
int find(int a)
{
	if(fa[a]==a)
	{
		return a;
	}
	else return fa[a]=find(fa[a]);
}
bool cmp(node as,node bs)
{
	return as.lo<bs.lo;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		rd[++tot].lo=w;
		rd[tot].fr=u;
		rd[tot].to=v;
		rd[++tot].lo=w;
		rd[tot].fr=v;
		rd[tot].to=u;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			rd[++tot].lo=x;
			rd[tot].fr=n+i;
			rd[tot].to=j;
			rd[++tot].lo=x;
			rd[tot].fr=j;
			rd[tot].to=n+i;
		}
	}
	sort(rd+1,rd+tot+1,cmp);
	int l=1;
	cnt=n+k;
	while(cnt>1)
	{
		if(find(rd[l].fr)!=find(rd[l].to)/*&&rd[l].fr<=n&&rd[l].to<=n*/)
		{
			fa[rd[l].to]=fa[rd[l].fr];
			/*if(rd[l].fr<=n&&rd[l].to<=n) */cnt--;
			sp+=rd[l].lo;
		}
		l++;
	}
	cout<<sp;
	return 0;
}
