#include<bits/stdc++.h>
namespace Hoks
{
	using namespace std;
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	const int N=1e4+10,M=1e6+10,B=15,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
	struct edge{int x,y,w;}e[M],g[M],gg[M];
	int n,m,k,tot,w[B],f[N],a[B][N];
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
	inline bool cmp(edge x,edge y){return x.w<y.w;}
	inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
	inline void solve()
	{
		n=read(),m=read(),k=read();int ans=0;tot=0;
		for(int i=1,x,y,w;i<=m;i++) x=read(),y=read(),w=read(),e[i]={x,y,w};
		for(int i=1;i<=k;i++)
		{
			w[i]=read();
			for(int j=1;j<=n;j++) a[i][j]=read();
		}sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y) continue;f[x]=y;g[++tot]=e[i];
			ans+=e[i].w;
		}int cnt=tot;
		for(int i=1;i<=cnt;i++) gg[i]=g[i];
		for(int s=1;s<1ll<<k;s++)
		{
			for(int i=1;i<=cnt;i++) g[i]=gg[i];
			tot=cnt;int res=0;
			for(int i=1;i<=k;i++) if(s>>(i-1)&1) res+=w[i];
			for(int i=1;i<=k;i++) if(s>>(i-1)&1)
				for(int j=1;j<=n;j++) g[++tot]={n+i,j,a[i][j]};
			sort(g+1,g+1+tot,cmp);
			for(int i=1;i<=n+k;i++) f[i]=i;
			for(int i=1;i<=tot;i++)
			{
				int x=find(g[i].x),y=find(g[i].y);
				if(x==y) continue;f[x]=y;res+=g[i].w;
			}ans=min(ans,res);
		}print(ans);put('\n');
	}
	inline void main()
	{
//		system("fc road.out road4.ans");
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		int T=1;
//		T=read();
		while(T--) solve();
		genshin:;flush();
	}
}
signed main()
{
	Hoks::main();return 0;
}
