#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += d)
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= d)
//#define int long long
void INIT() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 5e5 + 10;
int n, k;
int a[MAXN], xum[MAXN];

struct LR {
	int l, r;
}t[5000000 + 10];
int cnt;
bool cmp(const LR& x, const LR& y) {
	return x.r < y.r;
}

signed main() {
	INIT();
	
	bool tB = 0;
	cin >> n >> k;
	upl(i, 1, n, 1) {
		cin >> a[i];
		tB &= (a[i] == 0 || a[i] == 1);
		xum[i] = xum[i - 1] ^ a[i];
	}
	
	if(tB) {
		int cnt = 0;
		if(k) {
			upl(i, 1, n, 1) {
				if(a[i] == 1)
					cnt++;
			}
		} else {
			int t = 0;
			upl(i, 1, n, 1) {
				if(a[i] == 0) {
					cnt++;
					cnt += t / 2;
					t = 0;
				} else
					t++;
			}
		}
		cout << cnt;
		return 0;
	}
	
	upl(i, 1, n, 1) {
		upl(j, i, n, 1) {
			if((xum[j] ^ xum[i - 1]) == k) {
				t[++cnt] = {i, j};
//				cout << i << " " << j << "\n";
			}
		}
	}
	sort(t + 1, t + 1 + cnt, cmp);
	int ans = 0;
	LR last = {-1, -1};
	upl(i, 1, cnt, 1) {
		if(t[i].r < last.l || (t[i].r > last.r && t[i].l > last.r))
			ans++, last = t[i];
	}
	
	cout << ans;
	return 0;
}

