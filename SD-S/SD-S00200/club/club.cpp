#include <bits/stdc++.h>
using namespace std;
#define getc getchar
inline long long read(){
	char c = getc() , f = 1;
	while (c > '9' || c < '0'){
		if (c == '-')f = -1;
		c = getc();
	}
	long long p = 0;
	while (c >= '0' && c <= '9'){
		p = p * 10 + c - '0';
		c = getc();
	}
	return p * f;
}
struct node{int a , b , c;}a[100005];
vector <node> x , y , z;
int n;
long long ans;
signed main(){
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	int ___ = read();
	while (___--){
		n = read();
		ans = 0;
		x.clear();
		y.clear();
		z.clear();
		for (int i = 1;i <= n;++i){
			a[i].a = read();
			a[i].b = read();
			a[i].c = read();
			if (a[i].a >= a[i].b && a[i].a >= a[i].c){
				x.push_back(a[i]);
				ans += a[i].a;
			}else if (a[i].b >= a[i].a && a[i].b >= a[i].c){
				y.push_back(a[i]);
				ans += a[i].b;
			}else if (a[i].c >= a[i].a && a[i].c >= a[i].b){
				z.push_back(a[i]);
				ans += a[i].c;
			}
		}
		//printf ("	%d %d %d\n" , x.size() , y.size() , z.size());
		//printf ("	%lld\n" , ans);
		if ((int)x.size() > n / 2){
			sort (x.begin() , x.end() , [](const node &a , const node &b){return a.a - max(a.b , a.c) < b.a - max(b.b , b.c);});
			reverse (x.begin() , x.end());
			while ((int)x.size() > n / 2){
				node a = x.back();
				x.pop_back();
				ans -= a.a;
				ans += max(a.b , a.c);
			}
		}else if ((int)y.size() > n / 2){
			sort (y.begin() , y.end() , [](const node &a , const node &b){return a.b - max(a.a , a.c) < b.b - max(b.a , b.c);});
			reverse (y.begin() , y.end());
			while ((int)y.size() > n / 2){
				node a = y.back();
				y.pop_back();
				ans -= a.b;
				ans += max(a.a , a.c);
			}
		}else if ((int)z.size() > n / 2){
			sort (z.begin() , z.end() , [](const node &a , const node &b){return a.c - max(a.a , a.b) < b.c - max(b.a , b.b);});
			reverse (z.begin() , z.end());
			while ((int)z.size() > n / 2){
				node a = z.back();
				z.pop_back();
				ans -= a.c;
				ans += max(a.a , a.b);
			}
		}
		printf ("%lld\n" , ans);
	}
	return 0;
}
