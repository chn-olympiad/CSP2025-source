#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;

const int N=1e4+25,M=1e6+10,QWQ=2e5+10;
int n,m,k,fa[N],vis[12],sz[N];
ll c[12][N],cc[12];
ll ans;

struct node{
	int u,v,w,st;
}edge[M];

bool cmp(node a,node b)
{
	return (a.w<b.w)&&(a.w)&&(b.w);
}

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
	int fax=find(x);
	int fay=find(y);
	fa[fax]=fay;
	sz[fay]+=sz[fax];
	return;
}

bool same(int x,int y)
{
	return find(x)==find(y);
}

//bool check()
//{
//	bool flag=1;
//	for(int i=2;i<=n;i++)
//	{
//		if(!same(1,i)) flag=0;
//	}
//	return flag;
//}

void krus(int len)
{
	int cnt=1;
	int fir=edge[1].u;
	for(int i=1;i<=m+len;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(same(u,v)) continue;
		else
		{
			if(edge[i].st==0 && vis[v-n]==0)
			{
				ans+=cc[v-n];
				vis[v-n]=1;
				merge(u,v);
			    ans+=c[v-n][u];
			}
			else if(edge[i].st==0 && vis[v-n]==1)
			{
				merge(u,v);
			    ans+=c[v-n][u];
			}
			else
			{
				merge(u,v);
				ans+=w;
			}
		}
		if(sz[find(u)]==n) break;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=n+1;i<=n+k;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		edge[i].st=1;
	}
	int len=m;
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&cc[i]);
		if(cc[i]) flag=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(c[i][j]) flag=1;
			edge[++len].u=j;
		    edge[len].v=n+i;
		    edge[len].w=c[i][j]+cc[i];
		}
	}
	if(flag==0)
	{
		printf("0");
		return 0;
	}
//________________________________________________________

//	for(int i=1;i<=m+len;i++)
//	cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<" "<<edge[i].st<<endl;
//	    
//	cout<<endl;
//________________________________________________________

	sort(edge+1,edge+1+m+len,cmp);
//	sort(edge+2+m,edge+1+m+k*(n+1),cmp);
	
//_________________________________________________________

//	for(int i=1;i<=m+len;i++)
//	cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<" "<<edge[i].st<<endl;
//__________________________________________________________
    krus(len);
    printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
    return 0;
}


















//_________________________________________________________

