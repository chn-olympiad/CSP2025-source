//freopen!!!


#include<bits/stdc++.h>
#define ll long long       //long long 是否需要？？？ 
#define forr(a,b,c) for(int a=b;a<=c;a++)
using namespace std;

const int N=1e4+50;
const int M=2e6;
const int inf=0x3f3f3f3f;
int n,m,k;
int u[M],v[M],w[M];
int c[15];
int a[15][N];

ll ans=0;


struct node{
	int u;
	int v;
	int wei;
}edge[M];
int cnt;


bool cmp(node x,node y)
{
	return x.wei<y.wei;
}



int pre[N];



void init()
{
	forr(i,1,n+k) pre[i]=i;
}


int cha(int x)
{
	int r=x;
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	int t;
	while(pre[x]!=r)
	{
		t=pre[x];
		pre[x]=r;
		x=t;
	}
	return r;
}

void merge(int x,int y)
{
	pre[x]=y;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	forr(i,1,m) 
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		edge[++cnt].u=u[i];
		edge[cnt].v=v[i];
		edge[cnt].wei=w[i];
	}
	forr(i,1,k)
	{
		scanf("%d",&c[i]);
		forr(j,1,n)
		{
			scanf("%d",&a[i][j]);
			edge[++cnt].u=i+n;
			edge[cnt].v=j;
			edge[cnt].wei=a[i][j];        //记录边时只记录单向 
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	
	init();
	
	forr(i,1,cnt)
	{
		int tx=cha(edge[i].u);
		int ty=cha(edge[i].v);
		if(tx!=ty)
		{
			ans+=edge[i].wei;
			merge(tx,ty);
		}
	}
	printf("%lld",ans);
	return 0;
}

