#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug puts("Furina YYDS")
#define inf 0x3f3f3f3f
#define infi 0x3f3f3f3f3f3f3f3fll
#define up(i,x,y) for(register int i=x;i<=y;++i)
#define u(i,x,y) for(register int i=x;i<y;++i)
#define dn(i,x,y) for(register int i=x;i>=y;--i)
#define d(i,x,y) for(register int i=x;i>y;--i)
#define I return
#define LOVE 0
#define FURINA ;
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10|48);}
inline void writesp(int x){write(x),putchar(' ');}
inline void writeln(int x){write(x),putchar('\n');}
inline char getone(){char ch=getchar();while(ch<=32||ch>127)ch=getchar();return ch;}
inline string getstr(){string str="";char ch=getchar();while(ch<32||ch>127)ch=getchar();while(ch>=32&&ch<=127)str+=ch,ch=getchar();return str;}
inline void putstr(string str){u(i,0,str.length())putchar(str[i]);putchar('\n');}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void fre(){freopen("road.in","r",stdin),freopen("road.out","w",stdout);}
int n,m,k,fa[10025],cnt,ans;struct node{int u,v,w;}ed[2000005];
inline int find(int n){return n==fa[n]?n:fa[n]=find(fa[n]);}
inline bool cmp(node a,node b){return a.w<b.w;}
signed main(){
	fre();
	n=read(),m=read(),k=read();
	up(i,1,m){int u=read(),v=read(),w=read();ed[++cnt]={u,v,w};}
	up(i,1,n+k)fa[i]=i;up(i,1,k){ans+=read();up(j,1,n){int x=read();ed[++cnt]={j,n+i,x};}}
	sort(ed+1,ed+cnt+1,cmp);
	up(i,1,cnt)if(find(ed[i].u)!=find(ed[i].v))ans+=ed[i].w,fa[find(ed[i].u)]=find(ed[i].v);
	writeln(ans);
	I LOVE FURINA
}
