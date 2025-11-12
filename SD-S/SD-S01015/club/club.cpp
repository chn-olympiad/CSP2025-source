// 华风夏韵，洛水天依！
// 天依宝宝可爱！> <

#include<bits/stdc++.h>

#define int long long
#define il inline
#define i128 __int128
#define double long double
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb emplace_back

using namespace std;
bool memory_begin;

const int N=1e5+5,M=6e5+5,V=6e5+5,mod=998244353;
const double eps=1e-9;

il void read(int& x){char c;bool op=0;while((c=getchar())<'0'||c>'9')c=='-'&&(op=1);x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);op&&(x=-x);}

template <typename T> il T& add(T& a,T b){return (a+=b)>=mod&&(a-=mod),a;}
template <typename T> il T& chmax(T& a,T b){return b>a&&(a=b),a;}
template <typename T> il T& chmin(T& a,T b){return a>b&&(a=b),a;}

#define multiple_test 1
int __T=1,test_id;

int n,a[N][3],c[N][3];
priority_queue <pii,vector<pii>,greater<pii>> q[3];

il void solve()
{
	read(n); rep(i,1,n) rep(j,0,2) read(a[i][j]);
	rep(j,0,2) priority_queue<pii,vector<pii>,greater<pii>>().swap(q[j]);
	
	int x,y,z,ans=0,tmp;
	rep(i,1,n)
	{
		tmp=max(a[i][0],max(a[i][1],a[i][2]));
		rep(j,0,2) a[i][j]==tmp&&(x=j);
		tmp=-1;
		rep(j,0,2) j^x&&a[i][j]>tmp&&(tmp=a[i][j]);
		rep(j,0,2) a[i][j]==tmp&&x^j&&(y=j);
		z=3-x-y;
		c[i][0]=x,c[i][1]=y,c[i][2]=z;
		
//		cerr<<i<<" : "<<x<<' '<<y<<' '<<z<<'\n';
		
		if(q[x].size()<n>>1) ans+=a[i][x],q[x].push(mp(a[i][x]-a[i][y],i));
		else
		{
			if(q[x].top().st<a[i][x]-a[i][y])
			{
				tmp=q[x].top().nd;
				ans-=a[tmp][x],q[x].pop();
//				cerr<<"del "<<tmp<<' '<<x<<" --> "<<ans<<'\n';
				ans+=a[i][x],q[x].push(mp(a[i][x]-a[i][y],i));
//				cerr<<"ins "<<i<<' '<<x<<" --> "<<ans<<'\n';
			}
			else tmp=i;
			ans+=a[tmp][c[tmp][1]],q[c[tmp][1]].push(mp(a[tmp][c[tmp][1]]-a[tmp][c[tmp][2]],tmp));
		}
	}
	
	printf("%lld\n",ans);
}

il void init()
{

}

bool memory_end;
signed main()
{
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"memory = %.3f MB\n\n",abs(&memory_begin-&memory_end)/1024./1024.);
	init(); multiple_test&&(read(__T),1);
	rep(__Ti,1,__T) solve();
//	fprintf(stderr,"\ntime = %.3f ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

