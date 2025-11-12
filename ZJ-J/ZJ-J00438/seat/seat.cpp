#include<bits/stdc++.h>
//#define int long long
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
inline void fre(){freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);}
int a[105];
inline void getans(int n,int m,int rk){
	int x=1,y=1;
	while(rk){
		if(x==1&&(y&1^1))++y;
		else if(x==n&&y&1)++y;
		else if(y&1)++x;
		else --x;
		--rk;
	}writesp(y),writeln(x);
}signed main(){
	fre();
	int n=read(),m=read();
	up(i,1,n*m)a[i]=read();
	int t=a[1];sort(a+1,a+n*m+1);
	int rk=n*m-(lower_bound(a+1,a+n*m+1,t)-a);
	getans(n,m,rk);
	I AK CSP
}
