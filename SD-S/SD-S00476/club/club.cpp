#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

struct club {
	int id, c;
	friend bool operator < (club a, club b) {
		return a.c > b.c;
	}
};

struct people {
	club cc[5];
}a[N]; 

int T, n, f[N];
vector <int> t[5];

void solve() {
	for(int i = 1; i <= 3; i ++) t[i].clear();
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].cc[1].c >> a[i].cc[2].c >> a[i].cc[3].c;
		a[i].cc[1].id = 1, a[i].cc[2].id = 2, a[i].cc[3].id = 3;
	}
	for(int i = 1; i <= n; i ++) sort(a[i].cc + 1, a[i].cc + 4);
	for(int i = 1; i <= n; i ++) t[a[i].cc[1].id].push_back(i);
	int pos = -1;
	for(int i = 1; i <= 3; i ++) {
		if(t[i].size() > n / 2) {
			pos = i;
			break;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++) ans += a[i].cc[1].c;
	if(pos == -1) cout << ans << '\n';
	else {
		int k = t[pos].size() - n / 2, cnt = 0;
		for(int v : t[pos]) f[++ cnt] = a[v].cc[1].c - a[v].cc[2].c;
		sort(f + 1, f + cnt + 1);
		for(int i = 1; i <= k; i ++) ans -= f[i];
		cout << ans << '\n';
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --) solve();
	return 0;
}


