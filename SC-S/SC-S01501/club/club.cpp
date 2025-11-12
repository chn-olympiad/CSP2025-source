#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x, y, z, he, mx;
} a[100005];
bool cmp(node x, node y) {
	return x.he > y.he;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	while (t --) {
		long long n;
		cin >> n;
		for (long long i = 0; i < 100005; i ++) {
			a[i].x = 0;
			a[i].y = 0;
			a[i].z = 0;
			a[i].he = 0;
		}
		for (long long i = 1; i <= n; i ++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) a[i].mx = a[i].x;
			if (a[i].y >= a[i].x && a[i].y >= a[i].z) a[i].mx = a[i].y;
			if (a[i].z >= a[i].y && a[i].z >= a[i].x) a[i].mx = a[i].z;
			a[i].he = a[i].x + a[i].y + a[i].z;
		}
		sort(a + 1, a + 1 + n, cmp);
		long long cnt1 = 0;
		long long cnt2 = 0;
		long long cnt3 = 0;
		long long mxcn = n / 2;
		long long mxm = 0;
		for (long long i = 1; i <= n; i ++) {
			if (a[i].mx == a[i].x && cnt1 < mxcn) {
				cnt1++;
				mxm += a[i].x;
				continue;
			}
			else {
				if (a[i].y >= a[i].z && cnt2 < mxcn) {
					cnt2 ++;
					mxm += a[i].y;
					continue;
				}
				else {
					cnt3 ++;
					mxm += a[i].z;
					continue;
				}
			}
			if (a[i].mx == a[i].y && cnt2 < mxcn) {
				cnt2++;
				mxm += a[i].y;
				continue;
			}
			else {
				if (a[i].x >= a[i].z && cnt1 < mxcn) {
					cnt1 ++;
					mxm += a[i].x;
					continue;
				}
				else {
					cnt3 ++;
					mxm += a[i].z;
					continue;
				}
			}
			if (a[i].mx == a[i].z && cnt3 < mxcn) {
				cnt3++;
				mxm += a[i].z;
				continue;
			}
			else {
				if (a[i].x >= a[i].y && cnt1 < mxcn) {
					cnt1 ++;
					mxm += a[i].x;
					continue;
				}
				else {
					cnt2 ++;
					mxm += a[i].y;
					continue;
				}
			}
		}
		cout << mxm << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/