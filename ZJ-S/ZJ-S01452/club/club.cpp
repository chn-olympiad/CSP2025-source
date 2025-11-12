#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int int
#define pii pair<int,int>

const int N = 1e5 + 10;
int n, mx, a[N], cnt[5];
pair<int,int> b[N][5];
pair<int,int> c[N];
int d[N];

void dfs(int d) {
	if(d > n) {
		int tot = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i=1; i<=n; i++) {
			int fi = b[i][a[i]].first, se = b[i][a[i]].second;
			cnt[se]++;
			if(cnt[se] > n/2) {
				tot = -1;
				break;
			}
			tot += fi;
		}
		mx = max(mx, tot);
		return ;
	}
	a[d] = 1;
	dfs(d+1);
	a[d] = 2;
	dfs(d+1);
	a[d] = 3;
	dfs(d+1);
}

void solve() {

	cin >> n;
	if(n <= 10) {
		for(int i=1; i<=n; i++) {
			cin >> b[i][1].first >> b[i][2].first >> b[i][3].first;
			b[i][1].second = 1, b[i][2].second = 2, b[i][3].second = 3;

		}
		mx = 0;
		dfs(1);
		cout << mx << endl;
	} else {
		for(int i=1; i<=n; i++) {
			int t;
			cin >> c[i].first >> c[i].second >> d[i];
		}
		priority_queue<pair<int,pii >, vector<pair<int,pii > >, greater<pair<int,pii > > > pq[2];
		for(int i=1; i<=n; i++) {
			int fi = c[i].first, se = c[i].second;
			if(fi > se) {
				if((int)pq[0].size() >= n/2) {
					int f1 = pq[0].top().first, f2 = pq[0].top().second.first;
					if(fi <= f1) { // current is worst
						pq[1].push({se, {fi-se, i}}); // reverse push in another pq
					} else { // current is better
						pq[1].push({f1+f2, {-f2, pq[0].top().second.second}}); // reverse push in another pq
						pq[0].pop();
						pq[0].push({fi, {se-fi, i}}); // push in current
					}
				} else pq[0].push({fi, {se-fi, i}}); // push in current
			} else if(se > fi) {
				swap(fi, se);
				if((int)pq[1].size() >= n/2) {
					int f1 = pq[1].top().first, f2 = pq[1].top().second.first;
					if(fi <= f1) { // current is worst
						pq[0].push({se, {fi-se, i}}); // reverse push in another pq
					} else { // current is better
						pq[0].push({f1+f2, {-f2, pq[1].top().second.second}}); // reverse push in another pq
						pq[1].pop();
						pq[1].push({fi, {se-fi, i}}); // push in current
					}
				} else pq[1].push({fi, {se-fi, i}}); // push in current
			} else {
				if((int)pq[0].size() >= n/2) pq[1].push({fi, {se-fi, i}});
				else pq[0].push({fi, {se-fi, i}});
			}
		}
		priority_queue<int> pd;
		int tot = 0;
		while(pq[0].size()) tot += pq[0].top().first, pd.push(d[pq[0].top().second.second]-pq[0].top().first), pq[0].pop();
		while(pq[1].size()) tot += pq[1].top().first, pd.push(d[pq[1].top().second.second]-pq[1].top().first), pq[1].pop();
		while(pd.size()) {
			int f = pd.top();
			if(f > 0) tot += f, pd.pop();
			else break;
		}
		cout << tot << endl;
	}
}
signed main() {

	freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

	int _;
	cin >> _;
	while(_--)
		solve();

	return 0;

}