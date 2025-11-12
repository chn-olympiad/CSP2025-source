// replace.cpp
#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using pii=pair<int,int>;
const int M=2e5+5,N=1e7+5,base=19260817,delta=1145141;
string s[2][M],t[2][M];
int pl[M],pr[M],ql[M],qr[M],ans[M];
ull lsh[M],vals[M];
map<ull,int> mp;
vector<int> vecs[M],vect[M];
int ch[N][26],tot,fa[N],dfn[N],dcnt,siz[N],hson[N],top[N];
void trie_clear()
{
	for(int i=1;i<=tot;i++)
	{
		for(int j=0;j<26;j++) ch[i][j]=0;
		fa[i]=0;
	}
	tot=1,dcnt=0;
}
void insert(string s)
{
	int p=1;
	for(char c:s)
	{
		int x=c-'a';
		if(!ch[p][x]) ch[p][x]=++tot,fa[tot]=p;
		p=ch[p][x];
	}
}
int getpos(string s)
{
	int p=1;
	for(char c:s)
	{
		int x=c-'a';
		if(!ch[p][x]) return p;
		p=ch[p][x];
	}
	return p;
}
void dfs1(int u)
{
	hson[u]=-1,siz[u]=1;
	for(int v:ch[u]) if(v)
	{
		dfs1(v),siz[u]+=siz[v];
		if(hson[u]==-1||siz[hson[u]]<siz[v]) hson[u]=v;
	}
}
void dfs2(int u,int tp)
{
	dfn[u]=++dcnt,top[u]=tp;
	if(hson[u]==-1) return;
	dfs2(hson[u],tp);
	for(int v:ch[u]) if(v&&v!=hson[u]) dfs2(v,v);
}
vector<pii> jump(int p)
{
	vector<pii> res;
	while(p)
	{
		res.push_back({dfn[top[p]],dfn[p]});
		p=fa[top[p]];
	}
	return res;
}
struct BIT
{
	int t[N];
	inline void init(int n)
	{
		for(int i=0;i<=n;i++) t[i]=0;
	}
	inline void upd(int s,int x,int n)
	{
		for(;s<=n;s+=s&(-s)) t[s]+=x;
	}
	inline int qry(int s)
	{
		int r=0;
		for(;s;s-=s&(-s)) r+=t[s];
		return r;
	}
	inline int qry(int l,int r)
	{
		return qry(r)-qry(l-1);
	}
}tr;
vector<int> ps[M];
struct __q
{
	int l,r,op,id;
};
vector<__q> qs[M];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,lshcnt=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i],s[0][i]=" "+s[0][i]+" ",s[1][i]=" "+s[1][i]+" ";
//	for(int i=1;i<=n;i++)
//	{
//		if(s[0][i]==s[1][i])
//		{
//			cerr<<"i miss her\n";
//			cerr<<s[0][i]<<"\n";
//		}
//	}
	for(int i=1;i<=n;i++) if(s[0][i]!=s[1][i])
	{
		int l=1,r=(int)s[0][i].size()-2;
		while(s[0][i][l]==s[1][i][l]) l++;
		while(s[0][i][r]==s[1][i][r]) r--;
//		cout<<i<<" "<<l<<" "<<r<<"\n";
		ull val=0;
		for(int j=l;j<=r;j++)
		{
			val=val*base+s[0][i][j]+delta;
			val=val*base+s[1][i][j]+delta;
		}
		lsh[++lshcnt]=vals[i]=val;
//		cout<<val<<"\n";
		ql[i]=l,qr[i]=r;
	}
	sort(lsh+1,lsh+lshcnt+1),lshcnt=unique(lsh+1,lsh+lshcnt+1)-lsh-1;
	for(int i=1;i<=lshcnt;i++) mp[lsh[i]]=i;
	for(int i=1;i<=n;i++) vecs[mp[vals[i]]].push_back(i);
	for(int i=1;i<=q;i++) cin>>t[0][i]>>t[1][i],t[0][i]=" "+t[0][i]+" ",t[1][i]=" "+t[1][i]+" ";
	for(int i=1;i<=q;i++)
	{
		if(t[0][i].size()!=t[1][i].size()) continue;
		int l=1,r=(int)t[0][i].size()-2;
		while(t[0][i][l]==t[1][i][l]) l++;
		while(t[0][i][r]==t[1][i][r]) r--;
		ull val=0;
		for(int j=l;j<=r;j++)
		{
			val=val*base+t[0][i][j]+delta;
			val=val*base+t[1][i][j]+delta;
		}
		pl[i]=l,pr[i]=r;
		if(mp.count(val)) vect[mp[val]].push_back(i);
	}
	for(int k=1;k<=lshcnt;k++)
	{
//		cout<<"!!! solve "<<k<<"\n";
//		for(int x:vecs[k]) cout<<x<<" ";
//		cout<<"\n";
//		for(int x:vect[k]) cout<<x<<" ";
//		cout<<"\n";
		trie_clear();
		for(int x:vecs[k])
		{
			string str;
			for(int i=ql[x]-1;i>=1;i--) str.push_back(s[0][x][i]);
			insert(str);str.clear();
			for(int i=qr[x]+1;i<=(int)s[0][x].size()-2;i++) str.push_back(s[0][x][i]);
			insert(str);
		}
		dfs1(1),dfs2(1,1);
//		for(int u=1;u<=tot;u++)
//		{
//			cout<<u<<"("<<dfn[u]<<"):";
//			for(int v:ch[u]) cout<<v<<" ";
//			cout<<"\n";
//		}
		for(int x:vecs[k])
		{
			string str;
			for(int i=ql[x]-1;i>=1;i--) str.push_back(s[0][x][i]);
			int xx=dfn[getpos(str)];
			str.clear();
			for(int i=qr[x]+1;i<=(int)s[0][x].size()-2;i++) str.push_back(s[0][x][i]);
			int yy=dfn[getpos(str)];
//			cerr<<"p "<<x<<":"<<xx<<" "<<yy<<"\n";
			ps[xx].push_back(yy);
		}
		for(int x:vect[k])
		{
			string str;
			for(int i=pl[x]-1;i>=1;i--) str.push_back(t[0][x][i]);
			int p=getpos(str);
			auto rl=jump(p);
			str.clear();
			for(int i=pr[x]+1;i<=(int)t[0][x].size()-2;i++) str.push_back(t[0][x][i]);
			p=getpos(str);
			auto rr=jump(p);
//			cout<<"q "<<x<<":";
//			for(auto e:rl) cout<<"("<<e.first<<","<<e.second<<") ";
//			cout<<"->";
//			for(auto e:rr) cout<<"("<<e.first<<","<<e.second<<") ";
//			cout<<"\n";
			for(auto e:rl)
			{
				int x1=e.first,x2=e.second;
				for(auto e:rr)
				{
					int y1=e.first,y2=e.second;
					qs[x1-1].push_back({y1,y2,-1,x});
					qs[x2].push_back({y1,y2,1,x});
				}
			}
		}
		tr.init(tot);
		for(int x=1;x<=tot;x++)
		{
			for(int y:ps[x]) tr.upd(y,1,tot);
			for(auto e:qs[x])
			{
				int l=e.l,r=e.r,op=e.op,id=e.id;
				ans[id]+=op*tr.qry(l,r);
			}
		}
		for(int i=1;i<=tot;i++) ps[i].clear(),qs[i].clear();
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

// AVENGER_M & sanyueyetu
// zhu wo bu yao gua fen

// I MISS HER
