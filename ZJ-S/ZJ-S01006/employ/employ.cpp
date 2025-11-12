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
int n ,m ,dif[N] ,fact[N] ,c[N] ,p[N] ,ans;
bool vis[N];

namespace lolcrying {
	
	inline bool check(){
		int now = 0 ,sum = 0;
		up(i ,1 ,n) {
			if(now >= c[p[i]]) {++ now ; continue;}
			else if(!dif[i]) sum ++;
			else now ++;
		} return sum >= m;
	} inline void dfs(int x){
		if(x == n + 1){
			ans += check();
			return ;
		} up(i ,1 ,n) {
			if(!vis[i]) {
				vis[i] = 1 ; p[x] = i ;
				dfs(x + 1);
				vis[i] = 0;
			}
		}
	} signed main(){
		
		n = read() ,m = read();
		
		bool fl = 1;
		up(i ,1 ,n) {
			char x ; cin >> x; 
			dif[i] = (x == '0' ? 1 : 0);
			fl &= (dif[i] == 0);
		}
		
		up(i ,1 ,n) c[i] = read();
		
		if(n <= 10) {
			dfs(1);
			writeln(ans % mod);
			return 0;
		}
		
		if(fl){
			fact[0] = 1;
			up(i ,1 ,n) fact[i] = fact[i - 1] * i % mod;
			int total = 0 ;
			up(i ,1 ,n) total += c[i] == 0;
			if(total > n - m) puts("0");
			else writeln(fact[n - total] * fact[total] % mod);
			return 0 ;
		}
		
//		if(m == n) {
//		
//		}
		return 0;
	}
} signed main(){

	freopen("employ.in" ,"r" ,stdin);
	freopen("employ.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}