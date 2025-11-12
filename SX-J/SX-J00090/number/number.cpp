#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

char rst[1000010];

long long toInt(string s) {
	long long rst = 0, w = 1;
	for(int i = s.size() - 1; i >= 0; i--) {
		rst += w * (s[i] - '0');
		w *= 10;
	}
	return rst;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			rst[cnt] = s[i];
			cnt++;
		}
	}
	sort(rst, rst + cnt, greater<short>());
	rst[cnt] = '\0';
	cout << rst;
	return 0;
}