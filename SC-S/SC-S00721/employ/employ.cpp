#include <bits/stdc++.h>
#define endl '\n'
#define int ll
#define inline
#define sh short
#define fi first
#define se second
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=998'244'353;
const int MN=1e6+10;
//const ll inf=1e18;
const int inf=1e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

int n,m,ans,res,a[MN],ji[MN],su[MN],sv[MN],inv[MN];string s,ss;

inline int qpow(int a,int b,int p=mod)
{
	int res=1;while(b)res=b&1?res*a%p:res,a=a*a%p,b>>=1;
	return res;
}

inline int C(int x,int y){return ji[x]*inv[y]%mod*inv[x-y]%mod;}

inline bool solve()
{
	cin>>n>>m>>s,res=n,ss="";
	for(int i=1;i<=n;++i)ss+="1";
	for(int i=1;i<=n;++i)cin>>a[i],res-=a[i]==0;
	if(s==ss)
	{
		inv[0]=su[0]=ji[0]=1;for(int i=1;i<=n;++i)ji[i]=ji[i-1]*i%mod;
//		for(int i=1;i<=n;++i)su[i]=su[i-1]*ji[i]%mod;
//		sv[n]=qpow(su[n],mod-2,mod);
//		for(int i=n-1;i;--i)sv[i]=sv[i+1]*ji[i+1]%mod;
//		for(int i=1;i<=n;++i)inv[i]=sv[i]*su[i-1]%mod;
//		for(int i=m;i<=n;++i)ans=(ans+C(n,i))%mod;
		cout<<ji[res]<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}

signed main()
{
	frein(employ);freout(employ);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc employ.out employ.ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}