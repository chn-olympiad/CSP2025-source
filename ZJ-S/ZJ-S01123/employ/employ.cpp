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
const int mod=998244353;
const int maxn=500;
const int N=maxn+10;
int n, m, a[N], p[N], cnt[N]; char s[N];
//wmr

//incra

//lottle
signed main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s+1;
	L(i, 1, n) cin>>a[i];
	if (n<=10) {
		int ans=0;
		L(i, 1, n) p[i]=i;
		do {
			int cnt=0;
			L(i, 1, n) if (cnt>=a[p[i]]||s[i]=='0') ++cnt;
			ans+=n-cnt>=m;
		} while (next_permutation(p+1, p+n+1));
		printf("%d\n", ans);
		return 0;
	}
	bool flag=true;
	L(i, 1, n) flag&=(s[i]=='1'&&a[i]);
	if (flag) {
		int ans=1;
		L(i, 1, n) ans=(ll)ans*i%mod;
		printf("%d\n", ans);
		return 0;
	}
	puts("0");
	return 0;
}
