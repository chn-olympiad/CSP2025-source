//SN-S00244  张溪诺  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll u,v,w;
}tree[1000010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
ll ans,cnt,top;
ll fa[1000010];
ll n,m,k,id;
ll a[20010][10010];
ll vis[1000010];
ll c[20010];
int find(int x)
{
	if(x!=fa[x])
		fa[x]=find(fa[x]);
	return fa[x];
}
int mst()
{
	sort(tree+1,tree+top+1,cmp);
	for(int i=1;i<=id;i++)fa[i]=i;
	for(int i=1;i<=top;i++)
	{
		//if(cnt==n-1)break;
		ll xx=find(tree[i].u);
		ll yy=find(tree[i].v);
		if(xx!=yy)
		{
			fa[xx]=yy;
			cnt++;
			ans+=tree[i].w;
		}
	}
	//int orz=-1;
	//if(cnt==n-1)return ans;
	//else return orz;
	return ans;
}
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>tree[i].u>>tree[i].v>>tree[i].w;
	}
	top=m;id=n;
	for(int i=n+1;i<=k+n;i++)
	{
		cin>>c[i];
		id++;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			tree[++top].u=id;
			tree[top].v=j;
			tree[top].w=a[i][j];
		}
	}
	mst();
	for(int i=1;i<=cnt;i++)
	{
		if(tree[i].u>n&&vis[tree[i].u]==0)
		{
			ans+=c[tree[i].u];
			vis[tree[i].u]=1;
		}
	}
	cout<<ans;
	return 0;
}
//能骗40分！！能骗40分！！不要挂分！！不要挂分！！ 
