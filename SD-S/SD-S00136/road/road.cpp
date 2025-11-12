#include<bits/stdc++.h>
using namespace std;
int n,m,q,p,x[15],c[15][10005],f[10005];
struct nd
{
	int u,v,k;
}s[2000050];
bool cmp(nd a,nd b)
{
	return a.k<b.k;
}
int fd(int i)
{
	if(f[i]==i) return i;
	return f[i]=fd(f[i]);
}
void bfs()
{
	long long ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(f[s[i].u]==f[s[i].v]) continue;
		int fx=fd(s[i].u);
		int fy=fd(s[i].v);
		if(fx!=fy)
		{
			f[fx]=fy;
			ans+=s[i].k;
		}
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int aa,bb,cc;
		scanf("%d%d%d",&aa,&bb,&cc);
		s[i].u=aa,s[i].v=bb,s[i].k=cc;
		//cin>>s[i].u>>s[i].v>>s[i].k;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x[i]);
		//cin>>x[i];
		if(x[i]==0) p++;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(x[i]==0)
			{
				m++;
				s[m].u=i,s[m].v=j,s[m].k=c[i][j];
			}
		}
	}
	if(q-p==0)
	{
		bfs();
		return 0;
	}
	bfs();
	return 0;
}

