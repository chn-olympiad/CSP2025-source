#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	long long n, m, s;
	
	cin >> n >> m;
	
	v.resize(n * m);
	
	for (long long i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	
	s = v[0];
	
	sort(v.begin(), v.end());
	
	auto it = lower_bound(v.begin(), v.end(), s);
	long long h_pos = it - v.begin();
	h_pos = v.size() - h_pos;
	
	long long c, r;
	
	if (h_pos % n) {
		c = h_pos / n + 1;
		h_pos -= n * (c - 1);
	} else {
		c = h_pos / n;
		h_pos = n;
	}
	
	if (c % 2) {
		r = h_pos;
	} else {
		r = n - h_pos + 1;
	}
	
	cout << c << ' ' << r << endl;
	
	return 0;
}