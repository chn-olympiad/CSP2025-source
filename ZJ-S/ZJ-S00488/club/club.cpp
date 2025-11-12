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
inline void fre(){freopen("club.in","r",stdin),freopen("club.out","w",stdout);}
int n,fl[100005],cnt[3],ans;
struct node{int id,cl,val;const bool operator < (const node &b)const{return val<b.val;}};
inline void solve(){
	n=read(),ans=0;
	up(i,1,n)fl[i]=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	priority_queue<node>que;
	up(i,1,n){int x1=read(),x2=read(),x3=read();que.push({i,0,x1}),que.push({i,1,x2}),que.push({i,2,x3});}
	while(que.size()){
		int id=que.top().id,cl=que.top().cl,val=que.top().val;que.pop();
		if(fl[id])continue;if(cnt[cl]>=n/2)continue;
		ans+=val,fl[id]=1,++cnt[cl];
	}writeln(ans);
}signed main(){
	fre();
	int T=read();
	while(T--)solve();	
	I LOVE FURINA
}
