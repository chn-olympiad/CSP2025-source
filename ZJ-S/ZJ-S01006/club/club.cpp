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

const int N = 1e5 + 10;
int n ,cnt[4] ,club[4][N] ,a[N] ,b[N] ,c[N]; 

namespace lolcrying {
	
	
	signed main(){
		
		n = read();
		
		up(i ,1 ,3) cnt[i] = 0;
		
		int ans = 0 ;
		
		up(i ,1 ,n) {
			a[i] = read() ,b[i] = read() ,c[i] = read();
			int mx = max(a[i] ,max(b[i] ,c[i])) ,mn = min(a[i] ,min(b[i] ,c[i])) ,mid = ((a[i] ^ b[i] ^ c[i] ^ mx ^ mn));
		
			if(a[i] == mx) club[1][++ cnt[1]] = mx - mid ,ans += a[i];
			else if(b[i] == mx) club[2][++ cnt[2]] = mx - mid ,ans += b[i];
			else club[3][++ cnt[3]] = mx - mid ,ans += c[i];
		}
		
		int pos = 0 ,lim = (n >> 1);
		if(cnt[1] > lim) pos = 1;
		else if(cnt[2] > lim) pos = 2;
		else if(cnt[3] > lim) pos = 3;
		else pos = 0 ;
		 
		if(!pos) {
			writeln(ans);
			return 0 ;
		}
		
		sort(club[pos] + 1 ,club[pos] + cnt[pos] + 1);
		
		up(i ,1 ,cnt[pos] - lim) ans -= club[pos][i];
		
		writeln(ans);
		
		return 0;
	}
} signed main(){
	
	freopen("club.in" ,"r" ,stdin);
	freopen("club.out" ,"w" ,stdout);
	
	int T = read();
	while(T --) lolcrying :: main();
	return 0;
	
}