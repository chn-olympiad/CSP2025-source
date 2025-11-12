#include <bits/stdc++.h>
using namespace std;

int process(vector<int> &m1, vector<int> &m2, vector<int> &m3, int pos, int sum, int x1, int x2, int x3,
            vector<bool> flag) {
	if (pos >= m1.size() && x1 <= (m1.size() / 2) && x2 <= (m1.size() / 2) && x2 <= (m1.size() / 2)) {
		return sum;
	} else if (x1 > (m1.size() / 2) || x2 > (m1.size() / 2) || x2 > (m1.size() / 2)) {
		return 0;
	}
	int a = 0, b = 0, c = 0;
	if (!flag[pos]) {
		if (x1 <= m1.size() / 2) {
			flag[pos] = true;
			a = process(m1, m2, m3, pos + 1, sum += m1[pos], x1 + 1, x2, x3, flag);
		}
	}
	if (!flag[pos]) {
		if (x2 <= m1.size() / 2) {
			flag[pos] = true;
			b = process(m1, m2, m3, pos + 1, sum += m2[pos], x1, x2 + 1, x3, flag);
		}
	}
	if (!flag[pos]) {
		if (x3 <= m1.size() / 2) {
			flag[pos] = true;
			c = process(m1, m2, m3, pos + 1, sum += m3[pos], x1, x2, x3 + 1, flag);
		}
	}
	return max(a, max(b, c));
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while (t > 0) {
		t--;
		int n;
		cin >> n;
		vector<int> m1;
		vector<int> m2;
		vector<int> m3;
		vector<bool> flag;
		for (int i = 0; i < n; i++) {
			int tt;
			cin >> tt;
			m1.push_back(tt);
			cin >> tt;
			m2.push_back(tt);
			cin >> tt;
			m3.push_back(tt);
			flag[i] = false;
		}
		cout << process(m1, m2, m3, 0, 0, 0, 0, 0, flag) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}