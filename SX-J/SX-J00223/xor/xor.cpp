#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, k, num, ans;
int a[maxn], q[maxn];
map<int, queue<int> >mp;

int yh(int x, int y) {
	return (x | y) - (x &y);
}

struct node {
	int l;
	int r;
};
vector<node> qj;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		q[i] = yh(q[i - 1], a[i]);
		mp[q[i]].push(i);
	}
	for (int i = 1; i <= n; i++) {
		int need = yh(k, q[i - 1]);
		if (!mp[need].size())
			continue;
		else {
			while (mp[need].front() < i && !mp[need].empty())
				mp[need].pop();
			if (mp[need].empty())
				continue;
			qj.push_back({i, mp[need].front()});
			num++;
		}
	}
	for (int i = 0; i < num; i++) {
		if (qj[i].l == -1)
			continue;
		int kill = 0, ind = i + 1;
		while (qj[ind].l <= qj[i].r && ind < num) {
			kill++;
			ind++;
		}
		if (kill <= 1) {
			ans++;
			if (kill == 1)
				qj[i + 1].l = -1;
		} else {
			continue;
		}
	}
	printf("%d", ans);
	return 0;
}
