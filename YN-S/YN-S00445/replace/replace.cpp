#include <bits/stdc++.h>
using namespace std;
string s1, s2, t1, t2;
int n, q, l1, l2, ans, len;
int b1, end1, b2, end2;

struct message {
	int ladd, radd, needl, needr;
} cnt;
vector<message>a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		l1 = s1.size();
		l2 = s2.size();
		end1 = l1 - 1;
		end2 = l2 - 1;
		for (int j = 0; j < l1; j++)
			if (s1[j] == 'b') {
				b1 = j;
				break;
			}
		for (int j = 0; j < l2; j++)
			if (s2[j] == 'b') {
				b2 = j;
				break;
			}
		cnt.ladd = b2 - b1;
		cnt.radd = (end2 - b2) - (end1 - b1);
		cnt.needl = b1;
		cnt.needr = end1;
		a.push_back(cnt);
	}
	len = a.size();
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> t1 >> t2;
		l1 = t1.size();
		l2 = t2.size();
		end1 = l1 - 1;
		end2 = l2 - 1;
		for (int j = 0; j < l1; j++)
			if (t1[j] == 'b') {
				b1 = j;
				break;
			}
		for (int j = 0; j < l2; j++)
			if (t2[j] == 'b') {
				b2 = j;
				break;
			}
		for (int j = 0; j < len; j++)
			if (b1 >= a[j].needl && end1 >= a[j].needr && b1 + a[j].ladd == b2 && end1 + a[j].radd == end2)
				ans++;
		cout << ans;
	}
	return 0;
}