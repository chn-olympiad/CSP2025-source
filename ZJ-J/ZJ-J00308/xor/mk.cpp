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
const int N=(1<<20)+9,M=5e5+6;
namespace dino{
	mt19937 rnd(time(0));
	inline void zyt(){
		int n=8899;
		ww(n);wln(rnd()%201);
		for(ri i=1;i<=n;++i){
			ww(rnd()%300);
		}
	}
}
signed main(){
	dino::zyt();
}
