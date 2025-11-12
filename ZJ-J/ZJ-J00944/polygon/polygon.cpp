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

const int N = 5005 ,mod = 998244353;
int n ,a[N] ,sum ,f[N];

namespace lolcrying {
	
	inline int qpow(int a ,int b){
		int res = 1;
		for( ; b ; a = a * a % mod ,b >>= 1) if(b & 1) res = res * a % mod;
		return res;	
	} signed main(){
		
		n = read();
		up(i ,1 ,n) a[i] = read();
		
		sort(a + 1 ,a + 1 + n);
		
		f[0] = 1;
		
		up(i ,1 ,n) {
			int total = 0 ;
			
			if(i >= 3) {
				total = (qpow(2 ,i - 1) - 1 + mod) % mod;
				up(j ,1 ,a[i]) total -= f[j] ,total = (total + mod) % mod;

			}
			dn(j ,5000 ,a[i])
				f[j] += f[j - a[i]] ,f[j] %= mod;
	
			sum += total ,sum %= mod;

		}
		
		writeln(sum);
		
		return 0;
	}	
} signed main(){
	
	freopen("polygon.in" ,"r" ,stdin);
	freopen("polygon.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}

/*
Is DP good?
Why do you like DP so much ?
Can't you give any better problems ?
What a water T4 !!!!!!!!!!
*/