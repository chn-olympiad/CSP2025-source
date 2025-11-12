#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>
#define rd read()
#define x first
#define y second
#define y1 Y1
#define y0 Y0
//char buf[(1<<21)+10],obuf[(1<<21)+10],*p1=buf,*p2=buf,*O=obuf;int ol=(1<<21);
//#define getchar() (((p1==p2)&&(p2=((p1=buf)+fread(buf,1,ol,stdin)),p1==p2))?EOF:*p1++)
//#define flush() (fwrite(obuf,1,O-obuf,stdout),O=obuf)
//#define putchar(x) (((O-obuf==ol)&&(flush(),O-obuf==ol))?:*O++=x)
inline int read(int u=0,char c=getchar(),bool f=false){
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}
inline void read(string &s,char c=getchar()){
	for(;c<'0'||c>'1';c=getchar());s.clear();
	for(;c>='0'&&c<='1';c=getchar()) s+=c;
}
inline void wt(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}
inline void wt(int x,char c){wt(x);putchar(c);}
const int N=510,mod=998244353;
int n,m,c[N],p[N],subA=1;
string s;
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd,m=rd;read(s);int ans=0;s=" "+s;
	for(int i=1;i<=n;i++) c[i]=rd,p[i]=i,subA=min(subA,(int)(s[i]-'0'));
	do{
		int sum=0;
		for(int i=1;i<=n;i++) if(sum>=c[p[i]]||s[i]=='0') sum++;
		ans+=(n-sum>=m);
	}while(next_permutation(p+1,p+n+1));
	wt(ans,'\n');
	return /*flush(),*/0;
}
/*
3 2
101
1 1 2
*/
