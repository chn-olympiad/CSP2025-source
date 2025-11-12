#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int int

const int N = 500 + 10, MOD = 998244353;
int n, m;
string s;
int c[N], o[N], noo[N], cnt, da[N];

int jiecheng(int x) {
	ll tot = 1;
	for(int i=1; i<=x; i++) tot = tot*i%MOD;
	return tot;
}

void solve() {

	cin >> n >> m >> s;
	for(int i=1; i<=n; i++) cin >> c[i], o[i] = i;

	int cnt1 = 0;
	for(auto to  : s) cnt1 += (to == '1');

	if(n <= 10) {
		int tot = 0;
		do {
			int no = 0;
			for(int i=1; i<=n; i++) {
				int cur = o[i];
				if(no >= c[cur]) no++;
				else {
					if(s[i-1] == '0') no++;
				}
			}
			if(n-no >= m) tot++;
		} while(next_permutation(o+1, o+n+1));
		cout << tot;
	} else {
		int len = s.size();
		int L = 0, tot  =1;
		for(int i=0; i<=n; i++) {
			for(int j=1; j<=n; j++)if(c[j]>i)da[i]++;
		}
		for(int i=0; i<len; i++) {
			if(s[i] == '0') continue;
			else {
				noo[++cnt] = i-L;
				L = i+1;
			}
		}
		if(cnt < m) return cout << 0, void();

		for(int i=1; i<=cnt; i++) {
			noo[i] += noo[i-1];
		}
		int all=0;
		for(int i=0; i<(1<<cnt); i++) {
			vector<bool>v(cnt+1,0);int cccccc=0;
			for(int j=0; j<cnt; j++) if(i&(1<<j))v[j+1]=1,cccccc++;
			if(cccccc < m) continue;
			int kou=0,zeng=0,tot=1;
			for(int j=cnt; j>=1; j--) {
				int cc = 0;
				if(v[j]) {
tot*=(da[noo[j]]-kou);
				} else tot*=(n-kou),tot%=MOD;
				kou++;

			}
			all += tot;
			all%=MOD;
		}
		cout << all;
	}

}

signed main() {
//
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

//    int _; cin >> _; while(_--)
	solve();

	return 0;

}
