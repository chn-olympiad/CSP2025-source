#include<bits/stdc++.h>
namespace Hoks
{
	using namespace std;
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	const int N=5e2+10,M=524288,B=19,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
	char st;
	int n,m,a[N],b[N],fac[N];char s[N];
	namespace Fast_IO
	{
		static char buf[1000000],*paa=buf,*pd=buf,ot[10000000];int length=0;
		#define getchar() (paa==pd)&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
		inline int read()
		{
			int x(0),t(1);char c(getchar());
			while(!isdigit(c)){if(c=='-') t=-1;c=getchar();}
			while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
			return x*t;
		}
		inline void flush(){fwrite(ot,1,length,stdout);length=0;}
		inline void put(char c){if(length==999999) flush();ot[length++]=c;}
		inline void put(string s){for(char c:s) put(c);}
		inline void print(int x)
		{
			if(x<0) put('-'),x=-x;
			if(x>9) print(x/10);
			put(x%10+'0');
		}
		inline bool chk(char c){return !((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'));}
		inline bool ck(char c){return c!=' '&&c!='\n'&&c!='\r'&&c!=EOF;}
		inline void rd(char s[],int&n)
		{
			s[++n]=getchar();
			while(chk(s[n])) s[n]=getchar();
			while(ck(s[n])) s[++n]=getchar();
			n--;
		}
	}
	using namespace Fast_IO;
	inline void solve1()
	{
		for(int i=1;i<=n;i++) b[i]=i;
		int ans=0;
		do
		{
			int w=0;
			for(int i=1;i<=n;i++) if(!(a[b[i]]>w&&s[i]=='1')) w++;
			if(n-w>=m) ans++; 
		}while(next_permutation(b+1,b+1+n));
		print(ans%mod);put('\n');
	}
	inline void add(int&x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	int f[B][M],g[B][M];
	char ed;
	inline void solve2()
	{
		f[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n;j++) for(int ss=0;ss<1ll<<n;ss++)
				if(f[j][ss]) for(int k=1;k<=n;k++)
					if(!(ss>>(k-1)&1))
					{
						int nj=(s[i+1]=='1')&&(a[k]>i-j);nj+=j;
						add(g[nj][ss|(1ll<<(k-1))],f[j][ss]);
					}
			for(int j=0;j<=n;j++) for(int ss=0;ss<1ll<<n;ss++) f[j][ss]=g[j][ss],g[j][ss]=0;
		}int al=1ll<<n;al--;int ans=0;
		for(int i=m;i<=n;i++) add(ans,f[i][al]);
		print(ans);put('\n');
	}
	inline void solve3()
	{
		int ans=fac[n],ss=n;
		for(int i=1;i<=n;i++) b[a[i]]++;
		int t=1;
		for(int i=1,yy=0;i<=n;i++)
		{
			if(s[i]=='0') continue;
			ss--;int res=0;
			for(int j=0;j<i;j++) res+=b[j];
			t=t*(res-i+1)%mod;
		}t=t*fac[ss]%mod;
		print((ans-t+mod)%mod);put('\n');
	}
	inline void solve()
	{
		n=read(),m=read();n=0;rd(s,n);
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		for(int i=fac[0]=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		if(n<=10) return solve1();
		if(n<=18) return solve2();
		if(m==1) return solve3();
	}
	inline void main()
	{
//		system("fc employ.out employ.ans");
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		int T=1;
//		T=read();
		while(T--) solve();
		genshin:;flush();
//		cout<<((&st)-(&ed))*1.0/1024/1024;
	}
}
signed main()
{
	Hoks::main();return 0;
}
/*
18 0
11010010010110100
1 2 3 4 5 6 7 8 9 10 11 12 13 14 2 1 3 2
*/
/*
11 2
10101001001
1 2 3 4 7 1 4 2 3 4 2
36046080
*/
/*
12 2
101010001001
1 2 3 4 5 7 1 4 2 3 4 2
435456000
*/
/*
12 1
101010001001
1 2 3 4 5 7 1 4 2 3 4 2
479001600
*/
/*
15 1
101011101001101
1 2 3 4 5 7 1 4 2 3 4 2 12 14 10
972509923
*/
