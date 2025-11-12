#include <bits/stdc++.h>

using namespace std;

struct person {
	int index;
	int values;
	int places;
	int cnt;
	bool operator <(const person p1) const {
		return values < p1.values;
	}
};

int t;
int cnt[4];
bool getJob[100010];
person lis[300010];
long long ans1 = 0;

void dfs(int x, int n, long long ans) {
	if (x > 3 * n) {
		ans1 = max(ans1, ans);
		return;
	}
	dfs(x + 1, n, ans);
	int j = x;
	if (cnt[lis[j].places] <  n / 2) {
		if (getJob[lis[j].index])
			return;
		cnt[lis[j].places]++;
		//cout << lis[j].values << endl;
		getJob[lis[j].index] = true;
		ans += lis[j].values;
		dfs(x + 1, n, ans);
		cnt[lis[j].places]--;
		//cout << lis[j].values << endl;
		getJob[lis[j].index] = false;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	bool b1 = false;
	for (int i = 1; i <= t; i++) {
		int n;
		memset(cnt, 0, sizeof(cnt));
		memset(getJob, 0, sizeof(getJob));
		cin >> n;
		int ind = 0;
		for (int j = 1; j <= n; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			lis[++ind].index = j;
			lis[ind].places = 1;
			lis[ind].values = a;
			lis[ind].cnt = 0;
			lis[++ind].index = j;
			lis[ind].places = 2;
			lis[ind].values = b;
			lis[ind].cnt = 0;
			lis[++ind].index = j;
			lis[ind].places = 3;
			lis[ind].values = c;
			lis[ind].cnt = 0;
		}
		sort(lis + 1, lis + 3 * n + 1);
		long long ans = 0;
		long long ans2 = 0;
		if (n <= 100) {
			ans1 = 0;
			dfs(1, n, 0);
			if (b1)
				cout << endl;
			b1 = true;
			cout << ans1;
			continue;
		}
		for (int j = 3 * n; j >= 1; j--) {
			if (getJob[lis[j].index]) {
				continue;
			}
			if (cnt[lis[j].places] <  n / 2) {
				cnt[lis[j].places]++;
				//cout << lis[j].values << endl;
				getJob[lis[j].index] = true;
				ans += lis[j].values;
			}
		}
		memset(cnt, 0, sizeof(cnt));
		memset(getJob, 0, sizeof(getJob));
		for (int j = 3 * n; j >= 1; j--) {
			if (getJob[lis[j].index]) {
				continue;
			}
			if (cnt[lis[j].places] <  n / 2) {
				if (cnt[lis[j].places] ==  -1) {
					cnt[lis[j].places] =  n / 2 - 1;
					cnt[lis[j].places]++;
					lis[j].cnt++;
					//cout << lis[j].values << endl;
					getJob[lis[j].index] = true;
					ans2 += lis[j].values;
					continue;
				}
				if (cnt[lis[j].places] ==  n / 2 - 1 and lis[j].cnt != 2) {
					cnt[lis[j].places] = -1;
					continue;
				}
				cnt[lis[j].places]++;
				lis[j].cnt++;
				//cout << lis[j].values << endl;
				getJob[lis[j].index] = true;
				ans2 += lis[j].values;
			}
		}
		if (b1)
			cout << endl;
		b1 = true;
		cout << max(ans, ans2);
	}
	return 0;
}
