#include <bits/stdc++.h>
using namespace std;
//N<=1e5
//暴搜减支
const int N = 1e5 + 5;
int n, maxc, ans;
long long maxsum[N]; //深度i时最大,倒序！
int cnt[3];
int flag = 0;

//a[i][j] ai对j的好感度
void dfs(int i, long long sum, vector<vector<int>> &a) {
	if (i > n) {
		flag = 1;
		return;
	}
	for (int j = 0; j < 3; j++) {
		//	maxc = n / 2;
		if (cnt[j] < maxc) {
			if (maxsum[i + 1]) {
				//算过
				sum += maxsum[i + 1] + a[i][j];
				ans = max((long long)ans, sum);
				maxsum[i] = max(maxsum[i], maxsum[i + 1] + a[i][j]);
			} else {
				//没算过
				sum += a[i][j];
				ans = max((long long)ans, sum);
				if (flag)
					maxsum[i] = max(maxsum[i], maxsum[i + 1] + a[i][j]);
				cnt[j]++;
				dfs(i + 1, sum, a);
				cnt[j]--;
			}
		}
	}
	flag = 1;
	return;
}

void slove() {
	ans = 0;
	cin >> n;
	maxc = n / 2;
	for (auto i : cnt)
		i = 0;
	for (auto i : maxsum)
		i = 0;
	vector<int> a(n);
	for (auto &i : a) {
		int asd;
		cin >> i;
		cin >> asd;
		cin >> asd;
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < maxc; i++)
		ans += a[i];
	cout << ans;
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}