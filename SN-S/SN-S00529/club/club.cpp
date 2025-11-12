#include<bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define mid(l, r) ((l + r) >> 1)
#define pii pair<int, int>
#define sec second
#define fir first
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n;
int a[N][4], maxn[N], maxn1[N], c[N];
pii t[N];
bool f[N];
inline bool cmp(int x, int y){
	return x > y;
}inline bool cmp1(pii x, pii y){
	return x.fir > y.fir;
}
inline void solve(){
	cin >> n;
	memset(c, 0, sizeof(c));
	memset(maxn, 0, sizeof(maxn));
	memset(maxn1, 0, sizeof(maxn1));
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) maxn[i] = 1;
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) maxn[i] = 2;
		else maxn[i] = 3;
		if((a[i][3] >= a[i][1] && a[i][3] <= a[i][2]) || (a[i][3] <= a[i][1] && a[i][3] >= a[i][2])) maxn1[i] = 3;
		else if((a[i][2] >= a[i][1] && a[i][2] <= a[i][3]) || (a[i][2] <= a[i][1] && a[i][2] >= a[i][3])) maxn1[i] = 2;
		else maxn1[i] = 1;
//		cout << maxn[i] << " " << maxn1[i] << "\n";
		++c[maxn[i]];
	}
	if(max(c[1], max(c[2], c[3])) * 2 > n){
		int k = 0;
		if(c[1] >= c[2] && c[1] >= c[3]) k = 1;
		else if(c[2] >= c[1] && c[2] >= c[3]) k = 2;
		else k = 3;
		int tot = 0;
		for(int i = 1; i <= n; i++){
			if(maxn[i] == k){
				t[++tot] = {a[i][maxn[i]] - a[i][maxn1[i]], i};
			}
		}
		sort(t + 1, t + tot + 1, cmp1);
		ll ans = 0;
		for(int i = 1; i <= n / 2; i++) ans += a[t[i].sec][k], f[t[i].sec] = 1;
		for(int i = 1; i <= n; i++){
			if(!f[i]){
				if(maxn[i] == k) ans += a[i][maxn1[i]];
				else ans += a[i][maxn[i]];
			}
		}
		cout << ans << "\n";
	}else{
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			ans += a[i][maxn[i]];
		}
		cout << ans << "\n";
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

