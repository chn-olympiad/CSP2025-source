#include<bits/stdc++.h>
using namespace std;
int n,m,k,bcj[100005],yjhs=0,ans=0,yjhs1=0,v[10005];
int fi(int xx)
{
	if(bcj[xx]==xx) return xx;
	return bcj[xx]=fi(bcj[xx]);
}
struct node{
	int u,v,w,s=0;
}e[100005];
int cmp(node x,node y)
{
	if(x.w<y.w) return 1;
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int ttt,tt1;
		cin>>tt1;
		for(int j=1;j<=m;j++)
		{
			e[j+m+m*(i-1)+m*(j%m==0)].u=i+m;
			e[j+m+m*(i-1)+m*(j%m==0)].v=j;
			e[j+m+m*(i-1)+m*(j%m==0)].s=tt1;
			cin>>ttt;
			e[j+m*(i-1)+m*(j%m==0)+m].w=ttt+tt1;
//			cout<<e[j+m*(i-1)+m*(j%m==0)+m].w<<endl;
//			cout<<1;
		}
	}
	m+=k*m;
	n+=k;
	for(int i=1;i<=n;i++) bcj[i]=i;
	sort(e+1,e+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].s<<endl;
//	}
	for(int i=1;i<=m;i++)
	{
		if(fi(e[i].u)!=fi(e[i].v))
		{
			ans+=e[i].w;
			yjhs++;
			if(e[i].s!=0) yjhs1++;
//			cout<<e[i].u<<" "<<".///"<<" "<<e[i].v<<" "<<ans<<endl;
			bcj[e[i].v]=fi(e[i].u);
			if(e[i].s!=0)
			{
				e[i].s=0;
				for(int j=1;j<=m;j++)
				{
					if(e[j].u==e[i].u)
					{
						e[j].w-=e[j].s;
						e[j].s=0;
					}
				}
				sort(e+1,e+m+1,cmp);
				i=0;
				continue;
			}
		}
		if(yjhs==n-k+yjhs1+1) break;
	}
	cout<<ans;
	return 0;
} 
