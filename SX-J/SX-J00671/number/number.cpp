#include <bits/stdc++.h>
using namespace std;
string s, s2;
int a[1000000];
int sum = 0, p = 0, q = 0; //a为所有数，sum为累加数组的和，p为s的位数，q为数字在a中对应的下标

bool cmp(int x, int y) {

	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	p = s.size();
	for (int i = 0; i < p; i++) {
		if ((int)s[i] <= 'a') {
			a[q] = (int)s[i] - '0';
			q = q + 1;
		}
	}
	sort(a, a + p, cmp);
	for (int i = 0; i < q ; i++) {
		s2[i] = a[i] + '0';
		cout << s2[i];
	}
	return 0;
}
