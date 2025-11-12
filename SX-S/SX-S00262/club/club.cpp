#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
priority_queue<int, vector<int>, greater<>> q[3];
int t, n, a[N][3], ans;
int fi[N], se[N], ls[N];
int posfi[N], posse[N];
unordered_map<int, int> mp;

int main() {
	// yidingyaoqudiaozhushi!!!!!!!!!!
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; i++)
			while (q[i].size())
				q[i].pop();
		ans = 0, mp.clear();
		memset(fi, 0, sizeof fi);
		memset(se, 0, sizeof se);
		memset(ls, 0x3f, sizeof ls);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &a[i][j]);
				fi[i] = max(fi[i], a[i][j]);
				ls[i] = min(ls[i], a[i][j]);
			}
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == fi[i])
					posfi[i] = j, mp[fi[i]] = i;
				else if (a[i][j] != ls[i])
					se[i] = a[i][j], posse[i] = j;
			}
		}
		/*
		for (int i = 1; i <= n; i++) {
			int j=posfi[i];
			if(q[j].size() < n / 2) q[i].emplace(i),ans+=fi[i];
			else{
				if (a[q[j].top()][pos]> a[i][j])
					ans -= q[j].top(), q[j].pop();
			}
			else
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			pos.emplace(i);
			for (int j = 0; j < 3; j++) {
				scanf("%d", &a[i][j]);
				fi[i] = max(fi[i], a[i][j]);
				ls[i] = min(ls[i], a[i][j]);
			}
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == fi[i])
					posfi[i] = j;
				else if (a[i][j] == ls[i])
					posls[i] = j;
				else
					se[i] = a[i][j], posse[i] = j;
			}
		}
		while(!pos.empty())
			for(auto i:pos){

			}

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			if (q[0].size() < n / 2)
				q[0].emplace(a[i][0]), ans += a[i][0];
			else if (q[0].top() < a[i][0])
				ans -= q[0].top(), q[0].pop(), q[0].emplace(a[i][0]), ans += a[i][0];
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &a[i][j]);
		*
		for (int i = 1; i <= n; i++)
			q[posfi[i]].emplace(fi[i]), ans += fi[i];
		for (int j = 0; j < 2; j++)
			while (q[j].size() > n / 2) {
				int i = mp[q[j].top()];
				q[j].pop();
				int k = mp[q[j].top()];
				if (fi[i] + se[k] <= fi[k] + se[i])
					ans -= fi[i] - se[i];
				else
					ans -= fi[k] - se[k], q[j].pop(), q[j].emplace(fi[i]);
			}
		printf("%d\n", ans);*/
		for (int i = 1; i <= n; i++) {
			int j = posfi[i];
			if (q[j].size() < n / 2)
				q[j].emplace(fi[i]), ans += fi[i];
			else {
				int k = mp[q[j].top()];
				if (fi[i] + se[k] <= fi[k] + se[i])
					ans += se[i], q[posse[i]].emplace(se[i]);
				else
					ans -= fi[k] - se[k], ans += fi[i], q[j].pop(), q[j].emplace(fi[i]), q[posse[k]].emplace(se[k]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}