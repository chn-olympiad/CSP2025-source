/*
Thanks to you ,CCF.
是你，出了这么难的 T2，让我拼尽全力无法战胜。
是你，让我大概率 AFO 了。
是你，这么恶心。
我都感觉我没机会弄懂这道恶心的题的正解了。
是你，让我留下了当下第二大的遗憾。
I will never forget you ,CCF.
/ll
我们之间也算平了，我给你将近 1k money，你给我一个 S 2025 3= / 2=。
Thanks to you ,让我看到了我是真的
蒟蒻
纸张
彩笔
J 再好又有什么用呢？S 仍是一塌糊涂。

*/

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

const int N = 1e6 + 10 ,M = 4e6 + 10;
int n ,m ,k ,fa[N] ,ans ,a[15][N] ,c[N];
bool cle[15];

namespace lolcrying {
	
	
	struct node {int u ,v ,w;} e[M];
	inline bool cmp(node x ,node y){return x.w < y.w;}
	inline int find(int u){return u == fa[u] ? u : fa[u] = find(fa[u]);}

	signed main(){
		
		n = read() ,m = read() ,k = read();
		
		up(i ,1 ,m){
			int u = read() ,v = read() ,w = read();
			e[i].u = u ,e[i].v = v ,e[i].w = w;
		} int E = n - 1;
		sort(e + 1 ,e + 1 + m ,cmp);
		up(i ,1 ,n) fa[i] = i;
		up(i ,1 ,m) {
			if(!E) break;
			int u = e[i].u ,v = e[i].v ,fau = find(u) ,fav = find(v) ,w = e[i].w;
			if(fau == fav) continue;
			fa[fau] = fav;
			-- E;
			ans += w;
		}
		
		if(k == 0) {
			writeln(ans);
			return 0 ;
		}

		up(i ,1 ,k){
			c[i] = read();
			up(j ,1 ,n) a[i][j] = read();
		}

//up(i ,1 ,k) {
//up(j ,1 ,n) {
//e[++ m] = {i + n ,j ,a[i][j]};
//}
//}
//
//int s = n + k + 1;
//up(i ,1 ,k) e[++ m] = {s ,i ,c[i]};
//
//n = n + k + 1;
//
//int res = 0 ;
//
//sort(e + 1 ,e + 1 + m ,cmp);
//
//E = n - 1;
//up(i ,1 ,n) fa[i] = i;
//up(i ,1 ,m) {
//if(!E) break;
//int u = e[i].u ,v = e[i].v ,fau = find(u) ,fav = find(v) ,w = e[i].w;
//if(fau == fav) continue;
//fa[fau] = fav;
//-- E;
//res += w;
//}
		
		writeln(ans);
				
		return 0;
	}
} signed main(){

	freopen("road.in" ,"r" ,stdin);
	freopen("road.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	return 0;
	
}