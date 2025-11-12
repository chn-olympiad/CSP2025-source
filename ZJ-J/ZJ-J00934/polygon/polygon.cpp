// T4 polygon
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
const int N=5005;
const int P=998244353;
int n,x,num,cnt;
int a[N];

signed main(){
#ifdef IO
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
#endif
	n=rd();
	rep(i,1,n) a[i]=rd(),num+=a[i];
	sort(a+1,a+n+1,greater<int>());
	
//	rep(i,1,n) echo(a[i],' ');
//	puts("");
	if(num<=a[1]*2){puts("0");return 0;}
	
//	rep(i,1,n-2){
//		int op=n,x=a[op];
//		while(x<=a[i]) x+=a[--op];
//		echo(op,' '),echo(a[op],'\n');
//		cnt+=((op-i+1)*(op-i)>>1)*((n-op+1)*(n-op)>>1);
////		puts("");
//	}
	rep(i,1,n-2){
		int op=i+2;
		while(a[i+1]+a[op]>a[i]) ++op;--op;

//		echo(op,' '),echo(a[op],'\n');
		
		cnt+=((op-i+1)*(op-i)>>1)*((n-op+1)*(n-op)>>1);
		cnt%=P;
		
//		echo(cnt,'\n');
	}
	echo(cnt%P,'\n');
#ifdef IO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}


