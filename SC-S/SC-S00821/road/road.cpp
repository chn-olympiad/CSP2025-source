#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int dis,from,to,fl;
}b[1000010];
int n,m,k,a[11][10010],fa[10010];
int f[10010][10010];
unsigned long long sum;
bool comp(edge x,edge y)
{
	return x.dis<y.dis;
}
int _find(int t)
{
	if(fa[t]!=t)fa[t]=_find(fa[t]);
	return fa[t];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].from>>b[i].to>>b[i].dis;
		f[b[i].from][b[i].to]=i;
		f[b[i].to][b[i].from]=i;
		b[i].fl=0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)
		{
			for(int u=1;u<=n;u++)
			{
				if(j!=u)
				{
					if(f[j][u])
					{
						if(a[i][j]+a[i][u]<b[f[j][u]].dis)
						{
							b[f[j][u]].dis=a[i][j]+a[i][u];
							b[f[j][u]].fl=i;
						}
					}
					else
					{
						f[j][u]=++m;
						f[u][j]=m;
						b[m].from=j;
						b[m].to=u;
						b[m].dis=a[i][j]+a[i][u];
						b[m].fl=i;
					}
				}
			}
		}	
	}
	for(int i=1;i<=m;i++)if(b[i].fl)b[i].dis+=a[b[i].fl][0];
	sort(b+1,b+1+m,comp);
	for(int i=1;i<=m;i++)
	{
		if(_find(b[i].from)==_find(b[i].to))continue;
//		cout<<b[i].from<<' '<<b[i].to<<' '<<b[i].dis<<endl;
		sum+=b[i].dis;
		if(b[i].fl)
		{
			for(int j=i+1;j<=m;j++)
			{
				if(b[j].fl==b[i].fl)
				{
//					cout<<b[i].fl<<'/'<<b[j].fl<<endl;
					b[j].dis-=a[b[m].fl][0];
					b[j].fl=0;
				}
			}
			sort(b+2+i,b+1+m,comp);
		}
		fa[_find(b[i].from)]=fa[b[i].to];
	}
	cout<<sum;
	return 0;
}