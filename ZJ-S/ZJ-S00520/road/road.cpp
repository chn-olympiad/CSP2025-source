//17:02
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+10;
int n,m,k;
int tot=0;
struct node{
	int u,v,w;
}g[N];
int df[N];
int ji[N];
struct edge{
	pair<int,int> a[N];
}e[10];
int tp[N];
void _add(int u,int v,int w)
{
	tot++;
	g[tot].u=u;
	g[tot].v=v;
	g[tot].w=w;
}
bool cp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.first<p2.first;
}
int vis[N];
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int ans=0;
struct afo{
	int u,v,w,t;
	bool operator < (const afo &p) const{
		if(w==p.w)
		{
			return t<p.t;
		}else{
			return w>p.w;
		}
	}
};
priority_queue<afo> q;
void ku()
{
	int t=0;
	while(!q.empty())
	{
		afo now=q.top();
		q.pop();
		int u=now.u,v=now.v,w=now.w,op=now.t;
		if(!vis[u])
		{
			vis[u]=1;
			t++;
		}
		if(!vis[v])
		{
			vis[v]=1;
			t++;
		}
		int tx=fa[u],ty=fa[v];
		if(fa[find(tx)]!=fa[find(ty)])
		{
			fa[find(tx)]=fa[find(ty)];
			//cout<<u<<" "<<v<<" "<<w<<" "<<op<<'\n';
			ans+=w;
			if(op!=0)
			{
				q.push({u,e[op].a[ji[op]].second,e[op].a[ji[op]].first,op});
				ji[op]+=1;
			}
		}else if(op!=0){
			int kp=e[op].a[ji[op]].first;
			if(u==e[op].a[1].second)
			{
				kp+=df[op]+e[op].a[1].first;
			}
			q.push({u,e[op].a[ji[op]].second,kp,op});
			ji[op]+=1;
		}
		if(t==n)
		{
			return ;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		_add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>df[i];
		for(int j=1;j<=n;j++)
		{
			cin>>e[i].a[j].first;
			e[i].a[j].second=j;
		}
		sort(e[i].a+1,e[i].a+n+1,cp);
	}
	/*for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<e[i].a[j].first<<" "<<e[i].a[j].second<<'\n';
		}
		cout<<"---"<<'\n';
	}*/
	for(int i=1;i<=m;i++)
	{
		q.push({g[i].u,g[i].v,g[i].w,0});
	}
	for(int i=1;i<=k;i++)
	{
		q.push({e[i].a[1].second,e[i].a[2].second,e[i].a[1].first+e[i].a[2].first+df[i],i});
		ji[i]=3;
	}
	ku();
	cout<<ans<<'\n';
	return 0;
}

