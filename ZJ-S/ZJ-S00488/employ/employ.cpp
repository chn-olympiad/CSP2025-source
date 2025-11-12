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
inline void fre(){freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);}
int c[505],t[505],n,m,ans;string str;
inline void dfs(int stp,int x){
	if(stp>n){ans+=(n-x>=m);return ;}
	up(i,0,x)if(t[i])--t[i],dfs(stp+1,x+1),++t[i];
	up(i,x+1,n)if(t[i])--t[i],dfs(stp+1,x+(str[stp-1]=='0')),++t[i];
}signed main(){
	fre();
	n=read(),m=read(),str=getstr();
	up(i,1,n)c[i]=read(),++t[c[i]];
	dfs(1,0),writeln(ans);
	I LOVE FURINA
}
