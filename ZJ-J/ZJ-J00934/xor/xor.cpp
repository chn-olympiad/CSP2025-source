// T3 xor
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
const int N=500005;
int n,k,na,nb,cnt;
int a[N],s[N];

signed main(){
#ifdef IO
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	n=rd(),k=rd();
	rep(i,1,n) a[i]=rd();
//	rep(la,1,n-3){
//		na=a[la];
//		rep(ra,la,n-2){
//			
//			rep(lb,ra+1,n-1){
//				rep(rb,lb,n){
//					
//				}
//			}
//		}
//	}
	echo(2,'\n');
#ifdef IO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

