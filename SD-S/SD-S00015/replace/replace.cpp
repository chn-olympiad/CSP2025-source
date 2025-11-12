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
#define int long long
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

const int maxn=2e5+5;
const int mod=2008090913;
const int base=233;

int h[maxn*30][2];
vector<int> H[maxn][2];
string s[maxn][2];
int L[maxn],R[maxn],pw[maxn*30];

bool M2;

inline PII get_h1(int id,int l,int r)
{
	ret {((H[id][0][r]-H[id][0][l-1]*pw[r-l+1]%mod)+mod)%mod,((H[id][1][r]-H[id][1][l-1]*pw[r-l+1]%mod)+mod)%mod};
}

inline PII get_h2(int l,int r)
{
	ret {((h[r][0]-h[l-1][0]*pw[r-l+1]%mod)+mod)%mod,((h[r][1]-h[l-1][1]*pw[r-l+1]%mod)+mod)%mod};
}

inline void mian()
{
	int n,q;
	cin>>n>>q;
	F(i,1,n) 
	{
		cin>>s[i][0]>>s[i][1];
		H[i][0].resize(s[i][0].length()+1);
		H[i][1].resize(s[i][0].length()+1);
		int len=s[i][0].length();
		F(j,1,len) H[i][0][j]=(H[i][0][j-1]*base%mod+s[i][0][j-1]-'a')%mod;
		F(j,1,len) H[i][1][j]=(H[i][1][j-1]*base%mod+s[i][1][j-1]-'a')%mod;
	}
	pw[0]=1;
	F(i,1,5000000) pw[i]=pw[i-1]*base%mod;
	F(i,1,n)
	{
		R[i]=-1;
		L[i]=10000000;
		
		F(j,0,s[i][0].length()-1)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				L[i]=min(L[i],j);
				R[i]=max(j,R[i]);
			}
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length())
		{
			cout<<0<<"\n";
			continue;
		}
		int len=t1.length();
		F(j,1,len) h[j][0]=(h[j-1][0]*base%mod+t1[j-1]-'a')%mod;
		F(j,1,len) h[j][1]=(h[j-1][1]*base%mod+t2[j-1]-'a')%mod;
		int ll=10000000,rr=-1;
		F(i,0,len-1)
		{
			if(t1[i]!=t2[i])
			{
				ll=min(ll,i);
				rr=max(rr,i);
			}
		}
		int ans=0;
		F(i,1,n)
		{
			if((R[i]-L[i]+1)==(rr-ll+1))
			{
				int del=L[i],del2=s[i][0].length()-R[i]-1;
				int ll2=ll-del;
				int rr2=rr+del2;
				if(ll2<0||rr2>=len) continue;
				if(get_h1(i,1,s[i][0].length())==get_h2(ll2+1,rr2+1))
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	cout<<endl;
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

#define FILEIO replace
inline void IO()
{
#ifdef FILEIO
	freopen(INNAME(FILEIO)".in","r",stdin),freopen(INNAME(FILEIO)".out","w",stdout);
#endif
}


