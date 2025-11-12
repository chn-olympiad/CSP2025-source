// T2 seat
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define int long long
#define gc getchar
#define pc putchar
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define IO
using namespace std;
namespace Fast{
	inline int rd(){
		int n(0),f(1);char c=gc();
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=gc();
		}
		while(c>='0'&&c<='9'){
			n=(n<<1)+(n<<3)+(c^48);
			c=gc();
		}
		return n*f;
	}
	inline void print(int n){
		if(n<0)pc('-');
		if(n>9) print(n/10);
		pc(n%10^48);
		return;
	}
	inline void echo(int n,char c){
		print(n),pc(c);
		return;
	}
}using namespace Fast;
int n,m,x,cnt;
int a[105];
int s[15][15];
signed main(){
#ifdef IO
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
#endif
	n=rd(),m=rd();
	rep(i,1,n*m) a[i]=rd();
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
//	rep(i,1,n*m) echo(a[i],' ');
//	puts("");
	rep(i,1,m)
		if(i&1) rep(j,1,n) s[j][i]=a[++cnt];
		else pre(j,n,1) s[j][i]=a[++cnt];
//	rep(i,1,n)
//		rep(j,1,m)
//			echo(s[i][j]," \n"[j==m]);
//	puts("");
	rep(i,1,n)
		rep(j,1,m)
			if(s[i][j]==x) echo(j,' '),echo(i,'\n');
#ifdef IO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}


