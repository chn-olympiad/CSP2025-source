#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in","r".stdin);
	freopen("number.out","w".stdout);
	cin >> s;
	int sum = 0, cnt = 0, tex = 0, res = 0, m, n, v;
	s = res;
	res % 10 = sum;
	res % 10 / 10 = cnt;
	res % 10 / 10 / 10 = tex;
	if (sum > cnt > tex) {
		m = sum;
		n = cnt;
		v = tex;
	} else if (sum > tex > cnt) {
		m = sum;
		n = tex;
		v = cnt;
	} else if (tex > sum > cnt) {
		m = tex;
		n = sum;
		v = cnt;
	} else if (tex > sum > cnt) {
		m = tex;
		n = cnt;
		v = sum;
	} else if (cnt > sum > tex) {
		m = cnt;
		n = sum;
		v = tex;
	} else(cnt > tex > sum) {
		m = cnt;
		n = tex;
		v = sum;
	}
	int abc;
	abc = (m * 100) + (n * 10) + v;
	cout << abc;
	return 0;
}