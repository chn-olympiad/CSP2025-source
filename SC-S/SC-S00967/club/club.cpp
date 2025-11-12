#include <bits/stdc++.h>
using namespace std;
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return f * x;
} 
inline void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 2e5 + 10;
int t, n;
struct node{
	int a, b, c;
	int get(int x) {
		if(x == 1) return a;
		if(x == 2) return b;
		if(x == 3) return c;
		return 0;
	}
}s[N];
bool cmp(node a, node b) {
	int av = max(min(a.a - a.b, a.a - a.c), max(min(a.b - a.a, a.b - a.c), min(a.c - a.a, a.c - a.b)));
	int bv = max(min(b.a - b.b, b.a - b.c), max(min(b.b - b.a, b.b - b.c), min(b.c - b.a, b.c - b.b)));
	return av > bv;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	t = read(); 
	while(t--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			s[i].a = read();
			s[i].b = read();
			s[i].c = read();
		}
		sort(s + 1, s + n + 1, cmp);
		int cnt[4] = {0, 0, 0, 0}, ans = 0;
		for(int i = 1; i <= n; i++) {
			int typ = 0, typ2 = 0, typ3 = 0;
			if(s[i].a >= s[i].b && s[i].a >= s[i].c){
				typ = 1;
				if(s[i].b >= s[i].c) typ2 = 2, typ3 = 3;
				else typ2 = 3, typ3 = 2;
			}
			else if(s[i].b >= s[i].a && s[i].b >= s[i].c){
				typ = 2;
				if(s[i].a >= s[i].c) typ2 = 1, typ3 = 3;
				else typ2 = 3, typ3 = 1;
			}
			else{
				typ = 3;
				if(s[i].a >= s[i].b) typ2 = 1, typ3 = 2;
				else typ2 = 2, typ3 = 1;
			}
			if(cnt[typ] < n / 2) {
				cnt[typ]++;
				ans += s[i].get(typ);
			} else if(cnt[typ2] < n / 2) {
				cnt[typ2]++;
				ans += s[i].get(typ2);
			} else {
				cnt[typ3]++;
				ans += s[i].get(typ3);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
