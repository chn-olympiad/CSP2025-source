#include <bits/stdc++.h>
using namespace std;
int lst[200000][3];
struct dt {
	int st, nd, rd, next;
};
dt man[200000];
int clubs[3][200000];
int cnum[3];
bool rule(int a, int b) {
	return man[a].next > man[b].next;
}
void rechoose(int j, int n) {
	sort(clubs[j]+0, clubs[j]+cnum[j], rule);
	while (cnum[j] > n / 2) {
		int x = clubs[j][cnum[j]];
		dt mx = man[x];
		mx.st = mx.nd;
		mx.nd = mx.rd;
		mx.next = lst[x][mx.st] - lst[x][mx.nd];
		man[x]=mx;
		if(j==mx.st)string oop="BUG";
		clubs[mx.st][++cnum[mx.st]];
		cnum[j]--;
		int sj=cnum[j];
	}
}
int solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i][0] >> lst[i][1] >> lst[i][2];
		dt newdt;
		if (lst[i][0] > lst[i][1]) {
			if (lst[i][2] > lst[i][0]) {
				newdt.st = 2;
				newdt.nd = 0;
				newdt.rd = 1;
			} else {
				newdt.st = 0;
				newdt.nd = max(lst[i][1], lst[i][2]);
				newdt.rd = min(lst[i][1], lst[i][2]);
			}
		}
		if (lst[i][1] >= lst[i][0]) {
			if (lst[i][2] > lst[i][1]) {
				newdt.st = 2;
				newdt.nd = 1;
				newdt.rd = 0;
			} else {
				newdt.st = 1;
				newdt.nd = max(lst[i][0], lst[i][2]);
				newdt.rd = min(lst[i][0], lst[i][2]);
			}
		}
		newdt.next = lst[i][newdt.st] - lst[i][newdt.nd];
		man[i] = newdt;
		clubs[newdt.st][++cnum[newdt.st]]=i;
	}
	bool flags = true;
	for (int j = 0; j < 3; j++) {
		if (cnum[j] > n / 2)

		{
			flags = false;
			rechoose(j, n);
			break;
		}
	}
	if (flags) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += lst[i][man[i].st];
		}
		cout << ans << "\n";
		return 0;
	} else {
		int ans=0;
		for(int i=0; i<3; i++) {
			for(int j=0; j<cnum[i]; j++) {
				int x=clubs[i][j];
				ans += lst[x][i];
			}
		}
		cout<<ans<<'\n';
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(lst, 0, sizeof(lst));
		memset(man, 0, sizeof(man));
		memset(clubs,0,sizeof(clubs));
		memset(cnum,0,sizeof(cnum));
		solve();
	}
	return 0;
}