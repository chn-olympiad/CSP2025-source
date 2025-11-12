#include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	
	string s;
	
	cin >> s;
	
	vector <int> v;
	
	for (int i = 0; i < s.length(); ++i) {
		if (isdigit(s[i])) {
			v.push_back(s[i] - '0');
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	bool b = true;
	
	for (int i = 0; i < v.size(); ++i) {
		if (b && v[i] == 0 && i != v.size() - 1) {
			continue;
		}
		
		b = false;
		cout << v[i];
	}
	
	cout << endl;
	
	return 0;
}