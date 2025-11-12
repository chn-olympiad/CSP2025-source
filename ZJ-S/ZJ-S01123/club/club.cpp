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
const int maxn=1e5;
const int N=maxn+10;
int n, cnt[3], b[N], a[N][3], id[N][3];
//wmr

//incra

//lottle
signed main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; rd(T);
	while (T--) {
		rd(n); int sum=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		L(i, 1, n) {
			rd(a[i][0], a[i][1], a[i][2]);
			id[i][0]=0, id[i][1]=1, id[i][2]=2;
			sort(id[i], id[i]+3, [&](int x, int y) { return a[i][x]<a[i][y]; });
			sum+=a[i][id[i][2]]; ++cnt[id[i][2]];
		}
		int m=n>>1;
		if (cnt[0]<=m&&cnt[1]<=m&&cnt[2]<=m) printf("%d\n", sum);
		else {
			auto check=[&](int c) {
				int tot=0;
				L(i, 1, n) if (id[i][2]==c) b[++tot]=max(a[i][id[i][0]], a[i][id[i][1]])-a[i][id[i][2]];
				sort(b+1, b+tot+1);
				L(i, m+1, tot) sum+=b[i];
			};
			if (cnt[0]>m) check(0);
			else if (cnt[1]>m) check(1);
			else check(2);
			printf("%d\n", sum);
		}
	}
	return 0;
}
