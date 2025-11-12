#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	
	cin >> n >> k;
	
	vector <int> v(n);
	map <int, int> mp;
	
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	
	
	for (int i = 0; i < v.size(); ++i) {
		int j = i, h_sum = 0;
		bool flag = true;
		
		do {
			h_sum = h_sum ^ v[j];
		} while (j++ < n && h_sum != k);
		
		if (j >= v.size() && h_sum != k) {
			continue;
		}
		
		if (i == v.size() - 1) {
			mp[i] = -1;
		}
		
		mp[i] = j;
	}
	
	int maxcnt = 0;
	
	for (int i = 0; i < n - 1; ++i) {
		if (mp.count(i)) {
			int cnt = 0;
			int x = i;
			while (1) {
				if (!mp.count(x)) {
					break;
				}
				++cnt;
				x = mp[x];
			}
			
			maxcnt = max(maxcnt, cnt);
		}
	}
	
	cout << maxcnt << endl;
	
	return 0;
}