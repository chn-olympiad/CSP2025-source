#include<bits/stdc++.h>
using namespace std;
struct club {
	int j1, j2, j3;
	double q;
};
bool cmp(club a, club b) {
	return a.q > b.q;
}
//bool cmp1(club x,club y){
//	return max(x.j1,(max(x.j2,x.j3)))>max(y.j1,(max(y.j2,y.j3)));
//}
bool cmp1(club x, club y) {
	return max(x.j1, x.j2) > max(y.j1, y.j2);
}
int jdz(int x) {
	if (x >= 0) return x;
	else return -x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		club d[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> d[i].j1 >> d[i].j2 >> d[i].j3;
		for (int i = 1; i <= n; i++) {
//			int s=d[i].j1+d[i].j2+d[i].j3;
//			int temp=(s-d[i].j1)*(s-d[i].j1)+
//					 (s-d[i].j2)*(s-d[i].j2)+
//					 (s-d[i].j3)*(s-d[i].j3);
			int temp = jdz(d[i].j1 - d[i].j2) + jdz
			           (d[i].j1 - d[i].j3) + jdz(d[i].j2 - d[i].j3);
			d[i].q = temp;
		}
		sort(d + 1, d + n + 1, cmp);
		int d1 = 0, d2 = 0, d3 = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j1) {
				if (	d1 < (n / 2)) {
					d1++;
					ans += d[i].j1;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && d2 < (n / 2)) {
					d2++;
					ans += d[i].j2;
				} else {
					d3++;
					ans += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j2) {
				if (	d2 < (n / 2)) {
					d2++;
					ans += d[i].j2;
				} else if (max(d[i].j1, d[i].j3) == d[i].j1 && d1 < (n / 2)) {
					d1++;
					ans += d[i].j1;
				} else {
					d3++;
					ans += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j3) {
				if (	d3 < (n / 2)) {
					d3++;
					ans += d[i].j3;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && d2 < (n / 2)) {
					d2++;
					ans += d[i].j2;
				} else {
					d1++;
					ans += d[i].j1;
				}
			}
		}
		/////////////////////////
		for (int i = 1; i <= n; i++) {
			int s = d[i].j1 + d[i].j2 + d[i].j3;
			int temp = (s - d[i].j1) * (s - d[i].j1) +
			           (s - d[i].j2) * (s - d[i].j2) +
			           (s - d[i].j3) * (s - d[i].j3);
//			int temp=jdz(d[i].j1-d[i].j2)+jdz
//			(d[i].j1-d[i].j3)+jdz(d[i].j2-d[i].j3);
			d[i].q = temp;
		}
		sort(d + 1, d + n + 1, cmp);
		int d11 = 0, d21 = 0, d31 = 0;
		int ans1 = 0;
		for (int i = 1; i <= n; i++) {
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j1) {
				if (	d11 < (n / 2)) {
					d11++;
					ans1 += d[i].j1;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && d21 < (n / 2)) {
					d21++;
					ans1 += d[i].j2;
				} else {
					d31++;
					ans1 += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j2) {
				if (	d21 < (n / 2)) {
					d21++;
					ans1 += d[i].j2;
				} else if (max(d[i].j1, d[i].j3) == d[i].j1 && d11 < (n / 2)) {
					d11++;
					ans1 += d[i].j1;
				} else {
					d31++;
					ans1 += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j3) {
				if (	d31 < (n / 2)) {
					d31++;
					ans1 += d[i].j3;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && d21 < (n / 2)) {
					d21++;
					ans1 += d[i].j2;
				} else {
					d11++;
					ans1 += d[i].j1;
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////
		int mans = 0;
		int dd1 = 0, dd2 = 0, dd3 = 0;
		sort(d + 1, d + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j1) {
				if (	dd1 < (n / 2)) {
					dd1++;
					mans += d[i].j1;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && dd2 < (n / 2)) {
					dd2++;
					mans += d[i].j2;
				} else {
					dd3++;
					mans += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j2) {
				if (	dd2 < (n / 2)) {
					dd2++;
					mans += d[i].j2;
				} else if (max(d[i].j1, d[i].j3) == d[i].j1 && dd1 < (n / 2)) {
					dd1++;
					mans += d[i].j1;
				} else {
					dd3++;
					mans += d[i].j3;
				}
			}
			if (max(d[i].j1, max(d[i].j2, d[i].j3)) == d[i].j3) {
				if (	dd3 < (n / 2)) {
					dd3++;
					mans += d[i].j3;
				} else if (max(d[i].j2, d[i].j3) == d[i].j2 && dd2 < (n / 2)) {
					dd2++;
					mans += d[i].j2;
				} else {
					dd1++;
					mans += d[i].j1;
				}
			}
		}
		cout << max(ans1, max(ans, mans)) << endl;
	}
	return 0;
}
