#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int maxn = 114514;//Shirasu Azusa
const int maxm = 1e4 + 15;
int n, m, k, cnt = 0;
int cst[15];
int tot[15], cal[15];
bool vis[maxm];
struct edge{
	int u, v;
	int w;
}mp[maxn];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int check(int op){
	int tmp = 1, now = 0, ans = 0;
	REP(i, 1, cnt){
		vis[i] = 0;
	}
	int ta = 0, shi = op;
	while (shi > 0){
		ta += (shi & 1);
		shi >>= 1;
	}
	while (tmp < n + ((k - shi) << 1) && now <= cnt){
		edge pre = mp[++now];
		if (vis[pre.u] && vis[pre.v]){
			continue;
		}
		if (pre.u > n){
			int ka = (pre.u - n + 1) >> 1;
			if ((op >> (ka - 1)) & 1){//i : (pre.u - n + 1)
				continue;
			}
		}
		vis[pre.u] = vis[pre.v] = 1;
		tmp++;
		ans += pre.w;
	}
	return ans;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		mp[++cnt] = {u, v, w};
	}
	REP(i, 1, k){//j + m + 1 = jm1
		cin >> cst[i];
		for (int j = 1, w; j <= n; j++){
			cin >> w;
			mp[++cnt] = {n + (i << 1) - 1, j, w};
		}
		mp[++cnt] = {n + (i << 1), n + (i << 1) - 1, cst[i]};
	}//build graph

	sort(mp + 1, mp + cnt + 1, cmp);
	int na = INT_MAX;
	REP(i, 0, (1 << k) - 1){
		na = min(na, check(i));
	}
	cout << na;
	return 0;
}
/*
sample:
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
/*
Regard every village as a city;
Build a miniumn tree;
Finally check if a village don't make use, then kill it;
make use means connecting two cities.
That's all my thoughts.

17:17
Well, I find it completely wrong;
As the sample, this code would bridge the second village because it thought this point must be connected;
I need to find a better algorithm.
Can we kill each villlage,then check whether it benefits or not?
This can be tried.
To the sky blue archive.
(p.s.:I find these words are also blue.)

18:03
I find my code get worse,going to the toilet.

18:07
I've given up struggling, using the former algorithm which may cheat some extra points.
At last, I failed to suceed,resulting to be a normal senior in senior high school.

18:23
Only 7min left.
I use a one-by-one O(1024m + mlogm) algorithm.
Hope:over 0 pts.

Hope to be seen.
*/
