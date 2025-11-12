#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
struct info{
	int num, id;
}a[N][4], t[N];
int n, len[10];
bool cmp(info x, info y) {
	return x.num > y.num;
} 
void solve() {
	cin >> n;
	int ans = 0, sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i][1].num >> a[i][2].num >> a[i][3].num;
		a[i][1].id = 1, a[i][2].id = 2, a[i][3].id = 3;
		if(a[i][1].num < a[i][2].num) swap(a[i][1], a[i][2]);
		if(a[i][1].num < a[i][3].num) swap(a[i][1], a[i][3]);
		if(a[i][2].num < a[i][3].num) swap(a[i][2], a[i][3]);
		ans += a[i][1].num;
		t[i].num = a[i][1].num - a[i][2].num;
		t[i].id = i;
	}
	sort(t + 1, t + 1 + n, cmp);
	len[1] = len[2] = len[3] = 0;
	for(int i = 1; i <= n; i ++) {
//		cout << t[i].id << "\n";
		if(len[a[t[i].id][1].id] < n / 2) {
			len[a[t[i].id][1].id] ++;
		} else{
			len[a[t[i].id][2].id] ++;
			sum += t[i].num;
		}
	}
	ans -= sum;
	cout << ans << "\n";
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T --) solve();
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
