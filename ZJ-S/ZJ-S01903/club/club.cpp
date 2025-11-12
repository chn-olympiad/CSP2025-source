#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;

using PII = pair<int, int>;
using PIII = pair<int, PII>;

int T, n, s[5], ans, a[N][3], sum[N];
bitset<N> v;
priority_queue<PIII> pq;

void dfs(int x, int s1, int s2, int s3, int s) {
    if (s + sum[n] - sum[x - 1] < ans)  return ;
    if (x > n) {
        ans = max(ans, s);
        return ;
    }
    if (a[x][1] > a[x][2]) {
        if (a[x][1] > a[x][3]) {
            if (a[x][2] > a[x][3]) {
                if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
                if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
                if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
            } else {
                if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
                if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
                if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
            }
        } else {
            if (a[x][2] > a[x][3]) {
                if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
                if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
                if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
            } else {
                if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
                if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
                if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
            }
        }
    } else if (a[x][1] > a[x][3]) {
        if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
        if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
        if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
    } else {
        if (s3 < n / 2) dfs(x + 1, s1, s2, s3 + 1, s + a[x][3]);
        if (s1 < n / 2) dfs(x + 1, s1 + 1, s2, s3, s + a[x][1]);
        if (s2 < n / 2) dfs(x + 1, s1, s2 + 1, s3, s + a[x][2]);
    }
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> T;
    while (T -- ) {
        cin >> n;
        if (n <= 30) {
            for (int i = 1; i <= n; i ++ )
                cin >> a[i][1] >> a[i][2] >> a[i][3], sum[i] = sum[i - 1] + max({a[i][1], a[i][2], a[i][3]});
            ans = 0;
            dfs(1, 0, 0, 0, 0);
            cout << ans << '\n';
            continue;
        }
        v.reset();  s[1] = s[2] = s[3] = 0;   ans = 0;
        for (int i = 1, x, y, z; i <= n; i ++ )
            cin >> x >> y >> z,
            pq.push({x, {i, 1}}),
            pq.push({y, {i, 2}}),
            pq.push({z, {i, 3}});
		while (!pq.empty()) {
			PIII piii = pq.top();	pq.pop();
			int val = piii.first, idx = piii.second.first, cb = piii.second.second;
			if (v.test(idx) || s[cb] >= n / 2)	continue;
			v.set(idx);	s[cb] ++ ;
			ans += val;
            if (s[1] + s[2] + s[3] == n)    break;
		}
        while (!pq.empty()) pq.pop();
		cout << ans << '\n';
    }
    return 0;
}