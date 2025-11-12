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
#define popcount(x) __builtin_popcount(x)
using ll=long long;
using PII=pair<int,int>;
using db=double;
using DB=long double;
inline void init();
inline void IO();
mt19937 rng(time(NULL));

const int maxn=1e5+5;
const int mod=998244353;

int Ans[maxn];
//int dp[20][20][262149];
int p[maxn],c[maxn];

bool M2;

inline void mian()
{
	int n,m,ans=0;
	cin>>n>>m;
	F(i,1,n) p[i]=i;
	string s;
	cin>>s;
	s=" "+s;
	F(i,1,n) cin>>c[i];
//	dp[0][0][0]=1;
//	F(i,1,n)
//	{
//		F(j,0,i)
//		{
//			F(S,0,(1<<n)-1)
//			{
//				if(popcount(S)!=i) continue;
//				F(l,1,n)
//				{
//					if(S&(1<<(l-1)))
//					{
//						if(i==j)
//						{
//							if((s[i]=='0')||(c[l]==0)) dp[i][j][S]=(dp[i-1][j-1][S^(1<<(l-1))]+dp[i][j][S])%mod;
//							continue;
//						}
//						if(c[l]==j)
//						{
//							if((s[i]=='0')) dp[i][j][S]=((dp[i-1][j-1][S^(1<<(l-1))])+dp[i][j][S])%mod;
//							else if(s[i]=='1') dp[i][j][S]=(dp[i][j][S]+dp[i-1][j][S^(1<<(l-1))])%mod;
//							continue;
//						}
//						if((s[i]=='1')&&(c[l]>j)) 
//						{
//							dp[i][j][S]=(dp[i-1][j][S^(1<<(l-1))]+dp[i][j][S])%mod;
//						}
//						else 
//						{
//							if((c[l]<=(j-1))) dp[i][j][S]=(dp[i-1][j-1][S^(1<<(l-1))]+dp[i][j][S])%mod;
//						}
//					}
//				}
//			}
//		}
//	}
//	F(j,0,n-m)
//	{
//		ans=(ans+dp[n][j][(1<<n)-1])%mod;
//		D(dp[n][j][(1<<n)-1]);
//	}
//	cout<<ans<<endl;
	ans=0;
	do
	{
		int cnt=0;
		F(i,1,n)
		{
			if(s[i]=='0')
			{
				cnt++;	
			}
			else if(cnt>=c[p[i]])
			{
				cnt++;
			}
		}
		if((n-cnt)>=m)
		{
//			Ans[cnt]++;
			ans++;
			ans%=mod;
		}
	}while(next_permutation(p+1,p+n+1));
//	F(i,1,n)
//	{
//		D(dp[1][0][1<<(i-1)],dp[1][1][1<<(i-1)]);
//	}
//	F(i,0,n-m)
//	{
//		D(Ans[i]);
//	}
	cout<<ans<<endl;
}

int main()
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

#define FILEIO employ
inline void IO()
{
#ifdef FILEIO
	freopen(INNAME(FILEIO)".in","r",stdin),freopen(INNAME(FILEIO)".out","w",stdout);
#endif
}

/*
3 1
110
1 0 1
*/


