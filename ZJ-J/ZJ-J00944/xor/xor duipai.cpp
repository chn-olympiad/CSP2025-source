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
int n ,k ,a[N] ,pre[N] ,f[N];

namespace lolcrying {
	
	signed main(){
		
		n = read() ,k =read();
		
		up(i ,1 ,n) a[i] = read() ,pre[i] = (pre[i - 1] ^ a[i]);
		
		up(i ,1 ,n) {
			f[i] = f[i - 1];
			
			up(j ,1 ,i) {
				if((pre[i] ^ k) == pre[j - 1]) f[i] = max(f[i] ,f[j - 1] + 1);
			}
		}
		
		int ans = 0 ;
		up(i ,1 ,n) ans = max(ans, f[i]);
		
		writeln(ans);
		
		
		return 0;
	}	
} signed main(){
	
	freopen("xor.in" ,"r" ,stdin);
	freopen("xor_correct_ans.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}