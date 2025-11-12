#include<bits/stdc++.h> 
using namespace std;
int n,m,l,h=1;
bool e[1010]={0};
struct r
{
	int t=-1,w;
}dist[1010][1010];
int q[1010]={1};
bool cmp(r a,r b)
{
	return a.w<b.w;
}
int p()
{
	int ans=0,h1=1;
	e[1]=1;
	for(int i=1;h1<=n;i++)
	{
		int s=INT_MAX,s2;
		for(int j=0;j<h1;j++)
		{
			sort(dist[q[j]],dist[q[j]]+n,cmp);
			for(int k=0;k<n;k++)
			{
				if(dist[q[j]][k].w<s && dist[q[j]][k].t!=-1 && !e[dist[q[j]][k].t])
				{
					s=dist[q[j]][k].w;
					s2=dist[q[j]][k].t;
				}
			}
		}
		ans+=s;
		q[h1]=s2;
		e[s2]=1;
		h1++;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dist[a][b].w=dist[b][a].w=c;
		dist[a][b].t=b;
		dist[b][a].t=a;
	}
	cout<<p()<<"\n";
	return 0;
}
