#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;
const int maxn=1e4+10+100;
const int maxm=1e6+10;
int n,m,k;
typedef long long ll;
struct Edge
{
	int f,t;
	int w;
}eg[maxm];
bool operator<(const Edge& u,const Edge& v)
{
	return u.w<v.w;
}
Edge a[30][maxn];
int c[maxn];
long long ans=1e18;
namespace IOFT
{
	char ch;
	inline void rdll(ll& x)
	{
		x=0ll;
		ch=getchar();
		while(ch>'9'||ch<'0')
		{
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
	}
	void rdii(int& x)
	{
		x=0;
		ch=getchar();
		while(ch>'9'||ch<'0')
		{
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
	}
}
using IOFT::rdll;
using IOFT::rdii;
namespace solverr
{
	int f[maxn];
	int sz[maxn];
	bitset<20> bs;
	int cnt[30];
	void initft()
	{
		for(int i=1;i<=n+k;++i)
		{
			f[i]=i;
			sz[i]=1;
		}
		for(int i=0;i<=k;++i)
		{
			cnt[i]=1;
		}
	}
	int finf(int x)
	{
		if(f[x]==x)return x;
		return f[x]=finf(f[x]);
	}
	bool add(int u,int v)
	{
		u=finf(u);
		v=finf(v);
		if(u==v)
		{
			return 0;
		}
		if(sz[u]<sz[v])
		{
			swap(u,v);
		}
		f[v]=u;
		sz[u]+=sz[v];
		return 1;
	}
	int mnww;
	int to;
	int from;
	int id;
	int kk;
	long long tot;
	int used[30];
	int usedcnt;
	int i;
	int juu;
	void solve(int SS)
	{
		initft();
		bs=SS<<1;
		kk=bs.count();
//		printf("%d:\n",kk);
		tot=0ll;
		usedcnt=0;
		for(i=1;i<=k;++i)
		{
			if(bs[i])
			{
				tot+=c[i];
				used[++usedcnt]=i;
			}
		}
		int tocnt=1;
		for(i=1;i<n+kk;++i,++tocnt)
		{
			mnww=eg[cnt[0]].w;
//			to=eg[cnt[0]].t;
//			from=eg[cnt[0]].f;
			id=0;
			for(juu=1;juu<=usedcnt;++juu)
			{
				int& j=used[juu];
				if(bs[j]&&mnww>a[j][cnt[j]].w)
				{
					mnww=a[j][cnt[j]].w;
					id=j;
//					to=a[j][cnt[j]].t;
//					from=a[j][cnt[j]].f;
				}
			}
			if(id==0)
			{
				if(add(eg[cnt[0]].f,eg[cnt[0]].t))
				{
					tot=tot+(long long)(mnww);
				}
				else 
				{
					--i;
				}
			}
			else 
			{
				if(add(a[id][cnt[id]].f,a[id][cnt[id]].t))
				{
					tot=tot+(long long)(mnww);
				}
				else 
				{
					--i;
				}
			}
//			if(add((id!=0)?(a[id][cnt[id]].f):(eg[cnt[0]].f),(id!=0)?(a[id][cnt[id]].t):(eg[cnt[0]].t)))tot=tot+(long long)(mnww);
//			else
//			{
//				--i;
//			}
			++cnt[id];
		}
//		cerr<<tocnt<<' ';
		ans=min(ans,tot);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int begg=clock();
	rdii(n);rdii(m);rdii(k);
	for(int i=1;i<=m;++i)
	{
		rdii(eg[i].f);
		rdii(eg[i].t);
		rdii(eg[i].w);
	}
//	cerr<<clock()-begg<<endl;
	for(int i=1;i<=k;++i)
	{
		rdii(c[i]);
		for(int j=1;j<=n;++j)
		{
			a[i][j].f=i+n;
			a[i][j].t=j;
			rdii(a[i][j].w);
		}
	}
//	cerr<<clock()-begg<<endl;
	sort(eg+1,eg+m+1);
//	cerr<<clock()-begg<<endl;
	for(int i=1;i<=k;++i)
	{
		sort(a[i]+1,a[i]+n+1);
	}
//	cerr<<clock()-begg<<endl;
//	printf("\n\n\n");
//	for(int i=1;i<=m;++i)
//	{
//		printf("%d:%d %d %d\n",i,eg[i].f,eg[i].t,eg[i].w);
//	}
//	printf("\n\n\n");
//	for(int j=1;j<=k;++j)
//	{
//		
//		for(int i=1;i<=n;++i)
//		{
//			printf("%d %d %d\n",a[j][i].f,a[j][i].t,a[j][i].w);
//		}
//		printf("\n");
//	}
	for(int i=0;i<(1<<k);++i)
	{
		solverr::solve(i);
	}
	printf("%lld\n",ans);
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
