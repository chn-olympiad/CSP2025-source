#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e5 + 7;
int n;
int a[maxm][3];
struct node{
	int x, y, z;
	int c; 
}b[maxm];

bool cmp(node a, node b) {
	if(a.c == b.c) return max(a.x, max(a.y, a.z)) > max(b.x, max(b.y, b.z));
	return a.c > b.c;
}
void solve() {
	cin >> n; 
	long long ans = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		b[i].x = a[i][1], b[i].y = a[i][2], b[i].z = a[i][3];
		if(min(min(b[i].x, b[i].y), b[i].z) == b[i].x) b[i].c = max(b[i].y, b[i].z) - min(b[i].y, b[i].z);
		if(min(min(b[i].x, b[i].y), b[i].z) == b[i].y) b[i].c = max(b[i].x, b[i].z) - min(b[i].x, b[i].z);
		if(min(min(b[i].x, b[i].y), b[i].z) == b[i].z) b[i].c = max(b[i].y, b[i].x) - min(b[i].y, b[i].x);
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	sort(b + 1, b + n + 1, cmp);
	int i;
	for(i = 1; i <= n; i ++) {
		if(max(max(b[i].x, b[i].y), b[i].z) == b[i].x) {
			if(cnt1 + 1 <= n / 2) cnt1 ++, ans += b[i].x;
			else break;
		}else if(max(max(b[i].x, b[i].y), b[i].z) == b[i].y) {
			if(cnt2 + 1 <= n / 2) cnt2 ++, ans += b[i].y;
			else break;
		}else if(max(max(b[i].x, b[i].y), b[i].z) == b[i].z) {
			if(cnt3 + 1 <= n / 2) cnt3 ++, ans += b[i].z;
			else break;
		}
	}
	for(; i <= n; i ++) {
		if(cnt1 + 1 > n / 2) ans += max(b[i].y, b[i].z);
		else if(cnt2 + 1 > n / 2) ans += max(b[i].x, b[i].z);
		else if(cnt3 + 1 > n / 2) ans += max(b[i].y, b[i].x);
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
} 
/*
5
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
4
4 2 1
3 2 4
5 3 4
3 5 1
4
5 6 0
7 5 0
7 8 0
8 9 0
10
9 8 10
7 2 8
5 5 6
7 6 8
2 2 2
3 3 5
1 4 6
7 8 8
7 9 9
7 7 9
*/