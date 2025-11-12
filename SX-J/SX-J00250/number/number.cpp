#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	int a = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			v.push_back(0);
		} else if (s[i] == '1') {
			v.push_back(1);
		} else if (s[i] == '2') {
			v.push_back(2);
		} else if (s[i] == '3') {
			v.push_back(3);
		} else if (s[i] == '4') {
			v.push_back(4);
		} else if (s[i] == '5') {
			v.push_back(5);
		} else if (s[i] == '6') {
			v.push_back(6);
		} else if (s[i] == '7') {
			v.push_back(7);
		} else if (s[i] == '8') {
			v.push_back(8);
		} else if (s[i] == '9') {
			v.push_back(9);
		}
	}
	int Max = -1;
	int sw = 0;
	for (int i = 0; i < v.size(); i++) {
		Max = -1;
		for (int j = 0; j < v.size(); j++) {
			if (Max < v[j]) {
				Max = v[j];
				sw = j;
			}
		}
		v[sw] = -2;
		int d = 1;
		for (int z = 1; z < v.size() - i; z++) {
			d *= 10;
		}
		a = a + Max * d;
		if (v.size() == 1) {
			a = Max;
		}
	}
	cout << a;
	return 0;
}