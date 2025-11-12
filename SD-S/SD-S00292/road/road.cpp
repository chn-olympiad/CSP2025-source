#include<stdio.h>
#include<algorithm>
namespace mns
{
	struct Edge
	{
		int from,to,weight,cond;
	} edge[11000000];
	int fat[1024][10010];
	int find(int *fat,int x)
	{
		if(x[fat]==x)
		{
			return x;
		}
		return x[fat]=find(fat,x[fat]);
	}
	int gm;
	int c[10];
	long long ans[1024];
	void add_edge(int u,int v,int w,int c)
	{
		edge[gm].from=u;
		edge[gm].to=v;
		edge[gm].weight=w;
		edge[gm].cond=c;
		gm++;
	}
	int cmp(Edge a,Edge b)
	{
		return a.weight<b.weight;
	}
	long long kruskal(int n,int m,int k)
	{
		std::sort(edge,edge+m,cmp);
		int i,j;
		long long res;
		for(j=0;j<(1<<k);++j)
		{
			for(i=0;i<k;++i)
			{
				if(j&(1<<i))
				{
					ans[j]+=c[i];
				}
			}
			for(i=0;i<n;++i)
			{
				fat[j][i]=i;
			}
		}
		for(i=0;i<m;++i)
		{
			for(j=0;j<(1<<k);++j)
			{
				if(find(fat[j|edge[i].cond],edge[i].from)!=find(fat[j|edge[i].cond],edge[i].to))
				{
					find(fat[j|edge[i].cond],edge[i].from)[fat[j|edge[i].cond]]=find(fat[j|edge[i].cond],edge[i].to);
					ans[j|edge[i].cond]+=edge[i].weight;
//					printf("Connect %d,%d|w:%d|%x\n",edge[i].from+1,edge[i].to+1,edge[i].weight,j|edge[i].cond);
				}
			}
		}
		res=1e18;
		for(j=0;j<(1<<k);++j)
		{
			res=(res<ans[j]?res:ans[j]);
//			printf("%d ",ans[j]);
		}
		return res;
	}
	int main()
	{
		int n,m,k,i,j,r,t,w;
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d",&r,&t,&w);
			r--;
			t--;
			add_edge(r,t,w,0);
		}
		for(i=0;i<k;++i)
		{
			scanf("%d",c+i);
			for(j=0;j<n;++j)
			{
				scanf("%d",&w);
				add_edge(n+i,j,w,1<<i);
			}
		}
		m+=k*n;
		n+=k;
		printf("%lld",kruskal(n,m,k));
		return 0;
	}
};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	mns::main();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
