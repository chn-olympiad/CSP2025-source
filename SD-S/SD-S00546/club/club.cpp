#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
/*
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define bug cout<<"-------\n";
#define debug(x) cout<<#x<<'='<<x<<'\n';
#define file(FILENAME) freopen(FILENAME ".in","r",stdin),freopen(FILENAME ".out","w",stdout);
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl '\n'

const ll N = 100005;

ll a[N][5];
ll cnt[5], fl[N];
ll k[N];
ll n;
priority_queue<pair<ll, ll>> qu;
void solve1() {
	ll t = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(fl[i] == 1) {
			if(t * 2 < n) {
				ans += a[i][1], k[++t] = i;
				qu.push({max(a[i][2], a[i][3]) - a[i][1], t});
			} else {
				pair<ll, ll> u = qu.top();
				if(ans + u.first + a[i][1] > ans + max(a[i][3], a[i][2])) {
					ans = ans + u.first + a[i][1];
					k[u.second] = i;
					qu.pop();
					qu.push({max(a[i][2], a[i][3]) - a[i][1], u.second});
				} else {
					ans += max(a[i][3], a[i][2]);
				}
				/*ll id = 0;
				for(int j = 1; j <= t; j++) {
					if(id != 0) {
						if(ans - a[k[j]][1] + a[i][1] + max(a[k[j]][2], a[k[j]][3]) > ans - a[k[id]][1] + a[i][1] + max(a[k[id]][2], a[k[id]][3]))
							id = j;
					} else {
						if(ans - a[k[j]][1] + a[i][1] + max(a[k[j]][2], a[k[j]][3]) > ans + max(a[i][3], a[i][2]))
							id = j;
					}
				}
				if(id != 0) {
					ans = ans - a[k[id]][1] + a[i][1] + max(a[k[id]][2], a[k[id]][3]);
					k[id] = i;
				} else {
					ans += max(a[i][3], a[i][2]);
				}*/
			}
		} else ans += a[i][fl[i]];
	}
	cout << ans << endl;
}
void solve2() {
	ll t = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(fl[i] == 2) {
			if(t * 2 < n) {
				ans += a[i][2], k[++t] = i;
				qu.push({max(a[i][1], a[i][3]) - a[i][2], t});
			} else {
				pair<ll, ll> u = qu.top();
				if(ans + u.first + a[i][2] > ans + max(a[i][3], a[i][1])) {
					ans = ans + u.first + a[i][2];
					k[u.second] = i;
					qu.pop();
					qu.push({max(a[i][1], a[i][3]) - a[i][2], u.second});
				} else {
					ans += max(a[i][3], a[i][1]);
				}
				/*ll id = 0;
				for(int j = 1; j <= t; j++) {
					if(id != 0) {
						if(ans - a[k[j]][2] + a[i][2] + max(a[k[j]][1], a[k[j]][3]) > ans - a[k[id]][2] + a[i][2] + max(a[k[id]][1], a[k[id]][3]))
							id = j;
					} else {
						if(ans - a[k[j]][2] + a[i][2] + max(a[k[j]][1], a[k[j]][3]) > ans + max(a[i][1], a[i][3]))
							id = j;
					}
				}
				if(id != 0) {
					ans = ans - a[k[id]][2] + a[i][2] + max(a[k[id]][1], a[k[id]][3]);
					k[id] = i;
				} else {
					ans += max(a[i][1], a[i][3]);
				}*/
			}
		} else ans += a[i][fl[i]];
	}
	cout << ans << endl;
}
void solve3() {
	ll t = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(fl[i] == 3) {
			if(t * 2 < n) {
				ans += a[i][3], k[++t] = i;
				qu.push({max(a[i][2], a[i][1]) - a[i][3], t});
			} else {
				pair<ll, ll> u = qu.top();
				if(ans + u.first + a[i][3] > ans + max(a[i][1], a[i][2])) {
					ans = ans + u.first + a[i][3];
					k[u.second] = i;
					qu.pop();
					qu.push({max(a[i][1], a[i][2]) - a[i][3], u.second});
				} else {
					ans += max(a[i][1], a[i][2]);
				}
				/*ll id = 0;
				for(int j = 1; j <= t; j++) {
					if(id != 0) {
						if(ans - a[k[j]][3] + a[i][3] + max(a[k[j]][2], a[k[j]][1]) > ans - a[k[id]][3] + a[i][3] + max(a[k[id]][2], a[k[id]][1]))
							id = j;
					} else {
						if(ans - a[k[j]][3] + a[i][3] + max(a[k[j]][2], a[k[j]][1]) > ans + max(a[i][1], a[i][2]))
							id = j;
					}
				}
				if(id != 0) {
					ans = ans - a[k[id]][3] + a[i][3] + max(a[k[id]][2], a[k[id]][1]);
					k[id] = i;
				} else {
					ans += max(a[i][1], a[i][2]);
				}*/
			}
		} else ans += a[i][fl[i]];
	}
	cout << ans << endl;
}
void solve() {
	while(!qu.empty())qu.pop();
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][1] >= a[i][2]) {
			if(a[i][1] >= a[i][3]) cnt[1]++, fl[i] = 1;
			else cnt[3]++, fl[i] = 3;
		} else {
			if(a[i][2] >= a[i][3]) cnt[2]++, fl[i] = 2;
			else cnt[3]++, fl[i] = 3;
		}
	}
	if(cnt[1] >= cnt[2]) {
		if(cnt[1] >= cnt[3])solve1();
		else solve3();
	} else {
		if(cnt[2] >= cnt[3])solve2();
		else solve3();
	}
}
int main() {
	file("club")
	CLOSE
	ll T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

