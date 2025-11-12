#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<array>
#include<tuple>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<random>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define y0 yy0
#define y1 yy1
#define yn yyn
#define j0 jj0
#define j1 jj1
#define jn jjn
#define IOS ios::sync_with_stdio(false)
#define PY puts("Yes")
#define PN puts("No")
#define PW puts("-1")
#define P0 puts("0")
#define P__ puts("")
#define PU puts("--------------------")
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
#define reprange(a,b,c,d) for(int a=(b);a<=(c);a+=(d))
#define perrange(a,b,c,d) for(int a=(b);a>=(c);a-=(d))
#define graph(i,j,k,l) for(int i=k[j];i;i=l[i].nxt)
#define mp make_pair
#define pc putchar
#define fi first
#define se second
#define pb emplace_back
#define un using namespace
#define il inline
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof x)
#define lson(p) ((p)<<1)
#define rson(p) ((p)<<1|1)
#define lowbit(p) ((p)&-(p))
//#define double long double
//#define int long long
//#define int __int128
using namespace std;
un __gnu_pbds;
template<typename T1,typename T2>inline bool ckmx(T1 &x,T2 y){return x>=y?0:(x=y,1);}
template<typename T1,typename T2>inline bool ckmn(T1 &x,T2 y){return x<=y?0:(x=y,1);}
using i64=long long;
using u64=unsigned long long;
using pii=pair<int,int>;
using pss=pair<string,string>;
inline auto rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;
}
template<typename T>inline void write(T x,char ch='\n'){
	if(x<0)putchar('-'),x=-x;
	int y=0;static char z[50];
	while(x||!y)z[y++]=x%10+48,x/=10;
	while(y--)putchar(z[y]);if(ch)putchar(ch);
}
bool Mbg;
const i64 mod[2]={998358869,1000114537},base=31;
template<typename T1,typename T2>inline void adder(T1 &x,T2 y){x+=y,x=x>=mod?x-mod:x;}
template<typename T1,typename T2>inline void suber(T1 &x,T2 y){x-=y,x=x<0?x+mod:x;}
const int maxn=2e5+5,maxm=5e6+5,inf=0x3f3f3f3f;
const long long llinf=0x3f3f3f3f3f3f3f3f;
int n,Q,ans[maxn];
string s[maxn][2],t[maxn][2];
int ucnt;
map<array<i64,4>,int>uid;
vector<pss>vs[maxn];
vector<tuple<string,string,int>>vt[maxn];
struct Trie{
	int cnt,dfncnt;
	int nxt[maxm][26],dfn[maxn],lft[maxm],rht[maxm];
	int head[maxm],suf[maxn];
	void init(){
		rep(i,1,cnt)mem(nxt[i],0),head[i]=0;
		cnt=1,dfncnt=0;
	}
	il void ins(string str,int id){
		int p=1,len=str.size();
		rep(i,0,len-1){
			int q=str[i]-'a';
			if(!nxt[p][q])nxt[p][q]=++cnt;
			p=nxt[p][q];
		}
		suf[id]=head[p],head[p]=id;
	}
	int sta[maxm],tp;
	void dfs(){
		sta[1]=-1,sta[tp=2]=1;
		while(tp){
			const int p=sta[tp--];
			if(p<0){rht[-p]=dfncnt;continue;}
			lft[p]=dfncnt+1;
			if(head[p]){
				for(int i=head[p];i;i=suf[i])dfn[i]=++dfncnt;
			}
			per(i,25,0)if(nxt[p][i])sta[++tp]=-nxt[p][i],sta[++tp]=nxt[p][i];
		}
	}
	il int qry(string str){
		int p=1,len=str.size();
		rep(i,0,len-1)if(p)p=nxt[p][str[i]-'a'];
		return p;
	}
};
Trie pre,sec;
struct BIT{
	int len,c[maxn];
	void init(int _len){len=_len;rep(i,1,len)c[i]=0;}
	il void add(int x,int y){while(x<=len)c[x]+=y,x+=lowbit(x);}
	il void upd(int l,int r,int x){add(l,x),add(r+1,-x);}
	il int qry(int x){int res=0;while(x)res+=c[x],x-=lowbit(x);return res;}
} T;
vector<array<int,3>>vec[maxn];
vector<pii>qec[maxn];
inline void solve_the_problem(){
	cin>>n>>Q;
	rep(i,1,n)cin>>s[i][0]>>s[i][1];
	rep(i,1,Q)cin>>t[i][0]>>t[i][1];
	rep(i,1,n){
		int lcp=0,lcs=0;
		while(lcp<(int)s[i][0].size()&&s[i][0][lcp]==s[i][1][lcp])++lcp;
		while(lcs<(int)s[i][0].size()&&s[i][0][s[i][0].size()-1-lcs]==s[i][1][s[i][1].size()-1-lcs])++lcs;
		if(lcp==(int)s[i][0].size())continue;
		string s1=s[i][0].substr(0,lcp),s2=s[i][0].substr(s[i][0].size()-lcs,lcs);
		array<i64,4>hsh={0,0,0,0};
		rep(c,0,3)rep(j,lcp,(int)s[i][0].size()-1-lcs)hsh[c]=(hsh[c]*base+s[i][c>>1][j]-'a'+1)%mod[c&1];
		if(uid.find(hsh)==uid.end())uid[hsh]=++ucnt;
		reverse(all(s1)),vs[uid[hsh]].pb(s1,s2);
	}
	rep(i,1,Q)if(t[i][0].size()==t[i][1].size()){
		int lcp=0,lcs=0;
		while(lcp<(int)t[i][0].size()&&t[i][0][lcp]==t[i][1][lcp])++lcp;
		while(lcs<(int)t[i][0].size()&&t[i][0][t[i][0].size()-1-lcs]==t[i][1][t[i][1].size()-1-lcs])++lcs;
		if(lcp==(int)t[i][0].size())continue;
		string s1=t[i][0].substr(0,lcp),s2=t[i][0].substr(t[i][0].size()-lcs,lcs);
		array<i64,4>hsh={0,0,0,0};
		rep(c,0,3)rep(j,lcp,(int)t[i][0].size()-1-lcs)hsh[c]=(hsh[c]*base+t[i][c>>1][j]-'a'+1)%mod[c&1];
		if(uid.find(hsh)==uid.end())continue;
		reverse(all(s1)),vt[uid[hsh]].pb(s1,s2,i);
	}
	rep(d,1,ucnt)if(!vt[d].empty()){
		pre.init(),sec.init();
		for(auto i:vt[d]){
			pre.ins(get<0>(i),get<2>(i)),sec.ins(get<1>(i),get<2>(i));
		}
		pre.dfs(),sec.dfs();
		const int n1=pre.dfncnt,n2=sec.dfncnt;
		rep(i,1,n1)vec[i].clear(),qec[i].clear();
		for(auto i:vs[d]){
			int p1=pre.qry(i.fi),p2=sec.qry(i.se);
			if(!p1||!p2)continue;
			vec[pre.lft[p1]].push_back({sec.lft[p2],sec.rht[p2],1}),vec[pre.rht[p1]+1].push_back({sec.lft[p2],sec.rht[p2],-1});
		}
		for(auto i:vt[d]){
			const int id=get<2>(i);
			int p1=pre.dfn[id],p2=sec.dfn[id];
			qec[p1].pb(p2,id);
		}
		T.init(n2);
		rep(x,1,n1){
			for(auto i:vec[x]){
				int l=i[0],r=i[1],coef=i[2];
				T.upd(l,r,coef);
			}
			for(auto i:qec[x]){
				int y=i.fi,id=i.se;
				ans[id]=T.qry(y);
			}
		}
	}
	rep(i,1,Q)write(ans[i]);
}
bool Med;
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	fprintf(stderr,"%.3lfMB\n",(&Mbg-&Med)/1048576.0);
	int _=1;IOS;
	rep(__,1,_)solve_the_problem();
}
/*

*/

