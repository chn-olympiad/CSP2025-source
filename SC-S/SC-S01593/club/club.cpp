#include <bits/stdc++.h>
using namespace std;
struct p{
	int s1, s2, s3;
};
bool cmp1(p a, p b) {
	if (a.s1 - max(a.s2,a.s3) != b.s1 - max(b.s2,b.s3)) {
		return a.s1 - max(a.s2,a.s3) > b.s1 - max(b.s2,b.s3);
	} else {
		return a.s1 > b.s1;
	}
}
bool cmp2(p a, p b) {
	if (a.s2 - max(a.s1,a.s3) != b.s2 - max(b.s1,b.s3)) {
		return a.s2 - max(a.s1,a.s3) > b.s2 - max(b.s1,b.s3);
	} else {
		return a.s2 > b.s2;
	}
}bool cmp3(p a, p b) {
	if (a.s3 - max(a.s1,a.s2) != b.s3 - max(b.s1,b.s2)) {
		return a.s3 - max(a.s1,a.s2) > b.s3 - max(b.s1,b.s2);
	} else{
		return a.s3 > b.s3;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		p a[100001];
		for (int i = 0; i < n; i++) {
			cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
		}
		sort(a, a + n, cmp1);
		int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
		for (int i = 0; i < n / 2; i++) {
			ans1 += a[i].s1;
		}
		for (int i = n / 2; i < n; i++) {
			ans1 += max(a[i].s2, a[i].s3);
		}
		sort(a, a + n, cmp2);
		for (int i = 0; i < n / 2; i++) {
			ans2 += a[i].s2;
		}
		for (int i = n / 2; i < n; i++) {
			ans2 += max(a[i].s1, a[i].s3);
		}
		sort(a, a + n, cmp3);
		for (int i = 0; i < n / 2; i++) {
			ans3 += a[i].s3;
		}
		for (int i = n / 2; i < n; i++) {
			ans3 += max(a[i].s2, a[i].s1);
		}
		for (int i = 0; i < n; i++) {
			ans4 += max(a[i].s1, max(a[i].s2, a[i].s3));
		}
		cout << max(ans1, max(ans2, max(ans3, ans4))) << endl;
	}
	return 0;
}

