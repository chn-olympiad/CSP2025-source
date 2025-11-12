#include <bits/stdc++.h>
using namespace std;

int baoling(int n, vector<vector<int>> &vec, int person_index, int satisfaction, int one_num, int two_num,
            int three_num) {
	if (person_index == n) {
		return satisfaction;
	}
	if (one_num == n / 2) {
		return max(baoling(n, vec, person_index + 1, satisfaction + vec[person_index][1], one_num, two_num + 1, three_num),
		           baoling(n, vec, person_index + 1, satisfaction + vec[person_index][2], one_num, two_num, three_num + 1));
	}
	if (two_num == n / 2) {
		return max(baoling(n, vec, person_index + 1, satisfaction + vec[person_index][0], one_num + 1, two_num, three_num),
		           baoling(n, vec, person_index + 1, satisfaction + vec[person_index][2], one_num, two_num, three_num + 1));
	}
	if (three_num == n / 2) {
		return max(baoling(n, vec, person_index + 1, satisfaction + vec[person_index][1], one_num, two_num + 1, three_num),
		           baoling(n, vec, person_index + 1, satisfaction + vec[person_index][0], one_num + 1, two_num, three_num));
	}
	return max(baoling(n, vec, person_index + 1, satisfaction + vec[person_index][0], one_num + 1, two_num, three_num),
	           max(baoling(n, vec, person_index + 1, satisfaction + vec[person_index][1], one_num, two_num + 1, three_num),
	               baoling(n, vec, person_index + 1, satisfaction + vec[person_index][2], one_num, two_num, three_num + 1)));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> vec;
		bool three_all_0 = true;
		for (int i = 0; i < n; i++) {
			int one, two, three;
			cin >> one >> two >> three;
			if (three != 0) {
				three_all_0 = false;
			}
			vector<int> temp;
			temp.push_back(one);
			temp.push_back(two);
			temp.push_back(three);
			vec.push_back(temp);
		}
		cout << baoling(n, vec, 0, 0, 0, 0, 0) << endl;
	}
	return 0;
}