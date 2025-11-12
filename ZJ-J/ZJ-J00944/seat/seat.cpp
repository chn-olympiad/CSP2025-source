#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define inf 1e18
#define FK return
#define CCF 0;

using namespace std;

inline int read(){int x = 0 ; char c = getchar() ; bool w = 0 ;while(c < '0' || c > '9') {w |= (c == '-') ,c = getchar();} while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar();} return w ? -x : x;}
inline void write(int x) {if(x < 0) putchar('-') ,x = ~(x + 1) ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48);}
inline void writesp(int x){write(x) ,putchar(' ');}
inline void writeln(int x){write(x) ,putchar('\n');}

const int N = 105;
int n ,m ,a[N] ,sum ;

namespace lolcrying {
	
	signed main(){
		
		n = read() ,m = read();
		up(i ,1 ,n * m) {
			a[i] = read();
//			cout << a[i] << endl;
			sum += (a[i] > a[1]);
		}
		
		int r = 1 ,c = 1;
		
//		cout << sum << endl;
		
		up(k ,2 ,sum + 1) {
			if(c & 1) ++ r ;
			else -- r;
			if(r == n + 1) r = n ,++ c;
			if(r == 0) r = 1 ,++ c;
//			cout << r << ' ' << c << endl;
		}
		
		writesp(c) ,writeln(r);
		
		FK CCF;
	}	
} signed main(){
	
	freopen("seat.in" ,"r" ,stdin);
	freopen("seat.out" ,"w" ,stdout);
	
	int T = 1;
	while(T --) lolcrying :: main();
	FK CCF;
	
}

/*
要是下星期 CMJ 还不肯跟我讲话，CCF 你死全家。
我们可爱的 CCF，你怎么这么喜欢在 T2 放小模拟？
本来计算答案可以 O(1)，但是你这么执着于模拟，我就模拟好了。
QwQQaQ
*/