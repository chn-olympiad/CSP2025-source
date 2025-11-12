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

const int N=6e5+5,M=6e5+5,V=6e5+5,mod=998244353;
const double eps=1e-9;

il void read(int& x){char c;bool op=0;while((c=getchar())<'0'||c>'9')c=='-'&&(op=1);x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);op&&(x=-x);}

template <typename T> il T& add(T& a,T b){return (a+=b)>=mod&&(a-=mod),a;}
template <typename T> il T& chmax(T& a,T b){return b>a&&(a=b),a;}
template <typename T> il T& chmin(T& a,T b){return a>b&&(a=b),a;}

#define multiple_test 0
int __T=1,test_id;

int n,m,a[N];
char s[N];

il void solve()
{
	scanf("%lld %lld",&n,&m),scanf("%s",s+1); rep(i,1,n) scanf("%lld",&a[i]);
	
	int p[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int ans=0,cnt,now,c0;
	do
	{
		cnt=0,now=0,c0=0;
		rep(i,1,n)
		{
			c0+=s[i]=='0';
			if(s[i]=='0' || now>=a[p[i]]) {++now; continue;}
			++cnt;
		}
		if(cnt>=m) ++ans;
	}while(next_permutation(p+1,p+n+1));
	
	printf("%lld",(ans%mod+mod)%mod);
}

il void init()
{

}

bool memory_end;
signed main()
{
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"memory = %.3f MB\n\n",abs(&memory_begin-&memory_end)/1024./1024.);
	init(); multiple_test&&(scanf("%lld",&__T),1);
	rep(__Ti,1,__T) solve();
//	fprintf(stderr,"\ntime = %.3f ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

