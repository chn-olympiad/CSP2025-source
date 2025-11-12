#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[2000005],ee[2000005],eee[2000005];
int n,m,k,fa[11005],ans=1e18,pt[15],d[15][11005],ecnt;
bool cmp(node na,node nb)
{
	return na.w<nb.w;
}
int fd(int x)
{
	if(x-fa[x])return fa[x]=fd(fa[x]);
	return x;
}
void dff(int nn,int mm,int su)//nn->ji'ge'dian mm->ji'tiao'bian
{
	int jl=0,anss=0;
	for(int i=1;i<=mm;i++)ee[i]=e[i];//,cout<<ee[i].u<<' '<<ee[i].v<<' '<<ee[i].w<<'\n';
	sort(ee+1,ee+mm+1,cmp);
	for(int i=1;i<=nn;i++)fa[i]=i;
	for(int i=1,j=1;(i<=mm||j<=ecnt)&&jl<nn;)
	{
		if(ee[i].w<=eee[i].w||j>ecnt)
		{
			int uu=fd(ee[i].u),vv=fd(ee[i].v);
	//			cout<<ee[i].u<<' '<<ee[i].v<<' '<<ee[i].w<<' '<<su<<endl;
			if(uu-vv)
			{
				fa[uu]=vv;
				anss+=ee[i].w;
				jl++;
			}
			i++;
		}
		else
		{
			int uu=fd(eee[j].u),vv=fd(eee[j].v);
	//			cout<<ee[i].u<<' '<<ee[i].v<<' '<<ee[i].w<<' '<<su<<endl;
			if(uu-vv)
			{
				fa[uu]=vv;
				anss+=eee[j].w;
				jl++;
			}
			j++;
		}
	}
	ans=min(ans,anss+su);
}
void df(int x,int nn,int su,int mm)//x->dq nn->ji'ge'dian su->dian'quan'he mm->ji'tiao'bian
{
	if(x>k)
	{
		dff(nn,mm,su);
		return;
	}
	df(x+1,nn,su,mm);
	for(int i=1;i<=n;i++)
		e[++mm]=node{nn+1,i,d[x][i]};
	df(x+1,nn+1,su+pt[x],mm);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	bool fff=false;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",pt+i);
		if(pt[i])fff=true;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&d[i][j]);
			if(d[i][j])fff=true;
		}
	}
	if(!fff)return !printf("0");
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m&&ecnt<n;i++)
	{
		int uu=fd(e[i].u),vv=fd(e[i].v);
		if(uu-vv)
		{
			fa[uu]=vv;
			eee[++ecnt]=e[i];
		}
	}
	
	df(1,n,0,0);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
//TLE&&pian'fen
//rp++