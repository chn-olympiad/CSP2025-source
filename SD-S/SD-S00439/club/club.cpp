#include <bits/stdc++.h>
using namespace std;

struct Node {
	int num, id, l;
};

bool l[100005];
Node s[500005];

bool cmp(Node t1, Node t2) {
	if (t1.num == t2.num) {
		return t1.id < t2.id;
	} else {
		return t1.num > t2.num;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int f = n / 2;
		int x[4];
		for (int i = 1; i <= 3; i++) {
			x[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			l[i] = true;
		}
		int j = 1;
		for (int i = 1; i <= n; i++) {
			cin >> s[j].num >> s[j + 1].num >> s[j + 2].num;
			s[j].id = 1;
			s[j + 1].id = 2;
			s[j + 2].id = 3;
			s[j].l = i;
			s[j + 1].l = i;
			s[j + 2].l = i;
			j += 3;
		}
		j -= 1;
		sort(s + 1, s + 1 + j, cmp); 
		
		
//		for (int i = 1; i <= j; i++) {
//			cout << s[i].num << ' ';
//		}
//		cout << endl;
//		for (int i = 1; i <= j; i++) {
//			cout << s[i].id << ' ';
//		}
//		cout << endl;
//		for (int i = 1; i <= j; i++) {
//			cout << s[i].l << ' ';
//		}
//		cout << endl;
		
		
		long long ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 1; i <= j; i++) {
			if (x[s[i].id] < f && l[s[i].l]) {
				l[s[i].l] = false;
				x[s[i].id]++;
				ans1 += s[i].num;
			}
			if (x[1] + x[2] + x[3] == n) {
				break;
			}
		}
		for (int i = 1; i <= 3; i++) {
			x[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			l[i] = true;
		}
		for (int i = 2; i <= j; i++) {
			if (x[s[i].id] < f && l[s[i].l]) {
				l[s[i].l] = false;
				x[s[i].id]++;
				ans2 += s[i].num;
			}
			if (x[1] + x[2] + x[3] == n) {
				break;
			}
		}
		for (int i = 1; i <= 3; i++) {
			x[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			l[i] = true;
		}
		for (int i = 3; i <= j; i++) {
			if (x[s[i].id] < f && l[s[i].l]) {
				l[s[i].l] = false;
				x[s[i].id]++;
				ans3 += s[i].num;
			}
			if (x[1] + x[2] + x[3] == n) {
				break;
			}	
		}
		
//		cout << ans1 << endl;
//		cout << ans2 << endl;
//		cout << ans3 << endl;
		int maxn = 0;
		maxn = max(ans1, max(ans2, ans3));
		cout << maxn << endl;
	}
	
	return 0;
}

