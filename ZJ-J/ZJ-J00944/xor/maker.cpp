#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define inf 1e18

using namespace std;

inline int read(){int x = 0 ; char c = getchar() ; bool w = 0 ;while(c < '0' || c > '9') {w |= (c == '-') ,c = getchar();} while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar();} return w ? -x : x;}
inline void write(int x) {if(x < 0) putchar('-') ,x = ~(x + 1) ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48);}
inline void writesp(int x){write(x) ,putchar(' ');}
inline void writeln(int x){write(x) ,putchar('\n');}

const int N = 5e5 + 10;
mt19937_64 rnd(time(NULL));
int n ,k;

namespace lolcrying {
	
	signed main(){
		int lim = 1048576;
		n = 5e4 ; k = rnd() % lim + 1 ;
		writesp(n) ,writeln(k);
		up(i ,1 ,n) {
			int x = rnd() % lim + 1;
			writesp(x - 1);
		}
		
		return 0;
	}	
} signed main(){
	
	freopen("xor.in" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}