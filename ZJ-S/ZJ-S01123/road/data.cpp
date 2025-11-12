#include <bits/stdc++.h>
#define fst first
#define scd second
#define db double
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector <int>
#define pii pair <int, int>
#define sz(x) ((int)x.size())
#define ms(f, x) memset(f, x, sizeof(f))
#define L(i, j, k) for (int i=(j); i<=(k); ++i)
#define R(i, j, k) for (int i=(j); i>=(k); --i)
#define ACN(i, H_u) for (int i=H[u]; i; i=E[i].nxt)
using namespace std;
//char buf[1<<20], *p1=buf, *p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2)?EOF:*p1++)
template <typename INT> void rd(INT &res) {
	res=0; bool f=false; char ch=getchar();
	while (ch<'0'||ch>'9') f|=ch=='-', ch=getchar();
	while (ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48), ch=getchar();
	res=(f?-res:res);
}
template <typename INT, typename...Args>
void rd(INT &x, Args &...y) { rd(x), rd(y...); }
//dfs
mt19937 rnd(time(0));
//wmr
int random(int l, int r) { return rnd()%(r-l+1)+l; }
//incra

//lottle
signed main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen(".in", "r", stdin);
	freopen("road.in", "w", stdout);
	int n=1e4, m=1e6, k=10;
	printf("%d %d %d\n", n, m, k);
	L(i, 1, n-1) printf("%d %d %d\n", i, i+1, random(1, 1e9));
	L(i, n, m) printf("%d %d %d\n", random(1, n), random(1, n), random(1, 1e9));
	L(i, 1, k) {
		L(j, 1, n+1) printf("%d ", random(1, 1e9));
		puts("");
	}
	return 0;
}