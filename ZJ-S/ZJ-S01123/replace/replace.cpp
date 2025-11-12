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
const int maxn=2e5;
const int N=maxn+10;
int n, qn; string s1[N], s2[N];
map <pair <string, string>, vector <pii> > f;
//wmr

//incra

//lottle
signed main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>qn;
	L(i, 1, n) {
		cin>>s1[i]>>s2[i];
		int len=sz(s1[i]);
		L(j, 0, len-1) if (s1[i][j]!=s2[i][j]) {
			int ma=j;
			L(k, j+1, len-1) if (s1[i][k]!=s2[i][k]) ma=k;
			string g1, g2;
			L(k, j, ma) g1+=s1[i][k], g2+=s2[i][k];
			f[mp(g1, g2)].eb(mp(i, j));
			break;
		}
	}
	while (qn--) {
		string t1, t2;
		cin>>t1>>t2;
		int len=sz(t1), cnt=0;
		L(i, 0, len-1) if (t1[i]!=t2[i]) {
			int ma=i;
			L(j, i+1, len-1) if (t1[j]!=t2[j]) ma=j;
			string g1, g2;
			L(j, i, ma) g1+=t1[j], g2+=t2[j];
			for (pii t: f[mp(g1, g2)]) {
				int id=t.fst, pos=t.scd;
				if (pos>i||i+sz(s1[id])-pos-1>=len) continue;
				bool flag=true;
				L(k, 0, sz(s1[id])-1) if (t1[i-pos+k]==t2[i-pos+k]&&t1[i-pos+k]!=s1[id][k]) { flag=false; break; }
				cnt+=flag;
			}
			break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}