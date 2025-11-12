#include<bits/stdc++.h>
#define eb emplace_back
#define SZ(s) ((int)s.size())
#define all(s) s.begin(),s.end()
#define gt getchar
#define pt putchar
#define fst first
#define scd second
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int N=2e6+5;
const int L=1e7+5;
const int base=131;
const int mod1=1e9+9;
const int mod2=998244853;
template<class T,class I> inline bool chkmax(T &a,I b){return a<b?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return a>b?a=b,1:0;}
inline bool __(char ch){return ch>=48&&ch<=57;}
template<class T> inline void read(T &x){
	x=0;char ch=gt();bool sgn=0;
	while(!__(ch)&&ch!=EOF) sgn|=(ch=='-'),ch=gt();
	while(__(ch)) x=(x<<1)+(x<<3)+(ch&15),ch=gt();
	if(sgn) x=-x;
}
template<class T,class ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
int n,q,ans[N];
string s[N][2];
char tmp[L];
inline pii operator*(const pii &a,const int &b){return pii(1ll*a.fst*b%mod1,1ll*a.scd*b%mod2);}
inline pii operator+(const pii &a,const int &b){return pii((a.fst+b)%mod1,(a.scd+b)%mod2);}
struct Node{
	pii x,y;
	int id;
	inline bool operator<(const Node &b)const{return x!=b.x?x<b.x:y<b.y;}
	inline bool operator==(const Node &b)const{return x==b.x&&y==b.y;}
}a[N];
int tot=1,ch[L][26],ed[N][2];
inline void ins(int id,int op){
	int p=1;
	for(char C:s[id][op]){
		int c=C-'a';
		if(!ch[p][c]) ch[p][c]=++tot;
		p=ch[p][c];
	}
	ed[id][op]=p;
}
int dfn_L[L],dfn_R[L],ti;
void dfs(int u){
	dfn_L[u]=++ti;
	for(int i=0;i<26;++i) if(ch[u][i]) dfs(ch[u][i]);
	dfn_R[u]=ti;
}
namespace BIT{
	int c[L],vis[L],tim;
	inline int lowbit(int x){return x&(-x);}
	inline void clear(){tim++;}
	inline void upd(int x,int w){x++;for(;x<=tot+1;x+=lowbit(x)){if(vis[x]!=tim) vis[x]=tim,c[x]=0;c[x]+=w;}}
	inline int query(int x){x++;int ans=0;for(;x;x-=lowbit(x)) ans+=(vis[x]==tim)*c[x];return ans;}
	inline int query(int l,int r){return query(r)-query(l-1);}
}
struct Obj{
	int a,b,c,id;
	inline bool operator<(const Obj &rhs)const{
		if(a!=rhs.a) return a>rhs.a;
		if(b!=rhs.b) return b>rhs.b;
		return id<rhs.id;
	}
}obj[N];
inline void solve(int l,int r){
	int tot=0;
	for(int i=l;i<=r;++i){
		int u=a[i].id;
		if(u<=n){
			obj[++tot]={dfn_R[ed[u][0]],dfn_R[ed[u][1]],1,u};
			obj[++tot]={dfn_R[ed[u][0]],dfn_L[ed[u][1]]-1,-1,u};
			obj[++tot]={dfn_L[ed[u][0]]-1,dfn_R[ed[u][1]],-1,u};
			obj[++tot]={dfn_L[ed[u][0]]-1,dfn_L[ed[u][1]]-1,1,u};
		}
		else obj[++tot]={dfn_L[ed[u][0]],dfn_L[ed[u][1]],1,u};
	}
	sort(obj+1,obj+tot+1);
	BIT::clear();
	for(int i=1;i<=tot;++i){
		if(obj[i].id<=n) BIT::upd(obj[i].b,obj[i].c);
		else ans[obj[i].id]+=BIT::query(obj[i].b,ti);
	}
}
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	file("replace");
	read(n,q);
	int qwq=0;
	for(int i=1;i<=n+q;++i){
		int m=0;
		for(int j=0;j<2;++j){
			scanf("%s",tmp+1);
			m=strlen(tmp+1);
			for(int k=1;k<=m;++k) s[i][j]+=tmp[k]; 
		}
		if(i>n&&SZ(s[i][0])!=SZ(s[i][1])){ans[i]=0;continue;}
		int l=0;
		for(int j=0;j<m;++j) if(s[i][0][j]!=s[i][1][j]){l=j;break;}
		int r=m;
		for(int j=m-1;~j;--j) if(s[i][0][j]!=s[i][1][j]){r=j;break;}
		pii A(0,0),B(0,0);
		for(int j=l;j<=r;++j) A=A*base+s[i][0][j],B=B*base+s[i][1][j];
		string ns="",nt="";
		for(int j=0;j<m;++j){
			if(j<l) ns+=s[i][0][j];
			if(j>r) nt+=s[i][0][j];
		}
		s[i][0]=ns,s[i][1]=nt,a[++qwq]={A,B,i};
		reverse(all(s[i][0]));
		ins(i,0),ins(i,1);
	}
	dfs(1);
	sort(a+1,a+qwq+1);
	for(int l=1;l<=qwq;++l){
		int r=l;
		while(r<qwq&&a[r+1]==a[l]) r++;
		solve(l,r),l=r;
	}
	for(int i=n+1;i<=n+q;++i) printf("%d\n",ans[i]);
	return 0;
}
