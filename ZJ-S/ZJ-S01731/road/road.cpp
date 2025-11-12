#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
const int maxm=1e6+10;
const int maxk=15;
typedef long long ll;
int ui[maxm],vi[maxm];
ll wi[maxm];
struct edge
{
	int u,v;
	ll w;
};
bool cmp(edge xx,edge yy)
{
	return xx.w<yy.w;
}
ll a[maxk][maxn];
ll p[maxk];
int n,m,k,umi,vmi;
ll wmi=1e9;
ll yu=0;
int vis[maxn];
int init(int lz)
{
	fill(vis+1,vis+n+1,0);
	yu=0;
	int num=0;
	for(int i=1;i<=k;i++)
	{
		vis[i+n]=lz&1;
		if(lz&1)
		{
			yu+=p[i];
			num++;
		}
		lz/=2;
	}
//	cout<<"ok1"<<endl;
	return num;
}
int fa[maxn],visa[maxn];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
vector<edge>q;
ll prim(int r)
{
	fill(visa+1,visa+r+1,0);
	for(int i=1;i<=r;i++)
		fa[i]=i;
	ll ans=0;
	int num=0;
//	fa[vmi]=fa[umi];
//	visa[vmi]=visa[umi]=1;
//	cout<<"pro"<<endl;
	for(int i=0;i<q.size();i++)
	{
		if(num>=r)
			break;
//		cout<<"pro"<<endl;
		if(q[i].u>n&&vis[q[i].u]==0)
			continue;
		if(q[i].v>n&&vis[q[i].v]==0)
			continue;
//		cout<<"op";
		if(find(q[i].u)==find(q[i].v))
			continue;
//		cout<<q[i].u<<"y"<<q[i].v<<"y"<<q[i].w<<endl;
		ans+=q[i].w;
		fa[find(q[i].u)]=find(q[i].v);
		if(visa[q[i].u]==0)
			visa[q[i].u]=1,num++;
		if(visa[q[i].v]==0)
			visa[q[i].v]=1,num++;
//		cout<<"ok";
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>ui[i]>>vi[i]>>wi[i];
		if(wi[i]<wmi)
			wmi=wi[i],umi=ui[i],vmi=vi[i];
	}
//	cout<<"ok0"<<endl;
	for(int i=1;i<=k;i++)
	{
		cin>>p[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	ll ans=1e18;
//	cout<<"ok"<<endl;
	for(int i=1;i<=m;i++)
	{
		q.push_back({ui[i],vi[i],wi[i]});
//		q.push_back({vi[i],ui[i],wi[i]});
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			q.push_back({n+i,j,a[i][j]});
//			q.push_back({j,n+i,a[i][j]});
		}
	}
//	cout<<"okk"<<endl;
	sort(q.begin(),q.end(),cmp);
//	for(int i=0;i<q.size();i++)
//		cout<<q[i].u<<" "<<q[i].v<<" "<<q[i].w<<endl;
//	cout<<"ojbk"<<endl;
	for(int lz=0;lz<=(1<<k)-1;lz++)
	{
		int num=init(lz);
		ll pl=prim(n+num);
//		cout<<lz<<"x"<<yu<<"x"<<pl<<endl;
		ans=min(pl+yu,ans);
	}
	cout<<ans<<endl;
	return 0;
}


