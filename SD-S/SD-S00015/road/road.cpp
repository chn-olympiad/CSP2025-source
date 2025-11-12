bool M1;
#include <bits/stdc++.h>
using namespace std;
#define XY cerr<<"XY"<<endl
#define MKF cerr<<"MKF"<<endl
#define CONNECT_BASE(x,y) x##y
#define CONNECT(x,y) CONNECT_BASE(x,y)
#define NAME(x) #x
#define INNAME(x) NAME(x)
#define DEBUG_BASE(x) cerr<<#x<<"="<<x<<' '
#define DEB_1(x) DEBUG_BASE(x)
#define DEB_2(x,y) DEB_1(x),DEB_1(y)
#define DEB_3(x,y,z) DEB_1(x),DEB_2(y,z)
#define DEB_4(a,b,c,d) DEB_1(a),DEB_3(b,c,d)
#define DEB_5(a,b,c,d,e) DEB_1(a),DEB_4(b,c,d,e)
#define DEB_6(a,b,c,d,e,f) DEB_1(a),DEB_5(b,c,d,e,f)
#define COUNT_BASE(_6,_5,_4,_3,_2,_1,x,...) x
#define COUNT(...) COUNT_BASE(__VA_ARGS__,6,5,4,3,2,1)
#define D(...) cerr<<"[In Line "<<__LINE__<<"]: ",CONNECT(DEB_,COUNT(__VA_ARGS__))(__VA_ARGS__),cerr<<endl
//#define int long long
#define F(i,a,b) for(int i=(a),i##end=(b);i<=(i##end);++i)
#define UF(i,a,b) for(int i=(a),i##end=(b);i>=(i##end);--i)
#define look_time cerr<<(double)clock()/CLOCKS_PER_SEC<<endl
#define look_memory cerr<<abs(&M1-&M2)/1024.0/1024.0<<endl
#define uni(x,y) uniform_int_distribution<int>(x,y)(rng)
#define unl(x,y) uniform_int_distribution<ll>(x,y)(rng)
#define unr(x,y) uniform_real_distribution<double>(x,y)(rng)
#define ret return
using ll=long long;
using PII=pair<int,int>;
using db=double;
using DB=long double;
inline void init();
inline void IO();
mt19937 rng(time(NULL));

const int maxn=1e6+5;

bool vis[maxn],vis3[maxn];
int vis2[maxn];
int f[maxn],c[maxn];

struct Edge
{
	int u,v,w;
}E[maxn],E2[maxn];

bool M2;

inline int find(int x)
{
	ret f[x]=(x==f[x])?x:find(f[x]);
}

bool cmp(Edge a,Edge b)
{
	ret a.w<b.w;
}

inline void mian()
{
	int n,m,k;
	cin>>n>>m>>k;
	F(i,1,n) f[i]=i;
	F(i,1,m) cin>>E[i].u>>E[i].v>>E[i].w;
	sort(E+1,E+m+1,cmp);
	ll minn=1e18,sum=0;
	F(i,1,m)
	{
		int fx=find(E[i].u),fy=find(E[i].v);
		if(fx!=fy)
		{
			f[fx]=fy;
			vis[i]=1;
			sum+=E[i].w;
		}
	}
	minn=min(minn,sum);
	int cnt=0;
	F(i,1,m) if(vis[i]) E2[++cnt]=E[i];
	F(i,1,cnt) vis2[i]=0;
	F(i,1,k)
	{
		cin>>c[i];
		F(j,1,n)
		{
			cnt++;
			E2[cnt].u=j;
			E2[cnt].v=n+i;
			cin>>E2[cnt].w;
		}
	}
	sort(E2+1,E2+cnt+1,cmp);
	F(i,1,cnt) if(E2[i].v>n) vis2[i]=E2[i].v-n;
	vis3[0]=1;
	for(int S=0;S<(1<<k);S++)
	{
		sum=0;int X=0;
		F(i,1,k) 
		{
			if(S&(1<<(i-1))) vis3[i]=1,sum+=c[i],X++;
			else vis3[i]=0;
		}
		F(i,1,n+k) f[i]=i;
		int cnt2=0;
		F(i,1,cnt)
		{
			if(sum>minn) break;
			if(vis3[vis2[i]])
			{
				int fx=find(E2[i].u),fy=find(E2[i].v);
				if(fx!=fy)
				{
					f[fx]=fy;
					sum+=E2[i].w;
					cnt2++;
				}
			}
			if(cnt2==(n+X-1))
			{
				break;
			}
		}
		minn=min(minn,sum);
	}
	cout<<minn<<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int T=1;
	IO();
//	#define multitest 1
#ifdef multitest
	cin>>T;
#endif
	while(T--) init(),mian();
	look_time;
	look_memory;
	return 0;
}

inline void init()
{

}

#define FILEIO road
inline void IO()
{
#ifdef FILEIO
	freopen(INNAME(FILEIO)".in","r",stdin),freopen(INNAME(FILEIO)".out","w",stdout);
#endif
}

