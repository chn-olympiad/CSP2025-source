#include<bits/stdc++.h>
using namespace std;
int maxn=INT_MAX,n,m,k,num;
int bei[10005],fa[10005];
bool l[10005];
struct bian
{
	int x,y,lon;
}road[1000005],road1[1000005];
bool cmp(bian x,bian y)
{
	if(x.lon>y.lon) return 0;
	return 1;
}
int find(int x)
{
	fa[x]=x? x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>road1[i].x>>road1[i].y>>road1[i].lon;
		if(road1[i].x>road1[i].y) swap(road1[i].x,road1[i].y);		
	}
	num=m;
	for(int i=1;i<=k;i++)
	{
		cin>>bei[n+i];
		for(int j=1;j<=n;j++)
		{
			int xx; cin>>xx;
			road1[++num].x=j;
			road1[num].y=m+i;
			road1[num].lon=xx+bei[n+i];
		}
	}
	/*
	for(int i=1;i<=num;i++)
	{
		cout<<road[i].x<<road[i].y<<road[i].lon<<endl;
	}
	*/
	for(int s=0;s<=k;s++)
	{
		for(int i=1;i<=num+100;i++)
		{
			road[i].x=road1[i].x;
			road[i].y=road1[i].y;
			road[i].lon=road1[i].lon;
		}
		sort(road+1,road+num+1,cmp);
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		int cnt=0;
		for(int i=1;i<=num;i++)
		{
			int x=road[i].x;
			int y=road[i].y;
			if(find(x)!=find(y)&&y<=n+s)
			{
				y[fa]=x;
				cnt+=road[i].lon;
				if(road[i].y>n&&road[i].lon==road1[i].lon)
				{
					for(int j=i+1;j<=num;j++)
					{
						if(road[j].y==road[i].y) road[j].lon-=bei[road[i].y];
					}
					sort(road+1+i,road+num+1,cmp);
					/*
						for(int k=1;k<=num;k++)
						{
							cout<<road[k].x<<road[k].y<<road[k].lon<<endl;
						}
					*/
				}
			}
		}
		maxn=min(maxn,cnt);
	}
	cout<<maxn;
}
