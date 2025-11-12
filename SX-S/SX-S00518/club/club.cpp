#include <bits/stdc++.h>
using namespace std;
//#define ll long long;
int t, n, o;

struct stu {
	int m[3], z = 0, cj = 0;
} a[100010];

bool cmp(stu c, stu b) {
	if (c.z == o && b.z == o && o != -1) {
		int aa = c.m[c.z] + b.m[b.z] - b.cj, bb = b.m[b.z] + c.m[c.z] - c.cj;
		if (aa >= bb)
			return 1;
		else
			return 0;
//		if(a.m[a.z]>=b.m[b.z]){
//			if(a.cj>=b.cj)
//			return a;
//			else return b;
//		}else{
//			return a.cj<=b.cj;
//		}
	}
	return c.m[c.z] >= b.m[b.z];
}

//club
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;;
	while (t--) {
		long long ans = 0;
		cin >> n;
		int q[3] = {0, 0, 0};
		for (int i = 0; i < n; i++) {
			a[i].z = 0;
			a[i].cj = 0;
			for (int j = 0; j < 3; j++) {
				cin >> a[i].m[j];
				if (j > 0)
					if (a[i].m[j] > a[i].m[a[i].z]) {
						a[i].cj = a[i].m[j] - a[i].m[a[i].z];
						a[i].z = j;

					}
			}
			if (a[i].z == 0) {
				a[i].cj = a[i].m[0] - max(a[i].m[1], a[i].m[2]);
			}
			q[a[i].z]++;
		}
		o = -1;
		for (int i = 0; i < 3; i++) {
			if (q[i] > n / 2) {
				o = i;
				break;
			}
		}
		int p = n / 2;
		sort(a, a + n, cmp);

		for (int i = 0; i < n; i++) {
			if (a[i].z == o) {
				if (p > 0) {
					p--;
					ans += a[i].m[a[i].z];
//					cout << a[i].m[a[i].z] << ' ';
//					cout << ans << endl;
				} else {
					ans += a[i].m[a[i].z] - a[i].cj;
//					cout << a[i].m[a[i].z] << ' ' << a[i].cj << ' ';
//					cout << ans << endl;
				}

			} else {
				ans += a[i].m[a[i].z];
//				cout << a[i].m[a[i].z] << ' ';
//				cout << ans << endl;
			}

		}
		cout <<  ans << endl;
	}

	return 0;
}
//fight club
//the first rule,you do not talk about fight club
