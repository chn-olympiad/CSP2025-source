#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
using namespace std;

struct shod {
	int x, y, z;
} z[100001];

struct pp {
	int wz, xh, d;
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	
	while (t--) {
		vector <int> p[4];
		long long ans = 0;
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			
			cin >> z[i].x >> z[i].y >> z[i].z;
			
			if (z[i].x >= z[i].y && z[i].x >= z[i].z) {
				if (p[1].size() < n / 2) {
					p[1].push_back(z[i].x);
				} else {
					for (int j : p[1]) {
						if (z[i].x > j) {
							p[1].pop_back();
							p[1].push_back(z[i].x);
						}
					}
				}
			} else if (z[i].y >= z[i].x && z[i].y >= z[i].z) {
				if (p[2].size() < n / 2) {
					p[2].push_back(z[i].y);
				} else {
					for (int j : p[2]) {
						if (z[i].x > j) {
							p[2].pop_back();
							p[2].push_back(z[i].y);
						}
					}
				}
			} else if (z[i].z >= z[i].y && z[i].x <= z[i].z) {
				if (p[3].size() < n / 2) {
					p[3].push_back(z[i].z);
				} else {
					for (int j : p[3]) {
						if (z[i].x > j) {
							p[3].pop_back();
							p[3].push_back(z[i].z);
						}
					}
				}
			}
		}
		
		for (int j : p[1]) {
			ans += z[j].x;
		}
		
		for (int j : p[2]) {
			ans += z[j].y;
		}
		
		for (int j : p[3]) {
			ans += z[j].z;
		}
		
		cout << ans << endl;
	}
	
	
	return 0;
}
