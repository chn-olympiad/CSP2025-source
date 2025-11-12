#include<bits/stdc++.h>
namespace Hoks
{
	using namespace std;
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	const int N=1e5+10,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
	int n,a[4][N];
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
	inline void solve()
	{
		n=read();vector<int>x[4];int s=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) a[j][i]=read();
			pair<int,int> w{a[1][i],1};
			w=max({w,{a[2][i],2},{a[3][i],3}});
			x[w.second].emplace_back(i);s+=w.first;
		}priority_queue<int>q;int nd=0;
		for(int i=1;i<=3;i++) if(x[i].size()>n/2) for(auto w:x[i])
		{
			int mx=0;for(int k=1;k<=3;k++) if(i!=k) mx=max(mx,a[k][w]);
			q.emplace(mx-a[i][w]);nd=x[i].size()-n/2;
		}		
		while(nd&&!q.empty()) s+=q.top(),q.pop(),nd--;
		print(s);put('\n');
	}
	inline void main()
	{
//		system("fc club.out club5.ans");
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		int T=1;
		T=read();
		while(T--) solve();
		genshin:;flush();
	}
}
signed main()
{
	Hoks::main();return 0;
}
