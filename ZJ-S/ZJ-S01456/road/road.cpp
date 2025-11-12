//一眼最小生成树。
//一开始的思路有点复杂，姑且别提了吧
//用 O(2^k) 枚举对哪些乡村进行城市化改造，然后暴力建出所有 m+cnt*n 条边
//m+cnt*n<=10^6+10*10^4 可能比 2*10^6 还小，因此开得下
//然后直接克鲁斯卡尔求出最小生成树，单次复杂度 O((m+kn)*log(m+kn))
//总体复杂度 O(2^k*(m+kn)*log(m+kn))，可能略微卡不过去
//不过注意到 m 较大而 n 较小，显然可以先跑一遍最小生成树，然后后续计算只需保留最小生成树的 n-1 条边
//复杂度变成了 O(2^k*(kn)*log(kn))，比刚才好多了
//但是感觉仍然有一点极限，事实上图可能比较稠密，用 Prim 可能更好？
//复杂度应该可以降到 O(2^k*(n*log(n)+kn))，应该可过
//第一步的克鲁斯卡尔就不改了吧，应该不会卡得这么死吧
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+100,M=1e6+100;
int n,f[N],m,k,cntt;
ll a[13][N],c[13],dis[N];
bool vis[N];
struct eg
{
	int u,v;
	ll w;
}b[M];
vector<eg>g;
vector<pair<int,ll> >G[N];
bool cmp(eg x,eg y)
{
	return x.w<y.w;
}
int F(int x)
{
	return x==f[x]?x:f[x]=F(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	sort(b+1,b+m+1,cmp);
	ll as=0;
	int ct=0;
	for(int i=1;i<=m;i++)
	{
		if(F(b[i].u)!=F(b[i].v))
		{
			f[F(b[i].u)]=F(b[i].v);
			ct++;
			as+=b[i].w;
			g.push_back(b[i]);
			if(ct==n-1)
			{
				break;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	//cerr<<as<<"\n";
	for(int st=1;st<(1<<k);st++)
	{
		for(int j=0;j<=n+k;j++)
		{
			G[j].clear();
			dis[j]=0x3f3f3f3f3f3f3f3fll;
			vis[j]=0;
		}
		set<pair<ll,int> >S;
		cntt=0;
		ll su=0;
		int nds=n;
		for(int j=0;j<k;j++)
		{
			if((st>>j)&1)
			{
				su+=c[j+1];
				nds++;
				if(su>as)
				{
					goto nex;
				}
				for(int l=1;l<=n;l++)
				{
					//cntt++;
					//d[cntt].u=n+j+1;
					//d[cntt].v=l;
					//d[cntt].w=a[j+1][l];
					G[n+j+1].push_back(make_pair(l,a[j+1][l]));
					G[l].push_back(make_pair(n+j+1,a[j+1][l]));
				}
			}
		}
		for(int j=0;j<g.size();j++)
		{
			//cntt++;
			//d[cntt]=g[j];
			G[g[j].u].push_back(make_pair(g[j].v,g[j].w));
			G[g[j].v].push_back(make_pair(g[j].u,g[j].w));
		}
		//cerr<<su<<"\n";
		S.insert(make_pair(0ll,1));
		while(!S.empty())
		{
			int u=(S.begin()->second);
			su+=(S.begin()->first);
			S.erase(S.begin());
			vis[u]=1;
			if(su>as)
			{
				goto nex;
			}
			for(int j=0;j<G[u].size();j++)
			{
				int v=G[u][j].first;
				ll w=G[u][j].second;
				if(!vis[v]&&dis[v]>w)
				{
					if(dis[v]<0x3f3f3f3f3f3f3f3fll)
					{
						S.erase(make_pair(dis[v],v));
					}
					dis[v]=w;
					S.insert(make_pair(w,v));
				}
			}
		}
		as=min(as,su);
		nex:;
	}
	printf("%lld\n",as);
	return 0;
}