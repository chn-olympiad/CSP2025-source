#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
namespace io{
	inline int r(){
		char chr=getchar();
		int a=1,b=0;
		while(chr>'9'||chr<'0'){if(chr=='-')a=-1;chr=getchar();}
		while(chr<='9'&&chr>='0'){b=(b<<1)+(b<<3)+(chr^48);chr=getchar();}
		return a*b;
	}
	inline void wr(int x){
		if(x==0)return;
		if(x<0){putchar('-');x=-x;}
		wr(x/10);
		putchar((x%10)^48);
	}
	inline char gc(){char C=getchar();while(C<=' ')C=getchar();return C;}
	inline string gs(){
		string S="";char chr=getchar();
		while(chr<=' ')chr=getchar();
		while(chr>' '){S+=chr;chr=getchar();}
		return S;
	}
	inline void ww(int a){if(a==0)putchar('0');else wr(a);putchar(' ');}
	inline void wln(int a){if(a==0)putchar('0');else wr(a);putchar('\n');}
	inline void w(int a){if(a==0)putchar('0');else wr(a);}
}
using namespace io;
const int N=1e4+9;
namespace dino{
	int m,n,a[N];
	inline void zyt(){
		n=r(),m=r();
		for(ri i=1;i<=n*m;++i)a[i]=r();
		int cnt=0;
		for(ri i=1;i<=n*m;++i)if(a[i]>=a[1])++cnt;
		int a=cnt/n+(cnt%n!=0);
		int b=cnt%n;if(b==0)b=n;
		if(a%2==0)b=n+1-b;
		ww(a);wln(b);
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	dino::zyt();
}
