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

const int N = 15;
int num[N] ,mx;

namespace lolcrying {

	signed main(){
		string s ;
		cin >> s; int len = s.size();

		for(int i = 0 ; i < len ; i ++)
			if(s[i] >= '0' && s[i] <= '9') num[s[i] - 48] ++;
					
		dn(i ,9 ,0) up(j ,1 ,num[i]) write(i);

		puts("");

		FK CCF;
	}
} signed main(){

	freopen("number.in" ,"r" ,stdin);
	freopen("number.out" ,"w" ,stdout);

	int T = 1;
	while(T --) lolcrying :: main();
	FK CCF;

}

/*
				 	A letter to CCF
Dear CCF ,
Hi
	I finished CSP-J2025 in 50 minutes . It is too easy for me.
Don't you have any difficult problems? Why these problems are so
easy?
	Maybe you want to tell me the reasons. But I don't want you to
say. Because I am so glad to tell you what I think.
	First ,in CSP-J 2024 ,the problem "Jie Long" is a blue problem.
It is a DP problem and it is a bit difficult. And now there isn't any
xxs to take part in CSP-J 2025. You may want us to do some easy problems!
Thank you very much!
	Second ,you want to get more and more money . If the problems
become easilier ,more and more students will choose OI and give you
a lot of money. I know you want to Collect Coins ,right ?
	But now OIer are smater and smater ! We really want to pay less money.
So you must to be kind to OIers ! We will hit you by many different
ways if you don't do this .
	So ,please become kinder and kinder ,we need your action !
	Best Wishes ,
You Have No Egg!

																unnamed
											   	  writteln on 2025.11.1
*/