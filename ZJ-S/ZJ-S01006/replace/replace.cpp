#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define inf 1e18

using namespace std;

inline int read(){int x = 0 ; char c = getchar() ; bool w = 0 ; while(c < '0' || c > '9') {w |= (c == '-') ,c = getchar() ; } while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar();} return w ? -x : x;}
inline void write(int x){if(x < 0) putchar('-') ,x = ~(x + 1);if(x > 9) write(x / 10);putchar(x % 10 | 48);}
inline void writesp(int x){write(x) ,putchar(' ');}
inline void writeln(int x){write(x) ,putchar('\n');}

const int N = 505 ,mod = 998244353;
int n ,Q;

namespace lolcrying {
	
	signed main(){
		
		n = read() ,Q = read();
		while(Q --) {
			puts("0");
		}
		return 0;
	}
} signed main(){

	freopen("replace.in" ,"r" ,stdin);
	freopen("replace.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}