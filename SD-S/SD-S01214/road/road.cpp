#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int x=0;int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') ch=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int M=1e6+10;
const int N=1e4+10;
int n,m,k;
struct edge
{
	int to;
	int dis;
	int nxt; 
	int from;
	bool youlema;
}e[2*M+20*N];
bool cmp(edge q,edge w)
{
	return q.dis<w.dis;
}
int cnt=0;
int head[N+25];
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].dis=w;
	e[cnt].from=u;
	head[u]=cnt;
}
int xiang[15];

int fa[N+25];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
} 
void merge(int x,int y)
{
	fa[get(y)]=x;
	return;
}
int kr()
{

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1011;i<=1010+k;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+cnt+1,cmp); 
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].from;
		int v=e[i].to;
//		cout<<u<<" "<<v<<"qqq"<<endl;
		if(get(u)==get(v)) continue;
		else
		{
			merge(u,v);

			ans+=e[i].dis; 
			if(u>=1010)
			{
				for(int j=head[u];j;j=e[j].nxt)
				{
					if(!e[j].youlema)
					{
						e[j].dis-=xiang[u-1010];
						e[j].youlema=1;
					}	
				}
			}
			if(v>=1010)
			{
				for(int j=head[v];j;j=e[j].nxt)
				{
					if(!e[j].youlema)
					{
						e[j].dis-=xiang[v-1010];
						e[j].youlema=1;
					}
					
				}
			}
		}
	}
//	
//	for(int i=1;i<=k;i++)
//	{
//		if(has[i]) ans+=xiang[i];
//	}
	return ans;
}
signed main()
{

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		int uu,vv,ww;
		uu=read();
		vv=read();
		ww=read();
		add(uu,vv,ww);
		add(vv,uu,ww);
	}
	for(int i=1;i<=k;i++)
	{
		xiang[i]=read();
		for(int j=1;j<=n;j++)
		{
			int jia=read();	
			add(1010+i,j,jia+xiang[i]);
			add(j,1010+i,jia+xiang[i]);	
		}
	}
	cout<<kr()<<endl;
//	cerr<<1.0*(clock()-sti)/CLOCKS_PER_SEC<<endl;
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

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
