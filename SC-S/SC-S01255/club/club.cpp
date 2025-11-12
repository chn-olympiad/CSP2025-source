#include <bits/stdc++.h>

using namespace std;

struct Node{
	int num[4];
};

Node a[100010];

int getmax(const Node &x){
	return max(x.num[1], max(x.num[2], x.num[3]));
}

int getd(const Node &x){
	int maxx = getmax(x);
	int o1, o2;
	if(maxx == x.num[1])
		o1 = 2, o2 = 3;
	else if(maxx == x.num[2])
		o1 = 1, o2 = 3;
	else
		o1 = 1, o2 = 2;
	return min(maxx - x.num[o1], maxx - x.num[o2]);
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].num[1] >> a[i].num[2] >> a[i].num[3];
	sort(a + 1, a + n + 1, [](const Node &x, const Node &y){
		int max1 = getmax(x);
		int max2 = getmax(y);
		int d1 = getd(x);
		int d2 = getd(y);
		return d1 == d2 ? max1 > max2 : d1 > d2;
	});
//	for(int i = 1; i <= n; ++i)
//		cout << a[i].num[1] << ' ' << a[i].num[2] << ' ' << a[i].num[3] << ' ' << getd(a[i]) << '\n';
	int cnt[5] = {0, 0, 0, 0, 0};
	int res = 0;
	for(int i = 1; i <= n; ++i){
		int maxx = max(a[i].num[1], max(a[i].num[2], a[i].num[3]));
		int id, o1, o2;
		if(maxx == a[i].num[1])
			id = 1, o1 = 2, o2 = 3;
		else if(maxx == a[i].num[2])
			id = 2, o1 = 1, o2 = 3;
		else
			id = 3, o1 = 1, o2 = 2;
		if(cnt[id] < n / 2){
			res += maxx;
			cnt[id]++;
		}
		else{
			if(a[i].num[o1] > a[i].num[o2])
				id = o1;
			else
				id = o2;
			res += a[i].num[id];
			cnt[id]++;
		}
	}
	cout << res << '\n';
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
	
}
/*
4
9 2 2
10 9 9
9 0 0
10 8 8
*/