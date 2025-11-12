#include <bits/stdc++.h>
using namespace std;

struct Idea {
	int score, which;
};

struct Student {
	Idea scores[4];
	int idx;
} stus[100001];

int t, n;
int cnt[4];
vector<int> who_choose[4];

bool cmpScore(Idea &A, Idea &B) {
	return A.score > B.score;
}

bool cmpChange(pair<int, pair<int, int> > &A, pair<int, pair<int, int> > &B) {
	return A.second.second < B.second.second;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		stus[i].idx = i;
		cin >> stus[i].scores[1].score >> stus[i].scores[2].score >> stus[i].scores[3].score;
		stus[i].scores[1].which = 1;
		stus[i].scores[2].which = 2;
		stus[i].scores[3].which = 3;
		sort(stus[i].scores + 1, stus[i].scores + 4, cmpScore);
	}

	int maximum = n / 2;
	long long pre_ans = 0;

	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i++) {
		int highest = stus[i].scores[1].score;
		int idx = stus[i].scores[1].which;
		cnt[idx]++;
		who_choose[idx].push_back(i);
		pre_ans += highest;
	}

	long long backup_ans = pre_ans, final_ans = INT_MIN;

	vector<pair<int, pair<int, int> > > change_informations;

	bool no_need = 1;
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] <= maximum) {
			continue;
		}

		no_need = 0;
		int differ = abs(cnt[i] - maximum);
		for (int j = 1; j <= 3; j++) {
			change_informations.clear();

			if (j == i || maximum - cnt[j] > differ) {
				continue;
			}

			for (int k = 0; k < who_choose[i].size(); k++) {
				pair<int, pair<int, int> > push_need;
				push_need.first = j; // 跳到哪里
				push_need.second.first = who_choose[i][k]; // 谁跳
				push_need.second.second = abs(stus[push_need.second.first].scores[i].score - stus[push_need.second.first].scores[j].score); // 减少的答案
				change_informations.push_back(push_need);
			}

			sort(change_informations.begin(), change_informations.end(), cmpChange);
			for (int k = 0; k < change_informations.size(); k++) {
				if (k == differ) {
					break;
				}

				pre_ans -= change_informations[k].second.second;
			}

			final_ans = max(final_ans, pre_ans);
			pre_ans = backup_ans;
		}
	}

	if (no_need) {
		cout << pre_ans << endl;
	}

	else {
		cout << final_ans << endl;
	}

	return;
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}