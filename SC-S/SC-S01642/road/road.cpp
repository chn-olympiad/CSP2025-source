#include<bits/stdc++.h>

using namespace std;
#define ll long long 

const int N=1e6+15;
const int K=1e4+15;
const int M=11;
const ll inf=1e18;

int fa[K];
struct line
{
	int u,v;
	ll w;
}li[N],rli[1<<M][K];
struct node
{
	int cost;
	ll w[K];
}p[M];
int n,m,k;
bool fl=1;
int top,rtop[1<<M];
ll ans=inf;

int read()
{
	int x=0,f=1;
	char ch=getchar();
	if(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
			ch=getchar();
		}
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}

bool cmp(line a,line b)
{
	return a.w<b.w;
}

void get_ans(int sit,ll cost)
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	sort(li+1,li+top+1,cmp);
	ll res=cost;
//	cout<<"start "<<res<<endl;
	for(int i=1;i<=top;i++)
	{
		int u=li[i].u;
		int v=li[i].v;
		ll w=li[i].w;
		u=find(u),v=find(v);
		if(u!=v)
		{
			fa[v]=u;
			res+=w;
//			cout<<"add "<<w<<endl;
			rli[sit][++rtop[sit]]={u,v,w};
		}
	}
//	cout<<sit<<" "<<res<<endl;
	ans=min(ans,res);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		li[i].u=read();
		li[i].v=read();
		li[i].w=read();
	}
	top=m;
	get_ans(0,0ll);
	for(int i=1;i<=k;i++)
	{
		p[i].cost=read();
		if(p[i].cost) fl=0;
		for(int j=1;j<=n;j++)
		{
			p[i].w[j]=read();
			if(p[i].w[j]) fl=0;
		}
	}
	if(fl)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int sit=1;sit<(1<<k);sit++)
	{
		ll res=0;
		int last=sit-(sit&(-sit));
//		cout<<sit<<" "<<last<<endl;
		for(int i=1;i<=rtop[last];i++)
			li[i]=rli[last][i];
		top=rtop[last];
		for(int i=0;i<k;i++)
		{
			if((1<<i)&sit) res+=p[i+1].cost;
			if(((1<<i)&sit)&&(!((1<<i)&last)))
			{
				for(int j=1;j<=n;j++)
					li[++top]={n+i+1,j,p[i+1].w[j]};
			}
		}
		get_ans(sit,res);
	}
	cout<<ans<<endl;
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