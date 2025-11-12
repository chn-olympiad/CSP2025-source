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
inline void fre(){freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);}
int a[500005],dp[500005];
signed main(){
	fre();
	int n=read(),k=read(),ans=0;
	up(i,1,n)a[i]=a[i-1]^read();
	dn(i,n,1){dp[i]=dp[i+1];up(j,i,n)if((a[j]^a[i-1])==k)dp[i]=max(dp[i],dp[j+1]+1);}
	writeln(dp[1]);
	I AK CSP
}
//int a[500005],dp[500005][25],lst[500005][25],zor[500005][25];
//signed main(){
//	fre();
//	int n=read(),k=read(),t0=0,t1=0;
//	up(i,1,n)a[i]=a[i-1]^read();
//	up(i,1,n)zor[i][0]=((a[i]^a[i-1])&1?t1:t0),(a[i]^a[i-1])&1?t1=i:t0=i;
//	up(i,1,n)lst[i][0]=(((a[i]^a[i-1])&1)==(k&1)?t0:t1),(a[i]^a[i-1])&1?t1=i:t0=i;
//	up(i,1,n){dp[i][0]=dp[i-1][0];if(lst[i][0])dp[i][0]=max(dp[i][0],dp[lst[i][0]-1][0]+1);}
//	up(j,1,20)up(i,1,n){
//		zor[i][j]=zor[i][j-1];
//		while(zor[i][j]){
//			if(!((a[zor[i][j]]^a[i-1])&((1<<j+1)-1)))break;
//			zor[i][j]=zor[zor[i][j]-1][j-1];
//		}lst[i][j]=lst[i][j-1];
//		while(lst[i][j]){
//			if(((a[lst[i][j]]^a[i-1])&((1<<j+1)-1))==(k&((1<<j+1)-1)))break;
//			lst[i][j]=zor[lst[i][j]-1][j-1];
//		}dp[i][j]=dp[i-1][j];if(lst[i][j])dp[i][j]=max(dp[i][j],dp[lst[i][j]-1][j]+1);
//	}writeln(dp[n][20]);
//	I AK CSP
//}
