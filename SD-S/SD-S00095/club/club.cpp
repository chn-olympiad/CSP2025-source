#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x , y , z;
} ;

int n;
vector<Node> s1 , s2 , s3;
vector<int> r; 

inline void solve() {
	scanf ("%d" , &n);
	s1.clear(); s2.clear(); s3.clear(); r.clear();
	for (int i = 1; i <= n; i++) {
		Node c;
		scanf ("%d%d%d" , &c.x , &c.y , &c.z);
		if (c.x >= c.y && c.x >= c.z) s1.push_back(c);
		else if (c.y >= c.x && c.y >= c.z) s2.push_back(c);
		else if (c.z >= c.x && c.z >= c.y) s3.push_back(c);
	}
	int ans = 0;
	for (auto i : s1) ans += i.x;
	for (auto i : s2) ans += i.y;
	for (auto i : s3) ans += i.z;
	int cnt = 0;
//	cout << ans << " " << s1.size() << s2.size() << s3.size() << "\n";
	if (s1.size() > n / 2) {
		cnt = s1.size() - (n / 2);
		for (auto i : s1) 
			r.push_back(min(i.x - i.y , i.x - i.z));
	}
	if (s2.size() > n / 2) {
		cnt = s2.size() - (n / 2);
		for (auto i : s2) 
			r.push_back(min(i.y - i.x , i.y - i.z));
	}
	if (s3.size() > n / 2) {
		cnt = s3.size() - (n / 2);
		for (auto i : s3) 
			r.push_back(min(i.z - i.x , i.z - i.y));
	}
	sort(r.begin() , r.end());
	for (int i = 0; i < cnt; i++)
		ans -= r[i];
	printf ("%d\n" , ans);
}

int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T;
	scanf ("%d" , &T);
	while (T--) solve();
} 
/*
147325
*/
