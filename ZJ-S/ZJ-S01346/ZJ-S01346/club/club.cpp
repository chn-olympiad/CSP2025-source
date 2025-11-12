#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;

namespace CLUB {

const int N = 1e5 + 10;
int n, A[3][N], opt[N], cnt[3], to[N];

void main() {
	cin >> n; LL Ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> A[0][i] >> A[1][i] >> A[2][i]; 
		int t = max({A[0][i], A[1][i], A[2][i]}); Ans += t;
		if (A[0][i] == t) opt[i] = 0;
		else if (A[1][i] == t) opt[i] = 1;
		else opt[i] = 2;
		cnt[opt[i]] ++;
	}
	if (max({cnt[0], cnt[1], cnt[2]}) > n / 2) {
		int p = (cnt[0] > n / 2 ? 0 : (cnt[1] > n / 2 ? 1 : 2));
		priority_queue<pair<int, int> > pq;
		for (int i = 1; i <= n; i ++) if (opt[i] == p) {
			to[i] = -1;
			for (int j = 0; j < 3; j ++) if (j != p)
				if (to[i] == -1 || (A[p][i] - A[to[i]][i] > A[p][i] - A[j][i]))
					to[i] = j;
			pq.push({A[to[i]][i] - A[p][i], i});
		}
		while (!pq.empty() && max({cnt[0], cnt[1], cnt[2]}) > n / 2) {
			int u = pq.top().second; Ans += pq.top().first; pq.pop();
			cnt[opt[u]] --, cnt[to[u]] ++;
		}
	}
	cout << Ans << "\n";
	return ;
}

void clear() {
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i ++) A[0][i] = A[1][i] = A[2][i] = opt[i] = to[i] = 0;
	return ; 
}

}

int main() {
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _; cin >> _;
	while (_ --) CLUB::main(), CLUB::clear();
	return 0;
}