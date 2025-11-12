#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node {
	int x, y, z, id;
};
struct node2 {
	int s, id;
};
const int N=2e5+5;
int n;
node a[N], b[N];

bool cmp(node x, node y) {
	if(x.x == y.x) {
		if(x.y == y.y) return x.z > y.z;
		return x.y > y.y;
	}
	return x.x > y.x;
}

void solve() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		int tx = a[i].x, ty = a[i].y, tz = a[i].z;
		b[i].id = i;
		b[i].x = max(max(tx, ty), tz);
		b[i].z = min(min(tx, ty), tz);
		b[i].y = a[i].x + a[i].y + a[i].z - b[i].x - b[i].z;
	}
	sort(b+1, b+n+1, cmp);
	deque<node2> q1, q2, q3;
	for(int i=1; i<=n; i++) {
		int j = b[i].id;
		if(a[j].x == b[i].x) q1.push_back((node2){b[i].x, i});
		else if(a[j].y == b[i].x) q2.push_back((node2){b[i].x, i});
		else if(a[j].z == b[i].x) q3.push_back((node2){b[i].x, i});
		
		if(q1.size() > n / 2) {
			int id1 = q1.front().id, id2 = q1.back().id;
			if(b[id1].y - b[id2].y > b[id1].x - b[id2].x) {
				q1.pop_front();
				if(a[b[id1].id].x == b[id1].y) q1.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].y == b[id1].y) q2.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].z == b[id1].y) q3.push_back((node2){b[id1].y, id1});
			} else {
				q1.pop_back();
				if(a[b[id2].id].x == b[id2].y) q1.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].y == b[i].y) q2.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].z == b[i].y) q3.push_back((node2){b[id2].y, id2});
			}
		}
		if(q2.size() > n / 2) {
			int id1 = q2.front().id, id2 = q2.back().id;
			if(b[id1].y - b[id2].y > b[id1].x - b[id2].x) {
				q2.pop_front();
				if(a[b[id1].id].x == b[id1].y) q1.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].y == b[id1].y) q2.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].z == b[id1].y) q3.push_back((node2){b[id1].y, id1});
			} else {
				q1.pop_back();
				if(a[b[id2].id].x == b[id2].y) q1.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].y == b[i].y) q2.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].z == b[i].y) q3.push_back((node2){b[id2].y, id2});
			}
		}
		if(q3.size() > n / 2) {
			int id1 = q3.front().id, id2 = q3.back().id;
			if(b[id1].y - b[id2].y > b[id1].x - b[id2].x) {
				q3.pop_front();
				if(a[b[id1].id].x == b[id1].y) q1.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].y == b[id1].y) q2.push_back((node2){b[id1].y, id1});
				else if(a[b[id1].id].z == b[id1].y) q3.push_back((node2){b[id1].y, id1});
			} else {
				q3.pop_back();
				if(a[b[id2].id].x == b[id2].y) q1.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].y == b[i].y) q2.push_back((node2){b[id2].y, id2});
				else if(a[b[id2].id].z == b[i].y) q3.push_back((node2){b[id2].y, id2});
			}
		}
	}
	
	int ans = 0;
	while(!q1.empty()) {
		ans += q1.back().s;
		q1.pop_back();
	}
	while(!q2.empty()) {
		ans += q2.back().s;
		q2.pop_back();
	}
	while(!q3.empty()) {
		ans += q3.back().s;
		q3.pop_back();
	}
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
