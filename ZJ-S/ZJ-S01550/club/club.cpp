#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct stt {
	int a[5];
	int b[5];
} sts[N];
int n;
void chge (int x) {
	if (sts[x].a[0] > sts[x].a[1]) {
		if (sts[x].a[0] > sts[x].a[2]) {
			if (sts[x].a[1] > sts[x].a[2]) {
				sts[x].b[0] = 0, sts[x].b[1] = 1, sts[x].b[2] = 2;
			}
			else {
				sts[x].b[0] = 0, sts[x].b[1] = 2, sts[x].b[2] = 1;
			}
		}
		else {
				sts[x].b[0] = 2, sts[x].b[1] = 0, sts[x].b[2] = 1;
		}
	}
	else {
		if (sts[x].a[0] > sts[x].a[2]) {
			sts[x].b[0] = 1, sts[x].b[1] = 0, sts[x].b[2] = 2;
		}
		else {
			if (sts[x].a[1] < sts[x].a[2]) {
				sts[x].b[0] = 2, sts[x].b[1] = 1, sts[x].b[2] = 0;
			}
			else {
				sts[x].b[0] = 1, sts[x].b[1] = 2, sts[x].b[2] = 0;
			}
		}
	}
	return;
}
int cnt[5];
bool cmp1 (stt a, stt b) {
	return (a.a[a.b[0]] - a.a[a.b[1]]) < (b.a[b.b[0]] - b.a[b.b[1]]);
}
bool cmp2 (stt a, stt b) {
	return (a.a[a.b[0]] - a.a[a.b[2]]) < (b.a[b.b[0]] - b.a[b.b[2]]);
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int t;
	long long s = 0;
	cin >> t;
	while (t -- ) {
		s = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for (int i = 0; i < n; i ++ ) {
			cin >> sts[i].a[0] >> sts[i].a[1] >> sts[i].a[2];
			chge (i);
			s += sts[i].a[sts[i].b[0]];
//			cout << sts[i].b[0]<<sts[i].b[1]<<sts[i].b[2]<<endl;
			cnt[sts[i].b[0]] ++ ;
		}
		if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) {
			sort (sts, sts + n, cmp1);
			for (int i = 0; i < n; i ++ ) {
				if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) break;
				if(cnt[sts[i].b[0]] > n / 2) {
					if (cnt[sts[i].b[1]] < n / 2) {
						cnt[sts[i].b[0]] -- , cnt[sts[i].b[1]] ++ ;
						s -= sts[i].a[sts[i].b[0]] - sts[i].a[sts[i].b[1]];
					}
				}
			}
		}
		if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) {
			sort (sts, sts + n, cmp2);
			for (int i = 0; i < n; i ++ ) {
				if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) break;
				if(cnt[sts[i].b[0]] > n / 2) {
					if (cnt[sts[i].b[2]] < n / 2) {
						cnt[sts[i].b[0]] -- , cnt[sts[i].b[1]] ++ ;
						s -= sts[i].a[sts[i].b[0]] - sts[i].a[sts[i].b[2]];
					}
				}
			}
		}
		cout << s << endl;
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
