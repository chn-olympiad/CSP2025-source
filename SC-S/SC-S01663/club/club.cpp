#include<bits/stdc++.h>
using namespace std;
unsigned short t;
unsigned int n = 0;
unsigned int a[100000][3];
unordered_map<unsigned long long, unsigned long long> map1, map2;


void do_one();
void clear();

struct key {
	unsigned short x, y, z;
};


unsigned long long change(key tt) {
	int ttt  = n / 2 + 2;
	return ttt * ttt * tt.x + ttt * tt.y + tt.z;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		do_one();
		clear();
	}

	return 0;

}


void do_one() {
	unsigned long long ans = 0;
	cin >> n;
	for (unsigned i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	map1[0] = 0;
	queue<key> keys;

	for (unsigned i = 0; i < n; i++) {
		for (int x = 0; x <= min(i, n / 2); x++) {
			for (int y = 0; y <= min(i - x, n / 2); y++) {
				int z = i - x - y;
				if (z > n / 2)continue;
				key keyt = {x, y, z};
				keys.push(keyt);
			}
		}

		while (!keys.empty()) {
			key keyt = keys.front();
			key keyx = keyt, keyy = keyt, keyz = keyt;
			if (keyx.x + 1 <= n / 2) {
				keyx.x += 1;
				if (map2.count(change(keyx))) {
					map2[change(keyx)] = max(map2[change(keyx)], map1[change(keyt)] + a[i][0]);
				} else {
					map2[change(keyx)] = map1[change(keyt)] + a[i][0];
				}
			}
			if (keyy.y + 1 <= n / 2) {
				keyy.y += 1;
				if (map2.count(change(keyy))) {
					map2[change(keyy)] = max(map2[change(keyy)], map1[change(keyt)] + a[i][1]);
				} else {
					map2[change(keyy)] = map1[change(keyt)] + a[i][1];
				}
			}
			if (keyz.z + 1 <= n / 2) {
				keyz.z += 1;
				if (map2.count(change(keyz))) {
					map2[change(keyz)] = max(map2[change(keyz)], map1[change(keyt)] + a[i][2]);
				} else {
					map2[change(keyz)] = map1[change(keyt)] + a[i][2];
				}

			}
			keys.pop();
			ans = max(max(ans, map2[change(keyx)]), max(map2[change(keyy)], map2[change(keyz)]));
		}




		map1 = map2;
		map2.clear();

	}

	cout << ans << endl;

}

void clear() {
	memset(a, 0, sizeof(a));
	map1.clear();
	map2.clear();
}