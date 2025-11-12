//Fight until the end like I promised to
#include<bits/stdc++.h>
#define AK 0
#define int long long
#define D(x) cout<<#x<<": "<<x<<'\n'
#define De(x) cout<<#x<<": "<<x<<' '
#define ctn continue
#define brk break
#define space putchar(' ')
#define enter putchar('\n')
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
inline int read(){
	bool f = 0;
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = 1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();}
	return f ? -x : x;
}
const int N = 2e5 + 7, mod = 1e9 + 7;
int n;
int s[4];
int a[N][4], c[N];
bool is[N][4];
vector<int> zb;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &n);
		s[1] = s[2] = s[3] = 0;
		int ans = 0;
		memset(is, 0, sizeof(is));
		up(1, n, i){
			up(1, 3, j) a[i][j] = read();
			int mx = max(a[i][1], max(a[i][2], a[i][3]));
			if(a[i][1] == mx){
				is[i][1] = 1;
				s[1]++;
				c[i] = max(a[i][2], a[i][3]);
			}
			else if(a[i][2] == mx){
				is[i][2] = 1;
				s[2]++;
				c[i] = max(a[i][1], a[i][3]);
			}
			else if(a[i][3] == mx){
				is[i][3] = 1;
				s[3]++;
				c[i] = max(a[i][1], a[i][2]);
			}
			ans += mx;
		}
		up(1, 3, j){
			if(s[j] > n / 2){
				up(1, n, i) if(is[i][j]) zb.emplace_back(a[i][j] - c[i]);
				sort(zb.begin(), zb.end());
				up(0, s[j] - n / 2 - 1, i) ans -= zb[i];
				brk;
			}
		}
		zb.clear();
		printf("%lld\n", ans);
	}
	return AK;
}