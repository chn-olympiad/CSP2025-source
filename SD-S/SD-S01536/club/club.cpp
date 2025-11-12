#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;
ll a[100005][5];
vector < int > v[5];

void solve() {
	scanf("%d" , &n);
	ll sum = 0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= 3 ; j++) {
			scanf("%lld" , a[i] + j);
		}
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			v[1].push_back(i) , sum += a[i][1];
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
			v[2].push_back(i) , sum += a[i][2];
		else
			v[3].push_back(i) , sum += a[i][3];
	}
	if (v[1].size() > n / 2) {
		priority_queue < ll > q;
		for (auto i : v[1]) {
			q.push(max(a[i][2] , a[i][3]) - a[i][1]);
		}
		while (q.size() > n / 2) {
			sum += q.top();
			q.pop();
		}
	}
	else if (v[2].size() > n / 2) {
		priority_queue < ll > q;
		for (auto i : v[2]) {
			q.push(max(a[i][1] , a[i][3]) - a[i][2]);
		}
		while (q.size() > n / 2) {
			sum += q.top();
			q.pop();
		}
	}
	else if (v[3].size() > n / 2) {
		priority_queue < ll > q;
		for (auto i : v[3]) {
			q.push(max(a[i][2] , a[i][1]) - a[i][3]);
		}
		while (q.size() > n / 2) {
			sum += q.top();
			q.pop();
		}
	}
	printf("%lld\n" , sum);
}

signed main() {
	
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	scanf("%d" , &t);
	while (t--)
		solve();
	
	return 0;
}
