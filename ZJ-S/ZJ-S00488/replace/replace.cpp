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
inline string getstr(){string str="";char ch=getchar();while(ch<=32||ch>127)ch=getchar();while(ch>32&&ch<=127)str+=ch,ch=getchar();return str;}
inline void putstr(string str){u(i,0,str.length())putchar(str[i]);putchar('\n');}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void fre(){freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);}
string s1[200005],s2[200005],st[200005],sl[200005],sr[200005],sz[200005];
signed main(){
	fre();
	int n=read(),T=read();
	up(i,1,n)s1[i]=getstr(),s2[i]=getstr();
	up(i,1,n){
		int l=0,r=0;
		u(j,0,s1[i].length())if(s1[i][j]!=s2[i][j]){l=j;break;}
		dn(j,s1[i].length()-1,0)if(s1[i][j]!=s2[i][j]){r=j;break;}
		u(j,0,l)sl[i]+=s1[i][j];u(j,r+1,s1[i].length())sr[i]+=s1[i][j];
		up(j,l,r)st[i]+=s1[i][j],sz[i]+=s2[i][j];
	}while(T--){
		string t1=getstr(),t2=getstr(),tt="",tl="",tr="",tz="";int l=0,r=0,ans=0;
		u(i,0,t1.length())if(t1[i]!=t2[i]){l=i;break;}
		dn(i,t1.length()-1,0)if(t1[i]!=t2[i]){r=i;break;}
		u(i,0,l)tl+=t1[i];u(i,r+1,t1.length())tr+=t1[i];
		up(i,l,r)tt+=t1[i],tz+=t2[i];
		up(i,1,n)if(tt==st[i]&&tz==sz[i]){
			int nl=sl[i].length(),nr=sr[i].length(),fl=1;
			if(tl.length()<nl||tr.length()<nr)continue;
			u(j,tl.length()-nl,tl.length())if(sl[i][j-(tl.length()-nl)]!=tl[j]){fl=0;continue;}
			u(j,0,nr)if(sr[i][j]!=tr[j]){fl=0;continue;}ans+=fl;
		}writeln(ans);
	}I LOVE FURINA
}
