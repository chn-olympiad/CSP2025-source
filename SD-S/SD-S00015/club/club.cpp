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

int d[maxn][5];
int vis[maxn];int cnt[10];
PII a[maxn],b[maxn];
priority_queue<PII,vector<PII>,greater<PII> >q[3];

struct rnode
{
	int x,id,op;
}c[maxn];

bool M2;

bool cmp(rnode x,rnode y)
{
	ret x.x>y.x;
}

inline void mian()
{
	int n,cnt1=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	int m=n/2;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	F(i,1,n) vis[i]=0;
	F(i,1,n)
	{
		PII x,y,z;
		cin>>x.first>>y.first>>z.first;
		d[i][0]=x.first;
		d[i][1]=y.first;
		d[i][2]=z.first;
		x.second=0;
		y.second=1;
		z.second=2;
		PII maxx={-1,0},maxx2={-1,0};
		if(x>maxx2) maxx2=x;
		if(maxx2>maxx) swap(maxx,maxx2);
		if(y>maxx2) maxx2=y;
		if(maxx2>maxx) swap(maxx,maxx2);
		if(z>maxx2) maxx2=z;
		if(maxx2>maxx) swap(maxx,maxx2);
		a[i]=maxx;
		b[i]=maxx2;
		cnt1++;
		c[cnt1].x=x.first;c[cnt1].id=i;c[cnt1].op=0;
		cnt1++;
		c[cnt1].x=y.first;c[cnt1].id=i;c[cnt1].op=1;
		cnt1++;
		c[cnt1].x=z.first;c[cnt1].id=i;c[cnt1].op=2;
	}
	sort(c+1,c+cnt1+1,cmp);
	int ans=0;
	F(i,1,cnt1)
	{
		if(vis[c[i].id]) continue;
		int del=a[c[i].id].first-b[c[i].id].first;
		if(cnt[c[i].op]==m)
		{
			PII x=q[c[i].op].top();
			if(x.first<del)
			{
				q[c[i].op].pop();
				q[c[i].op].push({del,c[i].id});
				ans+=c[i].x;
				ans-=x.first;
				int nx=b[x.second].second;
				cnt[nx]++;
				q[nx].push({b[x.second].first-a[x.second].first,x.second});
				vis[c[i].id]=c[i].op+1;
				vis[x.second]=nx+1;
			}
		}
		else
		{
			ans+=c[i].x;
			q[c[i].op].push({del,c[i].id}); 
			cnt[c[i].op]++;
			vis[c[i].id]=c[i].op+1;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int T=1;
	IO();
	#define multitest 1
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

#define FILEIO club
inline void IO()
{
#ifdef FILEIO
	freopen(INNAME(FILEIO)".in","r",stdin),freopen(INNAME(FILEIO)".out","w",stdout);
#endif
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


*/
