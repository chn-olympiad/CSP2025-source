#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}r[100100];
int c[11];
int fa[10100];
bool flag[10100];
bool ji[10100];
bool cmp(road a,road b)
{
	if(a.w!=b.w)
	{
		return a.w<b.w;
	}
	return a.v<b.v;
}
int zu(int a)
{
	if(fa[a]!=a)
	{
		a=zu(fa[a]);
	}
	return fa[a];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(u>v)
		{
			swap(u,v);
		}
		r[i].u=u;
		r[i].v=v;
		r[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		ji[n+i]=0;
		for(int j=1;j<=n;j++)
		{
			int p;
			cin>>p;
			r[m+(i-1)*n+j].u=j;
			r[m+(i-1)*n+j].v=n+i;
			r[m+(i-1)*n+j].w=p;
			ji[j]=1;
			fa[j]=j;
		}
	}
	sort(r+1,r+m+n*k+1,cmp);
	int ans=0;
	for(int i=1;i<=m+n*k;i++)
	{
		if(r[i].v>n&&zu(r[i].u)!=zu(r[i].v)&&ji[r[i].v]==0)
		{
			int l=i,f=0;
			while(ji[r[l+1].v]==0&&r[l+1].v>n)
			{
				if(ji[r[l+1].v]==1)
				{
					break;
				}
				else if(ji[r[l+1].v]==0&&r[l+1].w+c[r[l+1].v-n]<r[i].w+c[r[i].v-n])
				{
					f=1;
					break;
				}
				l++;
			}
			if(f)
			{
				ans+=(r[l+1].w);
				fa[r[l+1].u]=zu(r[l+1].v);
			}
			else if(r[i].w+c[r[i].v-n]<r[l].w)
			{
				ji[r[i].v]=1;
				ans+=(r[i].w+c[r[i].v-n]);
				fa[r[i].u]=zu(r[i].v);
			}
		}
		if(zu(r[i].u)!=zu(r[i].v))
		{
			ans+=r[i].w;
			fa[r[i].u]=zu(r[i].v);
		}
	}
	cout<<ans;
	return 0;
}
