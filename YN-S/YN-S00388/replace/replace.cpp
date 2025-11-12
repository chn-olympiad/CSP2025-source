#include <bits/stdc++.h>
using namespace std;
int n, q, len1[200010];
vector<int>po[3000010], ne[3000010];

struct node {
	int x, y;
} ech[3000010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		len1[i] = s1.length();
		for (int j = 0; j < s1.length(); j++) {
			if (s1[j] == 'b')
				ech[i].x = j;
		}
		for (int j = 0; j < s2.length(); j++) {
			if (s2[j] == 'b')
				ech[i].y = j;
		}
		if (ech[i].x < ech[i].y)
			po[ech[i].y - ech[i].x].push_back(i);
		else
			ne[ech[i].x - ech[i].y].push_back(i);
	}
	while (q--) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int pos1, pos2, len2 = t1.length();
		for (int i = 0; i < t1.length(); i++) {
			if (t1[i] == 'b')
				pos1 = i;
		}
		for (int i = 0; i < t2.length(); i++) {
			if (t2[i] == 'b')
				pos2 = i;
		}
		if (t1.length() != t2.length())
			cout << 0 << endl;
		else {
			if (pos1 < pos2) {
				for (auto v : po[pos2 - pos1]) {
					if (pos1 >= ech[v].x && len2 - pos2 >= len1[v] - ech[v].y)
						ans++;
				}
			} else {
				for (auto v : ne[pos1 - pos2]) {
					if (pos2 >= ech[v].y && len1[v] - ech[v].x <= len2 - pos1)
						ans++;
				}
			}
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}