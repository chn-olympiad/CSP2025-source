#include<bits/stdc++.h>
namespace Hoks
{
	using namespace std;
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	const int N=5.2e6+10,M=4e5+10,mod1=998244353,mod2=1e9+7,p1=13331,p2=233,V=5e6,INF=0x3f3f3f3f;
	char beajgiojea;
	struct BIT
	{
		int n,c[M];BIT(){memset(c,0,sizeof c);}
		inline void modify(int x,int w){for(x++;x<=n;x+=x&-x) c[x]+=w;}
		inline int query(int x){int res=0;for(x++;x;x-=x&-x) res+=c[x];return res;}
		inline void mdf(int l,int r,int w){modify(l,w);modify(r+1,-w);}
		inline int qry(int l,int r){return query(r)-query(l-1);}
	}tt;
	int n,m,ans[M];char s[N],st[N];
	vector<char>as[M],at[M];
	int t[27][N];vector<int>x[M];int tot,cnt;
	map<pair<pair<int,int>,pair<int,int>>,int>mp;
	vector<int>ed[N];int low;
	int si[M],son[M],dfn[M],fa[M],top[M],to[M];
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
	char beajgiojeaiojehaoiqw;
	inline void init()
	{
		int l1=0,l2=0;
		for(int i=1;i<=n;i++)
		{
			int l=INF,r=0,ll=0;rd(s,ll);ll=0;rd(st,ll);l1+=ll*2;
			for(int j=1;j<=ll;j++) if(s[j]!=st[j]) l=min(l,j),r=max(r,j);
			long long sw1=0,sw2=0,tw1=0,tw2=0;
			for(int j=l;j<=r;j++) sw1=(1ll*sw1*p1+s[j])%mod1,sw2=(1ll*sw2*p2+s[j])%mod2;
			for(int j=l;j<=r;j++) tw1=(1ll*tw1*p1+st[j])%mod1,tw2=(1ll*tw2*p2+st[j])%mod2;
			if(l!=INF&&r)
			{
				for(int j=l-1;j>=1;j--) as[i].emplace_back(s[j]);
				for(int j=r+1;j<=ll;j++) at[i].emplace_back(s[j]);
			}pair<pair<int,int>,pair<int,int>> w={{sw1,sw2},{tw1,tw2}};
			if(!mp.count(w)) mp[w]=++tot;
			x[mp[w]].emplace_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			int l=INF,r=0,ll=0,lll=0;rd(s,ll);rd(st,lll);l2+=ll*2;
			if(ll!=lll){ans[i]=0;continue;} 
			for(int j=1;j<=ll;j++) if(s[j]!=st[j]) l=min(l,j),r=max(r,j);
			long long sw1=0,sw2=0,tw1=0,tw2=0;
			for(int j=l;j<=r;j++) sw1=(1ll*sw1*p1+s[j])%mod1,sw2=(1ll*sw2*p2+s[j])%mod2;
			for(int j=l;j<=r;j++) tw1=(1ll*tw1*p1+st[j])%mod1,tw2=(1ll*tw2*p2+st[j])%mod2;
			if(l!=INF&&r)
			{
				for(int j=l-1;j>=1;j--) as[i+n].emplace_back(s[j]);
				for(int j=r+1;j<=ll;j++) at[i+n].emplace_back(s[j]);
			}pair<pair<int,int>,pair<int,int>> w={{sw1,sw2},{tw1,tw2}};
			x[mp[w]].emplace_back(i+n);
		}
	}
	inline void insert(vector<char> s,int id)
	{
		int u=0;
		for(auto ss:s)
			if(!t[ss-'a'][u]) u=t[ss-'a'][u]=++cnt;
			else u=t[ss-'a'][u];
		ed[u].emplace_back(id);
	}
	inline void dfs1(int u,int ff)
	{
		si[u]=1;son[u]=0;fa[u]=ff;
		for(int i=0,v=t[0][u];i<26;i++,v=t[i][u])
		{
			if(!v) continue;
			dfs1(v,u);si[u]+=si[v];
			if(si[v]>si[son[u]]) son[u]=v;
		}
	}
	inline void dfs2(int u,int topf)
	{
		top[u]=topf;dfn[u]=++low;for(auto x:ed[u]) to[x]=u;
		if(son[u]) dfs2(son[u],topf);
		for(int i=0,v=t[0][u];i<26;i++,v=t[i][u]) if(v!=son[u]&&v) dfs2(v,v);
	}
	inline void cleart()
	{
		for(int j=0;j<26;j++) for(int i=0;i<=cnt;i++) t[j][i]=0;
		for(int i=0;i<=cnt;i++) ed[i].clear();cnt=0;
	}
	inline void clear()
	{
		for(int j=0;j<26;j++) for(int i=0;i<=cnt;i++) t[j][i]=0;
		for(int i=0;i<=cnt;i++) ed[i].clear();low=cnt=0;
	}
	inline void modify(int x,int w){tt.modify(x,w);}
	inline int query(int x)
	{
		int res=0;
		while(top[x]) res+=tt.qry(dfn[top[x]],dfn[x]),x=fa[top[x]];
		return res+tt.qry(0,dfn[x]);
	}
	inline void solve(int u)
	{
		sort(ed[u].begin(),ed[u].end());
		for(auto x:ed[u]) if(x<=n) modify(dfn[to[x]],1);
		for(auto x:ed[u]) if(x>n) ans[x-n]=query(to[x]);
		for(int i=0,v=t[0][u];i<26;i++,v=t[i][u]) if(v) solve(v);
		for(auto x:ed[u]) if(x<=n) modify(dfn[to[x]],-1);
	}
	inline void solve()
	{
		n=read(),m=read();init();
		for(int i=1;i<=tot;i++)
		{
//			cout<<i<<endl;
//			for(auto j:x[i])
//			{
//				cout<<j<<endl;
//				for(auto c:as[j]) cout<<c;cout<<endl;
//				for(auto c:at[j]) cout<<c;cout<<endl;
//			}cout<<endl;
			for(auto j:x[i]) insert(as[j],j);
			dfs1(0,0);dfs2(0,0);cleart();
			for(auto j:x[i]) insert(at[j],j);
			tt.n=low+5;solve(0);clear();
		}
		for(int i=1;i<=m;i++) print(ans[i]),put('\n');
	}
	inline void main()
	{
//		system("fc replace.out replace3.ans");
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		int T=1;
//		T=read();
		while(T--) solve();
		genshin:;flush();
//		cout<<((&beajgiojea)-(&beajgiojeaiojehaoiqw))*1.0/1024/1024;
	}
}
signed main()
{
	Hoks::main();return 0;
}
/*
hash get string
s_trie and t_trie
it's just enough,yeah?
*/
/*
4 2
b a
ba aa
aba aaa
aaabaa aaaaaa
aabaa aaaaa
baaaa aaaaa
*/
/*
17:11
Let's go!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
