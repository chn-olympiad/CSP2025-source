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
#define AK 0
#define CSP ;
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
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
inline void fre(){freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);}
int a[5005],n,ans,f[5005];const int mod=998244353;
inline int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%mod;
		a=(a*a)%mod,b>>=1;
	}return ans;
}inline void dfs(int stp){
	if(stp>n){
		int sum=0,maxn=0;
		up(i,1,n)if(f[i])sum+=a[i],maxn=max(maxn,a[i]);
		if(sum>(maxn<<1))++ans;
		return ;
	}f[stp]=1,dfs(stp+1),f[stp]=0,dfs(stp+1);
}signed main(){
	fre();
	n=read();
	up(i,1,n)a[i]=read();
	if(n>20)writeln((qpow(2,n)-(n*(n-1)/2+n+1)+mod)%mod);
	else dfs(1),writeln(ans);
	I AK CSP
}
